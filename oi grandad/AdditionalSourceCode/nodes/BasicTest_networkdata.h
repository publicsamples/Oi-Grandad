namespace project
{

struct BasicTest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "BasicTest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "172.nT6K8Ch7cT..RrvHe.VhRC.JSZsIQMX6bSaJBUZwMLLfZ.tKPPW3BpaQ1+usULUa5PLE3WwBlCiTPmy8EAACBpbXCvHM6IwMiFHt+ss0iIWLbqPW2dIXK6gjrg.iNGtYNUMElrvnxZRJqCU1hY5DvcyZOlrxMYCf39XxkeiTPJnShaLU55f3UuBRJ0Vb.3lQCC2GrRI6sDvA..yC..tZlkWLKidZItIvmXPvlA";
	}
};
}

