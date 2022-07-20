namespace project
{

struct send_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "send";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "356.nT6K8CFqATsB.X5z9PBHIia.uZTdlVbNPGgVdIUNxa6Z0BngBcBqA.fSH.eigH+zoTvL.TC.y.fCE5ZLTPQG55I7o3AVEyrkrI9SpNACq5sOxtJChAwXDqBemL5SzFzk7gUklbVMS7WX5QxEVfUaSTND9Ol9kXq.7cy9Y0dHFZuBxi.zdEevo.MC0+pPIZwkyBGfJ81GwYUFaX0lKkc0l7npJUEFvOqd4M3ztpL5VrX4XS+pjNocUsmszk+pz7OT0sd8DFQzmtlN1RT+Uoon75J+KLaM+zBAoIEWMDkAwXF5f7r5tM+rbhMtYzq9nDmUYDwVvnQTinC3DqFs92+.5BzMs9HSfzT.k.BTBMkdF.6frHAp.1Ly1vCXiJx1yvnhlq5oYcDbHYvK7LGS1NoM9yAv51ANygfUF3Cz.KChK2ptvP3mkfyWXKXUI.N9LDfXJccCViKCcSjw0mN0Y.nwtcNL7lA";
	}
};
}

