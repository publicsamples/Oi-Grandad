namespace project
{

struct FollowIN1_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "FollowIN1";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "340.nT6K8ClTATkB.X2j8PBDoiS.WzhcRI8DwnB1IAoJAgmTWOBnXD2fA...MtIrArPhoefL.HC.x..ETjgtcBaJl.5sL2Hah8jZe3nmq5IUeCpA0XFzCamLxRdhIoL860OXGzGIUP+kXmYxS0uJr.zWIQwPX6P0e4jqDWDfsatuqpFhCDGO7KKaw.vQ+kbUOUPei4nuhkx0ZSiCcqk.RO+W9DDvdzqgqfRpdYjoP4pwl8YIcQp9uyMRC+rvzN94q2JgYHxSFyF2HmeSVpDd6jvbwzyqChjRnYg7FTiwfNHO5UcYOJCwF1MirUGiTP+BEsBVvPACEFvPnOd0u1ATEnad0Q1.Q8AHvHjPQHe.DDBnJFlYxMDfMbQ1jgQKZtnml6H3vZPkKyQoEhp+mVg0eG3HGBFYfOnAVMHttUc0P3AKA6KvtlGwE2AtADc9Ylhv.MqmXPplA.";
	}
};
}

