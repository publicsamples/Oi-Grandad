namespace project
{

struct mod_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "mod";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "448.nT6K8C1CDTaC.XLj2PBHKaa.MCchBJohC8gLiFblYMY420LfDteVC.vxR556OBZsLEvJ.zB.s..rcL9ctzRflXddREzeINADZ1KWhp4CiUglNmEgckb4S6pIjHMZ1.zc3aIAJ3b1yMpkG47zvEZLCd6xJPAKbzLiMZBEg82SLjm3figRxXczb0wH+pbjXjdBTMthiEkPFrHzLSubQhv1hEJGUb6EYP3mgjoauI+QlqUijmdqHRsy4Ozuu.4.oieK.PGjerWAzn5SU6w9FUztHSfvYUrV7SygC77j+TMVEPOvn75mBBPahLbTGvEnwnpHRgAf.AgML.i..gYPyNfj6fcbPGNZrN44jdskVZLgsFRdt0QWHa+A4FQ.EMiZY31GNiyzN+U5MgKnuyKNBLn50UjtA.yPFlA35vAwqxR+g0rb.DKoMQppXDdmVC3Z41LNVf.BahA1UR3NrG4ghMgWwvK9e9JK8n4Yy3lZA01LxPNgnCD.NxuHJ.ZVxzLCVrFVvPKbOvpXgI.3hyt.YrgayWHdGxZpwMpewxjfZw2H7YKSrnZcT4n7EfgWOg1AhafI.zjbQShKqLVa1cNfpDvuJ.";
	}
};
}

