namespace project
{

struct test_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "test";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "491.nT6K8ClOFzvC.XA1KQB7TtM3+tT6J7TP5bZxC6f9FsjIloKtdDrDhCKNLBfm7.yNQF.P.DD.CA.GqlPoXT91c7zgrkgkRM4npGNYbEBrztAwrVJEmcxRcnS98F5yFvRYNGREqdvnMv2SBcJ64JYoPWDvRA4galMlx94p.5ZZjfmLzH8KlARA.KJSV+A7iaDZKhax9Ty8cTQMUMcRuaSSm0DRrmxouq3Wb54mFmeO1GUBvpyvXTmVKkg63XQPgfPkWbG+VrD33.wN4oCMOSZm7rqtqJaGNcYZIJ1zEsKrRFgunNTpLYoslGug6tzv2yNC+bjpONrBrzQ5leQ.ppxJMtyHxOGaAVlOLJc90XU.hhAlLSpkLUzlfCcSV+NnUAueSbfkGjUrrRXdkziQCcCdow8GkbNZMniLkzFXKXDnA0q.EfFHfrvRTTDC.Y..QZ4A33TtXVQPU56D8oL2V9QPh5NZfxnDDo00fHAvZMvfCM5eJsgCRkof5gMK0n4ZZUmsvfp7JfFv.5hVH6yYBbvfRIE7V3MT5PTRJWVj9NSWiXVFQAQfMJPKOydfjb4QZ2mzM3fq1m8R6RySli8RZwpw8MCf3At0G0K36.Zjy3cBZMxV+DTZTQfnmaCllkiZ65qwpBkiZfz4AzW.e0.";
	}
};
}

