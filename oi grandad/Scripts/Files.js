const var File1 = Synth.getAudioSampleProcessor("gran");
const var File2 = Synth.getAudioSampleProcessor("gran2");
const var File3 = Synth.getAudioSampleProcessor("gran3");
const var File4 = Synth.getAudioSampleProcessor("gran4");

const slot1 = File1.getAudioFile(0);
const slot2 = File2.getAudioFile(0);
const slot3 = File3.getAudioFile(0);
const slot4 = File4.getAudioFile(0);

const var FileSelect1 = Content.getComponent("FileSelect1");
const var FileSelect2 = Content.getComponent("FileSelect2");
const var FileSelect3 = Content.getComponent("FileSelect3");
const var FileSelect4 = Content.getComponent("FileSelect4");

const var FolderLabel = Content.getComponent("FolderLabel");
const var FolderLabel1 = Content.getComponent("FolderLabel1");
const var FolderLabel2 = Content.getComponent("FolderLabel2");
const var FolderLabel3 = Content.getComponent("FolderLabel3");

const var FileSelectFront1 = Content.getComponent("FileSelectFront1");
const var FileSelectFront2 = Content.getComponent("FileSelectFront2");
const var FileSelectFront3 = Content.getComponent("FileSelectFront3");
const var FileSelectFront4 = Content.getComponent("FileSelectFront4");

const var Analysis1 = Synth.getAudioSampleProcessor("Analysis1");
const var Analysis2 = Synth.getAudioSampleProcessor("Analysis2");
const var Analysis3 = Synth.getAudioSampleProcessor("Analysis3");
const var Analysis4 = Synth.getAudioSampleProcessor("Analysis4");

const slotA1 = Analysis1.getAudioFile(0);
const slotA2 = Analysis2.getAudioFile(0);
const slotA3 = Analysis3.getAudioFile(0);
const slotA4 = Analysis4.getAudioFile(0);

const var FileSelectMac1 = Content.getComponent("FileSelectMac1");
const var FileSelectMac2 = Content.getComponent("FileSelectMac2");
const var FileSelectMac3 = Content.getComponent("FileSelectMac3");
const var FileSelectMac4 = Content.getComponent("FileSelectMac4");


//Store folder path

const Folder = [];
const Folder2 = [];
const Folder3 = [];
const Folder4 = [];

// Choose a folder to load samples from. 

inline function onFolderSelectControl(component, value) {

//Select a folder

if(value == 1)
    

    FileSystem.browseForDirectory(FileSystem.AudioFiles, function(folder) {
        if (isDefined(folder) && folder.isDirectory()) {
         
         //find files in selected folder
         
            var folderArray = FileSystem.findFiles(folder, "*.wav, *.aif", false);

            for (file in folderArray) {
                file = file.toString(0);
                
            var folderArray2 = FileSystem.findFiles(folder, "*.wav, *.aif", false);
                                 
             for (file1 in folderArray2) {
              file1 = file1.toString(3);          
                
         //Populate the Folder Label
              
                FolderLabel.set("text", folder.toString(0));
                Folder.push(folder);
                
            };
            
            //send items to hidden ComboBox
            
            FileSelect1.set("items", folderArray.join("\n"));
            FileSelectFront1.set("items", folderArray2.join("\n"));
			FileSelectMac1.set("items", folderArray2.join("\n"));
            
            
           } 

}
        
    });
};

Content.getComponent("FolderSelect").setControlCallback(onFolderSelectControl);


//Loads the samples


inline function onFileSelectFront1Control(component, value)
{
     Engine.allNotesOff();
         	Record.setValue(0);
         	Record.changed();
         	Hold.setValue(0);
         	Hold.changed();
         	
	 FileSelect1.setValue(value);
     FileSelect1.changed();
     FileSelectMac1.setValue(value);
    
};

Content.getComponent("FileSelectFront1").setControlCallback(onFileSelectFront1Control);


inline function onFileSelectMac1Control(component, value)
{
	 Engine.allNotesOff();
         	Record.setValue(0);
         	Record.changed();
         	Hold.setValue(0);
         	Hold.changed();
         	
	 FileSelect1.setValue(value);
     FileSelect1.changed();
     FileSelectFront1.setValue(value);
};

Content.getComponent("FileSelectMac1").setControlCallback(onFileSelectMac1Control);


inline function onFileSelect1Control(component, value) {

    slot1.loadFile(FileSelect1.get("items").split("\n")[value - 1]);
    slotA1.loadFile(FileSelect1.get("items").split("\n")[value - 1]);
};

Content.getComponent("FileSelect1").setControlCallback(onFileSelect1Control);

inline function onFolderSelect1Control(component, value) {

//Select a folder

if(value == 1)
    

    FileSystem.browseForDirectory(FileSystem.AudioFiles, function(folder) {
        if (isDefined(folder) && folder.isDirectory()) {
         
         //find files in selected folder
         
            var folderArray = FileSystem.findFiles(folder, "*.wav, *.aif", false);

            for (file in folderArray) {
                file = file.toString(0);
                
            var folderArray2 = FileSystem.findFiles(folder, "*.wav, *.aif", false);
                                 
             for (File2 in folderArray2) {
              File2 = File2.toString(3);          
                
         //Populate the Folder Label
              
                FolderLabel1.set("text", folder.toString(0));
                Folder2.push(folder);
                
            };
            
            //send items to hidden ComboBox
            
            FileSelect2.set("items", folderArray.join("\n"));
            FileSelectFront2.set("items", folderArray2.join("\n"));
            FileSelectMac2.set("items", folderArray2.join("\n"));
           } 

}
        
    });
};

Content.getComponent("FolderSelect1").setControlCallback(onFolderSelect1Control);


//Loads the samples


inline function onFileSelectFront2Control(component, value)
{
	Engine.allNotesOff();
	    	Record.setValue(0);
	    	Record.changed();
	    	Hold.setValue(0);
	    	Hold.changed();

	 FileSelect2.setValue(value);
     FileSelect2.changed();
     FileSelectMac2.setValue(value);
};

Content.getComponent("FileSelectFront2").setControlCallback(onFileSelectFront2Control);


inline function onFileSelectMac2Control(component, value)
{
	Engine.allNotesOff();
	    	Record.setValue(0);
	    	Record.changed();
	    	Hold.setValue(0);
	    	Hold.changed();

	 FileSelect2.setValue(value);
     FileSelect2.changed();
     FileSelectFront2.setValue(value);
};

Content.getComponent("FileSelectMac2").setControlCallback(onFileSelectMac2Control);


inline function onFileSelect2Control(component, value) {

    slot2.loadFile(FileSelect2.get("items").split("\n")[value - 1]);
    slotA2.loadFile(FileSelect2.get("items").split("\n")[value - 1]);
};

Content.getComponent("FileSelect2").setControlCallback(onFileSelect2Control);

inline function onFolderSelect2Control(component, value) {

//Select a folder

if(value == 1)
    

    FileSystem.browseForDirectory(FileSystem.AudioFiles, function(folder) {
        if (isDefined(folder) && folder.isDirectory()) {
         
         //find files in selected folder
         
            var folderArray = FileSystem.findFiles(folder, "*.wav, *.aif", false);

            for (file in folderArray) {
                file = file.toString(0);
                
            var folderArray2 = FileSystem.findFiles(folder, "*.wav, *.aif", false);
                                 
             for (File2 in folderArray2) {
              File2 = File2.toString(3);          
                
         //Populate the Folder Label
              
                FolderLabel2.set("text", folder.toString(0));
                Folder3.push(folder);
                
            };
            
            //send items to hidden ComboBox
            
            FileSelect3.set("items", folderArray.join("\n"));
            FileSelectFront3.set("items", folderArray2.join("\n"));
            FileSelectMac3.set("items", folderArray2.join("\n"));
           } 

}
        
    });
};

Content.getComponent("FolderSelect2").setControlCallback(onFolderSelect2Control);


//Loads the samples


inline function onFileSelectFront3Control(component, value)
{
	Engine.allNotesOff();
	    	Record.setValue(0);
	    	Record.changed();
	    	Hold.setValue(0);
	    	Hold.changed();

	 FileSelect3.setValue(value);
     FileSelect3.changed();
     FileSelectMac3.setValue(value);
};

Content.getComponent("FileSelectFront3").setControlCallback(onFileSelectFront3Control);




inline function onFileSelect3Control(component, value) {

    slot3.loadFile(FileSelect3.get("items").split("\n")[value - 1]);
    slotA3.loadFile(FileSelect3.get("items").split("\n")[value - 1]);
};

Content.getComponent("FileSelect3").setControlCallback(onFileSelect3Control);




inline function onFileSelectMac3Control(component, value)
{
	Engine.allNotesOff();
	    	Record.setValue(0);
	    	Record.changed();
	    	Hold.setValue(0);
	    	Hold.changed();

	 FileSelect3.setValue(value);
     FileSelect3.changed();
     FileSelectMac3.setValue(value);
};

Content.getComponent("FileSelectMac3").setControlCallback(onFileSelectMac3Control);

inline function onFolderSelect3Control(component, value) {

//Select a folder

if(value == 1)
    

    FileSystem.browseForDirectory(FileSystem.AudioFiles, function(folder) {
        if (isDefined(folder) && folder.isDirectory()) {
         
         //find files in selected folder
         
            var folderArray = FileSystem.findFiles(folder, "*.wav, *.aif", false);

            for (file in folderArray) {
                file = file.toString(0);
                
            var folderArray2 = FileSystem.findFiles(folder, "*.wav, *.aif", false);
                                 
             for (File2 in folderArray2) {
              File2 = File2.toString(3);          
                
         //Populate the Folder Label
              
                FolderLabel3.set("text", folder.toString(0));
                Folder4.push(folder);
                
            };
            
            //send items to hidden ComboBox
            
            FileSelect4.set("items", folderArray.join("\n"));
            FileSelectFront4.set("items", folderArray2.join("\n"));
            FileSelectMac4.set("items", folderArray2.join("\n"));
           } 

}
        
    });
};

Content.getComponent("FolderSelect3").setControlCallback(onFolderSelect3Control);


//Loads the samples


inline function onFileSelect4Control(component, value) {

    slot4.loadFile(FileSelect4.get("items").split("\n")[value - 1]);
    slotA4.loadFile(FileSelect4.get("items").split("\n")[value - 1]);
};

Content.getComponent("FileSelect4").setControlCallback(onFileSelect4Control);


inline function onFileSelectFront4Control(component, value)
{
	Engine.allNotesOff();
	    	Record.setValue(0);
	    	Record.changed();
	    	Hold.setValue(0);
	    	Hold.changed();

	 FileSelect4.setValue(value);
     FileSelect4.changed();
     FileSelectMac4.setValue(value);
};

Content.getComponent("FileSelectFront4").setControlCallback(onFileSelectFront4Control);


inline function onFileSelectMac4Control(component, value)
{
		Engine.allNotesOff();
	    	Record.setValue(0);
	    	Record.changed();
	    	Hold.setValue(0);
	    	Hold.changed();

	 FileSelect4.setValue(value);
     FileSelect4.changed();
     FileSelectFront4.setValue(value);
};

Content.getComponent("FileSelectMac4").setControlCallback(onFileSelectMac4Control);



