namespace project
{

struct trkin3_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "trkin3";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "366.nT6K8C18ATxB.X4z8HBHKi9CMkwJa9+Z.wjjf.xf8i5yBLp6H6UBBP1BEVutdjRoy.PM.HC.u15fziyu19uVRIHQG9kxFueocgDIxS8jLQ1C6goJR70MKmqfNdsL9qAjHTjShY79gmmDVVoFbqk1gQGHwont8R760QdFiuL751utqoVBh7gcAxrbkBfip.sbRlZmfLEQhSrk0VsABFP6uZWK.JRQDsPFFnIRTCO8hxDsb9xkKHaVWkUCJSD2egzvtJpNBh7kaqnJb9Yp0WJH69KU+WJ7tq8BCAEwPyJAYOLUeMIZhY5X0DotXS6ctpcJNIh.ywiFIz3QiCzEI5Wsqi7f4EvJf.ifFCyLP6fVjDLEXlQNFjjM7.1nhrUFFqnMDxeOw1QjFzIOygy1Q9wIG.JtCv2OvINrcx.+QixMHtdq5ZCgGKa6mTtJr6rsBukUqAvcCj0wi6X3yE53CTI.KDwOavqEWMKFnQ.J4.FE";
	}
};
}

