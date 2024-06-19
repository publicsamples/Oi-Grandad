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
		return "507.nT6K8C1lDz3C.XfkHUB.Kq1qqHJbDU.Cp8TTkQgZc3Yl5PwpskGJP+e97+ZewZMgaH+A9.fO.3C.Tz7VScDp30UWNN61lEZKJG7U6xl0dJHAu1JaorA+YJaCKd8s5m7dsST6u3v2JMFkEmgMdMCQR7ZL7qIemDvUFe2dLEEuFRFefpxpbBc7Zb2m8Pbvnck6dLDga1EKkkL6kOCyhDdBXTe1EKxGfCztEtPQyk30NG9luYrXa7DcIHo.x1ycaZWP.X79bmBOmLv.5lF8HQcI0gCgURC0tj.azUUVH70UQxWLXqC1rtpWRe6xrUxTWMsGBzwl0ZbVoR0mGRwGeVmQQwHoTNcnvBdslK1T6PtGkldDWSa27TzevcwVYFdjJ8ZT74.q7+YllRSID0oznGCBbAZn8JzPx.wf5nF.fIP.yry.KieWaYQDzzLx1uaN3DjfJkg2fwVYLA.M5PSGrDV9rTR4LvAzga4QGEhgQ.NkGhB+JWGf.dorJNIaG4.fbX.DMMaOKG3s2FR2lqvLAZtXz5NMavh2AHmVp.b2ljFLBjMyvv9c..24UpBFzYx.cffp.uya9ISyfrwsbnMBydCvEWsmXVB8YsJJYAliG0wmM3LT9N7.MIDmGjQt3Pp7z3VU3xwd45ejcqIL7BDoirZZNVhn4r69.cCvQAF0";
	}
};
}

