namespace project
{

struct send3_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "send3";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "338.nT6K8ClRATjB.Xvz7PBHKaS.OfD6qib6CwIEQRP.YvpwkXcybW50A..aAIi4LdooS+PL.DC.w.fiCc6kInHCc6D1SqAzeYtR1D64zpfidt0QT8LHFDC1NYjmbFMHKWHzGIcPOlX2vjiDL7VJ8yxR.8MoIFB6Gp9Kmrk3t.rcy8U0ZHNPbLfiYYpE.N5ujacjC5YKG8MVJWpMAPPjzy+kWQAqG8Z3FTR0KibkJUN1rOJoKR0+ctQZ3GUl9wOW81IKDQdxY13J47ixNEvbyzypDhjTnYgbFDasfNHO5UkwtdzUhMraFYpNJ4f9CXLZr.gEMVXvJg9XU+5GPVftYUGWA.BHvHjPQHe.DDBnJFlYxMDfMbQ1jgQKZtP9lK15vZPgKyQoEhp+mVg0eG3HGBFYfOnAVMHttUc0P3AKA6KvtlGwE2AtADY9Ydhv.MqYj3Rj0KO";
	}
};
}

