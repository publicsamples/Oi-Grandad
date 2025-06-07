namespace project
{

struct ana4_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "ana4";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "425.nT6K8CV7BzOC.XRUCUB.saa.ellXHJjAsfSz5pDYddP4evaYrv5Ro++2dinKYps3oSo.3.PN.fC.skE+ITCIzwd1LEanienuYIPSOOeITz+M7jEZ1M2hpIahMwVIMgtyJ1YRGLjWFZJgRjlPDcI91Rv6SkGISOeGX6vBfl80iyjcyqDx8w9iGurPmdd7fXaE5wPVS+bb1AhVoUx.WyUsBjVQZWwVR1pPyVPGQuEnYih69MMD5Q9tSje.5tmeWMuRloUr+thi7kLe3nwBJrRfXnqBntAonPSq94l3t1ED9YIf5P8bk+WPXLFCIPsArH+2Eyokz38GFpIbX9zOljM8fZYLw1kglQppScft+xiKB4JE62EkPC+bSyCC7.BTDQCCiF.HF.Tdtnyvf4BLUKukIOVTkCavEbIb0dPH6CvgKhWpIFmDQuGgJvVkCoVI3Ze.16Pr3.vUATU415fDBgNa2VAcbWuOWFQFVXaPvhwyCk7CesT4BkCPc.Yh.p4Cf9QutHqrZrfCBBR1wRr.gCHJ0vXLLxOXbAXbpbBKO0l.P6hibKleI3bXLhB";
	}
};
}

