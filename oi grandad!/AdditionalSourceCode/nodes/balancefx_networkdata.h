namespace project
{

struct balancefx_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "balancefx";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "532.nT6K8ClFFTED.X5kMcB3RpC..8PNWqX3hHbWnApVxX3bCuEAPBeLHocLLCy+YhYID82izGfP.DD.CAP20I45Hw4Pw1TpDCSvythrMcJuz5Eqv6YWIlN158RRIf2ar5k26QPVf2o0Yms43b7nunRMYGbAuSQE.d+CacysuDPFqbirq6bi0OmTy1fjAOPiUsvP+RrFMIGaZtvHzYdsMW0h44EoUsIbaiI8fCG4482Av6wNae6MoUhYSMy5P94crzWKXzANBzyKSTaKXd0zr86TiyRqoxrI3CNVeka0qlHnnRjizxY5zR.uegEUzfE3mNkV7MnTAFXU5n048poz5Du2+syeXR0D0jnTTRCPmucWqAavkXnmgNyt05l0iPppoIUURfQnDNRETRbZxDEEjRRRZJ5Adg22zeX8HDwHrZJBiLDxzh6UfFWrxnTzfYI.JnFP.ATlr5l7jEvo7.YlEvaJ8Vn4iNHDY6jjfCnVspG0JArJIBiQOCZGuo3WqSPNFvN.sL3SCSZHq6H4REewP.h7Bts7tqbyKvnGMIHaKE.OIfcF0gSGrA5GLK3QWnhc1Pk4niQhmCj.2LIQp6+WEf1V9QDbUWgwiaGMm26AwfbTE5MLIyrvxgeiUnTVaxjNtfcGWUnBMdYBRjghudJMc4eA2sOOaKflGy7gYyzCDMIDtCK3k4lFzfPyfq13GlX5VpNOP8ATpB";
	}
};
}

