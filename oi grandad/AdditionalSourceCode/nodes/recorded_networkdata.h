namespace project
{

struct recorded_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "recorded";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "238.nT6K8C1d.TxA.HcSrLBHMZa.GnIIlPJKJNYFIvnPubUwYHGBaWV0BH.CIFaZJH1R+7jgJUvDpjqRpLaLIKv26asns5726yoVR.vuQP5j2X16YaMNR13B60aDb6vfOAHNNvwCHOL.grA9Nhg3HIJM1Kh6jfuZqyAH8AFhRJvh61E2vfWkJvuVmSi3hBuwzJOodaL803mb.7UdpykleOJCJvuKtAwqRpjJYfuwLWuS9ZWM+rcF.9EZfAODMKwaaJA.WAYfmbfMCt.5cLyxIpxkaAtWuebS9hIG1FGuAC.LLBXzMjwvoRMbEEEszRWvL.";
	}
};
}

