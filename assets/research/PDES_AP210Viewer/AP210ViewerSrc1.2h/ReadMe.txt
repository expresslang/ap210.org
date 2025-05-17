The AP210 Viewer Version 1.2h currently has a small set of limitations and
controls and an even smaller user manual shown below.

New Features since version 1.2g

    Implemented in View menu Primary and Secondary items.

    Added non-plated thru-holes.

    Added a usage view page for the interconnect module.
    This page includes all the thickness requirements

New Features since version 1.2f

    Added the capability to view component restriction assignment areas.
    This capability is accessed in the view menu.

    Added a message box to display the parsing errors when parsing an
    IDF fileset.

    Added support for the DIS and IS mapping of "located interconnnect module thickness".
    The DIS mapping is required until the ITI translator is updated.

New Features since version 1.2e:
    
    Fixes an error that when the surface of a component was
    changed and the file saved and redisplayed a 180 degree
    rotation was added.  Also if this is the only change
    and the file is closed you are now prompted to save the file. 

    Displays mechanical parts and list there physical_units
    in the tree view.

    Changed select to select the item on "top".

    Added transparency switch to board to make it transparent.
    Note a 1999 version of opengl32.ddl doesn't handle the
    transparency correctly.  This problem has only been observed
    on Windows 98.

    Reads part21 files with schema version information, such as
    those found in annexk of AP210.

    Added the ability to read files using shortnames.

New Features since version 1.2d:

    Updated to use latest version of IDF translator that corrects problems
    with cartesian_transformation_operator_2d axis1 and axis2.
		
    Components can be placed and unplaced with the changes saved in AP210.

    IDF import is readonly.  The file can be saved as AP210 but not modified.

New Features since version 1.1:

    The component_locations from AP210 files from the IDF translator
    are repaired. axis2 is populated and a mirror about the
    Y axis is applied to components on the secondary surface.
   
    IDF files are now imported rather than opened.

    An "Open Read Only" mode has been added.

    Unplaced components are listed in the the Unplaced sub folder
    in the Assembly folder.

    Reads files from the ITI AP210 Translator Version 1.2.

    Added Uninstall AP210Viewer program folder item.

    Double clicking the right mouse button on a single component will
    display a dialog box reporting information about the component.

    The tree view now shows the Assembly, Packaged Parts and Packages.
    Double clicking the right mouse buttion will report information on all
    of these.  With the exception of the PWB in the assembly.  The list
    of properties are the requirements_properties associated with the
    selected item.

    The "placement fixed" descriptive_representation_item of a
    packaged_component can be changed.  If one is changed the
    user will be asked if they which to save the design when they
    close it.  If the placement isn't fixed you can edit the
    location, rotation and surface of the component and it will
    move when the APPLY or OK button are hit.  These changes can
    be saved.

    You can edit the height of a package and the thickness of the
    interconnect module.

    Find_Item_Number has been added to the component and packaged_parts
    property sheets to explore the use of the data, it is calculated
    by the viewer and NOT saved to the AP210 file.

Limitations:
   The Viewer has been run on Win95, Win 98 and NT.  64 Meg is the minimum
   amount of memory recommended, 128 Meg is desirable.  Run time errors have
   occurred on a machine with 32 Meg of memory.

   You can't print from the application, a limitation of the Windows OpenGL 
   Implementation.  It may be possible to print in the future but it is a 
   low priority, see Image Capture below if you need to print.

   Not all the features work with IDF files. The best thing to do with an
   IDF file is to save it as an AP210 file and view that.  The IDF viewing
   capability will be gone in the future after the ability to view the 
   mechanical parts in AP210 is added. 

Features:
   Drag and Drop: You can drag an AP210 file with a .stp or .p21 extension 
                  into the view and it will be viewed.  This also works for
                  IDF files with a .IDF extension, but a corresponding IDF
                  library file with a .lib extension must be present.

Controls:
   In addition to the standard Windows application controls the PWA can be
   manipulated in the display.

   Viewing this file:  You can view this file using the "View Readme.txt"
                       item in the Help menu.  It is a little rough, the
                       DOS window shouldn't have to come up before the
                       notepad does.  There is also an item in the EMPilot
                       Folder.

   New Window: Under the windows menu select the "new window" item to 
               create a duplicate of the window.

   Selection: Double clicking the left mouse button will select all the 
              graphics under the cursor and they will be highlighted.
              The selected graphics will be highlighted in each graphics
              window that the PWA is displayed in. The reference designators
              and part numbers of components are the selected items are
              displayed in the lower right corner of the graphics windows.

              You can also select items in the tree view and they will be 
              highlighted.

              If you have more than one window open for a design (you used
              the new window) the selections in all the windows.

      Note: Some mechanism to cycle through the selected graphics needs to
            be implemented. Another approach since I get the Min and Max Z
            coordinates of the selected items would be to select the item
            on "top".

   Reporting: Double clicking the right mouse button on a single component
              will display a dialog box reporting information about the
			  component.

	          The tree view now shows the Assembly, Packaged Parts and Packages.
	          Double clicking the right mouse button will report information
			  on all of these.  With the exception of the PWB in the assembly.
			  The list of properties are the requirements_properties associated
			  with the selected item.

   Zooming: '+' and '-' keys and the mouse wheel if available. The 
            "+' and '-' keys provide a finer level of zooming.

      Note: The zooming moves the eye along the Z axis if you 
            zoom through the PWA the eye turns towards the PWA
            but the direction of movement along the Z-axis doesn't
            change. In other words initially the '-' key zooms
            towards the PWA then away from the PWA after you go
            through it.

   Scrolling: The 4 scrolls left, 6 right, 8 up and 2 down. If you 
              have the Num Lock on it will be noted in the lower
              right hand corner of the Viewer, the arrow keys on the
              keypad will then function for scrolling.

   Rotation: To rotate the PWA select a point on the display and 
             depress the left mouse button and drag the mouse.

   Image Capture: To capture an image from the application the current
                  approach is to use <Alt> Print Screen, which places
                  the entire Viewer window into the clipboard.  You can
                  then paste this into another application for use.

   Reading Files: You can read files with the following extensions:
        1) *.brd with a *.lib, an IDF file.
        2) *.idfstp a step equivalent IDF file (schema: IDF_V2)
        3) *.stp, *.p21, *.step, *.pdes and *.210 AP210 files

   Saving IDF files: You can save an IDF file in the following formats:
      1) Standard IDF format (*.brd and *.lib),
      2) IDF equivalent STEP file (*.idfstp these files when load behave 
         exactly like an IDF file),
      3) AP210 ARM file (*.ap210arm), and
      4) AP210 AIM file (*.210)

   Saving AP210 files:  You can save AP210 files using the following extensions
                        *.stp, *.p21, *.step, *.pdes, *.210.  The content of 
                        all the files are the same.

   Unstalling: You can uninstall the viewer by using the "Uninstall AP210Viewer"
               In the program folder.

Registry Entries:
   Here are the current registry entires used by the viewer with some typical values.

   HKEY_CURRENT_USER
      Software
	     EMPilot
		    AP210Viewer
			   Recent File List
			      File1                 "C:\Program Files\EMPilot\Examples\cable_db.stp"
				  File2                 "C:\Program Files\EMPilot\Examples\flasher.stp"
				  File3                 "C:\Program Files\EMPilot\Examples\mech.brd"
               Settings

   HKEY_LOCAL_MACHINE
      Software
	     EMPilot
		    AP210Viewer
			   1.1
			       AP210_VIEWER_HOME    "C:\Program Files\EMPilot"
				   AP210ARMtoAP210AIM   "ap210dis_299_40_to_aim_EXPX"
				   IDFToAP210ARM        "idf_v2_to_ap210dis_299_40_EXPX"
				   ROSE_DB              "C:\Program Files\EMPilot\Schemas"




