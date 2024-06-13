namespace project
{

struct send_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "send";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "659.nT6K8CFKGzDE.X1VXYB.Opd.L9xDPq8JNIuISeG5mr7Oks31v5J1rv+++yLVmA9iIWijTrD.LA.T.7Wt0sxvupOKyw1XfsnZrOU5WZkpOvwVWGylsdo7F.vweU0AmigsCGSIoUKrsYEyE04bB27ZHNlVkY1OBth9Y8CGWwhCGagsdw8cH3W0q1DHF9EtoxKLC8Va5QbodJsRoir4jW6iUsXfhOGHonT7oi3XqVcVozTAUd0p1VgeNgSIwzmnNqnK.fDppW8.M3qbhk0P3rFY1+1STzKJFiOMRZDb7EuEYXHDD9ldfIjgLC1ey7B3Qu.FeE0BETnwvlOwxjU7qWAieRgqrb+JrND9TqpdwQSFk7xoaUsAXWOXWyUGAZ8eR0AbCvcCmIGnjTTDAaC2WIyzD7P74LAeRjbbdRPSwnS+.1el+y+gV.Kn76cB+7jdNQPSORfhfdNORhMDlmdljlfZfhKTMqVVYu0BBd54.ejB.BHpAViLzLzLRA.P.EA.PA.fpxJOhDMHKHDBBFBpEfhGYnbKp3pENLIBLjqJ1Zql3gCePi3V3W08UEudgzxZ8r3Eei3noA4EnDFARjpKD.U2755rZIZ1zwKeil7dU1EG1BmCouG7AXNpwuAY.8kEIyISCxoL5LGXAl3ocLejg0CS6ipTIVuC6OtN.3VMFt1O4Zf4Wa05+CXOCPII3uTLpmSArC8q5SWg+f5jRdEpt9DnI1WVB.eUixygH36vokHW8xXm0rDyGmK8xGS0U0uhVbNQJyLdjpG1XgyG+wGd5sZTCp.iGpZWXrvekwgqn3mm4pPMK9.J0k6qVlZGDUrfecJhR4jFEo.3.uAb1TbagufslrAsIjGGnVBSkPnBNQRz0Kt5lOO";
	}
};
}

