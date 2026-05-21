#include "config.h"

int main();

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
std::string scrcpyConfig; // Contents of SCRCPY-config.txt

// Global Variables
std::string adb = "~/.android-toolkit/libs/adb ";
std::string cmd;
std::string user;
std::string file;
std::string input;
std::string null;
std::string home = getenv("HOME");
std::string tmp;
std::string output;

//450

// Conditions
bool isSCRCPYImplemented;
bool isDebug = std::filesystem::exists(home + "/.android-toolkit/isDebug");
std::string version = "Beta v1.4.15.b007";

void scrcpy() {
    system("clear");
    std::cout << "\e[1mSCRCPY\n\n\e[mPlease choose an option.\n\n";
    if (scrcpyConfig != "") {
        std::cout << "Loaded SCRCPY config.\n";
    } else {
        std::cout << "\e[1mOptions Selected:\n\e[m";
        if (dktp != "") { std::cout << "Desktop mode is on.\n"; } if (uhms != "") { std::cout << "Uhid Mouse is on.\n"; } if (uhkb != "") { std::cout << "Uhid Keyboard is on.\n"; } if (fscr != "") { std::cout << "Fullscreen is on\n"; } if (alot != "") { std::cout << "Always on Top is on\n"; } if (dbau != "") { std::cout << "Audio is on Both Devices\n"; } if (dfps != "") { std::cout << "Display FPS is on\n"; } if (appl != "") { std::cout << "Open Application " << applName << " on start\n"; } if (kdpo != "") { std::cout << "Device Screen will turn Off\n"; } if (kdfs != "") {std::cout << "Device will not Sleep\n"; }
    }
    std::cout << "\n1. Desktop Mode\n2. Uhid Mouse\n3. Uhid Keyboard\n4. Fullscreen\n5. Always on top\n6. Play Audio on Both Devices\n7. Print FPS\n8. Open Application\n9. Turn Device Screen Off\n10. Prevent Screen from Sleeping\n\nType Exit to exit.\n\nType Save to save current settings or Load to run SCRCPY with saved settings.\n\nPress ENTER to continue\n\n> ";
    std::getline(std::cin, input);

    system("clear");
    if (input == "") {
        std::cout << "\e[1mSCRCPY - Run\n\n\e[m";
        if (scrcpyConfig == "") {
            cmd = home + "/.android-toolkit/libs/SCRCPY/scrcpy --max-fps=60 --video-bit-rate=2M" + dktp + uhms + uhkb + fscr + alot + dbau + dfps + appl + kdpo + kdfs;
        } else {
            cmd = home + "/.android-toolkit/libs/SCRCPY/scrcpy --max-fps=60 --video-bit-rate=2M" + scrcpyConfig;
        }
        system(cmd.c_str());
        std::cout << "Finished.\n\nPress ENTER to continue.";
        std::getline(std::cin, null);
        main();
    } else if (input == "1") {
        std::cout << "\e[1mSCRCPY - Desktop Size\n\n\e[m";
        if (dktp == "") {
            std::cout << "Please provide the desktop size.\n\nEx. (1920x1080)\n\n> ";
            std::getline(std::cin, input);

            if (input != "") { dktp = " --new-display=" + input; }
        } else { dktp = ""; }
        scrcpy();
    } else if (input == "2") {
        if (uhms == "") { uhms = " --mouse=uhid"; } else { uhms = ""; }
        scrcpy();
    } else if (input == "3") {
        if (uhkb == "") { uhkb = " --keyboard=uhid"; } else { uhkb = ""; }
        scrcpy();
    } else if (input == "4") {
        if (fscr == "") { fscr = " -f"; } else { fscr = ""; }
        scrcpy();
    } else if (input == "5") {
        if (alot == "") { alot = " --always-on-top"; } else { alot = ""; }
        scrcpy();
    } else if (input == "6") {
        if (dbau == "") { dbau = " --audio-dup"; } else{ dbau = ""; }
        scrcpy();
    } else if (input == "7") {
        if (dfps == "") { dfps = " --print-fps"; } else { dfps = ""; }
        scrcpy();
    } else if (input == "8") {
        if (appl == "") {
            std::cout << "\e[1mSCRCPY - Open Package at Startup\n\n\e[mPlease provide a package to open at start.\n\n> ";

            std::getline(std::cin, applName);
            system("clear");
            if (applName != "") { appl = " --start-app=" + applName; }
        } else { appl = ""; }
        scrcpy();
    } else if (input == "9") {
        if (kdpo == "") { kdpo = " --turn-screen-off"; } else { kdpo = ""; }
        scrcpy();
    } else if (input == "10") {
        if (kdfs == "") { kdfs = " --stay-awake"; } else { kdfs = ""; }
        scrcpy();
    } else if (input == "Save" || input == "save") {
        cmd = "printf '" + dktp + uhms + uhkb + fscr + alot + dbau + dfps + appl + "' > " + home + "/.android-toolkit/SCRCPY-config.txt";
        system(cmd.c_str());
        scrcpy();
    } else if (input == "Load" || input == "load" ) {
        if (scrcpyConfig == "") {
            std::cout << "\e[1mSCRCPY - Load Settings\n\n\e[m";
            std::ifstream file(home + "/.android-toolkit/SCRCPY-config.txt");
            if (!file.is_open()) {
                std::cerr << "Error opening file.";
            }
            std::getline(file, scrcpyConfig);

            std::getline(std::cin, null);

            file.close();

            scrcpy();
        } else {
            scrcpyConfig = "";
        }
        scrcpy();
    } else if (input == "Exit" || input == "exit") {
        main();
    } else if (input == "dispVar" && isDebug == true) {
        std::cout << "\e[1mSCRCPY - dispVar\n\n\e[mcmd when loaded:  " << home << "/.android-toolkit/libs/SCRCPY/scrcpy --max-fps=60 --video-bit-rate=2M" << scrcpyConfig << "\n\nscrcpyConfig:  " << scrcpyConfig;
        
        std::getline(std::cin, null);
        scrcpy();
    } else {
        scrcpy();
    }
}

int main() {
    system("clear");
    std::cout << "\e[1mWelcome to Android Toolkit " << version << "!\n\nADB Connection:\n\e[ma1. Pair over WIFI\na2. Disconnect ADB Wireless Device\na3. List Devices\na4. Restart ADB\n\n\e[1mPackage Management:\n\e[mb1. Install\nb2. Uninstall\nb3. Re-Install System Package\nb4. List Packages\nb5. Debloat\nb6. Backup / Restore\nb7. Open Package\n\n\e[1mFile Management:\n\e[mc1. Push / Pull\nc2. File Manager\n\n\e[1mVisual Tools:\n\e[md1. SCRCPY";

    if (std::filesystem::exists(home + "/.android-toolkit/libs/SCRCPY/scrcpy") == false) {
        std::cout << " (Not Implemented)";
        isSCRCPYImplemented = false;
    } else { isSCRCPYImplemented = true; }
    std::cout << "\nd2. Screenshot / Record\n\n\e[1mPower:\n\e[me1. Reboot\n\n\e[1mSystem:\n\e[mf1. ADB Shell\n\n\e[1mMisc. Settings:\n\e[mg1. Display README";

    if (isDebug == true) {
        std::cout << "\n\n\e[1mDeveloper Tools:\n\e[mdev. Debug Settings";
    }

    std::cout << "\n\n> ";
    std::getline(std::cin, input);
    system("clear");

    if (input == "a1") {
        std::cout << "\e[1mAndroid Toolkit - Pair over WIFI\n\n\e[mPlease provide the device's IP.\n\nOn your phone enter Settings > Developer Options > Wireless Debugging > Pair device with pairing code.\n\nNote: You cannot use a VPN on the phone.\n\n> ";
        std::getline(std::cin, ip);

        if (ip == "") {
            main();

        } else {
            system("clear");
            std::cout << "\e[1mAndroid Toolkit - Pair over WIFI\n\n\e[mPlease provide the IP's Port.\n\n" << ip << ":xxxxx\n\n> ";
            std::getline(std::cin, port);

            system("clear");
            if (port == "") {
                main();
            } else {
                std::cout << "\e[1mAndroid Toolkit - Pair over WIFI\n\n\e[m";
                cmd = adb + "pair " + ip + ":" + port;
                system(cmd.c_str());

                std::cout << "\nPress ENTER to continue.";
                std::getline(std::cin, null);
                system("clear");

                std::cout << "\e[1mAndroid Toolkit - Pair over WIFI\n\n\e[mNow provide the IP's Port located under 'IP address & Port'.\n\n" << ip << ":xxxxx\n\n> ";
                std::getline(std::cin, port);

                system("clear");
                if (port == "") {
                    main();
                } else {
                    std::cout << "\e[1mAndroid Toolkit - Pair over WIFI\n\n\e[m";
                    cmd = "clear;" + adb + "connect " + ip + ":" + port;
                    system(cmd.c_str());

                    std::cout << "\nPress ENTER to continue.";
                    std::getline(std::cin, null);
                    main();
                }
            }
        }
    } else if (input == "a2") {
        std::cout << "\e[1mAndroid Toolkit - Disconnect ADB Wireless Device\n\n\e[m";
        cmd = adb + "devices";
        system(cmd.c_str());
        std::cout << "Choose a device to disconnect.\n\nType 'All' to disconnect all devices\n\n> ";
        std::getline(std::cin, ip);

        if (ip != "") {
            if (ip == "all" || ip == "All") {
                cmd = adb + "disconnect";
            } else {
                cmd = adb + "disconnect " + ip;
            }
            system("clear");
            std::cout << "\e[1mAndroid Toolkit - Disconnect ADB Wireless Device\n\n\e[m";
            system(cmd.c_str());

            std::getline(std::cin, null);
        }
        main();
    } else if (input == "a3") {
        system("clear");
        std::cout << "\e[1mAndroid Toolkit - List Devices\n\n\e[m";
        
        cmd = adb + "devices";
        system(cmd.c_str());

        std::getline(std::cin, null);
        main();
    } else if (input == "a4") {
        std::cout << "\e[1mAndroid Toolkit - Restart ADB\n\n\e[m";
        cmd = adb + "kill-server";
        system(cmd.c_str());
        cmd = adb + "start-server";
        system(cmd.c_str());

        std::cout << "\nPress ENTER to continue.";
        std::getline(std::cin, null);
        main();
    }
    else if (input == "b1") {
        std::cout << "\e[1mAndroid Toolkit - Install Package\n\n\e[m";
        std::cout << "Please provide the path to the APK.\n\n> ";
        std::getline(std::cin, path);
        if (path == "") {
            main();
        } else {
            system("clear");
            std::cout << "\e[1mAndroid Toolkit - Install Package\n\n\e[m";
            cmd = adb + "install " + path;
            system(cmd.c_str());

            std::cout << "\nFinished.\n\nPress ENTER to continue.";
            std::getline(std::cin, null);
            main();
        }
    } else if (input == "b2") {
        std::cout << "\e[1mAndroid Toolkit - Uninstall Package\n\n\e[m";
        std::cout << "Please provide the name of the package to be uninstalled.\n\n> ";
        std::getline(std::cin, package);

        if (package == "") {
            main();
        } else {
            cmd = adb + "shell pm uninstall --user 0 " + package;
            system("clear");

            std::cout << "\e[1mAndroid Toolkit - Uninstall Package\n\n\e[m";

            system(cmd.c_str());

            std::getline(std::cin, null);
            main();
        }
    } if (input == "b3") {
        std::cout << "\e[1mAndroid Toolkit - Reinstall Package\n\n\e[mPlease provide the name of the system package to be reinstalled.\n\n> ";
        std::getline(std::cin, package);

        if (package == "") {
            main();
        } else {
            system("clear");
            std::cout << "\e[1mAndroid Toolkit - Reinstall Package\n\n\e[m";
            cmd = adb + "shell pm install-existing --user 0 " + package;
            system(cmd.c_str());

            std::cout << "Finished.\n\nPress ENTER to continue.";
            std::getline(std::cin, null);
            main();
        }
    } else if (input == "b4") {
        std::cout << "\e[1mAndroid Toolkit - List Packages\n\n\e[m";
        cmd = adb + "shell pm list packages";
        system(cmd.c_str());
        std::cout << "\nNote: If there is an error message at the bottom of the list, this is not bad and simply means that ADB cannot access the work profile.";

        std::getline(std::cin, null);
        main();
    } else if (input == "b5") {
        std::cout << "\e[1mAndroid Toolkit - Debloat\n\n\e[mChoose an Option.\n\na1. OneUI - Low\na2. OneUI - Medium\na3. OneUI - High\n\n> ";
        std::getline(std::cin, input);

        if (input == "") {
            main();

        } else if (input == "a1") {
            std::cout << "\e[1mAndroid Toolkit - Debloat\n\n\e[m";
            system("/home/$USER/.android-toolkit/libs/bash.sh oneuiDebloatLow");
            std::getline(std::cin, null);
            main();

        } else if (input == "a2") {
            std::cout << "\e[1mAndroid Toolkit - Debloat\n\n\e[m";
            system("/home/$USER/.android-toolkit/libs/bash.sh oneuiDebloatMed");
            std::getline(std::cin, null);
            main();

        } else if (input == "a3") {
            std::cout << "\e[1mAndroid Toolkit - Debloat\n\n\e[m";
            system("/home/$USER/.android-toolkit/libs/bash.sh oneuiDebloatHigh");
            std::getline(std::cin, null);
            main();
        }
    } else if (input == "b6") {
        std::cout << "\e[1mAndroid Toolkit - Backup / Restore\n\n\e[mPlease select an option.\n\n1. Backup\n2. Restore\n\n> ";
        std::getline(std::cin, input);
        system("clear");

        if (input == "") {
            main();
        } else if (input == "1") {
            std::cout << "\e[1mAndroid Toolkit - Backup / Restore\n\n\e[mPlease provide the path to the folder where the backup will be saved to.\n\n> ";
            std::getline(std::cin, path);
            
            system("clear");
            if (path != "") {
                std::cout << "\e[1mAndroid Toolkit - Backup / Restore\n\n\e[mPlease give a name to the backup.\n\n> ";
                std::getline(std::cin, backup);
                system("clear");

                if (backup == "") {
                    main();
                } else {
                    std::cout << "\e[1mAndroid Toolkit - Backup / Restore\n\n\e[m";
                    cmd = adb + "backup -all -f " + path + "/" + backup + ".ab";
                    system(cmd.c_str());

                    system("clear");
                    std::cout << "\e[1mAndroid Toolkit - Backup / Restore\n\n\e[mPlease provide the encryption key.\n\n> ";
                    
                    std::getline(std::cin, input);
                    if (input != "") {
                        std::ofstream encryptionKey(path + "/" + backup + "_encryptionKey.txt");

                        encryptionKey << input;
                        encryptionKey.close();

                        std::cout << "\nFinished.\n\nPress ENTER to continue.";
                        std::getline(std::cin, null);
                    }
                }
            }
            main();
        } else if (input == "2") {
            std::cout << "\e[1mAndroid Toolkit - Backup / Restore\n\n\e[mPlease provide the path to the folder in which the backup file is stored.\n\n> ";
            std::getline(std::cin, path);
            system("clear");

            std::cout << "\e[1mAndroid Toolkit - Backup / Restore\n\n\e[mPlease provide the name of the backup (No extension).\n\n> ";
            std::getline(std::cin, file);
            system("clear");

            std::cout << "\e[1mAndroid Toolkit - Backup / Restore\n\n\e[m";

            if (file != "" && std::filesystem::exists(path + "/" + file + "_encryptionKey.txt")) {
                std::ifstream encryptionKey(path + "/" + file + "_encryptionKey.txt");
                std::getline(encryptionKey, output);
                std::cout << "Your encryption key: " + output + "\n\n";
            }

            if (backup != "") {
                cmd = adb + "restore " + path + "/" + file + ".ab";
                system(cmd.c_str());

                std::cout << "\n\nFinished.\n\nPress ENTER to continue.";

                std::getline(std::cin, null);
                main();
            }
        }
    } if (input == "b7") {
        std::cout << "\e[1mAndroid Toolkit - Open Application\n\n\e[mPlease provide a package to open on the device.\n\n> ";

        std::getline(std::cin, package);
        system("clear");
        if (package != "") {
            std::cout << "\e[1mAndroid Toolkit - Open Application\n\n\e[m";
            cmd = adb + "shell am start " + package;
            system(cmd.c_str());

            std::cout << "\nFinished.\n\nPress ENTER to continue.";

            std::getline(std::cin, null);
        }
        main();
    } else if (input == "c1") {
        std::cout << "\e[1mAndroid Toolkit - Push / Pull\n\n\e[mPlease choose an option.\n\n1. Push file\n2. Pull file\n\n> ";
        std::getline(std::cin, input);
        system("clear");

        if (input == "") {
            main();
        } else if (input == "1") {
            std::cout << "\e[1mAndroid Toolkit - Push / Pull\n\n\e[mPlease provide the path to file to be pushed.\n\n> ";
            std::getline(std::cin, file);
            system("clear");

            if (file == "") {
                main();
            } else {
                std::cout << "\e[1mAndroid Toolkit - Push / Pull\n\n\e[mPlease provide the path on the device for the file to be pushed to.\n\n> ";
                std::getline(std::cin, path);
                system("clear");

                if (path == "") {
                    main();
                } else {
                    std::cout << "\e[1mAndroid Toolkit - Push / Pull\n\n\e[m";
                    cmd = adb + "push " + file + " sdcard" + path;
                    system(cmd.c_str());

                    std::getline(std::cin, null);
                    main();
                }
            }

        } else if (input == "2") {
            std::cout << "\e[1mAndroid Toolkit - Push / Pull\n\n\e[mPlease provide the path to the file to be pulled.\n\n> ";
            std::getline(std::cin, file);
            system("clear");

            if (file == "") {
                main();
            } else {
                std::cout << "\e[1mAndroid Toolkit - Push / Pull\n\n\e[mPlease provide the path on this computer for the file to be pulled to.\n\n> ";
                std::getline(std::cin, path);
                system("clear");

                if (path == "") {
                    main();
                } else {
                    std::cout << "\e[1mAndroid Toolkit - Push / Pull\n\n\e[m";
                    cmd = adb + "pull sdcard" + file + " " + path;
                    system(cmd.c_str());

                    std::getline(std::cin, null);
                    main();
                }
            }
        }
    } else if (input == "c2") {
        while (std::cout << "Please provide a path on the device\n\nNote: The path automatically adds /sdcard/ to the beginning.\nPaths are absolute.\nType Exit to exit.\nType File to open file options.\nType Folder to open folder options.\n\n> " && std::getline(std::cin, path)) {
            system("clear");
            if (path == "exit" || path == "Exit") {
                break;
            } else if (path == "file" || path == "File") {
                std::cout << "\e[1mAndroid Toolkit - File Explorer\n\n\e[mPlease choose an option.\n\n1. Delete file\n2. Copy File\n3. Open file\n4. Edit File\n\n> ";
                std::getline(std::cin, input);

                system("clear");
                if (input == "1") {
                    std::cout << "\e[1mAndroid Toolkit - File Manager\n\n\e[mPlease provide a path on the device of a file to be deleted.\n\n> ";
                    
                    std::getline(std::cin, file);
                    system("clear");
                    if (file != "") {
                        std::cout << "\e[1mAndroid Toolkit - File Explorer\n\n\e[m";
                        cmd = adb + "shell rm /sdcard/" + file;
                        system(cmd.c_str());

                        std::cout << "\n\nPress ENTER to continue.";
                        std::getline(std::cin, null);
                    }
                } else if (input == "2") {
                    std::cout << "\e[1mAndroid Toolkit - File Explorer\n\n\e[mPlease provide the path on the device to the file that should be copied.\n\n> ";

                    std::getline(std::cin, file);
                    system("clear");
                    if (file != "") {
                        std::cout << "\e[1mAndroid Toolkit - File Explorer\n\n\e[mPlease provide the path where the file should be copied to.\n\n> ";
                        
                        std::getline(std::cin, path);
                        system("clear");
                        if (path != "") {
                            std::cout << "\e[1mAndroid Toolkit - File Explorer\n\n\e[m" << file << path;
                            cmd = adb + "shell cp /sdcard/" + file + " /sdcard/" + path;
                            system(cmd.c_str());

                            std::getline(std::cin, null);
                        }
                    }
                        
                } else if (input == "3") {
                    std::cout << "\e[1mAndroid Toolkit - File Explorer\n\n\e[mPlease provide the path to the file to be opened.\n\n> ";

                    std::getline(std::cin, file);
                    system("clear");
                    if (file != "") {
                        if (!std::filesystem::exists("/tmp/.android-toolkit/openFile") == true) {
                            system("rm -rf /tmp/.android-toolkit/openFile/; mkdir -p /tmp/.android-toolkit/openFile");
                        }

                        cmd = adb + "pull " + file + " /tmp/.android-toolkit/openFile";
                        system(cmd.c_str());

                        system("xdg-open /tmp/.android-toolkit/openFile/*");

                        std::getline(std::cin, null);
                    }   
                } else if (input == "4") {
                    std::cout << "\e[1mAndroid Toolkit - File Manager\n\n\e[mPlease provide the path to the file to be edited.\n\n> ";

                    std::getline(std::cin, file);
                    system("clear");
                    if (file != "") {
                        std::cout << "\e[1mAndroid Toolkit - File Manager\n\n\e[m";
                        if (!std::filesystem::exists("/tmp/.android-toolkit/editFile")) {
                            system("rm -rf /tmp/.android-toolkit/editFile/; mkdir -p /tmp/.android-toolkit/editFile/");
                        }

                        cmd = adb + "pull /sdcard/" + file + " /tmp/.android-toolkit/editFile/";
                        system(cmd.c_str());

                        std::cout << "\n\nFinished.\n\nPress ENTER to continue.";
                        std::getline(std::cin, null);
                    }
                }
            } else if (path == "folder" || path == "Folder") {
                std::cout << "\e[1mAndroid Toolkit - File Manager\n\n\e[mPlease choose an option.\n\n1. Delete Folder\n2. Copy Folder\n3. Make Folder\n\n> ";

                std::getline(std::cin, input);
                system("clear");
                if (input == "1") {
                    std::cout << "\e[1mAndroid Toolkit - File Manager\n\n\e[mPlease provide the path to the folder on the device to be deleted\n\n> ";

                    std::getline(std::cin, path);
                    system("clear");
                    if (path != "") {
                        std::cout << "\e[1mAndroid Toolkit - File Manager\e[m\n\n";
                        cmd = adb + "shell rm -r /sdcard/" + path;
                        system(cmd.c_str());

                        std::cout << "\n\nFinished.\n\nPress ENTER to continue.";
                        std::getline(std::cin, null);
                    }
                    system("clear");
                } else if (input == "2") {
                    std::cout << "\e[1mAndroid Toolkit - File Manager\n\n\e[mPlease provide the path to the folder to be copied.\n\n> ";

                    std::getline(std::cin, file);
                    system("clear");
                    if (file != "") {
                        std::cout << "\e[1mAndroid Toolkit - File Manager\n\n\e[mPlease provide the path for the folder to be copied to.\n\n> ";

                        std::getline(std::cin, path);
                        system("clear");
                        if (path != "") {
                            std::cout << "\e[1mAndroid Toolkit - File Manager\n\n\e[m";
                            cmd = adb + "shell cp -R /sdcard/" + file + " /sdcard/" + path;
                            system(cmd.c_str());

                            std::cout << "\n\nFinished.\n\nPress ENTER to continue.";
                            std::getline(std::cin, null);
                            system("clear");
                            if (null == "dispVar" && isDebug == true) {
                                std::cout << "file " << file << "\npath " << path << "\ncmd " << cmd;
                                std::getline(std::cin, null);
                            }
                        }
                    }
                } else if (input == "3") {
                    std::cout << "\e[1mAndroid Toolkit - File Manager\n\n\e[mPlease provide the path for the folder to be created in.\n\n> ";

                    std::getline(std::cin, path);
                    system("clear");
                    if (path != "") {
                        std::cout << "\e[1mAndroid Toolkit - File Manager\n\n\e[mPlease provide a name for the folder.\n\n> ";
                        
                        std::getline(std::cin, file);
                        system("clear");
                        if (file != "") {
                            std::cout << "\e[1mAndroid Toolkit - File Manager\n\n\e[m";

                            cmd = adb + "shell mkdir /sdcard/" + path + "/" + file;
                            system(cmd.c_str());

                            std::cout << "\n\nFinished.\n\nPress ENTER to continue.";
                            std::getline(std::cin, null);
                        }
                    }
                }
            } else {
                path = "/sdcard/" + path;
                std::cout << "\e[1mAndroid Toolkit - File Explorer\n\n\e[mCurrent Path: " << path << "\n\n";
                cmd = adb + "shell ls -r " + path;
                system(cmd.c_str());
            }
        }
        main();
    } else if (input == "d1") {
        if (isSCRCPYImplemented == true) {
            scrcpy();
        } else {
            std::cout << "\e[1mSCRCPY\n\n\e[mSCRCPY is not implemented. To do so, download the latest release of SCRCPY from https://github.com/Genymobile/scrcpy/releases/, and when installing, type './install -s'.\n\nPress ENTER to continue.";
            std::getline(std::cin, null);
            main();
        }
    } else if (input == "d2") {
        std::cout << "\e[1mAndroid Toolkit - Screenshot / Record\n\n\e[mPlease choose an option.\n\n1. Screenshot\n2. Screen Record\n\n> ";
        std::getline(std::cin, input);

        system("clear");
        if (input == "") {
            main();
        } else {
            std::cout << "\e[1mAndroid Toolkit - Screenshot / Record\n\n\e[mPlease provide a path for the capture.\n\n> ";
            std::getline(std::cin, path);

            system("clear");
            if (path == "") {
                main();
            } else {
                std::cout << "\e[1mAndroid Toolkit - Screenshot / Record\n\n\e[mPlease provide a name for the capture.\n\n> ";
                std::getline(std::cin, file);

                system("clear");
                if (input == "1") {
                    std::cout << "\e[1mAndroid Toolkit - Screenshot / Record\n\n\e[m";
                    cmd = adb + "shell screencap -p > " + path + "/" + file + ".png";
                    system(cmd.c_str());

                    std::cout << "\nIf an error about multiple displays showed, it most likely isn't a problem.\nIf however this is causing a problem, type 'display'.";

                    std::getline(std::cin, input);
                    system("clear");
                    if (input == "display") {
                        std::cout << "\e[1mAndroid Toolkit - Screenshot / Record\n\n\e[mPlease provide a display number (The one to the right of Display).\n\n";

                        cmd = adb + "shell dumpsys SurfaceFlinger --display-id";
                        system(cmd.c_str());

                        std::cout << "\n> ";
                        std::getline(std::cin, display);
                        system("clear");
                        if (display != "") {
                            std::cout << "\e[1mAndroid Toolkit - Screenshot / Record\n\n\e[m";
                            cmd = adb + "shell screencap -pd > " + path + "/" + file + ".png " + display;
                            system(cmd.c_str());

                            std::getline(std::cin, null);
                        }
                    }
                    main();
                } else if (input == "2") {
                    std::cout << "\e[1mAndroid Toolkit - Screenshot / Record\n\n\e[m";
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
    } else if (input == "e1") {
        std::cout << "\e[1mAndroid Toolkit - Restart\n\n\e[mType RESTART to continue.\n\n> ";

        std::getline(std::cin, input);
        system("clear");
        if (input == "RESTART") {
            std::cout << "\e[1mAndroid Toolkit - Restart Device\n\n\e[m";
            std::cout << "Restarting Device...\n\n";
            cmd = adb + "shell reboot";
            system(cmd.c_str());
            std::cout << "\n\nFinished.\n\nPress ENTER to continue.";
            
            std::getline(std::cin, null);
        }

        main();
            
    } else if (input == "e2") {
        std::cout << "\e[1mAndroid Toolkit - Power Off Device\n\n\e[m";
        std::cout << "Powering Off Device...\n\n";
        cmd = adb + "shell reboot -p";
        system(cmd.c_str());
        std::cout << "\n\nFinished.\n\nPress ENTER to continue.";
        
        std::getline(std::cin, null);
        main();
    } else if (input == "f1") {
        std::cout << "\e[1mAndroid Toolkit - ADB Shell\n\n\e[mType exit to exit Shell.\n\n";
        cmd = adb + "shell";
        system(cmd.c_str());
        main();
    }
    
    else if (input == "g1"){
        std::cout << "\e[1mREADME\n\n\e[m";
        std::ifstream file(home + "/.android-toolkit/README.md");
        while (std::getline(file, tmp)) {
            std::cout << tmp << std::endl;
        }

        std::cout << "\n\nPress ENTER to continue.";
        std::getline(std::cin, null);
        main();
    } else if (input == "dev" && isDebug == true) {
        std::cout << "\e[1mAndroid Toolkit - Debug Settings\n\n\e[m1. Config for Release\n2. Execute bash command\n\n> ";
        std::getline(std::cin, input);

        system("clear");
        if (input == "1") {
            system("rm -r ./build; rm ./libs/SCRCPY/*; rm ./nohup.out; printf '' > ./libs/SCRCPY/null");
        } else if (input == "2") {
            std::cout << "Enter a bash command.\n\n> ";

            std::getline(std::cin, cmd);
            system("clear");
            system(cmd.c_str());

            std::getline(std::cin, null);
        }
        main();
    } else {
        if (std::filesystem::exists("/tmp/.android-toolkit/") == true) {
            system("rm -rf /tmp/.android-toolkit/");
        }
        std::cout << "Exiting Android Toolkit...\n\n";
        return 0;
    }
}