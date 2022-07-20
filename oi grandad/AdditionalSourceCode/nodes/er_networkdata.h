namespace project
{

struct er_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "er";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "403.nT6K8CFUBzDC.X50KYB7taS.lMRLDWU0kijhHEY6SiZ1M.9jBYFiMGMb2DVlyXKShbL8C3C.+.vP.nADjylyV.z2Zoj+XwB+4XNURw9434CVsGnmyj0XQDNqXGhz2MXFUOShIw1F5ePmL1R7XuQ5u.AC8chPPyNSxXKi3w5Pacq0SX0vmbrQ5C0sGDQ5ksGmCPW6RAU+4IeIT64iEjAFpTGeDNYOWONVwZ..W1MXFF5mjwd1VbjCRlLEQhsF7GzMcRnlk.lzztRrcizGf9+oHVlnj.IxRPHFSe4gk34vbJbrTWQrsbLgEEMn0CnqcwI3fOpbxKLO5T4hO9eY+tl8kF2wOaVArX5ju9xNvodegayywwG1BXLpsAjMfeNUSmlsQEKUjLghQQohEHVXQnHwVDzCp6rAxj8eREJJAHBHPYDQnEe..KVAIVKeBYB3KDRb0xlWn8L6s6xNcnHZzwQuaqJMPF35AiTXhhpON+SJnGxIA9dfkgdxjddbDzAN6q1gGyoPVwECvmGHF6aZmCqyTTvLC.";
	}
};
}

