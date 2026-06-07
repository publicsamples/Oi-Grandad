namespace project
{

struct aaa_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "aaa";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "489.nT6K8ClnCzuC.XC1OcBzRid.nIPOIu6FvnCy1B4vmabI.43lb4F6e4GNyfbRUtkYKVrZ4cZP.XD.EA.7sVWajEFzSp9ynemzWufiAccrQU584YDvwOjtw4XoHMDGOoQa8wfm5WbRAoMRRwBQkxJr6d2N9Rh.b7FUZn6uIXAlKJpHSmKtfYhJr.yitAG7gv2SFFQObJiYnQ3VE1u9knWpkQu.fS59dMnUs1AdhMVoxN0ejK05H8588Z1lA1Bf6y7MbjvMh0JzCPI4gFxUt4e9Klh0.rms5iykDScKEo61wDb+Lu5XLO8PKP8+7YyhMdwr0jpJqFhHWyuIcLlQMLGdHoLlw50l8Q.yrkxhhzj6asUjLU0PfTMYr44uZCjLR5yJcAcD4n8WNTV24F8hUkjJHlPQIhIJTH71HcSe.yv4KsH83sSfs+jdiYOGPu.Pf.f..vwXcfVZ5HTB5hGZ2rPutwId8YaPguC.J.ixdXRWGwskMctFYf9AzxMfDT4EAbc5gUeGcGdfp..gsSXE1FlA.E.C1Q8tE8..1af.bfLAW1rjqEd.LdkSZYOwJWNiuuYw..TNPttxkYSQ4w6Xd3ubLMTIBP3B.TCbx.Z2EHuefnOT08lrfEqE+rE2REJAdCtw55.DY.vdfBY.";
	}
};
}

