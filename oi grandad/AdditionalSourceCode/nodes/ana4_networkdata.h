namespace project
{

struct ana4_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "ana4";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "425.nT6K8C17BzOC.XTUCUB.saa.ellXHJjAsfSpWqah44Ak+AuYG5fD9+24FQzcLXCoikjA3.PN.bC.skE24SCIzwbnjhMzwOzo1BzjyyV9D8mhkrPyt4UTMYRLI1FoIzcVwFSp.C4kglQl.oIDQWhuqDvqSkCISN+FX6vBfl80iwjcyo7w8wtiGsrPkddDgXa84wPNS+bZVBf1nM5.WyUsCjVPZWwUR1pPyVPuFnYah6dpFBcHeuIxO.c2yuqlSIyzJ1eWwQ1RlLFyQCGSa.dXnihmtAmnPSq94j3t10C94Hd5SOW4+0CFiwPioUfE4+tXMcDGu+tLMg6Rm9ujLoElVFRrcYnIjppzFn6u73lPtQw9cQIxvO2x7vNh7.BTDQCCiF.HF.Tdtnyvf4BLUKukIOVTkCavEbIj0dPJ6CvgKhWpJFmLQuGgJvVkCoVI7Ze.16Ps3.vUAVU495fDBgNa2ZAcvWuEWtQZWXaPvhwyCk7CesT4BkCPc.Yh.p4Cf9QutHqrZrfCBBR1wRr.gCHJ0vXLLxOXbAXbpbBKO0l.P6hibKleI3bXLhB";
	}
};
}

