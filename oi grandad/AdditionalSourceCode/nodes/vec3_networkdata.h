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
		return "475.nT6K8C1WCznC.XNkEYB.spd.64fkKBIx4Oh2TVtA.uZeAHNI9uz+Gi7++umQKasEOg5cJjC.7.vN.Tmwa8ks.NN6Fq1X+qLt..N1u9JNG67ZGNt9SMqCACa4r9YY1P+JMOkd.CI8I5FNVgFX33K1Wy0qD71JFtmIRhlL8L8DY2d5mfCVcd2dKzoVhxHnQKOEqCnWT.eQ9TKQLQwThNBqsv4XhU32kqoEyrAANS5X8.InhoUF+Z8fFzOZvv4bb6KaHb6.RQjB20IEFr90wDswJrqFtNlM9Pjtc8TXFZhdiFg3J8Z8SXy7Z8LAr100bG5H7CVclc+GiUCA9jnhlnnfdvGT+fY3Mh4uaGP8ffQSQRROommmHGI8.NViewhgSfvGUD7EQgZbwLyLSMXVXAHHG.E.fBg2AHR.Y.cDHwvFoYtz0+Oqa.oFBI19QUOMVNTAhj+FtYifnEAS0981VTzdXLZTbcB1c3LdlwlX4ZLOFsh7P+U2eh+U0oNIlmjRzmR5l.VSlZHqMBFAVG1OOhBl3XgBhKb8cxKH5bsVKzPrIAh21SJjScE26nlAE8ycZH47NLG5OPatbYzYjKwNt15GHDKKjiOL+0i8XPChnfLm8pLi6.ZWGpxSm.EF0.";
	}
};
}

