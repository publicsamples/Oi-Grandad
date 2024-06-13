//RR


const var Enable = Content.getComponent("Enable");


const var filters = [Synth.getMidiProcessor("Filter1"),
                     Synth.getMidiProcessor("Filter2"),
                     Synth.getMidiProcessor("Filter3"),
                     Synth.getMidiProcessor("Filter4")];
                     
const var RrLed = [Content.getComponent("RrLed1"),
                   Content.getComponent("RrLed"),
                   Content.getComponent("RrLed3"),
                   Content.getComponent("RrLed4")];
      

/** This is a data structure that can be used for
    storing any kind of information with the event
    ID as hash key.
    
    In order to use it, pass an array into the 
    init() function, then use the functions 
    
    push() and pop() to add or return values
    using the event ID as hash key.
    
    For performance reasons, it will not sort entries
    but just pick the first idle slot when you push new
    data.
*/
namespace EventIdStack
{
    // Should be enough, but you can add more if you want...
    const var MAX_SIZE = 128;
    
    /** Call this function to initialise the data
        array with the internal data structure.
    */
    inline function init(data)
    {
        data.reserve(MAX_SIZE);
        
        for(i = 0; i < MAX_SIZE; i++)
        {
            data[i] = [-1, undefined];
        }
    }
    
    /** This adds the given value to the data array
        using the event ID as hash key.
    */
    inline function push(data, eventId, value)
    {
        for(d in data)
        {
            if(d[0] == -1)
            {
                d[0] = eventId;
                d[1] = value;
                return;
            }
        }
        
        // Full...
        Console.assertTrue(false);
    }
    
    /** Returns the value for the given eventID and
        removes the data from the slot. 
    */
    inline function pop(data, eventId)
    {
        for(d in data)
        {
            if(d[0] == eventId)
            {
                d[0] = -1;
                return d[1];
            }
        }
        
        // Can't find it...
        Console.assertTrue(false);
    }
}


// We need to store the MIDI channels for each note number
const var noteOnChannels = [];

// Let's use that fancy data structure for our problem...
EventIdStack.init(noteOnChannels);

// the RR counter
reg rrIndex = 0;