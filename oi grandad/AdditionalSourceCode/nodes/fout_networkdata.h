namespace project
{

struct fout_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "fout";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "148.nT6K8CB0cQ..BhLGe.Ug3F.hXQRTRVijsKSmJ61hVJQVvpvLC15HLDaT5Gv+er1p.ImJnpaJ.K+jL7CrDn0wYQRD9SWVlA9U5.+h9d4SDh6ZRllhUWS1tskJfmoSkHd6VhbfWWVFheoVpUZ.d217XUw6A1EIA3SjXfO.dgZkEb..vbnTXDfnEntvkNM.zD614vHXF.";
	}
};
}

