namespace project
{

struct mod_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "mod";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "451.nT6K8C1QDzbC.XNj2PBDKia.8BKyzjsgLxS3WSfvHzdhWdMZ3CNVC..fv4FN.Pj+PJyJ.zB.s.fCreM9e9zRflWdVxEz+IVgDZ1LOhpoSicglOuEgMkj4T6pITDBMc.5X9NRPdgm2d1YwboFmFxfiavcVVAJfQilYDglOQX+MECYIX7KSxFailrNF4pqG4ko6pulT9XvlPyLM6EEgckJVOtXWUrAwOCkocUTNjLaKGSYWjLUEKZpeOGh9sk.I.OI3bP9wl83pM.0wwtWtp16rjVFJRzvXriygC7Lk+VNfhddnMop+IH7rJxvR4EpQYZLJs.T.ABBJF.PB.hBclc.BjPEHFAzXJhpHDEWETVwFo0.sfAVdXI9AJFnJRKbHcOo+iI2Fx7VY9BUAgfni2hHH7EgeRx3b3L9jNaMLoeFTzt9rJd0Oj0yCv4gndS6l7V5XJPWPdbGY.M8ELt6scqEgWnOa1ic9sTAmd3oqlBDvETd9QMlU0Vu6KzMYJb3ajahjGGYfJNTFvdOTqC56ZxHuao8FBMxLybI9YYgCbR8SwDDag8BMDYvlpA5vB9E4KPHULLn2KrHWLItkjgn4ckWk97qB.";
	}
};
}

