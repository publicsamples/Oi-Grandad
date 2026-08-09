template <int NumVoices> struct .h
{
	// This macro enables C++ compilation to a snex_osc
	SNEX_NODE(.h);
	
	// This function will be called once per sample
	float tick(double uptime)
	{
		return Math.fmod(uptime, 1.0);
	}
	
	// This function will calculate a chunk of samples
	void process(OscProcessData& d)
	{
		for (auto& s : d.data)
		{
			s = tick(d.uptime);
			d.uptime += d.delta;
		}
	}
	
	// This can be used to initialise the processing if required.
	void prepare(PrepareSpecs ps)
	{
	}
	
	void setExternalData(const ExternalData& d, int index)
	{
	}
	template <int P> void setParameter(double v)
	{
	}
};
