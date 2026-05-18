# Welcome to Android Toolkit!

!(https://github.com/AtlasJ2301/android-toolkit/blob/main/icon.png?raw=true)

## INFO

- Application Name: android-toolkit 
- Version: Alpha v1.2.6
- Release Date: May 18, 2026

Supported Platforms
- Linux

## NOTES

If you wish for SCRCPY capabilities, you must compile the source code and obtain the SCRCPY files yourself. To do this, retrieve the files at 'https://github.com/Genymobile/scrcpy/releases' and extract the files, not the folder, to the SCRCPY link folder in the projects root folder before compiling.

## SOURCES

- [SCRCPY](https://github.com/Genymobile/scrcpy/releases)
- [ADB](https://developer.android.com/tools/adb)

## INSTALLATION

- install Simply run the install file in the projects root folder.
- For extra options,
- curl - !Work in Progress!

## RELEASE NOTES

**Switched from Bash to C++**

**main.cpp**
- SCRCPY: Added a menu instead of a sequence of questions for SCRCPY
- SCRCPY: Added option to enable always on top on boot
- SCRCPY: Added option to enable audio on both devices
- SCRCPY: Added option to display FPS
- SCRCPY: Added option to open app on start
- SCRCPY: Added way to save SCRCPY config !Work in Progress!
- General: Added all features from indexGUI.sh !Work in Progress!
- General: Added Pair over WIFI feature
- General: Added Disconnect ADB Wireless Device feature
- General: Added Restart ADB feature

**install**
- Added update from Github feature.

## DEPRECATED FILES

- As of Beta 0.3.4, index.sh is deprecated.
- As of Beta 1.0.0, indexGUI.sh and all accompanying files are deprecated.

## CONTRIBUTORS

- [Atlas Junifer](https://github.com/AtlasJ2301)

## BEGINNER HELP

> We all struggled with linux at some point, so here is the place for those people.

### INSTALLATION

> There are two methods to doing this. Curl, which is much easier, or manual, which though being harder, is still easy. We'll start with curl.

#### Curl

If you do not have curl installed, run this command:
    sudo apt install curl

- sudo: Run as superuser (Lets command be ran with root access).
- apt: A place to install linux packages from.

From here it is as easy as running a single command:
    curl -fs https://raw.githubusercontent.com/AtlasJ2301/android-toolkit/refs/heads/main/libs/bash.sh | bash -s -- curl

From here, it will ask for your password, and then Hooray! You now have Android Toolkit installed to your system!

To run it, you can either open it from the start menu (Super / Windows Button) or by typing this command:
    android-toolkit

If you need help, type this command:
    android-toolkit --help

#### Manual Install

**Locating the Folder**

> Generally, you should keep downloads somewhere in your home folder unless you use something like a separate hard drive, but for this demonstration I will show you how to set it up in the Downloads folder.

Open a terminal (CTRL + ALT + T).

Where do you want to download it? If you want something like your downloads file, you would run the command:
    cd /home/$USER/Downloads

- cd: Change Directory (Folder).
- /home/$USER/Downloads: The path to change directory to to.

> You actually do not have to change the $USER part, as the system will recognize it as a variable, however it is still good practice to fully type your username.

**Installing from Github**

From here, you will want to pull the files from github.

If you do not have git installed, run this command:
    sudo apt install git

> To copy and paste from and to a terminal, instead of just using CTRL + C or CTRL + V, you have to use CTRL + SHIFT + C and CTRL + SHIFT + V.

- git: The package to interact with Git and Github from a computer.

To pull the github files, run this command:
    git clone https://github.com/AtlasJ2301/android-toolkit

**Installing to your System**

Next you will want to install android-toolkit to your system. To do this, simply run the install file. Open the file in the same terminal by using this command:
    ./install

- ./: Open a file in a relative directory.
- install: This is the file to be opened.

> For more help with the install file, run './install --help'

> This '--help' rule applies to the vast majority of things on linux, more specifically, packages.

From here, it will ask for your password, and then Hooray! You now have Android Toolkit installed to your system!

To run it, you can either open it from the start menu (Super / Windows Button) or by typing this command:
    android-toolkit

If you need help, type this command:
    android-toolkit --help

### UPDATING

**Running Install File**

Recall where you kept the download at. Change your directory via this command:
    cd /path/to/directory/

From here, all you have to do is open the install file with an argument:
    ./install -u

- -u: Update download from Github.

## DEVELOPMENT

**AI USAGE**

- AI is only to be used to help with coding, not to code for you. It is okay to use LLM's to understand a concept while developing, as long as it doesn't have direct contribution to a project by itself.

- Using AI to learn an aspect of coding in general is ok and permitted, as you, the developer, are still actually comprehending the information yourself.

**Work in Progress**

- add file manager

- finish C++ version

**Future Plans**

- Add curl support to download
    
- power menu
    
- add image support to file manager (xdg-open?)

- add detection and support for windows bash script
