namespace project
{

struct min_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "min";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "375.nT6K8CliBz1B.Xtz8TBDshd.s3Px1HkXDOiuYBCmFdJmyEgV2uA15ppJaaNV3b7.DKkBx.PL.TC.tzEcVm7FBf2mxLh400I3c5ImUntfSILSHTgswZrVqfW47UQ+Iq7E6l2GNjfWKzIl5Gk7Aog2Fd2J5W+nScIlYvI0f0xiBrU.vezi1VmfWJeUkScsvJedkIF8kOuJmS8A7VoFP5Adbcia2GBuJ+I5KQ4y7fdjNi5DneDxICSIUqWREdwe3erLZ.4Z3n0f05BZEMlyxgbA5Sxta0dUeTGNkZBn9ZjtoaV733bPLbV.47zb.s.yaw83bMGNtli0ZDZmkm4Eg5qQ13k3S9BLf.E.BJFxG7kyJ13AQf3pH.TooJ9HgbUvCGPUCKzsshXv8Miut..hRNFWe6rgiQZ+BBxgCFmv4WqQ9.u4HIIi73Rj.C2p.+KnCcNN4k0z5wqapb0D1D3hDprdK.s8AAODW2xeDwkQHf4hetEqiDD21NQA";
	}
};
}

