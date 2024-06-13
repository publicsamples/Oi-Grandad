namespace project
{

struct vec3_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "vec3";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "443.nT6K8CltBzXC.XDVMYB7PaS.6mJ2LZYtI5bpKQmn.i+6fpUKCuahDvhrIhygvVvPN4j9A.D.CAfP.3Zbphf7y0hutRMHOmXCyGXGqZO.km0zWx7azFsZ.4es6BxSblBkux8ZNc9X0XxnsrX3SULF5i7Tp.k2BXmQjuTE+dsCTp.P9OoKB4NMDCTdIHKPAQhjDIJkf7POsU6PzlmK5ogZBmwVUzpnvpUQasQKvQ9ewZ5K.jeUn7Z3qqVmOM7WHrgKSGNlYYJnB7.JiXXWoCPox0.1HlFMKeiVUeNKNxCAji7EMXCyet1F8QdMUh7FXShlkGMsk+ILTG4YOVsI9qcw++JxWbDJA+azJoO17bbhceQFc.1FYBkjISlV1NsKSE3mEaWzQOLPoxmrSLJITQhrQjjjnhVPOHeFrEYNCBisSnXKKHCHPQ.vgt5.PVF.eclmFKwEKOeCHvKnDZP.LR2HYGR9XiFFzHkQFnwmOfGfIrCBBUDR+lYCQBGGfFCbA1LIA94gFlKy6XsFrQcGCJm4yUbAB4BnW.60oASDC.VCD7Ubu4d0Vg48bzNjqvF6.nxgD9a4ngA5bOxYbLC";
	}
};
}

