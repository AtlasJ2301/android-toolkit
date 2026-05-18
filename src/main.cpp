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
std::string scrcpyConfig; // Contents of SCRCPY-config.txt

// Conditions
bool isSCRCPYImplemented;
std::string version = "Alpha v1.2.6 ";

// Global Variables
std::string user;
std::string input;
std::string null;
std::string home = getenv("HOME");

void scrcpy() {
    system("clear");
    std::cout << "Please choose an option.\n\nNote: Im pretty sure that SCRCPY broke Desktop mode in v4.0 as it completely freezes the phone and restarts it, so until further updates I would advise against using it.\n\n";
    if (scrcpyConfig != "") {
        std::cout << "Loaded SCRCPY config.";
    } else {
        if (dktp != "") {
            std::cout << "Desktop mode is on. (You should turn this off).\n";
        } if (uhms != "") {
            std::cout << "Uhid Mouse is on.\n";
        } if (uhkb != "") {
            std::cout << "Uhid Keyboard is on.\n";
        } if (fscr != "") {
            std::cout << "Fullscreen is on\n";
        } if (alot != "") {
            std::cout << "Always on Top is on\n";
        } if (dbau != "") {
            std::cout << "Audio is on Both Devices\n";
        } if (dfps != "") {
            std::cout << "Display FPS is on\n";
        } if (appl != "") {
            std::cout << "Open Application " << applName << " on start\n";
        }
    }
    std::cout << "\n1. Desktop Mode\n2. Uhid Mouse\n3. Uhid Keyboard\n4. Fullscreen\n5. Always on top\n6. Play Audio on Both Devices\n7. Print FPS\n8. Open Application\nType Exit to exit.\n\nType Save to save current settings or Load to run SCRCPY with saved settings.\n\nPress ENTER to continue\n\n> ";
    std::getline(std::cin, input);

    system("clear");
    if (input == "") {
        if (scrcpyConfig != "") {
            std::string cmd = home + "/.android-toolkit/libs/SCRCPY/scrcpy --max-fps=60 --video-bit-rate=2M" + dktp + uhms + uhkb + fscr + alot + dbau + dfps + appl;
        } else {
            std::string cmd = home + "/.android-toolkit/libs/SCRCPY/scrcpy --max-fps=60 --video-bit-rate=2M" + scrcpyConfig;
        }
        system(cmd.c_str());
        std::cout << "Finished.\n\nPress ENTER to continue.";
        std::getline(std::cin, null);
        main();
    } else if (input == "1") {
        if (dktp == "") {
            std::cout << "Please provide the desktop size.\n\nEx. (1920x1080)\n\n> ";
            std::getline(std::cin, input);

            if (input != "") {
                dktp = " --new-display=" + input;
            }
        } else {
            dktp = "";
        }
        scrcpy();
    } else if (input == "2") {
        if (uhms == "") {
            uhms = " --mouse=uhid ";
        } else {
            uhms = "";
        }
        scrcpy();
    } else if (input == "3") {
        if (uhkb == "") {
            uhkb = " --keyboard=uhid ";
        } else {
            uhkb = "";
        }
        scrcpy();
    } else if (input == "4") {
        if (fscr == "") {
            fscr = " -f ";
        } else {
            fscr = "";
        }
        scrcpy();
    } else if (input == "5") {
        if (alot == "") {
            alot = " --always-on-top ";
        } else {
            alot = "";
        }
        scrcpy();
    } else if (input == "6") {
        if (dbau == "") {
            dbau = " --audio-dup ";
        } else{
            dbau = "";
        }
        scrcpy();
    } else if (input == "7") {
        if (dfps == "") {
            dfps = " --print-fps ";
        } else {
            dfps = "";
        }
        scrcpy();
    } else if (input == "8") {
        if (appl == "") {
            std::cout << "Please provide a package to open at start.\n\n> ";

            std::getline(std::cin, applName);
            system("clear");
            if (applName != "") {
                appl = " --start-app=" + applName + " ";
            }
        } else {
            appl = "";
        }
        scrcpy();
    } else if (input == "Save" || input == "save") {
        cmd = "printf '" + dktp + uhms + uhkb + fscr + alot + dbau + dfps + appl + "' > " + home + "/.android-toolkit/SCRCPY-config.txt";
        system(cmd.c_str());
        scrcpy();
    } else if (input == "Load" || input == "load" ) {
        if (scrcpyConfig != "") {
            std::ifstream file(home + "/.android-toolkit/SCRCPY-config.txt");
            if (!file.is_open()) {
                std::cerr << "Error opening file.";
                
                std::getline(std::cin, null);
                scrcpy();
            } else {
                std::getline(file, scrcpyConfig);
            }

            std::getline(std::cin, null);
        } else {
            scrcpyConfig = "";
        }
        scrcpy();
    } else if (input == "Exit" || input == "exit") {
        main();
    }
}

int main() {

    system("clear");

    std::cout << "Welcome to Android Toolkit " << version << "!\n\na1. Pair over WIFI\na2. Disconnect ADB Wireless Device\na3. List Devices\na4. Restart ADB\n\nb1. Install\nb2. Uninstall\nb3. Re-Install System Package\nb4. List Packages\nb5. Debloat\nb6. Backup / Restore\n\nc1. Push / Pull\nc2. File Manager\n\nd1. SCRCPY";

    if (std::filesystem::exists(home + "/.android-toolkit/libs/SCRCPY/scrcpy") == false) {
        std::cout << " (Not Implemented)";
        isSCRCPYImplemented = false;
    } else {
        isSCRCPYImplemented = true;
    }

    std::cout << "\nd2. Screenshot / Record";

    if (std::filesystem::exists(home + "/.android-toolkit/isDebug") == true) {
        
        std::cout << "\n\ndev. Debug Settings";
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
            std::cout << "Please provide the IP's Port.\n\nEx: 192.168.0.116\n\n> ";
            std::getline(std::cin, port);

            if (port == "") {
                main();
            } else {
                cmd = "clear;" + adb + "pair " + ip + ":" + port;
                system(cmd.c_str());

                std::getline(std::cin, null);
                system("clear");
                std::cout << "Now provide the IP's Port located under 'Device Name'.\n\n" << ip << ":xxxxx\n\n> ";
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
    } else if (input == "a4") {
        cmd = adb + "kill-server";
        system(cmd.c_str());
        cmd = adb + "start-server";
        system(cmd.c_str());

        std::cout << "\nPress ENTER to continue.";
        std::getline(std::cin, null);
        main();
    }
    else if (input == "b1") {

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
            system("/home/$USER/.android-toolkit/libs/bash.sh oneuiDebloatLow");
            std::getline(std::cin, null);
            main();

        } else if (input == "a2") {
            system("/home/$USER/.android-toolkit/libs/bash.sh oneuiDebloatMed");
            std::getline(std::cin, null);
            main();

        } else if (input == "a3") {
            system("/home/$USER/.android-toolkit/libs/bash.sh oneuiDebloatHigh");
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
    } else if (input == "c2") {
        while (std::cout << "\nPlease provide a path on the device\n\nNote: The path automatically adds /sdcard/ to the beginning.\nPaths are absolute.\nType Exit to exit.\n\n> " && std::getline(std::cin, path)) {
            system("clear");
            if (path == "exit" || path == "Exit") {
                main();
            } else if (path == "file" || path == "File") {
                std::cout << "Please choose an option.\n\n1. Delete file\n2. Copy File\n\n> ";
                std::getline(std::cin, input);

                system("clear");
                if (input == "1") {
                    std::cout << "Please provide the path to the file.\n\n> ";
                    std::getline(std::cin, file);
                    if (file != "") {
                        cmd = adb + "shell rm /sdcard/" + file;
                        system(cmd.c_str());

                        std::getline(std::cin, null);
                    }
                } else if (input == "2") {
                    std::cout << "Please provide the path to the file to be copied\n\n> ";
                    std::getline(std::cin, file);
                    
                    system("clear");
                    if (file != "") {
                        std::cout << "Please provide the path where the file should be copied to.\n\n> ";
                        std::getline(std::cin, path);

                        system("clear");
                        if (path != "") {
                            cmd = adb + "shell cp /sdcard/" + file + " /sdcard/" + path;
                            system(cmd.c_str());

                            std::getline(std::cin, null);
                        }
                    }
                }
                main();
            } else {
                path = "/sdcard/" + path;
                std::cout << "Current Path: " << path << "\n\n";
                cmd = adb + "shell ls -r " + path;
                system(cmd.c_str());
            }
        }
    } else if (input == "d1") {
        if (isSCRCPYImplemented == true) {
            scrcpy();
        } else {
            std::cout << "SCRCPY is not implemented. To do so, download the latest release of SCRCPY from https://github.com/Genymobile/scrcpy/releases/, and when installing, type './install -s'.\n\nPress ENTER to continue.";
            std::getline(std::cin, null);
            main();
        }
    } else if (input == "d2") {
        std::cout << "Please choose an option.\n\n1. Screenshot\n2. Screen Record\n\n> ";
        std::getline(std::cin, input);

        system("clear");
        if (input == "") {
            main();
        } else {
            std::cout << "Please provide a path for the capture.\n\n> ";
            std::getline(std::cin, path);

            system("clear");
            if (path == "") {
                main();
            } else {
                std::cout << "Please provide a name for the capture.\n\n> ";
                std::getline(std::cin, file);

                system("clear");
                if (input == "1") {
                    cmd = adb + "shell screencap -p > " + path + "/" + file + ".png";
                    system(cmd.c_str());

                    std::cout << "\nIf an error about multiple displays showed, it most likely isn't a problem.\nIf however this is causing a problem, type 'display'.";

                    std::getline(std::cin, input);
                    system("clear");
                    if (input == "display") {
                        std::cout << "Please provide a display number (The one to the right of Display).\n\n";

                        cmd = adb + "shell dumpsys SurfaceFlinger --display-id";
                        system(cmd.c_str());

                        std::cout << "\n> ";
                        std::getline(std::cin, display);
                        system("clear");
                        if (display != "") {
                            cmd = adb + "shell screencap -pd > " + path + "/" + file + ".png " + display;
                            system(cmd.c_str());

                            std::getline(std::cin, null);
                        }

                        main();
                    }
                    main();
                } else if (input == "2") {
                    cmd = adb + "pull /sdcard/tmp/tmp.mp4 " + path + "/" + file + ".mp4"; 
                    system("/home/$USER/.android-toolkit/libs/bash.sh screenrecord");

                    system(cmd.c_str());
                    std::cout << "\n\nPress ENTER to continue.";
                    std::getline(std::cin, null);
                    main();
                } else {
                    main();
                }
            }
        }
    } else if (input == "dev" && std::filesystem::exists(home + "/.android-toolkit/isDebug")) {
        std::cout << "Debug Settings.\n\n1. Config for Release\n2. Create SCRCPY link\n\n> ";
        std::getline(std::cin, input);

        system("clear");
        if (input == "1") {
            system("rm -r ./build; rm ./libs/SCRCPY/*; rm ./nohup.out");
        } else if (input == "2") {
            system("ln -s ./libs/SCRCPY/ ./");
        }
        main();
    } else if (input == "e1"){
        system("cat ~/.android-toolkit/README.md");

        std::cout << "\n\nPress ENTER to continue.";
        std::getline(std::cin, null);
        main();
    } else {
        std::cout << "Exiting Android Toolkit...\n\n";
        return 0;
    }
}