namespace project
{

struct vrtb_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "vrtb";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "206.nT6K8CVt.ThA.H4hkDBPKzI.+qW2CfSd7Q8BQMFBFOlvvSaLh8kdmpphsAHTxGv+gbDsDzjonTSAU4ufyfqUQsKZ.rEAJVlyVLUyyO3v93ZLH4OxeXyQlZ60IykhETANTyI3VA3Pijo1lyzi7RLDtUKL3t1NEsZ101n6EoCjeJtNK5WLZO.IOK8Zx7rEawTk7tWC17yghcBMI+BBF4anePD4l.AHPXRm9f.rvjRlVNNbugz0cXpzDU17BvBEvtzm3ts.P6hi1h4KAmCCQT.";
	}
};
}

