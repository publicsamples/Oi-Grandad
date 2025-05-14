namespace project
{

struct modcont_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "modcont";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "586.nT6K8CFxeTfD.XlEHMBDKa1iZDWZA3F.RWgIz6yuN.MXmjTd1wD..Dnz3PeQPwlk7CD..A.O.rtXrQ7FCwxitTT1LaRvu.wPewRV1hkeYakrQm2PVEdV9MJGYsbFMVhkiyRT5KEeiyPQYLr.VtiGNKuAcVy9FIPVKwY4+OeJsReOafkqqxS4FdALrfk1UYMCA4cphEZgIak7jElhn6nOJbT569hwpsRzjuLwAvf+BD1pqvNP.mxIN5OayITJmUXU9hzHh0xYLjQQ1+AeSmGJgOJ8iOmkv4fEhyvRPdVt6NcdamphxPtUSVJanKFmarQZquYBtC2H7iGjlj4tm3QG6AJqxWjFc+7aSnDVewG08t5r4HP5peC1px8TkkgqCO9js28+qQq0Er5qFos2L.3gfFMr0H..ADPBAH...L.fgrg.D9aFcZxelPJDo6f5aZFTIR2A02zLnRjtCpuoJCJCo5f5aZFTHR0Ak2jLnPvo5vfT1aBlEESnAR.ynmuSweJl.02UjlL.vSBwAk2zLnPjdHIpouoYPkH03fhaRFTIROHooouoYPkHEGTd7jKnSTSmGYcmf9Ke6JvyCUn7fVtikHCFgq3vzjknmzNE0bZNo7mNmZXI5oeXZeM4qVd93r8fQAGXdpU8jPSUyNJs.JXcSa5WM9ERB5SCdjbPb4qenoIBxvQq1maZ31uJcgt5AJFyjOaPcijWGwHcMHiBCZ1E4GhAa3PRxiDFJgmDvIokXIQi8liPFJLfPB5ctf0jf3nzjOmC7EGA1MfOc.";
	}
};
}

