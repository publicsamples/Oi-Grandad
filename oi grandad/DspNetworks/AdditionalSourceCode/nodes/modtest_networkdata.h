namespace project
{

struct modtest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "modtest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "497.nT6K8C1rDzyC.XdUFQB.Stc.0nIsEZZOsjMVKwtED4ufH4crhv5lpFQ.0ruwvH1ixTfN.nC.9..DGYUlKk8TkCpFomnCa8D9RLAqpY1Xph+TpiHxpN6mXW8AhmrJ7axnegNk9j8OlxpVt.YUNhuGSeh.W.aQ7pNZkDzo5viQvAD8o+5XiQiuqIIe1EIGB+G1ouQry.+1rcTrO5w8wBTIXkDie54SVfHqpRHqF7viGUD3I9qkg4PK3AVJrVPLTYU.DDzhAPYtKiFBASQqnQu4lZSGUDKfBKUyvSVezpXxmUrvhkroiTdUmx0A5tOOd.1+PXiljo.axVCFGe1Rjv5.JLXM62OoZ.xIhkTQx5.1Y0MNCdQFcMzfxgp1MIaV1U0d1V13to2GVAZPAGkZlA.vFBqgA.E.fBkiGboMXtEBd2iRF5X3DDuJKWAXlSk0N7XCG4XyERJmd0zQ0HW1burv+RjXoW.VyBbV2EBUpQXJWXRqjlPgPCuwUzYaKhcV8UplkQROg0wPfsJNqI5TE.tC0Y.a4oHnPr3JOpx1.ukdisQ1ZiA.8Ctkv.ma4csywta6A.JAULpAj2D3sKewIdq..Q9UPBLiR7Lrcw0FDbdOsrNP.BaAwYlwsHQrvBlRwPQXEp63g.D4yAVnvj6ccfZCvWE";
	}
};
}

