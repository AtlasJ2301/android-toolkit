# 👋 Welcome to Android Toolkit!

![Android Toolkit Icon](./icon.png)

## ℹ️ INFO

- Application Name: android-toolkit 
- Version: Beta v1.7.28.b034
- Release Date: 

Supported Platforms
- Linux

## 🔗 SOURCES

- [SCRCPY](https://github.com/Genymobile/scrcpy/releases)
- [ADB](https://developer.android.com/tools/adb)

## 🛠️ INSTALLATION

- install Simply run the install file in the projects root folder. use ./install --help for options.
- Run these commands:

```bash
mkdir -p android-toolkit-release && cd ./android-toolkit-release && git init && git pull https://github.com/AtlasJ2301/android-toolkit && ./install -s
```

## 📋 RELEASE NOTES

**- Reformatted README.md**
**- Rewrote install in C++**
**- File Manager: Added Rename feature.**
**- Added Different Text Colors**
**- Added Error message for unavailable option on main menu**
**- Added a header for the main menu**
**- Made SCRCPY automatically pull and implement itself on install**
**- Replaced Curl command with sequence of other commands**
**- Added remove SCRCPY feature to installer**


## ⛓️‍💥 DEPRECATED FILES

- As of Beta 0.3.4, index.sh is deprecated.
- As of Beta 1.0.0, indexGUI.sh and all accompanying files are deprecated.

## 🤝 CONTRIBUTORS

- [Atlas Junifer](https://github.com/AtlasJ2301)

## 🛟 BEGINNER HELP

> We all struggled with linux at some point, so here is the place for those people.

### 🛠️ INSTALLATION

> There are two methods to doing this. A sequence of commands, which is much easier, or manual, which though being harder, is still easy. We'll start with curl.

#### SINGLE COMMAND

> To copy and paste from and to a terminal, instead of just using CTRL + C or CTRL + V, you have to use CTRL + SHIFT + C and CTRL + SHIFT + V.

It is as easy as running a single command:

```bash
mkdir -p android-toolkit-release && cd ./android-toolkit-release && git init && git pull https://github.com/AtlasJ2301/android-toolkit && ./install -s
```

From here, it will ask for your password, and then Hooray! You now have Android Toolkit installed to your system!

To run it, you can either open it from the start menu (Super / Windows Button) or by typing this command:

```bash
android-toolkit
```

If you need help, type this command:

```bash
android-toolkit --help
```

#### ⚙️ Manual Install

**Locating the Folder**

> Generally, you should keep downloads somewhere in your home folder unless you use something like a separate hard drive, but for this demonstration I will show you how to set it up in the Downloads folder.

Open a terminal (CTRL + ALT + T).

Where do you want to download it? If you want something like your downloads file, you would run the command:

```bash
cd /home/$USER/Downloads
```

- cd: Change Directory (Folder).
- /home/$USER/Downloads: The path to change directory to to.

> You actually do not have to change the $USER part, as the system will recognize it as a variable, however it is still good practice to fully type your username.

**Installing from Github**

From here, you will want to pull the files from github.

If you do not have git installed, run this command:

```bash
sudo apt install git
```

- git: The package to interact with Git and Github from a computer.

To pull the github files, run this command:

```bash
git clone https://github.com/AtlasJ2301/android-toolkit
```

**Installing to your System**

Next you will want to install android-toolkit to your system. To do this, simply run the install file. Open the file in the same terminal by using this command:

```bash
./install
```

- ./: Open a file in a relative directory.
- install: This is the file to be opened.

> For more help with the install file, run './install --help'

> This '--help' rule applies to the vast majority of things on linux, more specifically, packages.

From here, it will ask for your password, and then Hooray! You now have Android Toolkit installed to your system!

To run it, you can either open it from the start menu (Super / Windows Button) or by typing this command:

```bash
android-toolkit
```

If you need help, type this command:

```bash
android-toolkit --help
```

### 🔄 UPDATING

**Running Install File**

Recall where you kept the download at. Change your directory via this command:

```bash
cd /path/to/directory/
```

From here, all you have to do is open the install file with an argument:

```bash
./install -u
```

- -u: Update download from Github.

## 💻 DEVELOPMENT

**AI USAGE**

- AI is only to be used to help with coding, not to code for you. It is okay to use LLM's to understand a concept while developing, as long as it doesn't have direct contribution to a project by itself.

- Using AI to learn an aspect of coding in general is ok and permitted, as you, the developer, are still actually comprehending the information yourself.

**Work in Progress**

- add file manager

**Future Plans**

- add appimage support

- add detection and support for windows or OSX
