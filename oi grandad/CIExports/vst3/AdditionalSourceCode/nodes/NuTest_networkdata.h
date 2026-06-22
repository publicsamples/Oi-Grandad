namespace project
{

struct NuTest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "NuTest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "137.nT6K8ChoEP..hhHGd.VPaCP6eRVcRse7FYRffU6ggdpNbQTuqN.YBjN4C7+l0mxjbh7+N.pL45pDBeh1c17f3tVpvNX00xmaYoB3UdIxCuOVpP.dMYWHd0g5PkFf2ssl0F2PBgm0bqRyyxh3rKKG9qUFArRDvmXABO.757zUC.PUHfATiPo2QHJ";
	}
};
}

