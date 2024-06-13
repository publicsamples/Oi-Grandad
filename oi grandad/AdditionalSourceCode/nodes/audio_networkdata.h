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
		return "336.nT6K8C1oATiB.XkT7TB.saa.8EiLAsnwIEjqmAD5u4TL+3.A9g1x3+++ZZXKXCvBsamBw.PL..C.szk7mScEHl5t+Biobiab7eURWixXgX5zK9antfujmGBmn+yY0a.LkhCPLki78L8KAn8ro7wgTcdFZtLAU5WMj5AG9hXKPqb2eA.lxKDScdUUScsfFe8lolziudF+oEAltY1TCwUCkVC3FiIdYn7YFkaQ613cWlpfoZkzmdmV1R5m1sfsl3yxG2Eqb3qx+bVSXLs9uYiYGHJhinHMd.AhDVAGPh7fkzZvNVBtlhtkDtrx7eL6ALyQq.Q6BE7raXWvPU28V3jHf.G.BFjGCnWQWmgy0hCdvgDvcHjkqLoxWkgKLKoivx9EKCkZVvKEl6UYHO2o1OWNQ+d3kJvz9bLaRWNHT7XpXZGGO.bA9ouA.m1ZtatHIKyd";
	}
};
}

