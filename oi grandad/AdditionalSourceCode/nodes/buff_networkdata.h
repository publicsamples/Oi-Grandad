namespace project
{

struct buff_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "buff";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "438.nT6K8CV3CTVC.XWUFYBDKqa.b+HoL8DNvi9EZRBC91Ge0IAlI.02+K...Hp7x20ClMGYJrC.5.fN..6pblwF71M0Fq6m0rlhh25ZyKu2JwIdaFTN2r0EmXPLiQHKTDy3sxIj9dBqFMbY3EucRkDu0geBQ0uD0dRGOtwYJYWu1ULuGgI3sNWrSX0pDkvOcv56ayGKwCx+BVI4BcbIkGXo.7bN8kMRyozdqKxtIC5cY39qgCXqQtViOYsbPUcU035BJx8MJyPpSagYIzxyy4zei00wMJbx6UHkITiChCYM16ZvHlMloQfe61wtKkAY+SMhpZTQYImvJjNwjhrbbIMUQ4f5fuUfWT4pXTLAIcI8XWDcwOOrtrhlxLerMNbMvBPe+A+4m0iH6.BPBLFFZog33aRt2WBfC2bbk2hXvB8R.FpV7KhUrSYQKwmKIb0m57xrWlkBPnkJeLGJ9XhEOfF5GWkEcivSnkYvKFrLPLoF+IALAYCm.f3EbfihL.JOLcBlM.vcLQgmkHvgCfOg.4R.3CvEyA0FPANfu+AhULCbW4AtBv6CAsKNJVreUHFXN2foa.1J.NY.";
	}
};
}

