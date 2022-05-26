namespace project
{

struct loopar2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "loopar2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "237.nT6K8CV+.zwA.HdCsLBLohZ.ngj8YZXAgGg0iPpfA.8v.MBx1160CFnvcJqvZwP9C7emFGFGrFMDvzfASyBGC31WlMMmFmVqwXwRETfzt0D.o1YoxOSUY6LAasXA8wYKVl3WKNMxjzCD3Qf+Uus2J5SgfrD2pg1D3GUp3rDWluZi3GC3Y4A7QaUkRcofOIoSfVucRR6IFJE.+jVgb4wMjdvA7aD+f3YK1hkIvOwRUuMxaOkhYWF.dCPv.dJOVgdeB.A.9YwE.f3IHzVJhek.AmfjdRHhwyEA8tNyrHFSQMBh70vWE0..Tr0QJxAy";
	}
};
}

