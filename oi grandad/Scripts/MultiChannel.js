// Multichannel menus
const var MultiChannelTest = Synth.getChildSynth("oi grandad");


var matrix = MultiChannelTest.getRoutingMatrix();

const var SucessLabel = Content.getComponent("SucessLabel");
const var SucessLabel1 = Content.getComponent("SucessLabel1");
const var SucessLabel2 = Content.getComponent("SucessLabel2");
const var SucessLabel3 = Content.getComponent("SucessLabel3");


inline function onOutputSelectorControl(component, value)
{
	
	local success = true;
	
	switch(value)
    {
        case 1: 
            matrix.addConnection(0, 0);
            matrix.addConnection(1, 1);
            break;
        case 2: 
            matrix.addConnection(0, 2);
            
          
            success = matrix.addConnection(1, 3);
            break;
        case 3:
            matrix.addConnection(0, 4);
            success = matrix.addConnection(1, 5);
            break;
        case 4:
            matrix.addConnection(0, 6);
            success = matrix.addConnection(1, 7);
            break;
    }
    
    if(!success)
    {
        matrix.addConnection(0, 0);
        matrix.addConnection(1, 1);
    }
    
    SucessLabel.set("text", success ? "OK" : "Error");
};

Content.getComponent("OutputSelector").setControlCallback(onOutputSelectorControl);


inline function onOutputSelector1Control(component, value)
{

	local success = true;
	
	switch(value)
    {
        case 1:
            matrix.addConnection(2, 0);
            matrix.addConnection(3, 1);
            break;
        case 2:
            matrix.addConnection(2, 2);
            success = matrix.addConnection(3, 3);
            break;
        case 3:
            matrix.addConnection(2, 4);
            success = matrix.addConnection(3, 5);
            break;
        case 4:
            matrix.addConnection(2, 6);
            success = matrix.addConnection(3, 7);
            break;
    }
    
    if(!success)
    {
        matrix.addConnection(2, 0);
        matrix.addConnection(3, 1);
    }
    
    SucessLabel1.set("text", success ? "OK" : "Error");
};

Content.getComponent("OutputSelector1").setControlCallback(onOutputSelector1Control);



inline function onOutputSelector2Control(component, value)
{

	local success = true;
	
	switch(value)
    {
        case 1:
            matrix.addConnection(4, 0);
            matrix.addConnection(5, 1);
            break;
        case 2:
            matrix.addConnection(4, 2);
            success = matrix.addConnection(5, 3);
            break;
        case 3:
            matrix.addConnection(4, 4);
            success = matrix.addConnection(5, 5);
            break;
        case 4:
            matrix.addConnection(4, 6);
            success = matrix.addConnection(5, 7);
            break;
    }
    
    if(!success)
    {
        matrix.addConnection(4, 0);
        matrix.addConnection(5, 1);
    }
    
    SucessLabel2.set("text", success ? "OK" : "Error");
};

Content.getComponent("OutputSelector2").setControlCallback(onOutputSelector2Control);



inline function onOutputSelector3Control(component, value)
{

	local success = true;
	
	switch(value)
    {
        case 1:
            matrix.addConnection(6, 0);
            matrix.addConnection(7, 1);
            break;
        case 2:
            matrix.addConnection(6, 2);
            success = matrix.addConnection(7, 3);
            break;
        case 3:
            matrix.addConnection(6, 4);
            success = matrix.addConnection(7, 5);
            break;
        case 4:
            matrix.addConnection(6, 6);
            success = matrix.addConnection(7, 7);
            break;
    }
    
    if(!success)
    {
        matrix.addConnection(6, 0);
        matrix.addConnection(7, 1);
    }
    
    SucessLabel3.set("text", success ? "OK" : "Error");
};

Content.getComponent("OutputSelector3").setControlCallback(onOutputSelector3Control);


//presets
const var Pbox = [];

Pbox[0] = Content.getComponent("settings");
Pbox[1] = Content.getComponent("blank1");
Pbox[2] = Content.getComponent("blank2");

const var pre= Content.getComponent("presets");

inline function onpresetsControl(component, value)
{
    for (i = 0; i < Pbox.length; i++)
        Pbox[i].showControl(value - 1 == i);
};


Content.getComponent("presets").setControlCallback(onpresetsControl);

function onControl(number, value)
{
    if(number == widget1)
    {
        Module1.setAttribute(Module1.Parameter, value);
    }
    else if (number == widget2)
    {
        Module2.setAttribute(Module2.Parameter, value);
    }
}