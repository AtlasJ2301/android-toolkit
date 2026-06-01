#include "config.h"

// To compile this, from the android toolkit root folder, run "g++ ./src/install.cpp -o ./install"

bool isDebug;

int main(int argc, char* argv[]) {
    clear();
    setTextColor("green");
    boldText("Android Toolkit - Install\n\n" + androidToolkitAsciiHeader + "Installing Android Toolkit " + version);
    
    int i = 1;

    while (i < argc) {
        if (std::string(argv[i]) == "-d") {
            isDebug = true;
        } if (std::string(argv[i]) == "-s") {
            isScrcpy = true;
        } if (std::string(argv[i]) == "-u") {
            isUpdate = true;
        } if (std::string(argv[i]) == "--use-system-adb") {
            isUseSystemAdb = true;
        } if (std::string(argv[i]) == "-r") {
            isRemove = true;
        } if (std::string(argv[i]) == "--help") {
            isHelp = true;
        } if (std::string(argv[i]) == "--remove-scrcpy") {
            isRemoveScrcpy = true;
        }

        i++;
    }

    if (isHelp == true) {
        std::cout << "\nUsed to install android-toolkit to the system.\n\nAndroid Toolkit: An easy to use ADB interface\n\nUsage:\n\n-d                  Compile as developer\n  --help            Displays this page\n-r                  Uninstall android-toolkit from device\n  --remove-scrcpy   Removes cached SCRCPY download\n-s                  Prompts for the addition of SCRCPY.\n-u                  Update android-toolkit from github.\n";
    
        return 0;
    }

    if (isRemove == true) {
        boldText("Android Toolkit - Uninstall\n\n");
        std::filesystem::remove_all(home + "/.android-toolkit/");
        std::filesystem::remove_all(home + "/.local/share/applications/android-toolkit.desktop");
        system("bash -c 'if [[ -f /usr/bin/android-toolkit ]]; then sudo rm /usr/bin/android-toolkit; fi'");

        return 0;
    }

    if (isUpdate == true) {
        system("git init && git pull https://github.com/AtlasJ2301/android-toolkit");

        return 0;
    }

    if (isRemoveScrcpy == true) {
        std::filesystem::remove_all("./libs/SCRCPY/");

        return 0;
    }

    if (isScrcpy == true && !std::filesystem::exists("./libs/SCRCPY/")) {
        system("mkdir ./libs/SCRCPY/ && wget https://github.com/Genymobile/scrcpy/releases/download/v4.0/scrcpy-linux-x86_64-v4.0.tar.gz && tar -xvf scrcpy-linux-*.tar.gz && mv ./scrcpy-linux-*/* ./libs/SCRCPY/ && rm -rf ./scrcpy*");
    }

    mkdir(home + "/.android-toolkit/", true);

    std::ofstream conditions(home + "/.android-toolkit/conditions");

    if (isDebug == true) {
        conditions << "isDebug";
        std::cout << "\n\nDebug Mode\n\n";
    }

    mkdir("./build", true);

    system("cd ./build/; cmake ../; make");

    std::filesystem::copy("./README.md", home + "/.android-toolkit/README.md");
    std::filesystem::copy("./libs/", home + "/.android-toolkit/libs/");
    std::filesystem::copy("./icon.png", home + "/.android-toolkit/icon.png");
    std::filesystem::copy("./build/android-toolkit", home + "/.android-toolkit/android-toolkit");
    if (isScrcpy == true) {
        std::filesystem::copy("./libs/SCRCPY/", home + "/.android-toolkit/libs/SCRCPY/");
    }

    system("sudo cp -f ./libs/android-toolkit /usr/bin/android-toolkit");

    std::ofstream desktopFile(home + "/.android-toolkit/android-toolkit.desktop");
    desktopFile << "[Desktop Entry]\nName=Android Toolkit\nExec=bash -c 'gnome-terminal --geometry=115x48 -- /home/" + user + "/.android-toolkit/android-toolkit'\nType=Application\nIcon=/home/" + user + "/.android-toolkit/icon.png\nComment=An Easy to use ADB interface";
    desktopFile.close();

    copyOverwrite(home + "/.android-toolkit/android-toolkit.desktop", home + "/.local/share/applications/android-toolkit.desktop");

    std::filesystem::remove_all("./build/");

    conditions.close();

    system("gnome-terminal --geometry=115x48 -- android-toolkit");

    return 0;
}