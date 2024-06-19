namespace project
{

struct gtt_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "gtt";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "399.nT6K8CFPBzBC.Xv0KcBzRaE.npIjWCEb1P+2dhbNYgNgncBzFwkWgjaxCgewCBTQAwIWIePO.PD.+..6NN.1is0BA4ADeJgbtZ0dJg2I8hQfcNWnkGU58BhI.16HUCicWy0brD1mTos1Y76kClYuZB.XuSkJ51ZB2MgbwkpJr.iFXDwEJr3BKP3EXwNF6M9b4RLvQXeTGmSDgca6QhgJigdfw9gWX0n1CnOzHZc8U5E5IzDV4fO31NR0.PPywJvtntylIJ7+jJuRK0hKv0jXt4XNB6Bv9s091efUn0+TCuIGkDSvHXlNjGXFSYl2ATTKFJyjlycxTNoykLv+s8LzsqhvtBZCOfGWoc1ULA+u264vjjEJJTRUZuJT3D5OjalRXUB1.myBKYhE3my0UZwRndTNPwhyREp2zy0Pk.BHPQDIEmc..qo7CfJw7KLJXBGm4vHChDuslooA4YFTtFbbs71LRCjAtdvHElGee47z3RKfS.xdzsLR1A8d1ygKQwCbxyk.X2tMeKKfIraLfglA";
	}
};
}

