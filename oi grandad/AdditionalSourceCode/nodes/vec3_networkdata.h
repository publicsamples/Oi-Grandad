namespace project
{

struct vec3_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "vec3";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "456.nT6K8Cl5BTeC.XKlNYB.OaS.OJbsRj8f2nooR.UWCDHFRGzjCNojYo+++1aPgNdNM4j9AHD.DAvP.7mq0oRBxOWK95Jsf7chsLgfcrp4Pi77lFSlekVoUCH+qcWPVhyzn7UtW24SHqNyEsk0BGREag5HeEKQ4q.1WDYLA7dcC5i7Ur.P9PoKB4OMLSTNEQApHSllLQoOxCA0VcC7lVhyyEA0PEgyXKJZUSX0nns3nDn4+E.I6og4qFkeCec09DhgY3z7giZVVBp.NhxThgckNPEKWCXkXXzt7UZU84tzH+CPNxdZvVl+bMNpi7arDYNvVDMKPa5K+PrPajmAY0j3u1Eq37+qHewPnO9WocRcv445D61iFc.1JgB0DJTfrrExtLUfeVr4oifVnhkSYgvnlPIQxJYZZhRRA0f7WvUn4rHL1RghsrCB0.BT..RiYG.jkA8qNySij3uwy2PB7CTxJHfGonT6.i4CTdX3jTFyLFe7.d.lvNOHHZHEaFFhOdnyqXzJ.KVKIj.+7vTyk4OV6CNMtiwxYtbEn.At.tEzdcevZmA.0.AcErXKASwCzhj6fATaiBH.z3PbuasEgAahivh4qDF4LXQA";
	}
};
}

