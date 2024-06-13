namespace project
{

struct send2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "send2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "337.nT6K8ClRAziB.Xvj7PBHKaS.OfD6qir2EPSJhjf.xfUiKw5472HRG.PxAXyggrPSm9QL.DC.w.PiCcqkomHCc6D1SqAzaYtQxD64zlPidt0PT8rG1CC1NYjkbnFjkKD5ijNnmgX2vjgDK71I8qxR.8MoIFBaGp9Kmbk3p.rcy8U05GMObLfyvxTK.ZzeI2ZHGzyVM5arTtTYBPPjjy+kWQAKG8X3FTR0KiLEJUMxrOJoKR0+ctQX3G0k1wOW8VIKDQdxW13F47axNEvbuzyJDhjTfYeb1CasftGN5UEZWN5JQF1MiLUGibPOawBnCX.w.xfUB8wp90Ndp.cypNtBf.BLBITDxG.Ag.phgYlbCAXCWjMYXzhlKju4hsNrFT3xbTZgn5+oUX82ANxgfQF3CZfUChqaUWMDdvRv9Brq4Qbwcfa.QlelmHLPyZFItDY8xC";
	}
};
}

