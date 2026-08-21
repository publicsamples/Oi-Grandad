/** ModulatorMatrix example HISE 5.0 Edition

This is a very bare-bone example that shows how to use the matrix modulators to implement a dynamic modulation
system. If you compare this example to the previous implementation of the modulation matrix, you'll see that the
majority of the code in here is just CSS / LAF styling - this is because the entire functionality, data management &
UI interaction has been integrated natively into HISE and gives you ready-to-use building blocks for your modulation
system!

In this example there are three modulation sources:

- LFO
- AHDSR
- Velocity

And three modulation targets:

1. OSC1 Gain
2. OSC1 Pitch
3. OSC1 Reverb

The first two modulation targets are matrix modulators, which means that they offer the full modulation resolution
&& polyphonic support. The third modulation target is just a random HISE module parameter - in our case the wet amount
of a simple reverb module. This has no modulation slot, but by setting the `matrixTargetId` property of the connected UI
knob in the interface it will be registered as additional modulation target which will be handled by the same system as the
"real" ones. Note how there is basically no distinction between these three targets in the handling & appearance!
*/
Content.makeFrontInterface(1100, 600);

// Let's create a matrix handler object that can be used to programmatically change
// query the modulation connections.
// Note that as soon as you create this object it will also write the modulation connections into the user preset
// so that they are restored correctly.
const var matrixHandler = Engine.createModulationMatrix("Global Modulator Container1");

// If you want to be notified about connection changes, you can attach a callable object here
matrixHandler.setConnectionCallback(function(source, target, isConnected)
{
	Console.print(source);
	Console.print(target);
	Console.print(isConnected);
});

// Clear all connections (whatever connections you had will now be printed to the console)
matrixHandler.clearAllConnections("");

// This can be used to add more functions to the custom popup menu of a UI knob that is assigned to a modulation
// target
matrixHandler.setEditCallback(["my funky item", "another item"], function(index)
{
	Console.print(index);
});

// This can be used to add custom behaviour whenever the user is dragging a modulation dragger
matrixHandler.setDragCallback(function(source, target, eventType)
{
	.dump(source, target, eventType);
});

//! CSS DEFINITIONS ==============================================================

// Now we're going to use the new floating tile elements which offer the most commonly requested features
const var laf = Content.createLocalLookAndFeel();

// Since there are many (layout) customization requests, these new UI components follow a CSS-only styling.
// Finally a reason to start using this!
laf.setInlineStyleSheet("

/** The background panel for the matrix. */
.matrix
{
	content: '';
	background: #333;
	border-radius: 3px;
	padding: 10px;
}

/** If there are no connections we show a empty message. */
.matrix:empty { 
  color: #666; 
  content: 'No connections..'; 
}

.search
{
	background: #555;
	margin-bottom: 10px;
	padding: 5px;
	height: 20px;
	border-radius: 3px;
	padding-left: 100vh;
	color: #999;
}

.search::before
{
	content: '';
	background-image: var(--icon);
	background-color: #888;
	width: 100vh;
	margin: 5px;
}

#clearsearch
{
	background-color: #888;
	height: 20px;
	margin: 10px;
	margin-top: 0px;
}

/** The matrix table header. */
th { background: transparent; }

/** The background panel for the drag controller. */
#controller
{
	background: #333;
	padding: 10px;
	border-radius: 3px;
	flex-direction: row-reverse;
}



/** The draggable UI components that you can drop onto a UI knob. */
.dragger
{
	background-color: rgba(0, 0, 0, 0.3);
	font-family: 'Lato';
	color: rgba(255,255,255, 0.7);
	width: auto;
	border-radius: 50%;
	padding: 0px 10px;
	cursor: grabbing;
}
.dragger:hover { color: white; }
.dragger:active { transform: scale(98%);}
button:hover { color: white; }
.dragger::before
{
	content: '';	
	background-color: white;
	background-image: var(--dragPath);
	width: 24px;
	margin: 5px;
}

td, .targetLabel
{
	color: #999;
	font-size: 15px;
}

.targetLabel
{
	width: 130px;
}

.slider
{
	background: #444;
	border-radius: 3px;
	margin: 2px;
	color: #bbb;
}

.slider:empty
{
	color: #666;
}

.slider::before
{
	content: '';
	width: calc(var(--value) * 100%);
	height: 100%;
	background-color: #777;
	position: absolute;
	margin: 5px;
}

.unipolar::before, .bipolar::before
{
	
	
	/* this calculates the bipolar width with some advanced
	   CSS math expression skills. */
	width: max(calc(calc(0.5 - var(--value)) * 100%),  
	           calc(calc(var(--value) - 0.5) * 100%)); 
	           
	/* this calculates the leftmost position of the value rectangle. */
	left: min(calc(var(--value) * 100%), 50%);
}

select
{
	background: #444;
	border-radius: 3px;
	color: #999;
	font-weight: bold;
	text-align: left;
	padding: 10px;
}

/** Draw the drop down arrow. */
select::before
{
	/** CSS requires that you specify a content property for
	    any pseudo element that is supposed to be shown. */
	content: '';
	
	/** Pass in a Base64 string for any path using the standard HISE Path converter. */
	background-image: \"84.t0lavsBQ76.tCwF..VDQX+9fCw1WJBDQnj.cCwFp5YBQ3NhqCwly0w.QzMCcCwF..d.QTV.gCwFD6YBQpsevCwVtvsBQn.AtCwlavsBQ76.tCMVY\";
	
	background-color: rgba(255,255,255, 0.4);
	
	/** Set the position to absolute so that it won't cut into the text area. */
	position: absolute;
	width: 100vh;
	margin: 8px;
	right: 0px;
}

/** Make the arrow light up at hover. */
select::before:hover
{
	background-color: white;
}

button
{
	background: red;
	border-radius: 3px;
	background: #444;
	color: #999;
	content: 'Off';
}

.modplotter
{
	background: red;
}

/** The add/remove/clear buttons. */
.control-button
{
	width: 70px;
	/** Reset the content property so that the original text is displayed. */
	content: ''; 
}


button:checked
{
	background: #999;
	color: #333;
	content: 'On';
}



");

// This is the matrix component which shows a row for each connection with the given UI elements
const var Matrix = Content.getComponent("Matrix");
Matrix.setLocalLookAndFeel(laf);

// This is the menu bar which offers the add/remove/clear button as well as draggers that can be dropped on any
// UI knob to establish a connection
const var MatrixController = Content.getComponent("MatrixController");
MatrixController.setLocalLookAndFeel(laf);

const var SliderMatrix = Content.getComponent("SliderMatrix");
SliderMatrix.setLocalLookAndFeel(laf);

//! UI KNOB LAF ==============================================================

const var knobLaf = Content.createLocalLookAndFeel();

const var ARC = 2.4;
const var START = -ARC;
const var ARC_WIDTH = 2.0 * ARC;
const var THICKNESS = 14.0;

var p = {};               // Pick one of these:
p.EndCapStyle = "rounded";   // ["butt", "square", "rounded"]
p.JointStyle = "beveled"; // ["mitered", "curved","beveled"]
p.Thickness = THICKNESS;

inline function drawModSlider(g, obj)
{
	local a = Rectangle(obj.area).reduced(THICKNESS/2 + 2);
	local n = Rectangle(0.0, 0.0, 1.0, 1.0);

	local track = Content.createPath(); track.setBounds(n);
	track.addArc(n, START-0.05, START + ARC_WIDTH+0.05);
	
	if(obj.modulationDragState)
	{
		if(obj.modulationDragState == 2)
		{
			g.setColour(obj.itemColour1);
		}
		else
		{
			g.setColour(0x44FFFFFF);
		}
		
		g.fillEllipse(a.reduced(-THICKNESS/2 - 1));
	}
	
	
	g.setColour(0x77000000);
	g.drawPath(track, a, THICKNESS);
	
	local modRange = Content.createPath(); modRange.setBounds(n);
	modRange.addArc(n, START + obj.modMinValue * ARC_WIDTH,
					   START + obj.modMaxValue * ARC_WIDTH);
					   
	g.setColour(0x22FFFFFF);
	g.drawPath(modRange, a, THICKNESS - 2);
	
	local value = Content.createPath(); value.setBounds(n);
	value.addArc(n, START + obj.valueNormalized * ARC_WIDTH,
					START + Math.range(obj.scaledValue + obj.addValue, 0.0, 1.0) * ARC_WIDTH);
					
	g.setColour(obj.itemColour1);
	g.drawPath(value, a, THICKNESS - 4);
	
	local thumb = Content.createPath(); thumb.setBounds(n);
	thumb.addArc(n, START + obj.valueNormalized * ARC_WIDTH - 0.01,
					START + obj.valueNormalized * ARC_WIDTH + 0.01);
	
	g.setColour(Colours.white);
	g.drawPath(thumb, a, p);
	
	g.drawAlignedText(obj.valueAsText, a, "centred");
	g.setColour(0x55FFFFFF);
	g.drawAlignedText(obj.text, a, "centredBottom");
}

// These three function will be used to define the appearance of the modulation connection sliders when you hover
// over a knob with modulation connections

// draw the "background" of the hover popup (including the value label)
inline function drawModulationDragBackground(g, obj)
{
	if(obj.hover)
	{
		local lr = Rectangle(obj.labelArea);

		g.setColour(0xFF444444);
		g.fillRoundedRectangle(lr, 3.0);
		g.setColour(0xFFAAAAAA);
		g.drawRoundedRectangle(lr, 3.0, 1.0);
		g.setColour(0xDDFFFFFF);
		g.drawAlignedText(obj.hoverSourceName + ": " + obj.hoverText, lr.reduced(4, 0), "centred");
	}
}

// called for each modulation dragger to render the "knob" for the intensity
inline function drawModulationDragger(g, obj)
{
	local area = Rectangle(obj.area);
	local track = Content.createPath();
	local dragPath = Content.createPath();
	local start;
	local end;
	
	switch(obj.mode)
	{
		case 0:
			start = -ARC;
			end = -ARC + 2.0 * ARC * obj.value;
			break;
		case 1:
			start = 0;
			end = ARC * obj.value;
			break;
		case 2:
			end = ARC * obj.value;
			start = - 1.0 * end;
			break;
	}
	
	dragPath.setBounds(area);
	track.setBounds(area);
	
	g.setColour(0xFF282828);
	g.fillEllipse(area);
	g.setColour(0xFFAAAAAA);
	g.drawEllipse(area, 1.0);
		
	dragPath.addArc(area.reduced(4), start, end);
	track.addArc(area.reduced(4), -ARC, ARC);
	g.setColour(obj.hover ? 0x22ffffff : 0x11ffffff);
	g.fillPath(track.createStrokedPath(5.0, ""), area);
	g.setColour(Colours.withMultipliedAlpha(obj.itemColour, obj.clicked ? 1.0 : 0.8));
	g.fillPath(dragPath.createStrokedPath(5.0, ""), area);
}

const var DRAG_SIZE = 36;

// calculate the positioning of the mod draggers as well as the value label)
inline function getModulatorDragData(obj)
{
	local totalWidth = obj.connections.length * (DRAG_SIZE + 4);
	totalWidth += 140;
	
	local x = Rectangle(obj.sliderBounds[0], obj.sliderBounds[1] + obj.sliderBounds[3], totalWidth, DRAG_SIZE);
	x = x.constrainedWithin(obj.parentBounds);
	
	for(s in obj.connections)
		obj.dragAreas.push(x.removeFromLeft(DRAG_SIZE).reduced(2));
	
	x.removeFromLeft(10);
	
	obj.labelArea = x;
	return obj;
}

knobLaf.registerFunction("drawRotarySlider", drawModSlider);
knobLaf.registerFunction("drawModulationDragBackground", drawModulationDragBackground);
knobLaf.registerFunction("getModulatorDragData", getModulatorDragData);
knobLaf.registerFunction("drawModulationDragger", drawModulationDragger);

const var UI_KNOBS = [Content.getComponent("Reverb"),
                      Content.getComponent("Pitch"),
                      Content.getComponent("Gain")];

for(k in UI_KNOBS)
	k.setLocalLookAndFeel(knobLaf);