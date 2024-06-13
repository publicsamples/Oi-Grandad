namespace project
{

struct track_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "track";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "506.nT6K8C1lDT3C.XfkHUB.Kq1qqHJbDU.Cp8TTkQgZc3Yl5PwpskGJP+e97+ZewZMgaH+A9.fO.3C.Tz7VScDp30UWNN61lEZKJG7U6xl0dJHAu1JaorA+YJaCKd8s5m7dsST6u3v2JMFkEmgMdMCQR7ZL7qIemDvlqL9t8XJJdMjL9.UkU4D5303tO6g3fQ6J28XHB2rKVJKY1KeFlEIR.i5ytXQ9.bf1svEJZtDu14v27MiEa+DcIHo.x1ycaZWP.X77O2ovyICLftoQORTWRc3PXkzPsKIvFcUkEBecUj7EC15fMqq5kz2tLakL0US6g.cD0ZbVoR0mGRwGeVmQQwHoTNcnvBdslK1T6PtGkldDWSa27TzevcwVYFdjJ8ZT74.q7+YllRSID0oznGCBaAZn8JzPx.wf5nF.fADvL5L.KieWaYQAzzrz1uaM3rjfJkg+fwJASL.ni0THKgkOKkTNqb.b3UdTQgXXDfS4gsvux0AFfUJqhyv1wb.BNL.flx1yhCn12FIYLoYAn4hQQX51fkXFXNsbA3baRZyF.WN6i6y.D3GUUEJTmKKJ.CKE7JeiOOMDzF6RCwQ31QvWbu8DCIzmypnMKhb7nL9LnlJeGdflDhyA3tEowkQnJgKG6Ep+srakvfKPLcjQSy0RjLmcmGna.NJvnF.";
	}
};
}

