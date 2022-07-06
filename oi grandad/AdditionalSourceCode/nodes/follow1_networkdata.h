namespace project
{

struct follow1_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "follow1";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "279.nT6K8CFCDzFB.HLCoHBLIha.l0IBcn0wAvSTP4XEcg6iNcAEsYgQDQUTvx3D5P9CuoggYY4NK9qwrdssFa.hOMyQOZXV9UsFw8DAW0SRMVBfZAkwS76DjBowXf.ehGQkdsJvNoTfGYotNSb3OC3UO21aj5TGR3mGWQd.uy9dpzjB9yRwsMl1MdkCf+oUGSbbuTDPfec3FHdEEYB7Ml8bKjqjvPPbBY.3OXgA7QbrjdaDp.Bj..LP2FfKfBlBlwCP4qYJqEoU5wBqAohipGMz.Ygas.Zgrwbnr.wCE3.NAbvq8.7aavyEL5UhxJQEj4yvVbs0BN3NVQHsAUnL7z.Aix..LDbGWPfQR01Pj4D3JZ4aWG30.7OA";
	}
};
}

