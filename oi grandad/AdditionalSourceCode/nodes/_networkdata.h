namespace project
{

struct _networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "17.nT6K8CBBAA..k0FbzkG....";
	}
};
}

