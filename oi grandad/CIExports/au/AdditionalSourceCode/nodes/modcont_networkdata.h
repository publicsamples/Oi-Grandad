namespace project
{

struct modcont_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "modcont";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "426.nT6K8CV0HTPC.XLT4XBDKqJ.OEHqEJZ4F5IKIiPXDpA75OB.0IKyP...bW2eaAibVam9ArB.v.fK.H431aMPu17EYirmvWCP54rFhpORZSnO1acRdxmwFl0WVAzyfCG8VjslIC4CbOJMWks.mEmAFDzTmjmxWDMsljGvAVZv3SRYQPw6bT9xCxk1G8YbW2CylEtFLJvBfdNC2axDxwX2Xy1TxXZYDG8WTUVKvntnr1AzKyzbciSPTk31LSK2DjtXNJOXGBNK5HhMIX3ojWsORWVXJTgUsf5hxZRZRwipeiXjk81DeSLAw6w231CH8+SVjNTTfFTXzLvLK.DAT..jB.fpja.g+kqqIuykfTMJs6LlIOSoAJDRyBTdlRCTHjlEfB8FHmQlgBGkSNxz6w6KETd7ow.MGJBRvH6UVsMV1Gzdpi.F.FrlNJjdT9vTtDVigLtPRPuE3HYPf4r45AyBvzAq4yHEmOSUNTh9HB.XliOWPaqDtZPCzyBFEbvAFPFw7gvvFUxP1HvThGDvAYRKPXiuc.pgQADRv1xUrdDfSkpraFpJ1Cxa.+6.";
	}
};
}

