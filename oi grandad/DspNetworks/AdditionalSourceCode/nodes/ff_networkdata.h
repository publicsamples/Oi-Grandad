namespace project
{

struct ff_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "ff";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "111.nT6K8Chd0L..RbzEZ.XpMvXJhkFdaSKa2wzSmg.YzJyganssaoe.+m2ryD3hH+myklLtiLG2WIynhkAuwPE0YyFC6lpLBtqzHxxpsBKbbOWZ5tiNnCxD3dSY7lGdRhAvcBFLtiX0EclBA..SQQHJ";
	}
};
}

