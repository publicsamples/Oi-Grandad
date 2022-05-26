namespace project
{

struct f1_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "f1";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "472.nT6K8ClRCTmC.X0kKYB7vha.cbOMAKKFgeV70kQS+2FQd54QFwiodaxYH53hCZi4k0SJE3C..APP.vF.4YUU9X0H9YUKWJ6qrIzMpfhNz0S3WwHr5Fy1RV7mUMEOq5VeE6pPQb.qBemL5XnMLLjUmndrpl3yY5UDLupE0zyD6K5Gl0WQU9wpN1qwXV4P3SgKHacyne8QKOqNIRjGbHhISjjvErZD6eOEnLP2D6i7Bp+znqx30Z7uLgAC1DY86R5l5YO0weWadJPxJ2lFlYwLDcN+68Xxvu9myAz4DZ+DShEZCSvDkNQ05zUTF5p.YUNfnO8McrsnVVc.p9ZXF2Eozq9nE9.W19ysfGPkX.TMU8bJwDk1jHo0fvAolzDHhzhHww0bQaOzZQQHooPGtKW97RTTiE.fmVCcbKHUAABP..N0Ycfc7.fZG6CjGvisOnCmWOWCPbSnrBBwVaQyii.a.XLvUvXbfBKywh91FeGYoS.QoCn3oelY4pPyg1m8AsbPh8H9.vb.Zfnn2dzwNstqAFXPB7AGFHtLuiUQan.1vUtEAVLxPTsBbsj6PyCtsPnDYysM7uKSbWrty1cQN13H4SBVsKaOdf3gqxNHVxnIbXKfE2tNvCA3eB";
	}
};
}

