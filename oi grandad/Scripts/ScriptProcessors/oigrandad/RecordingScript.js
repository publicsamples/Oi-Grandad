

reg bl;function prepareToPlay(sampleRate, blockSize)
{
	bl = blockSize;
	g_accumulator.reserve(sampleRate * 30 / blockSize); // reserve 30sec to prevent more allocation that we already have in the audio thread (Buffer.create())
}
 function processBlock(channels)
{
	if (g_record)
	{
		// append a new empty buffer at the end of the accumulator
		g_accumulator.push([Buffer.create(bl), Buffer.create(bl)]);
		
		// copy channels
		channels[0] >> g_accumulator[g_accumulator.length-1][0];
		channels[1] >> g_accumulator[g_accumulator.length-1][1];
	}
}
 function onControl(number, value)
{
	
}
 