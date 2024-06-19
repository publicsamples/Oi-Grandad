namespace project
{

struct pmod_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "pmod";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "651.nT6K8CFjRz.E.XYVRYB.upa.mPwJOe8No51Wl9NzjnZfxItMYZV9.BK8ewI529smD2GYJXD.GAvQ.7XnM67NwbqOAyegB2nadrbts4ZcPvWtdryLpey9qdgGe45S5r+8xiv4wS4K483mFc.ON6oa1IEr7wzZFOFRD.d7E1GycJYUidqbVMArjKirk8z60LK6e7dL6bmVr9DWttTLTXlhkDcOkuUyfYolq5TfwIoSnidsSs2No4o9VEfrSoWISOPCCaAZdLuAPvLz0w9K2CMRoe.jW4juEyPxGqY7hMbHEohnhjZCdrk6q+iGKYzK2a6FlUK7qJptEe0RifSzI5RqZabG.TF2JiZ473oHj4t.LbhBZBJN0vALBqnpXvg14wYlxrHa1YkJbPz4UsMJD+5PxLqZX+it4YZK3BeNMMMI4nJFiQGQTPHDFQAqhpfRXheOXMAR4CcG.dHngk0TiHH..DD.J.G.fZroH..6AEI.AAOCo.e5d8YtZ1kinPjpfIKH28zDfrpoZnxxWUVoPBsqgCWPAlQFKP4PxfPpIL0QlfMEWz.PwK5MihDPMplvQz5r7IZnT4DA9XR4CkMRMgqBxTro3hVNNQhbn2gAPA43jIKsH.E8q7zJBrAnWAxlk.QfY8SroNoDfxg9RZjBA18mN3QamYDhYeC.JvhswR+6tk4VWDOVMUMY97fE8soSyTsMeGbN9PQveRvZfLvgG8UKIadRBO73aiuLFaIEcfsiy73sDXfXds1Tf3wTLd0PW3JnMvl.LQ5qde+BULsDMbH8xfkHKE2crr3EhP4XmnOa5yY3DjGVdEzXPOJK3jKZnJknOM13xa2HfNP.gSPxlPLXSb25gv3oqCTq.70A";
	}
};
}

