namespace project
{

struct record_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "record";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "331.nT6K8C1uAzfB.XPz3PBDMSc.NyZ2mE9ZVpvRIP0eQiXOMCZLZTwvupppdG6b9OJ4vTJK.zB.t.vD9LtfU4LaLSwexZJLV0a+kc0kZoVriUguSF8MZK9LOxOVcRkEqJQ7oX5WBnZO6Ie7mTmugEKjxiFnQepeRO3OWDr.pbw5c5K5hAX0lKkszDCJz0bXpnCcc.wT+vvCrTPU3zH4SM5REwrZwLuJinO8NcrwneZ2yq2.cV93MXEo+bTdWyyB6Ffpp7cyNCGPjDDhj.IgHQTXc.DHriIFz8LgGoL+OCSvZsh3GQbCFPy1AtAjpd6sHAqCl.BbHPvX7FfPfFtElFIN7AGT.uDjik0BhJHUlYvrHc.K1uXanVyBtTXHtJLx4Nu8ykSz4dj51.5L3Ql6hAc.BGeLEilWL4G6HFSfK3d5e.34hqpECvH.kbDiB.";
	}
};
}

