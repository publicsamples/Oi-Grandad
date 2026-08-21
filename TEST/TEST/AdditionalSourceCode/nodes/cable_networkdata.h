namespace project
{

struct cable_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "cable";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "322.nT6K8C1wDTbB.HgysHBLsw8ZaKSKhFffRhjHbYEkqcuEzPWrP+6cXfJ14FUoJ+IYKUahXYdtcrTADDTzAq0yiCAoyDbibesFKZ9c74oLchUM.aGVAzrqbriHqeOmwxLQawuo7eRQSDbbVrXEE8nXYz7qbmynIxqEq7eM3AG+vcQ1A1kL1bTvEMSnh1QvR4ZAPSHMDxTSRHkvZ99033yYaAZJIxSSdOx3EVzrg3RplMqm2fe6Ha2ClsAnoBLnnIDuKQrkBTCnwTlUxrzTVoZC.J.Fqt4.vr4WEU9vu.dcOTC.afLbhO5hihSxL0rSWgRiLk0zYf.JzwCwP1iVGOZCBHYXcSEhRjKFg+OXNN.0LEllxFaptQsjZEElg1j2C3bbNr.MbvC31+gbRoHCYTrj9MJV9IZ08tERvgzgApN3hBdpA.";
	}
};
}

