const var mastervol = Content.getComponent("mastervol");
const var Vol = Content.getComponent("Vol");
const var Vol1 = Content.getComponent("Vol1");
const var Vol2 = Content.getComponent("Vol2");
const var Vol3 = Content.getComponent("Vol3");
const var vol1 = Synth.getEffect("Proc");
const var vol2 = Synth.getEffect("Proc2");
const var vol3 = Synth.getEffect("Proc3");
const var vol4 = Synth.getEffect("Proc4");



inline function onmastervolControl(component, value)
{
	Vol.setValue(value);
	vol1.setAttribute(vol1.vol, value);
	Vol1.setValue(value);
	vol2.setAttribute(vol2.vol, value);
	Vol2.setValue(value);
	vol3.setAttribute(vol3.vol, value);
	Vol3.setValue(value);
	vol4.setAttribute(vol4.vol, value);
};

Content.getComponent("mastervol").setControlCallback(onmastervolControl);


const var masterpos = Content.getComponent("masterpos");
const var pos = Content.getComponent("pos");
const var pos1 = Content.getComponent("pos1");
const var pos2 = Content.getComponent("pos2");
const var pos3 = Content.getComponent("pos3");


inline function onmasterposControl(component, value)
{
	pos.setValue(value);
	gran.setAttribute(gran.pos, value);
	pos1.setValue(value);
	gran2.setAttribute(gran2.pos, value);
	pos2.setValue(value);
	gran3.setAttribute(gran3.pos, value);
	pos3.setValue(value);
	gran4.setAttribute(gran4.pos, value);
};

Content.getComponent("masterpos").setControlCallback(onmasterposControl);

const var mastergrain = Content.getComponent("mastergrain");
const var grainsize1 = Content.getComponent("grainsize1");
const var grainsize2 = Content.getComponent("grainsize2");
const var grainsize3 = Content.getComponent("grainsize3");
const var grainsize4 = Content.getComponent("grainsize4");



inline function onmastergrainControl(component, value)
{
		grainsize1.setValue(value);
	gran.setAttribute(gran.grain, value);
	grainsize2.setValue(value);
	gran2.setAttribute(gran2.grain, value);
	grainsize3.setValue(value);
	gran3.setAttribute(gran3.grain, value);
	grainsize4.setValue(value);
	gran4.setAttribute(gran4.grain, value);
};

Content.getComponent("mastergrain").setControlCallback(onmastergrainControl);




const var masterdense = Content.getComponent("masterdense");
const var Dense = Content.getComponent("Dense");
const var Dense1 = Content.getComponent("Dense1");
const var Dense2 = Content.getComponent("Dense2");
const var Dense3 = Content.getComponent("Dense3");


inline function onmasterdenseControl(component, value)
{
	Dense.setValue(value);
	gran.setAttribute(gran.dense, value);
	Dense1.setValue(value);
	gran2.setAttribute(gran2.dense, value);
	Dense2.setValue(value);
	gran3.setAttribute(gran3.dense, value);
	Dense3.setValue(value);
	gran4.setAttribute(gran4.dense, value);
};

Content.getComponent("masterdense").setControlCallback(onmasterdenseControl);

const var masterpitch = Content.getComponent("masterpitch");
const var pitch = Content.getComponent("pitch");
const var pitch1 = Content.getComponent("pitch1");
const var pitch2 = Content.getComponent("pitch2");
const var pitch3 = Content.getComponent("pitch3");


inline function onmasterpitchControl(component, value)
{
	pitch.setValue(value);
	gran.setAttribute(gran.pitch, value);
	pitch1.setValue(value);
	gran2.setAttribute(gran2.pitch, value);
	pitch2.setValue(value);
	gran3.setAttribute(gran3.pitch, value);
	pitch3.setValue(value);
	gran4.setAttribute(gran4.pitch, value);
};

Content.getComponent("masterpitch").setControlCallback(onmasterpitchControl);

const var masterspread = Content.getComponent("masterspread");
const var spread = Content.getComponent("spread");
const var spread1 = Content.getComponent("spread1");
const var spread2 = Content.getComponent("spread2");
const var spread3 = Content.getComponent("spread3");


inline function onmasterspreadControl(component, value)
{
	spread.setValue(value);
	gran.setAttribute(gran.spread, value);
	spread1.setValue(value);
	gran2.setAttribute(gran2.spread, value);
	spread2.setValue(value);
	gran3.setAttribute(gran3.spread, value);
	spread3.setValue(value);
	gran4.setAttribute(gran4.spread, value);
};

Content.getComponent("masterspread").setControlCallback(onmasterspreadControl);

const var masterdetune = Content.getComponent("masterdetune");
const var det = Content.getComponent("det");
const var det1 = Content.getComponent("det1");
const var det2 = Content.getComponent("det2");
const var det3 = Content.getComponent("det3");


inline function onmasterdetuneControl(component, value)
{
	det.setValue(value);
	gran.setAttribute(gran.detune, value);
	det1.setValue(value);
	gran2.setAttribute(gran2.detune, value);
	det2.setValue(value);
	gran3.setAttribute(gran3.detune, value);
	det3.setValue(value);
	gran4.setAttribute(gran4.detune, value);
};

Content.getComponent("masterdetune").setControlCallback(onmasterdetuneControl);

const var mastercut = Content.getComponent("mastercut");
const var cutoff = Content.getComponent("cutoff");
const var cutoff1 = Content.getComponent("cutoff1");
const var cutoff2 = Content.getComponent("cutoff2");
const var cutoff3 = Content.getComponent("cutoff3");
const var filter1 = Synth.getEffect("Proc");
const var filter2 = Synth.getEffect("Proc2");
const var filter3 = Synth.getEffect("Proc3");
const var filter4 = Synth.getEffect("Proc4");

inline function onmastercutControl(component, value)
{
	cutoff.setValue(value);
	filter1.setAttribute(filter1.cut, value);
	cutoff1.setValue(value);
	filter2.setAttribute(filter2.cut, value);
	cutoff2.setValue(value);
	filter3.setAttribute(filter3.cut, value);
	cutoff3.setValue(value);
	filter4.setAttribute(filter4.cut, value);
};

Content.getComponent("mastercut").setControlCallback(onmastercutControl);

const var masterres = Content.getComponent("masterres");
const var res = Content.getComponent("res");
const var res1 = Content.getComponent("res1");
const var res2 = Content.getComponent("res2");
const var res3 = Content.getComponent("res3");


inline function onmasterresControl(component, value)
{
	res.setValue(value);
	filter1.setAttribute(filter1.res, value);
	res1.setValue(value);
	filter2.setAttribute(filter2.res, value);
	res2.setValue(value);
	filter3.setAttribute(filter3.res, value);
	res3.setValue(value);
	filter4.setAttribute(filter4.res, value);
};

Content.getComponent("masterres").setControlCallback(onmasterresControl);


const var mastermix = Content.getComponent("mastermix");
const var mix1 = Content.getComponent("mix1");
const var mix2 = Content.getComponent("mix2");
const var mix3 = Content.getComponent("mix3");
const var mix4 = Content.getComponent("mix4");


inline function onmastermixControl(component, value)
{
	mix1.setValue(value);
	filter1.setAttribute(filter1.Mix, value);
	mix2.setValue(value);
	filter2.setAttribute(filter2.Mix, value);
	mix3.setValue(value);
	filter3.setAttribute(filter3.Mix, value);
	mix4.setValue(value);
	filter4.setAttribute(filter4.Mix, value);
};

Content.getComponent("mastermix").setControlCallback(onmastermixControl);


const var del1 = Synth.getEffect("Proc");
const var del2 = Synth.getEffect("Proc2");
const var del3 = Synth.getEffect("Proc3");
const var del4 = Synth.getEffect("Proc4");



const var masterfeed = Content.getComponent("masterfeed");

const var feed1 = Content.getComponent("feed1");
const var feed2 = Content.getComponent("feed2");
const var feed3 = Content.getComponent("feed3");
const var feed4 = Content.getComponent("feed4");

inline function onmasterfeedControl(component, value)
{
	feed1.setValue(value);
	del1.setAttribute(del1.dfeed, value);
	feed2.setValue(value);
	del2.setAttribute(del2.dfeed, value);
	feed3.setValue(value);
	del3.setAttribute(del3.dfeed, value);
	feed4.setValue(value);
	del4.setAttribute(del4.dfeed, value);
};

Content.getComponent("masterfeed").setControlCallback(onmasterfeedControl);

const var masterdmix = Content.getComponent("masterdmix");
const var delmix = Content.getComponent("delmix1");
const var delmix1 = Content.getComponent("delmix2");
const var delmix2 = Content.getComponent("delmix3");
const var delmix3 = Content.getComponent("delmix4");


inline function onmasterdmixControl(component, value)
{
	

	delmix.setValue(value);
	del1.setAttribute(del1.dmix, value);
	delmix1.setValue(value);
	del2.setAttribute(del2.dmix, value);
	delmix2.setValue(value);
	del3.setAttribute(del3.dmix, value);
	delmix3.setValue(value);
	del4.setAttribute(del4.dmix, value);
};

Content.getComponent("masterdmix").setControlCallback(onmasterdmixControl);




//xfade

const var XF = Content.getComponent("xfade");
const var xfade = Synth.getModulator("xfade");
const var xf1 = Synth.getEffect("xf1");
const var xf2 = Synth.getEffect("xf2");
const var xf3 = Synth.getEffect("xf3");
const var xf4 = Synth.getEffect("xf4");
const var XFcont = Content.getComponent("XFcont");
