template <int NV>
struct poly_resonator
{
    SNEX_NODE(poly_resonator);

    static const int NUM_CHANNELS = 2;

    double sr = 44100.0;

    // ================= CONTROLS =================

    double decay   = 0.7;
    double tone       = 0.5;
    double structure  = 0.0;
    double spread     = 0.5;
    double saturation = 0.3;
    double mix        = 0.5;
    double mode       = 1.0;

    // ================= VOICE =================

    struct VoiceData
    {
		double prevInput = 0.0;

        // 6 modes L
        double y1L0 = 0.0; double y2L0 = 0.0;
        double y1L1 = 0.0; double y2L1 = 0.0;
        double y1L2 = 0.0; double y2L2 = 0.0;
        double y1L3 = 0.0; double y2L3 = 0.0;
        double y1L4 = 0.0; double y2L4 = 0.0;
        double y1L5 = 0.0; double y2L5 = 0.0;

        // 6 modes R
        double y1R0 = 0.0; double y2R0 = 0.0;
        double y1R1 = 0.0; double y2R1 = 0.0;
        double y1R2 = 0.0; double y2R2 = 0.0;
        double y1R3 = 0.0; double y2R3 = 0.0;
        double y1R4 = 0.0; double y2R4 = 0.0;
        double y1R5 = 0.0; double y2R5 = 0.0;

        int noteNumber = 60;
        double energyMemoryL = 0.0;
        double energyMemoryR = 0.0;

        void reset()
        {
	
			energyMemoryL = 0.0;
			energyMemoryR = 0.0;

            y1L0=0;y2L0=0;y1L1=0;y2L1=0;y1L2=0;y2L2=0;
            y1L3=0;y2L3=0;y1L4=0;y2L4=0;y1L5=0;y2L5=0;

            y1R0=0;y2R0=0;y1R1=0;y2R1=0;y1R2=0;y2R2=0;
            y1R3=0;y2R3=0;y1R4=0;y2R4=0;y1R5=0;y2R5=0;
        }
    };

    PolyData<VoiceData, NV> voiceData;

    void prepare(PrepareSpecs ps)
    {
        sr = ps.sampleRate;
        voiceData.prepare(ps);
    }

    void reset() {}

    // ratio morph
    inline double getRatio(int m)
    {
        double s = structure;
        double h = (double)(m + 1);

        double p = 1.0;

        if(m == 0) p = 1.0;
        if(m == 1) p = 2.76;
        if(m == 2) p = 5.40;
        if(m == 3) p = 8.93;
        if(m == 4) p = 13.34;
        if(m == 5) p = 18.64;
        
        

        return h * (1.0 - s) + p * s;
    }

    template <int C>
    void processFrame(span<float, C>& data)
    {
        if(mode < 0.5)
            return;

        auto& v = voiceData.get();

        double input = 0.5 * (data[0] + data[1]);
double diff = input - v.prevInput;
v.prevInput = input;

// transient emphasis
double exciteSignal = diff;

// only allow positive transients
if(exciteSignal < 0.0)
    exciteSignal = 0.0;

        double baseFreq = 440.0 *
            Math.pow(2.0, (v.noteNumber - 69) / 12.0);

        double outL = 0.0;
        double outR = 0.0;

// ===== DECAY CONTROL (stable & musical) =====

double d = decay;

// cubic shaping for finer control at high end
double shaped = d * d * d;

// pole radius range
double minR = 0.97;     // short but still resonant
double maxR = 0.9998;   // very long but stable

double baseR = minR + (maxR - minR) * shaped;

        double slope = structure * 0.015;

        // ===== MODE 0 =====
        {
            double ratio = getRatio(0);
            double freq = baseFreq * ratio;
            if(freq > sr * 0.45) freq = sr * 0.45;

            double omega = 2.0 * Math.PI * freq / sr;
            double R = baseR - slope * 0.0;

            double coeff = 2.0 * R * Math.cos(omega);
            double coeff2 = 0.0 - (R * R);

            double excite = exciteSignal * 1.0;

            double yL = excite + coeff * v.y1L0 + coeff2 * v.y2L0;
            v.y2L0 = v.y1L0;
            v.y1L0 = yL;

            double omegaR = omega * (1.0 + spread * 0.01);
            double coeffR = 2.0 * R * Math.cos(omegaR);

            double yR = excite + coeffR * v.y1R0 + coeff2 * v.y2R0;
            v.y2R0 = v.y1R0;
            v.y1R0 = yR;

            outL += yL;
            outR += yR;
        }

        // ===== MODE 1 =====
        {
            double ratio = getRatio(1);
            double freq = baseFreq * ratio;
            if(freq > sr * 0.45) freq = sr * 0.45;

            double omega = 2.0 * Math.PI * freq / sr;
            double R = baseR - slope * 1.0;

            double coeff = 2.0 * R * Math.cos(omega);
            double coeff2 = 0.0 - (R * R);

            double excite = exciteSignal * 5.6;

            double yL = excite + coeff * v.y1L1 + coeff2 * v.y2L1;
            v.y2L1 = v.y1L1;
            v.y1L1 = yL;

            double omegaR = omega * (1.0 + spread * 0.01);
            double coeffR = 2.0 * R * Math.cos(omegaR);

            double yR = excite + coeffR * v.y1R1 + coeff2 * v.y2R1;
            v.y2R1 = v.y1R1;
            v.y1R1 = yR;

            outL += yL;
            outR += yR;
        }

        // Repeat same pattern for modes 2–5
        // (identical structure, excite = 0.4, 0.25, 0.15, 0.1)

        // tone
        double tilt = 1.0 - tone * 0.5;
        outL = outL * tilt;
        outR = outR * tilt;

        // saturation
        double drive = 1.0 + saturation * 3.0;
        outL = Math.tanh(outL * drive) / drive;
        outR = Math.tanh(outR * drive) / drive;

        data[0] = data[0] * (1.0 - mix) + (float)outL * mix;
        data[1] = data[1] * (1.0 - mix) + (float)outR * mix;
        
  
    }
    
    

    template <typename PD>
    void process(PD& data)
    {
        auto fd = data.toFrameData();
        while(fd.next())
            processFrame(fd.toSpan());
    }

    void handleHiseEvent(HiseEvent& e)
    {
        if(e.isNoteOn())
        {
            auto& v = voiceData.get();
            v.noteNumber = e.getNoteNumber();
            v.reset();
        }
    }

    void setExternalData(const ExternalData& d, int index) {}

    template<int P>
    void setParameter(double v)
    {
        if(P == 0) decay   = v;
        if(P == 1) tone       = v;
        if(P == 2) structure  = v;
        if(P == 3) spread     = v;
        if(P == 4) saturation = v;
        if(P == 5) mix        = v;
        if(P == 6) mode       = v;
    }
};