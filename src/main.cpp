#include "config.h"

int main();

// Function Variables
std::string adb = "~/.android-toolkit/libs/adb ";
std::string backup;
std::string file;
std::string path;
std::string port;
std::string ip;
std::string package;
std::string cmd;

std::string dktp;
std::string uhms;
std::string uhkb;
std::string fscr;


// Conditions
bool isExiting;
bool isSCRCPYImplemented;
std::string version = "1.1.0 debug";

// Commonly Used Variables
std::string input;
std::string null;

void scrcpy() {
    std::cout << "Please choose an option.\n\n1. Desktop Mode\n2. Uhid Mouse\n3. Uhid Keyboard\n4. Fullscreen\n\nPress ENTER to continue\n\n> ";
    std::getline(std::cin, input);

    system("clear");
    if (input == "") {
        std::string cmd = "nohup ./libs/SCRCPY/scrcpy" + dktp + uhms + uhkb + fscr + " &";
        system(cmd.c_str());
        main();
    } else if (input == "1") {
        if (input != "") {
            if (dktp == "") {
                std::cout << "Please provide the desktop size.\n\nEx. (1920x1080)\n\n> ";
                std::getline(std::cin, input);

                if (input != "") {
                    dktp = " --new-display=" + input + "\\120 ";
                }
            } else {
                dktp = "";
            }
        }
    } else if (input == "2") {
        uhms = " --mouse=uhid ";
    } else if (input == "3") {
        uhkb = " --keyboard=uhid ";
    } else if (input == "4") {
        fscr = " -f ";
    }
    scrcpy();
}

int main() {

    system("clear");

    std::cout << "Android Toolkit v" << version << "\n\na1. Pair over WIFI\na2. Disconnect ADB Wireless Device\na3. List Devices\n\nb1. Install\nb2. Uninstall\nb3. Re-Install System Package\nb4. List Packages\nb5. Debloat\nb6. Backup / Restore\n\nc1. Push / Pull\n\nd1. SCRCPY";
    if (std::filesystem::exists("./libs/SCRCPY/scrcpy") == false) {
        std::cout << " (Not Implemented)";
        isSCRCPYImplemented = false;
    } else {
        isSCRCPYImplemented = true;
    }
    std::cout << "\n\n> ";
    
    std::getline(std::cin, input);
    system("clear");

    if (input == "a1") {

        std::cout << "On your phone enter Settings > Developer Options > Wireless Debugging > Pair device with pairing code.\n Please provide the device's IP.\n\nNote: You cannot use a VPN on the phone.\n\n> ";
        std::getline(std::cin, ip);

        if (ip == "") {
            main();
        } else {
            system("clear");
            std::cout << "Please provide the IP's Port.\n\n> ";
            std::getline(std::cin, port);

            if (port == "") {
                main();
            } else {
                cmd = "clear;" + adb + "pair " + ip + ":" + port;
                system(cmd.c_str());

                system("clear");
                std::cout << "Now provide the IP's Port located under 'Device Name'.\n\n> ";
                std::getline(std::cin, port);

                if (port == "") {
                    main();
                } else {
                    cmd = "clear;" + adb + "connect " + ip + ":" + port;
                    system(cmd.c_str());

                    std::getline(std::cin, null);
                    main();
                }
            }
        }
    } else if (input == "a2") {

        cmd = adb + "devices";
        system(cmd.c_str());
        std::cout << "Choose a device to disconnect.\n\nType 'All' to disconnect all devices\n\n> ";
        std::getline(std::cin, ip);

        if (ip == "") {
            main();
        } else if (ip == "all" || ip == "All") {
            cmd = adb + "disconnect";
        } else {
            cmd = adb + "disconnect " + ip;
        }
        system("clear");
        system(cmd.c_str());

        std::getline(std::cin, null);
        main();
    } else if (input == "a3") {
        system("clear");

        cmd = adb + "devices";
        system(cmd.c_str());

        std::getline(std::cin, null);
        main();
    } else if (input == "b1") {

        std::cout << "Please provide the path to the APK.\n\n> ";
        std::getline(std::cin, path);
        if (path == "") {
            main();
        } else {
            system("clear");
            cmd = adb + "install " + path;
            system(cmd.c_str());

            std::getline(std::cin, null);
            main();
        }
    } else if (input == "b2") {

        std::cout << "Please provide the name of the package to be uninstalled.\n\n> ";
        std::getline(std::cin, package);

        if (package == "") {
            main();
        } else {
            cmd = adb + "shell pm uninstall --user 0 " + package;
            system("clear");

            system(cmd.c_str());

            std::getline(std::cin, null);
            main();
        }
    } if (input == "b3") {

        std::cout << "Please provide the name of the system package to be reinstalled.\n\n> ";
        std::getline(std::cin, package);

        if (package == "") {
            main();
        } else {
            system("clear");
            cmd = adb + "shell pm install-existing --user 0 " + package;
            system(cmd.c_str());

            std::getline(std::cin, null);
            main();
        }
    } else if (input == "b4") {
        cmd = adb + "shell pm list packages";
        system(cmd.c_str());
        std::cout << "\nNote: If there is an error message at the bottom of the list, this is not bad and simply means that ADB cannot access the work profile.";

        std::getline(std::cin, null);
        main();
    } else if (input == "b5") {
        std::cout << "Choose an Option.\n\na1. OneUI - Low\na2. OneUI - Medium\na3. OneUI - High\n\n> ";
        std::getline(std::cin, input);

        if (input == "") {
            main();

        } else if (input == "a1") {
            system("/home/$USER/.android-toolkit/libs/debloat/oneuiLow.sh");
            std::getline(std::cin, null);
            main();

        } else if (input == "a2") {
            system("/home/$USER/.android-toolkit/libs/debloat/oneuiMed.sh");
            std::getline(std::cin, null);
            main();

        } else if (input == "a3") {
            system("/home/$USER/.android-toolkit/libs/debloat/oneuiHigh.sh");
            std::getline(std::cin, null);
            main();

        }
    } else if (input == "b6") {
        std::cout << "Please select an option.\n\n1. Backup\n2. Restore\n\n> ";
        std::getline(std::cin, input);
        system("clear");

        if (input == "") {
            main();
        } else if (input == "1") {
            std::cout << "Please provide the path to the folder where the backup will be saved to.\n\n> ";
            std::getline(std::cin, path);
            system("clear");

            if (path == "") {
                main();

            } else {
                std::cout << "Please give a name to the backup.\n\n> ";
                std::getline(std::cin, backup);
                system("clear");

                if (backup == "") {
                    main();
                } else {
                    cmd = adb + "backup -all -f " + path + "/" + backup + ".ab";
                    system(cmd.c_str());

                    std::getline(std::cin, null);
                    main();

                }
            }
        } else if (input == "2") {
            std::cout << "Please provide the path to the backup file.\n\n> ";
            std::getline(std::cin, backup);
            system("clear");

            if (backup == "") {
                main();
            } else {
                cmd = adb + "restore " + backup;
                system(cmd.c_str());

                std::getline(std::cin, null);
                main();
            }
        }
    } else if (input == "c1") {
        std::cout << "Please choose an option.\n\n1. Push file\n2. Pull file\n\n> ";
        std::getline(std::cin, input);
        system("clear");

        if (input == "") {
            main();
        } else if (input == "1") {
            std::cout << "Please provide the path to file to be pushed.\n\n> ";
            std::getline(std::cin, file);
            system("clear");

            if (file == "") {
                main();
            } else {
                std::cout << "Please provide the path on the device for the file to be pushed to.\n\n> ";
                std::getline(std::cin, path);
                system("clear");

                if (path == "") {
                    main();
                } else {
                    cmd = adb + "push " + file + " sdcard" + path;
                    system(cmd.c_str());

                    std::getline(std::cin, null);
                    main();
                }
            }

        } else if (input == "2") {
            std::cout << "Please provide the path to the file to be pulled.\n\n> ";
            std::getline(std::cin, file);
            system("clear");

            if (file == "") {
                main();
            } else {
                std::cout << "Please provide the path on this computer for the file to be pulled to.\n\n> ";
                std::getline(std::cin, path);
                system("clear");

                if (path == "") {
                    main();
                } else {
                    cmd = adb + "pull sdcard" + file + " " + path;
                    system(cmd.c_str());

                    std::getline(std::cin, null);
                    main();
                }
            }
        }
    } else if (input == "d1") {
        scrcpy();
    }
    else {
        std::cout << "Exiting Android Toolkit...\n\n";

        return 0;
    }

}