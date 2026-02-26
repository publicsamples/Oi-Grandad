template <int NV> struct BufferState
{
	SNEX_NODE(BufferState);
	
	// Initialise the processing specs here
	void prepare(PrepareSpecs ps)
	{
		
	}
	
	// Reset the processing pipeline here
	void reset()
	{
		
	}
	
	// Process the signal here
	template <typename ProcessDataType> void process(ProcessDataType& data)
	{
		
	}
	
	// Process the signal as frame here
	template <int C> void processFrame(span<float, C>& data)
	{
	}
	
	// Process the MIDI events here
	void handleHiseEvent(HiseEvent& e)
	{
		
	}
	
	// Use this function to setup the external data
	void setExternalData(const ExternalData& d, int index)
	{
		
	}
	
	// Set the parameters here
	template <int P> void setParameter(double v)
	{
		
	}
};
