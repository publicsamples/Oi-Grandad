namespace project
{

struct FollowIN4_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "FollowIN4";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "342.nT6K8ClTATlB.X3D9PBDoiS.ezhcRI8DwnB1IAoJAgmTWOBji0kzD..f.2hTDDHwzOvL.HC.x..ETjgtcBaJl.5uLWIah8jZg3nmq5IUeCpA0XFzCamLxS9hIoD52qgvNnORpfdLwNgIOEP+rvBPekDECg8CU+kS1RbO.1t49tp5HNPb7vwrrEC.G8WxU8TA8Mli9JVJWqMNNzsWBH87e4SP.6QuFtBJo5kQtRkKGa1mkzEo5+N2HM7yJS+3mud6DlgHO4Labkb9QYoP3sTByMSOuLHRJglMxaPMFC5h7nW0EK6QYH1vtYjs5njB5aLXnnfFJZnXACg93U+5GPVft4UGYCDEe.BLBITDxG.Ag.phgYlbCAXCWjMYXzhlKju4hsNrFT4xbTZgn5+oUX82ANxgfQF3CZfUChqaUWMDdvRv9Brq4Qbwcfa.QmeloHLPy5IFjpY.";
	}
};
}

