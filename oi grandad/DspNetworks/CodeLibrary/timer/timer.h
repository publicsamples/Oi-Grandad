template <int NumVoices> struct timer
{
	SNEX_NODE(timer);
	
	// Calculate a new timer value here
	double getTimerValue()
	{
		return 0.0;
	}
	// Reset any state here
	void reset()
	{
	}
	// Initialise the processing
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
