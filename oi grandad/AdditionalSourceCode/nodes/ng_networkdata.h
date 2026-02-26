namespace project
{

struct ng_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "ng";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "488.nT6K8CllDTuC.XkUGQBDw0MJjzTks+D4wIRaVPoTeq.ox9QoM2iyN...fKpCulgZYJ.O.rC.9.PFjkZh483qqQ4DiPaopcT1KqScEOZq6jRZskogEnsQ4i9NFqCO8hRpYFTFcIgPI1JQ9Qaeh3nsZ7xqpKo+Y0GM5NoZrs1X5Upz6YMbJ8MzJ1eENg15VvFi0EANASP1q99T9QNZL9ePTByiTdYo.z7pVx13bJsmA7cTFYXAg9ddut6CMv.DNvBf0PwGjyi1BeUHeNKI1kcty4Tpn.ycQMl5n2cO3jERoufa6109AygyJ4D6RMUC6tznCgTvhEXcUDN7hC7.tSB4Z+mSh8jW7YSM4R5huK1.JT70ekllEXfIfh0OQc1FleymHb.LK3nPAMupCDEnQVxbLXv.r.RjDC.L..bFV8vKVugFBvPPJTIL8WjGzllrPWWDSfpXSdBusQFqjOXcrI0kU+MHQwGSZBo4MuLqWYARsdy4FPgR.DZC2dhkFqJR.3hyn2vBzS1PP1.aFQKzkawhyBntfKhxJ7PHNWqioSAMGC5PJS1Fzx94IMJhV5uXPOzFV.iYjmvxUbSSYpq4sD.G.YIX7CNjIPcffG4JZBn1G.SuR4w6A1xxFXs77LgEZhhYWGPUFPKGnnF";
	}
};
}

