namespace project
{

struct granulargate_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "granulargate";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "491.nT6K8CVfCzvC.XokKgB7xha.HUhixcnU3HDNQ1VtAkVCVA7Ar3FgDR9kVzXjMNJqNSAYAZmB9.PO.TD.GDEQgG9YbA6Vj2NwRdKz21ZsNIVOXRTW9cUNwXDdqmZa0QmUrVij25voEds6f1QNYS6fO3sUadu8CcBp5VTSaqNc3jnqiZaeE0qul4C4h3CVaQc3Gu1HGcF7a2t1Ug7nV1DyNgCmb3ncYmK1ZrvMQL7.cek5ZSpkj3jFLANHMwbzChITnnnXAB0bjOm0iFjTM9cxnMro4NnqPvHSUEWnYiLvjghKvvBDdgGzgPmirLqCLvgbnbC.u8I4zkNqF3YAtjq5Uv1oZWr.c0eS5U7.V93ujeSmXhphzzDNZWOX02hCnxkJPPYYxBkJWlbY5AJRSbBuEj+4ZBEuqb90eaZEKAZP4FFBHvl.gHBP..EQvnXIM.sm.q.VIorTnP.R4BHvxgLZGeC86iYX.ibH+YlRLvgpkWsPYvBHNFRXNte4zfE3glCX.17eSMC3vE.XHkPG5GAfGztysPuAX7iNrMJAYCETKjQmJmmGeLuwLHWgBjpZwD.vMiOAkRGafECDdDN7y5rT.SLvIO.Of3kgXHEQ6wG2ZTkXAYr0.LE9wJ6.M5r8.nhcACrneSRzD.NHfIO";
	}
};
}

