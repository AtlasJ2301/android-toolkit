#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <filesystem>

// Function Variables
std::string backup;
std::string path;
std::string port;
std::string ip;
std::string package;
std::string display;

// SCRCPY Variables
std::string dktp; // Desktop Mode
std::string uhms; // Uhid Mouse
std::string uhkb; // Uhid Keyboard
std::string fscr; // Fullscreen
std::string alot; // Always on Top
std::string dbau; // Double Audio
std::string dfps; // Display FPS
std::string applName; // Application to be opened
std::string appl; // Parsed argument
std::string kdpo; // Keep Display On
std::string kdfs; // Keep Display from Sleeping
std::string cscf; // Custom SCRCPY flag
std::string scrcpyConfig; // Contents of SCRCPY-config.txt

// Global Variables
std::string adb = "~/.android-toolkit/libs/adb ";
std::string cmd;
std::string file;
std::string input;
std::string null;
std::string home = getenv("HOME");
std::string user = getenv("USER");
std::string tmp;
std::string output;
std::string androidToolkitAsciiHeader = "   ___     ___   _   __    ____     __    __   __\n  /   \\   |   \\ | | |  \\  |   _|   /  \\  |  | |  \\ \n /  _  \\  | |\\ \\| | |   | |    \\  |    |  ||  |   |\n/__| |__\\ |_| \\___| |__/  |__|\\_\\  \\__/  |__| |__/\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n   _____    __     __    _     _  _  __   _____\n  |_   _|  /  \\   /  \\  | |   | |// |  | |_   _|\n    | |   |    | |    | | |_  |  \\   ||    | |\n    |_|    \\__/   \\__/  |___| |_|_\\ |__|   |_|\n\n";
std::string cmdPrefix;

// Conditions
std::string version = "Beta v1.9.28.b036";
bool isRemoveScrcpy;
bool isUseSystemAdb;
bool isSCRCPYImplemented;
bool isError;
bool isScrcpy;
bool isUpdate;
bool isRemove;
bool isHelp;

void adbFontFix() {
    std::cout << "\e[m\n";
}

void copyOverwrite(std::string copyOverwritePathFrom, std::string copyOverwritePathTo) {
    if (std::filesystem::exists(copyOverwritePathTo)) {
        std::filesystem::remove(copyOverwritePathTo);
    }
    std::filesystem::copy(copyOverwritePathFrom, copyOverwritePathTo);
}

void mkdir(std::string mkdirPath, bool overwrite) {
    if (std::filesystem::exists(mkdirPath) == false) {
        std::filesystem::create_directory(mkdirPath);
    } else if (overwrite == true) {
        std::filesystem::remove_all(mkdirPath);
        std::filesystem::create_directory(mkdirPath);

    } else {
        std::cerr << "\e[1mError: Folder already exists.\e[m";
    }
}

void clear() {
    std::cout << "\033[2J\033[1;1H";
}

void boldText(std::string boldTextInput) {
    std::cout << "\e[1m" + boldTextInput + "\e[m";
}

void setTextColor(std::string colorTextColor) {
    if (colorTextColor == "green") {
        std::cout << "\x1B[32m";
    } else if (colorTextColor == "clear") {
        std::cout << "\e[m";
    }
}