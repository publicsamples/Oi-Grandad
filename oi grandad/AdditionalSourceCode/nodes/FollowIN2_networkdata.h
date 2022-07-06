namespace project
{

struct FollowIN2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "FollowIN2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "341.nT6K8ClTAzkB.X3z8PBHIiS.Gzh8QQd7A1RsCA.IH1s6cCof+qrpDDfMmsMS7sjQ5GfL.HC.x.P0SjgtcB6pl.5qLWHYwdVsNZzyVMkpG5A5ApYPOrcxHG4QTSX52qczNnWZpfdKwFyjo1OJs.zaMUwPX2P0e4joDWDfsatOLq9QyCGObKKe0.nQ+krUSUPOTqQuEKk6UFiCcak.SN+W9DDzbzmgsfSpdYjmLAiQ19tjNIU+24JkgeWW5F+L1aizLD4IeYiKjyOIaUBuURvbuzSrCjlRjYebnGnVC5d3nW0ns4nMDYraF4qNBofdHEJhLXQzhnBZHzGw5W23gBzMw5Xa.ovGf.iPBEg7APPHfpXXlI2P.1vEYSFFsn4B4atXqCqAUtLGkVHp9eZEV+cfibHXjA9fFX0f35V0UCgGrDru.6ZdDWbG3FPz4mYJBCzrdhAoZF.";
	}
};
}

