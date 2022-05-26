namespace project
{

struct follow_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "follow";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "483.nT6K8ClWCzrC.X8UMYB7vha.UbOMAKKFgeV70kQS+2FCOAtgtWqyqtmCKbvWu3kSj1QRF.D.AA.Q..vypp7wpQ7ypVtT1WYRnZTAEcnqmvuhSXUMl8kr3Oq5IdV0sdJ1UghXAVE9NYzuP67u2mgGXUJUdr5l32Y5TD.yqZUY5ZhsE8Cy5snJ+XUG60WLqbH7mvFjstYzu93kmUefJhDIIRTRSrAqFw92OARCzMw9Hyf5uL5JLdcF+SCePDvSyAlC2BVISFLIx52kzQomMEN72EmeBjrxwogYVbCQGC+5e9FPmUn8SrHVHNbAJkJMNZKJCcV.XUVfnOcNcrunVVc.ppxWC03vHkd0GuvHn5zDjHMIRSTPTRrBx1edELAptopmyHZSSsFDQjZRTP.oAQpiuAi1dn0hjL0VnCGlKehIJpwCDHDHv..voPqCpGvZSnn2vsBShFCabJC9NaBL4k7Av1w73HvF.FC3BXLMPAKCwh9Z2H5.5HPT6.JhzOarbUj4P6ydPSh8uXtjwg8Aqo.z.wPu8ni0YcWCLvvA72.jGfBW1wcBJ6FBfMpxuVfEaFBqUfqkbGZbvMEBkKaNugucY5cs9081tKxwFeIeNX0nr87AhHtJjf3IilgAax4310AdL.+S";
	}
};
}

