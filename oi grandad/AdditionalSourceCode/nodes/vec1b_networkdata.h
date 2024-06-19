namespace project
{

struct vec1b_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "vec1b";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "425.nT6K8C1oBzOC.XkEHYB.uhS.OTbOmlEY2DkZF8OGlFITvPQwcfjTSn.ppJvUUe+2BwX5GvC.8.fO.neaNzWwXXONcZ3Q3SC0ijiv2L1TsBzqY9tzQ1Sp2CNzyUsEU+9rOargXRdhmwQwVzBP+DJMzWgruXxVBzZ54rq2DO1vIEGisCMHcT3TxbZ4EG5ifhjTXBRBjTChdYVe0N7XEgyrV1P37UlGEEWuL8kUi..zeLtpsznaAmamjbq6fLfX3vSLqKgl.ObnOrroZCLgx2GGFuJee1HrB.5gPxSdyS9t7H7Y0dnuhxjsjOIdWYUck+oIK9erIiwQzf7uOKT6gUDpY18FLsAbajIIISSQqai100D32Mea5YFCSn7oMxIIQJRjMBDDjziBMCzeAWAlGLCHPQ.vgt5.PVF.eclmFKwEKOeCHvKnDZP.LR2HYGR9XiFFzHkQFnwmOfGfIrCBBUDR+lYCQBGGfFCbAFMIA94gGlKy6XVivQkGCJF5KUbAB4BnW.60oASDCHVCH7UBe62l7EKYiamOrtZYm8LGRXc02J3PmILxrNx5kG.";
	}
};
}

