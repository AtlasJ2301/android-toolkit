#include "config.h"

// try to make gui in c#

int main();

void install() {

    // Define Variables

    std::string null;
    std::string path;

    system("clear");

    std::cout << "Please provide the location of the APK you wish to install.\n\n> ";
    std::cin >> path; 
    std::string cmd = "adb install " + path + "; printf '\n'; read -p 'Press ENTER to continue.' null";

    system("clear");

    system(cmd.c_str());

    std::getline(std::cin, null);

    main();
    
}

int main() {

    // Define Variables
    std::string version = "CPP_DEBUG";

    std::string input;

    // Clear
    system("clear");

    // header
    std::cout << "Welcome to Android Toolkit v" << version << "!\nPlease select an option:\n\n";

    // options
    std::cout << "1. Install\n\n> ";

    std::cin >> input;

    if (input == "1") {
        
        install();

    }

    return 0;

}