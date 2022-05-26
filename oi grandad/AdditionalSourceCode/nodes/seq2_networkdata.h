namespace project
{

struct seq2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "seq2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "296.nT6K8CFiATOB.XUz3PBLIiJ.rOjRPTJqRV6XGDUWmEJC7Hn6XJZZnACrQ5AS8wCT5GfK.zB.u.PiUwQL2jJP9JQVxBOWbhO3P9lxEIyusssph7XtJ3qo7EWZnlHuiGFxa44TH1QBMFKlBVEDD407G95XewOVxkF1hScBtWlFv0CaJWDC4W8PdpFB4rEJ3XUbko1KIdZZdVGFPQNMdjfZZbYWcbQjiDTDic28I5YeZqN.ecwH72V7DTUrslLLjusU07w+aHPQjOSSg8HyCsLwRdMUk0jL+4H6HSakc4LnRz4tln..0zHxggTCoENVQLWZU.Bblnyvcf53VJn7.IoKNEsU2JufCZFAx8DLetdemjHA6i2o6vzRSrPA44+BGCBwI.zztcNLPlA";
	}
};
}

