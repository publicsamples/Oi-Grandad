namespace project
{

struct fff_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "fff";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "410.nT6K8CVkBTHC.XhEJcB3xhd.Hsmlf8nbcCXyergw6JeYPpzNv2.u0nszCCMCqebYlU0KQJEO.HD.9..CxnTie.a+HEC.M67.ZN9VKbymH3oDlICp9SI7NoYtBMm4Bu9To2L3k.Z9iTLcyZZZt2rEEcyeToctOlfcy+cvFICKVVfwENzPBKUfQFWh3MzwOF+NzXgibvkzrmONoPRy1eSdgJibfnalgWnkmeaiFpDPekqzKbiyDV8vQHfzj2bEkWknG06QA47E3IUdkV5kafCJxcHm6RZVflYa8uuFXEdwrD0iRZRjWfG3EOmM3FS4ELHvNPZYyO1GBv+jy8shvutAyI3yUZmukW.ySuITnjfbQNIOgODI1TBqS3G3bSOm.IW.lyjckW9.upGkoJtJTuJoJ2jN+GXAn.BP.HXbX1AzNfec.Z4LVAI9kiBghiivXrFIxzXyfCQ1IzJhJNNduUzxqn1gD.LODajSJMBfiUOm9A2pEjS.1dzsLd1wbF8LdIJ3.mXtD.1EVyOKegQEXii6Sn+TMB.LuabcaBE";
	}
};
}

