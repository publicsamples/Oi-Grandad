namespace project
{

struct recorder_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "recorder";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "340.nT6K8CV1ATkB.Xaj5TBDMaa.8EM075PSsxPrQIHU0.xHsLCJLZr5TH...Q44HdXP9zjLs.vK..C.bD5R6AZxIxWtdOJwSXnYO4VTMarFqsNzD5tpu0jeO8tT+q.ZJgxBM67NEw1RVMnZlbjk7oeTd7GVnPr9QH+9heTQzO2lkfrZg1dXKYaAPyotphotbHgNliD6anaO4U5HwRbwuKaAMFTEtLTcLS1XQ6xZ61PSFeGaO7yWxOba8XMPWkO8DjRU+bSb2TPlYk6hLlcfnHJDE4wBPfvPKgnGOVGWRv1Zh9mDcGyZPq0h1.h1FLfhLDaCnMiOKdSKIiBHvYffwbivfF9BSqEG9fiCX2gPVLDU+pLbgYIc.KX6WVXnTyvD5LtWbXL6WkF+bGz94iSzxdD0cAjaviLGVC5ADN3XJ.sWr451wEy.WzOcP.H5hy1BSvQPZoaDE.";
	}
};
}

