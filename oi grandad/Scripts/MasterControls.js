const var AllPosMode = [Content.getComponent("posmode2"),
                        Content.getComponent("posmode4"),
                        Content.getComponent("posmode3"),
                        Content.getComponent("posmode1")];


inline function onposmode5Control(component, value)
{
	for(s in AllPosMode)
	       s.setValue(value);
	for(c in AllPosMode)
	       c.changed();
};

Content.getComponent("posmode5").setControlCallback(onposmode5Control);


const var AllPos = [Content.getComponent("pos"),
                    Content.getComponent("pos1"),
                    Content.getComponent("pos3"),
                    Content.getComponent("pos2")];
                    

inline function onpos4Control(component, value)
{
	for(s in AllPos)
	       s.setValue(value);
	for(c in AllPos)
	       c.changed();
};

Content.getComponent("pos4").setControlCallback(onpos4Control);
                

const var AllPosModSrc = [Content.getComponent("pos1modsel"),
                          Content.getComponent("pos1modsel2"),
                          Content.getComponent("pos1modsel3"),
                          Content.getComponent("pos1modsel1")];


inline function onpos1modsel4Control(component, value)
{
	for(s in AllPosModSrc)
	       s.setValue(value);
	for(c in AllPosModSrc)
	       c.changed();
};

Content.getComponent("pos1modsel4").setControlCallback(onpos1modsel4Control);
                                              
                          
const var AllPosMod = [Content.getComponent("posmod"),
                                Content.getComponent("posmod1"),
                                Content.getComponent("posmod3"),
                                Content.getComponent("posmod2")];
                                

inline function onposmod4Control(component, value)
{
	for(s in AllPosMod)
	       s.setValue(value);
	for(c in AllPosMod)
	       c.changed();
};

Content.getComponent("posmod4").setControlCallback(onposmod4Control);

                                
                                
const var AllPitchMode = [Content.getComponent("pitchmode1"),
                          Content.getComponent("pitchmode3"),
                          Content.getComponent("pitchmode4"),
                          Content.getComponent("pitchmode2")];


inline function onpitchmode9Control(component, value)
{
		for(s in AllPitchMode)
	       s.setValue(value);
		for(c in AllPitchMode)
	       c.changed();
};

Content.getComponent("pitchmode9").setControlCallback(onpitchmode9Control);
                        

const var AllPitch = [Content.getComponent("pitch"),
                      Content.getComponent("pitch1"),
                      Content.getComponent("pitch3"),
                      Content.getComponent("pitch2")];
                      

inline function onpitch4Control(component, value)
{
		for(s in AllPitch)
	       s.setValue(value);
		for(c in AllPitch)
	       c.changed();
};

Content.getComponent("pitch4").setControlCallback(onpitch4Control);


const var AllPitchModSrc = [Content.getComponent("PmodSel1"),
                            Content.getComponent("PmodSel2"),
                            Content.getComponent("PmodSel4"),
                            Content.getComponent("PmodSel3")];
                            

inline function onPmodSel9Control(component, value)
{
		for(s in PmodSel3)
	       s.setValue(value);
		for(c in PmodSel3)
	       c.changed();
};

Content.getComponent("PmodSel9").setControlCallback(onPmodSel9Control);
                        

const var AllPitchMod = [Content.getComponent("pmod1"),
                         Content.getComponent("pmod2"),
                         Content.getComponent("pmod3"),
                         Content.getComponent("pmod4")];
                         

inline function onpmod5Control(component, value)
{
		for(s in AllPitchMod)
	       s.setValue(value);
		for(c in AllPitchMod)
	       c.changed();
};

Content.getComponent("pmod5").setControlCallback(onpmod5Control);
                         

const var AllSync = [Content.getComponent("psync1"),
                     Content.getComponent("psync2"),
                     Content.getComponent("psync3"),
                     Content.getComponent("psync4")];
                     

inline function onpsync5Control(component, value)
{
		for(s in AllSync)
	       s.setValue(value);
		for(c in AllSync)
	       c.changed();
};

Content.getComponent("psync5").setControlCallback(onpsync5Control);


const var AllDiv = [Content.getComponent("pitch8"),
                    Content.getComponent("pitch11"),
                    Content.getComponent("pitch13"),
                    Content.getComponent("pitch15")];
                    

inline function onpitch9Control(component, value)
{
		for(s in AllDiv)
	       s.setValue(value);
		for(c in AllDiv)
	       c.changed();
};

Content.getComponent("pitch9").setControlCallback(onpitch9Control);
               

const var AllStages = [Content.getComponent("StgSel1"),
                       Content.getComponent("StgSel2"),
                       Content.getComponent("StgSel3"),
                       Content.getComponent("StgSel4")];
                       

inline function onStgSel5Control(component, value)
{
		for(s in AllStages)
	       s.setValue(value);
		for(c in AllStages)
	       c.changed();
};

Content.getComponent("StgSel5").setControlCallback(onStgSel5Control);


const var AllDense = [Content.getComponent("Dense1"),
                      Content.getComponent("Dense"),
                      Content.getComponent("Dense2"),
                      Content.getComponent("Dense3")];
                      

inline function onDense4Control(component, value)
{
		for(s in AllDense)
	       s.setValue(value);
		for(c in AllDense)
	       c.changed();
};

Content.getComponent("Dense4").setControlCallback(onDense4Control);


const var AllDenseSrc = [Content.getComponent("densemodsel2"),
                         Content.getComponent("densemodsel"),
                         Content.getComponent("densemodsel1"),
                         Content.getComponent("densemodsel3")];
                         
 
 inline function ondensemodsel4Control(component, value)
 {
 			for(s in AllDenseSrc)
	       s.setValue(value);
		for(c in AllDenseSrc)
	       c.changed();
 };
 
 Content.getComponent("densemodsel4").setControlCallback(ondensemodsel4Control);
 

const var AllDenseMod = [Content.getComponent("densemod"),
                         Content.getComponent("densemod2"),
                         Content.getComponent("densemod3"),
                         Content.getComponent("densemod1")];
                         

inline function ondensemod4Control(component, value)
{
	
 			for(s in AllDenseMod)
	       s.setValue(value);
		for(c in AllDenseMod)
	       c.changed();
};

Content.getComponent("densemod4").setControlCallback(ondensemod4Control);

                         
const var AllGrain = [Content.getComponent("grainsize1"),
                      Content.getComponent("grainsize2"),
                      Content.getComponent("grainsize4"),
                      Content.getComponent("grainsize3")];
                      

inline function ongrainsize5Control(component, value)
{
	for(s in AllGrain)
	       s.setValue(value);
		for(c in AllGrain)
	       c.changed();
};

Content.getComponent("grainsize5").setControlCallback(ongrainsize5Control);


const var AllGrainSrc = [Content.getComponent("GrainModSel1"),
                         Content.getComponent("GrainModSel3"),
                         Content.getComponent("GrainModSel4"),
                         Content.getComponent("GrainModSel2")];
                         

inline function onGrainModSel5Control(component, value)
{
		for(s in AllGrainSrc)
	       s.setValue(value);
		for(c in AllGrainSrc)
	       c.changed();
};

Content.getComponent("GrainModSel5").setControlCallback(onGrainModSel5Control);
                    

const var AllGrainMod = [Content.getComponent("GrainMod1"),
                         Content.getComponent("GrainMod3"),
                         Content.getComponent("GrainMod4"),
                         Content.getComponent("GrainMod2")];
                         

inline function onGrainMod5Control(component, value)
{
			for(s in AllGrainMod)
	       s.setValue(value);
		for(c in AllGrainMod)
	       c.changed();
};

Content.getComponent("GrainMod5").setControlCallback(onGrainMod5Control);

                    
const var AllSprd = [Content.getComponent("spread"),
                     Content.getComponent("spread1"),
                     Content.getComponent("spread3"),
                     Content.getComponent("spread2")];
                     

inline function onspread4Control(component, value)
{
		for(s in AllSprd)
	       s.setValue(value);
		for(c in AllSprd)
	       c.changed();
};

Content.getComponent("spread4").setControlCallback(onspread4Control);


const var AllSprdSrc = [Content.getComponent("spreadmodsel"),
                        Content.getComponent("spreadmodsel2"),
                        Content.getComponent("spreadmodsel3"),
                        Content.getComponent("spreadmodsel1")];
                        

inline function onspreadmodsel4Control(component, value)
{
	for(s in AllSprdSrc)
	       s.setValue(value);
		for(c in AllSprdSrc)
	       c.changed();
};

Content.getComponent("spreadmodsel4").setControlCallback(onspreadmodsel4Control);


const var AllSprdMod = [Content.getComponent("spreadmod"),
                        Content.getComponent("spreadmod1"),
                        Content.getComponent("spreadmod3"),
                        Content.getComponent("spreadmod2")];
                        

inline function onspreadmod4Control(component, value)
{
	for(s in AllSprdMod)
	       s.setValue(value);
		for(c in AllSprdMod)
	       c.changed();
};

Content.getComponent("spreadmod4").setControlCallback(onspreadmod4Control);


const var AllDetune = [Content.getComponent("det"),
                       Content.getComponent("det2"),
                       Content.getComponent("det3"),
                       Content.getComponent("det1")];


inline function ondet4Control(component, value)
{
	for(s in AllDetune)
	       s.setValue(value);
		for(c in AllDetune)
	       c.changed();
};

Content.getComponent("det4").setControlCallback(ondet4Control);


const var AllDetuneSrc = [Content.getComponent("detmodsel"),
                          Content.getComponent("detmodsel1"),
                          Content.getComponent("detmodsel3"),
                          Content.getComponent("detmodsel2")];
                          
 
 inline function ondetmodsel4Control(component, value)
 {
	for(s in AllDetuneSrc)
	       s.setValue(value);
		for(c in AllDetuneSrc)
	       c.changed();
 };
 
 Content.getComponent("detmodsel4").setControlCallback(ondetmodsel4Control);
  
                          
const var AllDetuneMod = [Content.getComponent("detmod"),
                                                    Content.getComponent("detmod1"),
                                                    Content.getComponent("detmod3"),
                                                    Content.getComponent("detmod2")];
                                                    

inline function ondetmod4Control(component, value)
{
	for(s in AllDetuneSrc)
	       s.setValue(value);
		for(c in AllDetuneSrc)
	       c.changed();
};

Content.getComponent("detmod4").setControlCallback(ondetmod4Control);
                  
                          
const var AllCut = [Content.getComponent("cutoff"),
                    Content.getComponent("cutoff1"),
                    Content.getComponent("cutoff3"),
                    Content.getComponent("cutoff2")];

inline function oncutoff4Control(component, value)
{
		for(s in AllCut)
	       s.setValue(value);
		for(c in AllCut)
	       c.changed();
};

Content.getComponent("cutoff4").setControlCallback(oncutoff4Control);
                    
                    

const var AllRes = [Content.getComponent("res"),
                    Content.getComponent("res1"),
                    Content.getComponent("res3"),
                    Content.getComponent("res2")];
                    

inline function onres4Control(component, value)
{
			for(s in AllRes)
	       s.setValue(value);
		for(c in AllRes)
	       c.changed();
};

Content.getComponent("res4").setControlCallback(onres4Control);


const var AllFmix = [Content.getComponent("mix1"),
                     Content.getComponent("mix3"),
                     Content.getComponent("mix4"),
                     Content.getComponent("mix2")];
                     

inline function onmix5Control(component, value)
{
		for(s in AllFmix)
	       s.setValue(value);
		for(c in AllFmix)
	       c.changed();
};

Content.getComponent("mix5").setControlCallback(onmix5Control);
                     
                     
const var AllFtype = [Content.getComponent("type"),
                      Content.getComponent("type1"),
                      Content.getComponent("type3"),
                      Content.getComponent("type2")];
                      

inline function ontype4Control(component, value)
{
		for(s in AllFtype)
	       s.setValue(value);
		for(c in AllFtype)
	       c.changed();
};

Content.getComponent("type4").setControlCallback(ontype4Control);


const var AllFmodSrc = [Content.getComponent("cut1modsel"),
                                          Content.getComponent("cut1modsel1"),
                                          Content.getComponent("cut1modsel3"),
                                          Content.getComponent("cut1modsel2")];
                                          

inline function oncut1modsel4Control(component, value)
{
	for(s in AllFmodSrc)
	       s.setValue(value);
		for(c in AllFmodSrc)
	       c.changed();
};

Content.getComponent("cut1modsel4").setControlCallback(oncut1modsel4Control);
                
                                          
const var AllFMod = [Content.getComponent("filtermod"),
                     Content.getComponent("filtermod1"),
                     Content.getComponent("filtermod3"),
                     Content.getComponent("filtermod2")];
                     

inline function onfiltermod4Control(component, value)
{
		for(s in AllFMod)
	       s.setValue(value);
		for(c in AllFMod)
	       c.changed();
};

Content.getComponent("filtermod4").setControlCallback(onfiltermod4Control);

                                        
const var DelModSrc = [Content.getComponent("delmodsel1"),
                       Content.getComponent("delmodsel3"),
                       Content.getComponent("delmodsel2"),
                       Content.getComponent("delmodsel4")];
                       

inline function ondelmodsel5Control(component, value)
{
	for(s in DelModSrc)
	       s.setValue(value);
		for(c in DelModSrc)
	       c.changed();
};

Content.getComponent("delmodsel5").setControlCallback(ondelmodsel5Control);


const var DelMod = [Content.getComponent("delmod3"),
                    Content.getComponent("filtermod3"),
                    Content.getComponent("delmod2"),
                    Content.getComponent("delmod1")];
                    

inline function ondelmod5Control(component, value)
{
		for(s in DelMod)
	       s.setValue(value);
		for(c in DelMod)
	       c.changed();
};

Content.getComponent("delmod5").setControlCallback(ondelmod5Control);
                   

const var DelTime = [Content.getComponent("DelayTime4"),
                     Content.getComponent("DelayTime2"),
                     Content.getComponent("DelayTime3"),
                     Content.getComponent("DelayTime5")];
                     

inline function onDelayTime6Control(component, value)
{
	for(s in DelTime)
	       s.setValue(value);
		for(c in DelTime)
	       c.changed();
};

Content.getComponent("DelayTime6").setControlCallback(onDelayTime6Control);


const var DelFeed = [Content.getComponent("feed1"),
                     Content.getComponent("feed3"),
                     Content.getComponent("feed4"),
                     Content.getComponent("feed2")];
                     

inline function onfeed5Control(component, value)
{
		for(s in DelFeed)
	       s.setValue(value);
		for(c in DelFeed)
	       c.changed();
};

Content.getComponent("feed5").setControlCallback(onfeed5Control);


const var DelMix = [Content.getComponent("delmix1"),
                    Content.getComponent("delmix3"),
                    Content.getComponent("delmix4"),
                    Content.getComponent("delmix2")];
                    

inline function onmix5Control(component, value)
{
		for(s in DelFeed)
	       s.setValue(value);
		for(c in DelFeed)
	       c.changed();
};

Content.getComponent("mix5").setControlCallback(onmix5Control);


const var DelCut = [Content.getComponent("delmix6"),
                     Content.getComponent("delcut1"),
                     Content.getComponent("delcut2"),
                     Content.getComponent("delcut4")];
                     

inline function ondelcut3Control(component, value)
{
		for(s in DelCut)
	       s.setValue(value);
		for(c in DelCut)
	       c.changed();
};

Content.getComponent("delcut3").setControlCallback(ondelcut3Control);

                     
const var DelCutMod = [Content.getComponent("delcutmod1"),
                        Content.getComponent("delcutmod2"),
                        Content.getComponent("delcutmod4"),
                        Content.getComponent("delcutmod3")];

inline function ondelcutmod5Control(component, value)
{
		for(s in DelCutMod)
	       s.setValue(value);
		for(c in DelCutMod)
	       c.changed();
};

Content.getComponent("delcutmod5").setControlCallback(ondelcutmod5Control);


const var DelCutModSrc = [Content.getComponent("redmodsel1"),
                          Content.getComponent("redmodsel2"),
                          Content.getComponent("redmodsel4"),
                          Content.getComponent("redmodsel3")];
                          

inline function onredmodsel5Control(component, value)
{
		for(s in DelCutModSrc)
	       s.setValue(value);
		for(c in DelCutModSrc)
	       c.changed();
};

Content.getComponent("redmodsel5").setControlCallback(onredmodsel5Control);


const var AllVol = [Content.getComponent("Vol"),
                    Content.getComponent("Vol2"),
                    Content.getComponent("Vol3"),
                    Content.getComponent("Vol1")];
                    

inline function onVol4Control(component, value)
{
		for(s in AllVol)
	       s.setValue(value);
		for(c in AllVol)
	       c.changed();
};

Content.getComponent("Vol4").setControlCallback(onVol4Control);


const var AllVolModSrc = [Content.getComponent("ampmodsel"),
                          Content.getComponent("ampmodsel2"),
                          Content.getComponent("ampmodsel3"),
                          Content.getComponent("ampmodsel1")];
                          
                          

inline function onampmodsel4Control(component, value)
{
	for(s in AllVolModSrc)
	       s.setValue(value);
		for(c in AllVolModSrc)
	       c.changed();
};

Content.getComponent("ampmodsel4").setControlCallback(onampmodsel4Control);


const var AllVolMod = [Content.getComponent("volmod2"),
                       Content.getComponent("volmod"),
                       Content.getComponent("volmod1"),
                       Content.getComponent("volmod3")];
                       

inline function onvolmod4Control(component, value)
{
		for(s in AllVolMod)
	       s.setValue(value);
		for(c in AllVolMod)
	       c.changed();
};

Content.getComponent("volmod4").setControlCallback(onvolmod4Control);
                      

const var AllPan = [Content.getComponent("pan"),
                    Content.getComponent("pan2"),
                    Content.getComponent("pan3"),
                    Content.getComponent("pan1")];


inline function onpan4Control(component, value)
{
	for(s in AllPan)
	       s.setValue(value);
		for(c in AllPan)
	       c.changed();
};

Content.getComponent("pan4").setControlCallback(onpan4Control);

                    
                    
const var AllPanSrc = [Content.getComponent("PanModSel1"),
                       Content.getComponent("PanModSel2"),
                       Content.getComponent("PanModSel4"),
                       Content.getComponent("PanModSel3")];
                       

inline function onPanModSel5Control(component, value)
{
	for(s in AllPanSrc)
	       s.setValue(value);
		for(c in AllPanSrc)
	       c.changed();
};

Content.getComponent("PanModSel5").setControlCallback(onPanModSel5Control);


const var AllPanMod = [Content.getComponent("PanMod3"),
                       Content.getComponent("PanMod1"),
                       Content.getComponent("PanMod2"),
                       Content.getComponent("PanMod4")];


inline function onPanMod5Control(component, value)
{
		for(s in AllPanMod)
	       s.setValue(value);
		for(c in AllPanMod)
	       c.changed();
};

Content.getComponent("PanMod5").setControlCallback(onPanMod5Control);



const var AllAtk = [Content.getComponent("attack"),
                    Content.getComponent("attack1"),
                    Content.getComponent("attack3"),
                    Content.getComponent("attack2")];
                    

inline function onattack4Control(component, value)
{
		for(s in AllAtk)
	       s.setValue(value);
		for(c in AllAtk)
	       c.changed();
};

Content.getComponent("attack4").setControlCallback(onattack4Control);


const var AllDec = [Content.getComponent("decay2"),
                    Content.getComponent("decay"),
                    Content.getComponent("decay1"),
                    Content.getComponent("decay3")];
                    

inline function ondecay4Control(component, value)
{
			for(s in AllDec)
	       s.setValue(value);
		for(c in AllDec)
	       c.changed();
};

Content.getComponent("decay4").setControlCallback(ondecay4Control);

                    
const var AllSus = [Content.getComponent("sustain2"),
                    Content.getComponent("sustain3"),
                    Content.getComponent("sustain1"),
                    Content.getComponent("sustain")];
                    

inline function onsustain4Control(component, value)
{
		for(s in AllSus)
	       s.setValue(value);
		for(c in AllSus)
	       c.changed();
};

Content.getComponent("sustain4").setControlCallback(onsustain4Control);


const var AllRoute = [Content.getComponent("route"),
                      Content.getComponent("route2"),
                      Content.getComponent("route4"),
                      Content.getComponent("route3")];
                      

inline function onroute1Control(component, value)
{
		for(s in AllRoute)
	       s.setValue(value);
		for(c in AllRoute)
	       c.changed();
};

Content.getComponent("route1").setControlCallback(onroute1Control);

                 