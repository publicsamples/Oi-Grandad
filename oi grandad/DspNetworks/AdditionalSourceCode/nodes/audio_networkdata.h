namespace project
{

struct audio_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "audio";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "530.nT6K8C1BDTDD.X3EMYB7xha.XdE2JEoALxQvNe.ibvEvl8gvmtxunEfEYSDlRck5Pg3rSAD.BAPP.3YYM1VD6FqGpOicc9VrBtcSsq1ne0ps.ws90WgysOu4GynNFKjshyeC1l7q73kRJ6GuzZV.2V4BD2xA88n5UDfFsHxhU5ZWoiKw37RrqEc3TKWWnd06pk5asDKCWF0vGbwxmyWhpuAsuX9wZK0tdLPdbZAXbZJGfqgqmCSvlAfaeWw6Ax7iir6zjHHjRBRxyTzDyv5bhWb8QpWwF7QLClWyruGdfNMlENABeTRfO3yy0jMFyHF1sPV3CbD21wulWxntlr0lyW0n.MEAMIYhjD0ygcijll7ndj7hXC1rltV8eK3DduAffKFNrZM1ZYEi.Tj2aBBJoLKTVXWu1SvArUZWyf8OEbAAZAZbAKhPEALMQX2..If.HmUdbMc.bZvE2MjKBNMXv.j4.mdk7eFaALxUZfxVxQVzBldifHWAu77cq5S.R.NDiAAVlgar1cmHXA2lwrxY2VStyhfbOM.kkf7k5PklMvH.1DDYPkjIf.WEJy6bbyQWH7vcK9JFC9tWMhItA9gljAKXEvAbcETWJgNfrVBqcDLab6v.uxIxBO9vRJ2jr0cR.3LvoPZnFzIsdjHAqfGHflTGi5EEjDic8v9vnDwrwSwBLGqVuyygz8ApBDIFb1.PnJ.";
	}
};
}

