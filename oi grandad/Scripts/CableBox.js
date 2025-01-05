/** CableBox Component
*    by Christoph Hart
*
*    A component with source & destination connections and the ability to create cables
*    by dragging.
*/

namespace CableBox
{
/** Adds a new CableBox. */
    inline function create(name, x, y)
    {
        local widget = Content.addPanel(name, x, y);
    
        Content.setPropertiesFromJSON(name, {
        "width": 180,
        "height": 180,
        "allowCallbacks": "Clicks, Hover & Dragging",
        "saveInPreset": true
        });
    
        widget.data.connections = [];
        widget.data.fadeOutAlpha = 1.0;
        widget.data.fadeOutCable = undefined;
        
        widget.setPaintRoutine(function(g)
        {
            g.fillAll(Colours.black);
        
            for(inputBox in this.data.inputBoxes)
            {
                g.setColour(inputBox == this.data.currentDragBox ? 0x44FFFFFF : 0x22FFFFFF);
                g.fillRoundedRectangle(inputBox, 6.0);
                g.setColour(inputBox == this.data.currentDragBox ? 0xFFFFFFFF : 0x88FFFFFF);
                g.drawRoundedRectangle(inputBox, 6.0, 1);
            }
        
            for(outputBox in this.data.outputBoxes)
            {
                g.setColour(0x22FFFFFF);
                g.fillRoundedRectangle(outputBox, 6.0);
                g.setColour(0x88FFFFFF);
                g.drawRoundedRectangle(outputBox, 6.0, 1);
            }
        
            if(this.data.currentDragPosition.length)
            {
                g.setColour(Colours.white);
            
                var start = getCenter(this.data.currentDragBox);
                var end = this.data.currentDragPosition;
            
                drawCable(g, start, end);
            }
        
            for(connection in this.data.connections)
            {
            
                g.setColour(0x88FFFFFF);
                drawCable(g, getCenter(this.data.inputBoxes[connection[0]]), 
                            getCenter(this.data.outputBoxes[connection[1]]) );
            
            }
            
            if(this.data.fadeOutCable)
            {
                g.setColour(Colours.withAlpha(Colours.white, this.data.fadeOutAlpha));
                g.drawPath(this.data.fadeOutCable, -1, 2.0);
            }
        });
    
    
        widget.setMouseCallback(function(event)
        {
            if(event.clicked)
            {
                for(inputBox in this.data.inputBoxes)
                {
                    if(contains([event.x, event.y], inputBox))
                    {
                        this.data.currentDragBox = inputBox;
                        this.repaint();
                        return;
                    }
                }
                for(outputBox in this.data.outputBoxes)
                {
                    if(contains([event.x, event.y], outputBox))
                    {
                        var index = this.data.outputBoxes.indexOf(outputBox);
                    
                        for(connection in this.data.connections)
                        {
                            if(connection[1] == index)
                            {
                                this.data.currentDragBox = this.data.inputBoxes[connection[0]];
                                this.data.connections.remove(connection);
                                this.repaint();
                                this.setValue(this.data.connections);
                                this.changed();
                            
                                return;
                            }
                        }
                    }
                }
            
                return;
            }
            if(event.mouseUp)
            {
                for(outputBox in this.data.outputBoxes)
                {
                    if(contains([event.x, event.y], outputBox))
                    {
                        this.data.currentDragTarget = ouputBox;
                    
                        var start = this.data.inputBoxes.indexOf(this.data.currentDragBox);
                        var end = this.data.outputBoxes.indexOf(outputBox);
                        var connection = [start, end];
                    
                        this.data.connections.insert(-1, connection);
                        this.setValue(this.data.connections);
                        this.changed();
                    }
                }
                
                if(this.data.currentDragBox)
                {
                    this.data.fadeOutCable = CableBox.createCable(CableBox.getCenter(this.data.currentDragBox), [event.x, event.y]);
                    this.data.currentDragBox = undefined;
                    this.data.currentDragPosition = -1;
                
                    this.data.fadeOutAlpha = 1.0;
                    this.startTimer(30);
                
                }
            
                
                this.repaint();
                return;
            }
            if(event.drag)
            {
                if(this.data.currentDragBox)
                {
                    this.data.currentDragPosition = [event.x, event.y];
                    this.repaint();    
                }
            }
        });
        
        widget.setTimerCallback(function()
        {
            this.data.fadeOutAlpha -= 0.2;
            
            if(this.data.fadeOutAlpha <= 0.0)
            {
                this.data.fadeOutCable = undefined;
                this.stopTimer();
            }
                
            this.repaint();
        });
        
        return widget;
    };
    
    const var INPUT = 1;
    const var OUTPUT = 0;
    
    /** Sets the amount of boxes for the given CableBox. */
    inline function setNumBoxes(box, boxAmount, isInput)
    {
        local boxes = [];
    
        if(isInput)
        {
            box.data.numInputs = boxAmount;
            box.data.inputBoxes = boxes;    
        }
        else
        {
            box.data.numOutputs = boxAmount;
            box.data.outputBoxes = boxes;    
        }
    
        local heightPerBox = (box.getHeight()-20) / boxAmount;
    
        for(i = 0; i < boxAmount; i++)
        {
            local y = i * heightPerBox;
            boxes[i] = [(isInput ? 10 : box.getWidth() - 40), 10 + y, 15, 15];
        }    
    };

    /** Call this function in the onControl callback to update the graphics. */
    inline function updateCableBox(box)
    {
        box.data.connections = value;
        box.repaint();
    }
    


    /** Helper function that checks if the given point is in the rectangle. */
    inline function contains(point, area)
    {
        return point[0] > area[0] && point[0] < area[0] + area[2] &&
            point[1] > area[1] && point[1] < area[1] + area[3];
    }

    /** Returns the center point of the rectangle. */
    inline function getCenter(area)
    {
        return [area[0] + 0.5*area[2], area[1] + 0.5*area[3]];
    }


    /** creates a cable with the given points. */
    inline function createCable(start, end)
    {
        local midY = Math.max(start[1], end[1]) + 30 + 150.0/(end[0]-start[0]);
        local midX = start[0] + (end[0] - start[0])/2;
        
        local p = Content.createPath();
    
    
    
        p.startNewSubPath(start[0], start[1]);
        
        p.quadraticTo(midX, midY, end[0], end[1]);
        
        return p;
    }
    
    /** Draws the cable. */
    inline function drawCable(g, start, end)
    {
        local p = createCable(start, end);
        
        g.drawPath(p, -1, 2.0);
    
        g.setColour(0x88FFFFFF);
        g.fillEllipse([start[0]-2, start[1]-2, 4, 4]);
        g.fillEllipse([end[0]-2, end[1]-2, 4, 4]);
    }

    
};