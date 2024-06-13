namespace project
{

struct send_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "send";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "334.nT6K8CFRAThB.XvD7PBHKaS.OfD6qir2EPSJhjf.xfUiKw5YFcj7AAfr4jwbFuzzoePL..C.v.fauH8DYnamvVZMf9KyURUrmRaBM54VGQ0ydXOrEB8v1Ii7j2frbAfdnnC5YH1ML4HAukR+rrDPeKRhgv9gp+xIaItJ.a2beTsFRyCGC3Lr7Ti9K4VG4fd1pQeikxcpxwgAPQN+WdEErbzmgavHUuLxUpP4nZeSRGjp+6bgxvuIL8iel5sSVHh7jwrwUx4GkUZgyESOoP.JRQlExYOr0B5f3nW0c4nqDUraF4oNJ4fdFKXFvnwhFKNXkPejpe8iGKP2jpiKB9AHvHjPQHe.DDBnJFlYxMDfMbQ1jgQKZtnml6H3vZPfKyQoEhp+mVg0eG3HGBFYfOnAVMHttUc0P3AKA6KvtlGwE2AtADX9Q6DiAZtcNLplA.";
	}
};
}

