namespace project
{

struct FollowIN3_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "FollowIN3";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "342.nT6K8ClTATlB.X3D9PBHIiS.Ozh8QQd7A1RsCA.IH1s6cCiPmC8Bkf.r4rsYhukLR+vL.HC.x..ETjgtcBaJl.5uLWIah8jZg3nmq5IUeCpA0XGzCamLxSNiIoE52qgvPnORxfdLwdgIOEP+rvBPekDECg8CU+kS1RbS.1t49tp5HNPbDwwrrEC.G8WxU8jA8Mli9JVJWqMNNzsWBH87e4UP.6QuFtBJo5kQtRkKGa1mkzEo5+N2HM7yJS+3mud6D1gHO4Labkb9QYoT3sTByMSOuPHRRglMxaPMFC5h7nWUFK6QYI1vtYjs5nDC5MnwnwhCVzXQArD5iW8qe.YA5lWcjMPTe.BLBITDxG.Ag.phgYlbCAXCWjMYXzhlKju4hsNrFT4xbTZgn5+oUX82ANxgfQF3CZfUChqaUWMDdvRv9Brq4Qbwcfa.QmeloHLPy5IFjpY.";
	}
};
}

