**INFO:**

    Application Name: android-toolkit 
    
    Version: Alpha 0.5.3.2
    
    Release Date:

**NOTES:**

    SCRCPY - If you wish for SCRCPY capabilities, you must compile the source code and obtain the SCRCPY files yourself. 
    To do this, retrieve the files at 'https://github.com/Genymobile/scrcpy/releases' and extract the files, not the folder, 
    to the SCRCPY link folder in the projects root folder before compiling.

    Compile - If you wish to compile android-toolkit, either run the 'compile.sh' file, or if you wish for debug settings, 
    in your terminal run './usr/bin/compile.AppImage ./ &&  chmod +x *.AppImage' while in the source code directory.

    Run android-toolkit - To run an AppImage of android-toolkit, open the file in your linux devices terminal.

**SOURCES:**

    SCRCPY - https://github.com/Genymobile/scrcpy/releases

    AppImageTool - https://github.com/AppImage/appimagetool

    Yet Another Dialog - https://github.com/v1cont/yad

    ADB - https://developer.android.com/tools/adb

**INSTALLATION**

    curl - 

**RELEASE NOTES:**

    - indexGUI.sh

        - Made install accessable through the GUI

        - Made version number a variable

        - Added file manager #Currently Developing#

        - Changed yad and adb files to only run from local.

    - compile.sh

        - Moved this file into ./usr/src/ and accessable through the GUI

        - Made compiler automatically include version name in appimage

        - Allowed selection of architype version

    - install

        - added gui sudo prompt

**DEPRECATED FILES:**

    - As of Beta 0.3.4, index.sh is deprecated

**CONTRIBUTORS:**

    - Atlas D Junifer
    
        - Github: AtlasJ2301

**DEVELOPMENT RULES:**

    - AI USAGE:

        - AI is only to be used to help with coding,
        not to code for you. It is okay to use LLM's
        to understand a concept while developing, 
        as long as it doesn't have direct contribution 
        to a project by itself.

        - Using AI to learn an aspect of coding in
        general is ok and permitted, as you, the
        developer, are still actually comprehending
        the information yourself.
