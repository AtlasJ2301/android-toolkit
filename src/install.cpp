#include "config.h"

bool isDebug;

int main() {
    clear();
    std::cout << "\e[1m" + androidToolkitAsciiHeader << "Installing Android Toolkit " + version;
    std::ifstream var("tmp");
    while (std::getline(var, output)) {
        if (output == "-d") {
            isDebug = true;
        } if (output == "-s") {
            isScrcpy = true;
        } if (output == "-u") {
            isUpdate = true;
        } if (output == "-r") {
            isRemove = true;
        } if (output == "--help") {
            isHelp = true;
        } if (output == "--remove-scrcpy") {
            isRemoveScrcpy = true;
        }
    }
    
    std::remove("tmp");

    if (isHelp == true) {
        std::cout << "\nUsed to install android-toolkit to the system.\n\nAndroid Toolkit: An easy to use ADB interface\n\nUsage:\n\n-d       Compile as developer\n-r       Uninstall android-toolkit from device\n-s       Prompts for the addition of SCRCPY.\n-u       Update android-toolkit from github.\n";
    
        std::remove("install.out");
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

    boldText("Android Toolkit - Install\n\n");

    if (isScrcpy == true && !std::filesystem::exists("./libs/SCRCPY/")) {
        system("mkdir ./libs/SCRCPY/ && wget https://github.com/Genymobile/scrcpy/releases/download/v4.0/scrcpy-linux-x86_64-v4.0.tar.gz && tar -xvf scrcpy-linux-*.tar.gz && mv ./scrcpy-linux-*/* ./libs/SCRCPY/ && rm -rf ./scrcpy*");
    }

    if (isDebug == true) {
        std::cout << "Debug Mode\n\n";
    }

    mkdir(home + "/.android-toolkit/", true);

    mkdir("./build", true);

    system("cd ./build/; cmake ../; make");

    std::filesystem::copy("./README.md", home + "/.android-toolkit/README.md");
    std::filesystem::copy("./libs/", home + "/.android-toolkit/libs/");
    std::filesystem::copy("./libs/SCRCPY/", home + "/.android-toolkit/libs/SCRCPY/");
    std::filesystem::copy("./icon.png", home + "/.android-toolkit/icon.png");
    std::filesystem::copy("./build/android-toolkit", home + "/.android-toolkit/android-toolkit");

    std::ofstream("./libs/SCRCPY/null");
    std::remove("install.out");

    system("sudo cp -f ./libs/android-toolkit /usr/bin/android-toolkit");

    std::ofstream desktopFile(home + "/.android-toolkit/android-toolkit.desktop");
    desktopFile << "[Desktop Entry]\nName=Android Toolkit\nExec=bash -c 'gnome-terminal --geometry=115x48 -- /home/" + user + "/.android-toolkit/android-toolkit'\nType=Application\nIcon=/home/" + user + "/.android-toolkit/icon.png\nComment=An Easy to use ADB interface";
    desktopFile.close();

    copyOverwrite(home + "/.android-toolkit/android-toolkit.desktop", home + "/.local/share/applications/android-toolkit.desktop");

    std::filesystem::remove_all("./build/");

    if (isDebug == true) {
        system("rm ./libs/SCRCPY/*");
    }

    system("gnome-terminal --geometry=115x48 -- android-toolkit");

    std::ofstream("./libs/SCRCPY/null");

    return 0;
}