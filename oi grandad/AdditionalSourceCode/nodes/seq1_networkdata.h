namespace project
{

struct seq1_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "seq1";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "337.nT6K8C1HDziB.H0iuHBPoZS.PHxUFcJZso0NKswNTci6FrsOIfinWE8lOULxrszOOpX5lBAFPAC6g873ik509d7hLOkk8dx7wHKEBtLo1iL+0VYPYaSNdQTyr6gho0RbpC7jaa04zC9cZ0wsDB91zUTgvgh1XkzTHOoFFxqxujM8ZQfgSJ.tpviK4chvsWmBUnIbzimPUHOaiQcpRAOZ0.2mj1OdoBHeTqPUfbuTCLjeYriLeSBEh7OVJBWH2IgMpNjmwyR9HPdRuNRMf.k..Jfp50OV.CEKAbDwFDaB8hZ.wDHQnj0nIPKMfaLNIPAtuDNPwfGH9EvPwRvyHFvHIHdMRqRPKjflgYARNTHGPmgCPBN.1ZuwVLthxCFmiVQRPCoG.88BQWMlRdAqBDSpI4.fkfOnLzv.4tDbYwUemfIPPDRgwVP3L3GFiamG3o.9OA";
	}
};
}

