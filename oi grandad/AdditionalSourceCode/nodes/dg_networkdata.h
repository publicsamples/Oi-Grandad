namespace project
{

struct dg_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "dg";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "417.nT6K8CVoBzKC.X6EMYB.wha.3bpb8uiiPxPlcT8.GPkN9enKCjIpMknj9ujd3i1e1BHLkBD.CAPP.zI5SM5CV.9fYsAK8eRK.vaqCf22SoNmOQrQnmACZ9QnWiRrFAdyT8KelxJlSQ.79OoElWMd8CdmPg4UyT5o9VBMRwkxxH5i+hxrFpdhvfzNUhzfAmQz4SsHpcfe+68XjMwJ8P+fWN9WjxCdo+FHER3qCDLuqW8Ib7a3jIk.5m6TV8MAVWSWsHUPsVAd87ZvL45cctHTPsFxFkvJjJuzEzfj5Fp08CdEf2kN+5m4S+xtQbVNpd.N7JemM9EQXkcC2CjTC0vR+Xm5O44+jClFx9oBoweRSvtWUsJWk0zUipBJhDkTmv2ADSD5yJZCZMmUCYRhaRBUkk0UigcyfUgW5ArtrnbRZRpBm.Bb.HXPYO.TGVvhUPheonfC4PSjhrPR7JIW1YlCdvFvrQEQBNN3eaMoABfyCFRwiFQubdEWPCDNw6dzUZedXCbfy8UqviYhoUP3gWM+r3EFTfLtsOA9SwN.rvtszBLT";
	}
};
}

