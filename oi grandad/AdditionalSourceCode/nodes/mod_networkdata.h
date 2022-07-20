namespace project
{

struct mod_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "mod";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "474.nT6K8C1pDTnC.Xaz5PBHoaa.aoVlNRHaBhWlQGzvXFSUNnlcK9g3BAfNv.bD8I4zMI0K.HC.u.ftgJR1PG+PmZGfoadlRGo+TrBGXZ27ILlFwXSvTn6lx1h17pcYZDIOLkizY36IA7rZ9DTTKu7XL9SyJ.AJdJP4P4OLWNnwkKyt.RmOLUZJ6uqXISgAeSEkwBwzVOmbryi.SpjA6Ald0Mnjoryjw5QG9EmtH7yQt5WrxgnZa8XKaBkqhMITMD5PXeqQxK.c2ygBfTiHDze1MHG2.1GVjic67ht+YMsJPb.p03nmKW7bk+VN1DRM3pD6uRBRKhKdB5RYnFjqonzBPADTPPw.PI.fBc0cxCPIEDAjPDIJQJ3xnjxJIEq05HEj+XIEGFBsxHu0PZFzFo1hgDI4aS7Hh2hUQuASBKXfEKRPCU3orqU9cXPOCKxNbWUOO+vHgGgxih5oulhxmwALP.Y+vcjQ5fsfbW19ZK5k9.k8Ji7NU5zSw5bUfLt35ISMJqN.+8hYHsDz.7RNRjLx39uO.lU1vduPZNHBWaFYvkpZHmw40CKex6rRBlS+P2IwWbMCUF7JcJ4JeO+h4IBw7IJMTWgnyEITln.6.HVeok3RLC3G67YUJxuJ";
	}
};
}

