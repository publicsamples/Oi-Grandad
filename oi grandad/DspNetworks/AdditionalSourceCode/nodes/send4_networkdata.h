namespace project
{

struct send4_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "send4";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "336.nT6K8ClRATiB.XvT7LBLIaS.bSqc0Qtsg3jhHTWiTYFppINTbZWkmQToG8ZdXglN8GC.w.PL.33P2dYBJxP2Ng8zZ.8WlqjMwdNsH3nmacDUOChAwfsSF4IeQCxx0A8QRFziI1KL4HgBukR+rrDPeSZhgv9gp+xIaItI.a2beUsFhCDGC3XVlZAfi9K4VGwfd1xQeikxkZS.DDI87e4STv5QuFtAkT8xHWoRkiM6iR5hT8emajF9Qkoe7yUucx5PjmblMtRN+nrSAL2L8r5fHoDZVHmAwVKnCxidUWrqGcgXC6lQlpiRLnmwfgBCZnnghEKD5iU8qe.YA5lUcbEHf.iPBEg7APPHfpXXlI2P.1vEYSFFsn4B4atXqCqAEtLGkVHp9eZEV+cfibHXjA9fFX0f35V0UCgGrDru.6ZdDWbG3FPj4m4IBCzrlQhKQVu7";
	}
};
}

