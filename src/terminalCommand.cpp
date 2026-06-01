#include "config.h"

// To compile this, from the android-toolkit root folder, run "g++ ./src/terminalCommand.cpp -o ./libs/android-toolkit"

int main(int argc, char* argv[]) {
    
    int i = 1;
    while (i < argc) {
        if (std::string(argv[i]) == "--help") {
            std::cout << "Android Toolkit: An easy to use ADB interface\n\nUsage:\n\n-t       Open in separate terminal\n\n";

            if (std::filesystem::exists(home + "/.android-toolkit/libs/SCRCPY/") == true) {
                std::cout << "SCRCPY is implemented.\n\n";
            } else {
                std::cout << "SCRCPY is not implemented.\n\n";
            }

            return 0;
        }

        if (std::string(argv[i]) == "-t") {
            cmdPrefix = "gnome-terminal --geometry=115x48 -- ";
        }

        i++;
    }

    cmd = cmdPrefix + "~/.android-toolkit/android-toolkit";
    
    system(cmd.c_str());

    return 0;
}