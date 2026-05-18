**INFO:**

    Application Name: android-toolkit 
    
    Version: Alpha 1.2.6
    
    Release Date:

**NOTES:**

    SCRCPY - If you wish for SCRCPY capabilities, you must compile the source code and obtain the SCRCPY files yourself. 
    To do this, retrieve the files at 'https://github.com/Genymobile/scrcpy/releases' and extract the files, not the folder, 
    to the SCRCPY link folder in the projects root folder before compiling.

**SOURCES:**

    SCRCPY - https://github.com/Genymobile/scrcpy/releases

    ADB - https://developer.android.com/tools/adb

**INSTALLATION**

    compile.sh - Simply run the install file in the projects root folder.

    curl - !Work in Progress!

**RELEASE NOTES:**

    - Switched from Bash to C++.

    - main.cpp
        - SCRCPY
            - Added a menu instead of a sequence of questions for SCRCPY
            - Added option to enable always on top on boot
            - Added option to enable audio on both devices
            - Added option to display FPS
            - Added option to open app on start
            - Added way to save SCRCPY config !Work in Progress!
        - Added all features from indexGUI.sh !Work in Progress!
        - Added Pair over WIFI feature
        - Added Disconnect ADB Wireless Device feature
        - Added Restart ADB feature

    - install
        - Added update from Github feature.

**DEPRECATED FILES:**

    - As of Beta 0.3.4, index.sh is deprecated.

    - As of 1.2.1 Release, indexGUI.sh and all accompanying files are deprecated.

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

**Work in Progress**

    - add file manager

**Future Plans**

    - finish C++ version

    - Add curl support to download
    
    - power menu
    
    - add image support to file manager

    - add detection and support for windows bash script