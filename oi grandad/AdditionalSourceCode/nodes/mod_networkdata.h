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
		return "385.nT6K8Cl.Cz6B.XJD1PBLohS.qZZsKJhkGwHFwJbEBeVdXctgyfaXVJHLri9EBAVT5GfJ.vB.q.vicrM5ZIUf7JD2HWdcTZMfIOuZHY9FFph7tlAe7ju5IUy+.cH+BulgHCI0BRhct9QF4Ju8.WyhaqZ0QLM76Hz1D5VEEfAVvj+vC4YnL4WLDtTWbbEjZ5XQZ96PfhHuEd4fx7vGSgRkiKaiBxd139XgaTS8ietpsSTEONxS6ai7cJP1LoKNbsZn5uznXwVUjtHwuSbm5XUCDLq01z5W.+AxoAlDJNJo.GMgkM5ZFDDnQVyXD.T.AD.vBxAT.XLkUF.HbvKDBGTsqPqSWQbCfZCfOyAC5tcLhPvu4ni+Gvb8bIfe4JGDFsLPVbbWBCUiiVMgxLiWQyK9e5BK4nYxXlrouyvMPFDnBHwqgN3LkgkxxT9v.ktjytHQd0na.Lt4cIikr6.9c96US.0BtsK6b3CDJ9VFoLZqmbN3nZa.3RlgsXTazNNfJA3UC.";
	}
};
}

