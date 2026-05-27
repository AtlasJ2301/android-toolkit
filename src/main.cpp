#include "config.h"

int main();

bool isDebug = std::filesystem::exists(home + "/.android-toolkit/isDebug");

int main() {
    clear();
    setTextColor("green");
    std::cout << "\e[1m" << androidToolkitAsciiHeader;

    if (isError == true) {
        std::cerr << input << ": Not an option\n\n";
    }

    isError = false;
    
    boldText("Welcome to Android Toolkit " + version + "!\n\nADB Connection:\n");
    std::cout << "a1. Pair over WIFI\na2. Disconnect ADB Wireless Device\na3. List Devices\na4. Restart ADB\n\n";

    setTextColor("green");
    boldText("Package Management:\n");
    std::cout << "b1. Install\nb2. Uninstall\nb3. Re-Install System Package\nb4. List Packages\nb5. Debloat\nb6. Backup / Restore\nb7. Open Package\n\n";
    
    setTextColor("green");
    boldText("File Management:\n");
    std::cout << "c1. Push / Pull\nc2. File Manager\n\n";
    
    setTextColor("green");
    boldText("Visual Tools:\n");
    std::cout << "d1. SCRCPY";

    if (std::filesystem::exists(home + "/.android-toolkit/libs/SCRCPY/scrcpy") == false) {
        std::cout << " (Not Implemented)";
        isSCRCPYImplemented = false;
    } else { isSCRCPYImplemented = true; }

    std::cout << "\nd2. Screenshot / Record\n\n";

    setTextColor("green");
    boldText("Power:\n");
    std::cout << "e1. Reboot\n\n";

    setTextColor("green");
    boldText("System:\n");
    std::cout << "f1. ADB Shell\n\n";

    setTextColor("green");
    boldText("Misc. Settings:\n");
    std::cout << "g1. Display README";

    if (isDebug == true) {
        boldText("\n\nDeveloper Tools:\n");
        std::cout << "dev. Debug Settings";
    }

    std::cout << "\n\n> ";
    std::getline(std::cin, input);
    clear();

    if (input == "a1") {
        setTextColor("green");
        boldText("Android Toolkit - Pair over WIFI\n\n");
        std::cout << "Please provide the device's IP.\n\nOn your phone enter Settings > Developer Options > Wireless Debugging > Pair device with pairing code.\n\nNote: You cannot use a VPN on the phone.\n\n> ";
        std::getline(std::cin, ip);

        if (ip == "") {
            main();

        } else {
            clear();
            setTextColor("green");
            boldText("Android Toolkit - Pair over WIFI\n\n");
            std::cout << "Please provide the IP's Port.\n\n" << ip << ":xxxxx\n\n> ";
            std::getline(std::cin, port);

            clear();
            if (port == "") {
                main();
            } else {
                setTextColor("green");
                boldText("Android Toolkit - Pair over WIFI\n\n");
                cmd = adb + "pair " + ip + ":" + port;
                system(cmd.c_str());

                std::cout << "\nPress ENTER to continue.";
                std::getline(std::cin, null);
                clear();

                setTextColor("green");
                boldText("Android Toolkit - Pair over WIFI\n\n");
                std::cout << "Now provide the IP's Port located under 'IP address & Port'.\n\n" << ip << ":xxxxx\n\n> ";
                std::getline(std::cin, port);

                clear();
                if (port == "") {
                    main();
                } else {
                    setTextColor("green");
                    boldText("Android Toolkit - Pair over WIFI\n\n");
                    cmd = "clear;" + adb + "connect " + ip + ":" + port;
                    system(cmd.c_str());

                    std::cout << "\nPress ENTER to continue.";
                    std::getline(std::cin, null);
                    main();
                }
            }
        }
    } else if (input == "a2") {
        setTextColor("green");
        boldText("Android Toolkit - Disconnect ADB Wireless Device\n\n");
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
            clear();
            setTextColor("green");
            boldText("Android Toolkit - Disconnect ADB Wireless Device\n\n");
            system(cmd.c_str());

            std::getline(std::cin, null);
        }
        main();
    } else if (input == "a3") {
        clear();
        setTextColor("green");
        boldText("Android Toolkit - List Devices\n\n");
        
        cmd = adb + "devices";
        system(cmd.c_str());

        std::getline(std::cin, null);
        main();
    } else if (input == "a4") {
        setTextColor("green");
        boldText("Android Toolkit - Restart ADB\n\n");
        cmd = adb + "kill-server";
        system(cmd.c_str());
        cmd = adb + "start-server";
        system(cmd.c_str());

        std::cout << "\nPress ENTER to continue.";
        std::getline(std::cin, null);
        main();
    }
    else if (input == "b1") {
        setTextColor("green");
        boldText("Android Toolkit - Install Package\n\n");
        std::cout << "Please provide the path to the APK.\n\n> ";
        std::getline(std::cin, path);
        if (path == "") {
            main();
        } else {
            clear();
            setTextColor("green");
            boldText("Android Toolkit - Install Package\n\n");
            cmd = adb + "install " + path;
            system(cmd.c_str());

            std::cout << "\nFinished.\n\nPress ENTER to continue.";
            std::getline(std::cin, null);
            main();
        }
    } else if (input == "b2") {
        setTextColor("green");
        boldText("Android Toolkit - Uninstall Package\n\n");
        std::cout << "Please provide the name of the package to be uninstalled.\n\n> ";
        std::getline(std::cin, package);

        if (package == "") {
            main();
        } else {
            clear();
            setTextColor("green");
            boldText("Android Toolkit - Uninstall Package\n\n");

            cmd = adb + "shell pm uninstall --user 0 " + package;
            system(cmd.c_str());

            std::getline(std::cin, null);
            main();
        }
    } if (input == "b3") {
        setTextColor("green");
        boldText("Android Toolkit - Reinstall Package\n\nPlease provide the name of the system package to be reinstalled.\n\n> ");
        std::getline(std::cin, package);

        if (package == "") {
            main();
        } else {
            clear();
            setTextColor("green");
            boldText("Android Toolkit - Reinstall Package\n\n");
            cmd = adb + "shell pm install-existing --user 0 " + package;
            system(cmd.c_str());

            std::cout << "Finished.\n\nPress ENTER to continue.";
            std::getline(std::cin, null);
            main();
        }
    } else if (input == "b4") {
        setTextColor("green");
        boldText("Android Toolkit - List Packages\n\n");
        cmd = adb + "shell pm list packages";
        system(cmd.c_str());
        std::cout << "\nNote: If there is an error message at the bottom of the list, this is not bad and simply means that ADB cannot access the work profile.";

        std::getline(std::cin, null);
        main();
    } else if (input == "b5") {
        setTextColor("green");
        boldText("Android Toolkit - Debloat\n\n");
        std::cout << "Choose an Option.\n\na1. OneUI - Low\na2. OneUI - Medium\na3. OneUI - High\n\n> ";
        std::getline(std::cin, input);

        if (input == "") {
            main();

        } else if (input == "a1") {
            setTextColor("green");
            boldText("Android Toolkit - Debloat\n\n");
            system("/home/$USER/.android-toolkit/libs/bash.sh oneuiDebloatLow");
            std::getline(std::cin, null);
            main();

        } else if (input == "a2") {
            setTextColor("green");
            boldText("Android Toolkit - Debloat\n\n");
            system("/home/$USER/.android-toolkit/libs/bash.sh oneuiDebloatMed");
            std::getline(std::cin, null);
            main();

        } else if (input == "a3") {
            setTextColor("green");
            boldText("Android Toolkit - Debloat\n\n");
            system("/home/$USER/.android-toolkit/libs/bash.sh oneuiDebloatHigh");
            std::getline(std::cin, null);
            main();
        }
    } else if (input == "b6") {
        setTextColor("green");
        boldText("Android Toolkit - Backup / Restore\n\n");
        std::cout << "Please select an option.\n\n1. Backup\n2. Restore\n\n> ";
        std::getline(std::cin, input);
        clear();

        if (input == "") {
            main();
        } else if (input == "1") {
            setTextColor("green");
            boldText("Android Toolkit - Backup / Restore\n\n");
            std::cout << "Please provide the path to the folder where the backup will be saved to.\n\n> ";
            std::getline(std::cin, path);
            
            clear();
            if (path != "") {
                setTextColor("green");
                boldText("Android Toolkit - Backup / Restore\n\n");
                std::cout << "Please give a name to the backup.\n\n> ";
                std::getline(std::cin, backup);
                clear();

                if (backup == "") {
                    main();
                } else {
                    setTextColor("green");
                    boldText("Android Toolkit - Backup / Restore\n\n");
                    cmd = adb + "backup -all -f " + path + "/" + backup + ".ab";
                    system(cmd.c_str());

                    clear();
                    setTextColor("green");
                    boldText("Android Toolkit - Backup / Restore\n\n"); 
                    std::cout << "Please provide the encryption key.\n\n> ";
                    
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
            setTextColor("green");
            boldText("Android Toolkit - Backup / Restore\n\n");
            std::cout << "Please provide the path to the folder in which the backup file is stored.\n\n> ";
            std::getline(std::cin, path);
            clear();

            setTextColor("green");
            boldText("Android Toolkit - Backup / Restore\n\n");
            std::cout << "Please provide the name of the backup (No extension).\n\n> ";
            std::getline(std::cin, file);
            clear();

            setTextColor("green");
            boldText("Android Toolkit - Backup / Restore\n\n");

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
        setTextColor("green");
        boldText("Android Toolkit - Open Application\n\n");
        std::cout << "Please provide a package to open on the device.\n\n> ";

        std::getline(std::cin, package);
        clear();
        if (package != "") {
            setTextColor("green");
            boldText("Android Toolkit - Open Application\n\n");
            cmd = adb + "shell am start " + package;
            system(cmd.c_str());

            std::cout << "\nFinished.\n\nPress ENTER to continue.";

            std::getline(std::cin, null);
        }
        main();
    } else if (input == "c1") {
        setTextColor("green");
        boldText("Android Toolkit - Push / Pull\n\n");
        std::cout << "Please choose an option.\n\n1. Push file\n2. Pull file\n\n> ";
        std::getline(std::cin, input);
        clear();

        if (input == "") {
            main();
        } else if (input == "1") {
            setTextColor("green");
            boldText("Android Toolkit - Push / Pull\n\n");
            std::cout << "Please provide the path to file to be pushed.\n\n> ";
            std::getline(std::cin, file);
            clear();

            if (file == "") {
                main();
            } else {
                setTextColor("green");
                boldText("Android Toolkit - Push / Pull\n\n");
                std::cout << "Please provide the path on the device for the file to be pushed to.\n\n> ";
                std::getline(std::cin, path);
                clear();

                if (path == "") {
                    main();
                } else {
                    setTextColor("green");
                    boldText("Android Toolkit - Push / Pull\n\n");
                    cmd = adb + "push " + file + " sdcard" + path;
                    system(cmd.c_str());

                    std::getline(std::cin, null);
                    main();
                }
            }

        } else if (input == "2") {
            setTextColor("green");
            boldText("Android Toolkit - Push / Pull\n\n");
            std::cout << "Please provide the path to the file to be pulled.\n\n> ";
            std::getline(std::cin, file);
            clear();

            if (file == "") {
                main();
            } else {
                setTextColor("green");
                boldText("Android Toolkit - Push / Pull\n\n");
                std::cout << "Please provide the path on this computer for the file to be pulled to.\n\n> ";
                std::getline(std::cin, path);
                clear();

                if (path == "") {
                    main();
                } else {
                    setTextColor("green");
                    boldText("Android Toolkit - Push / Pull\n\n");
                    cmd = adb + "pull sdcard" + file + " " + path;
                    system(cmd.c_str());

                    std::getline(std::cin, null);
                    main();
                }
            }
        }
    } else if (input == "c2") {
        setTextColor("green");
        boldText("Android Toolkit - File Manager\n\n");
        while (std::cout << "Please provide a path on the device\n\nNote: The path automatically adds /sdcard/ to the beginning.\nPaths are absolute.\nType Exit to exit.\nType File to open file options.\nType Folder to open folder options.\n\n> " && std::getline(std::cin, path)) {
            clear();
            if (path == "exit" || path == "Exit") {
                break;
            } else if (path == "file" || path == "File") {
                setTextColor("green");
                boldText("Android Toolkit - File Manager\n\n");
                std::cout << "Please choose an option.\n\n1. Delete file\n2. Copy File\n3. Open file\n4. Edit File\n5. Rename File\n\n> ";
                std::getline(std::cin, input);

                clear();
                if (input == "1") {
                    setTextColor("green");
                    boldText("Android Toolkit - File Manager\n\n");
                    std::cout << "Please provide a path on the device of a file to be deleted.\n\n> ";
                    
                    std::getline(std::cin, file);
                    clear();
                    if (file != "") {
                        setTextColor("green");
                        boldText("Android Toolkit - File Manager\n\n");
                        cmd = adb + "shell rm /sdcard/" + file;
                        system(cmd.c_str());

                        std::cout << "\n\nPress ENTER to continue.";
                        std::getline(std::cin, null);
                    }
                } else if (input == "2") {
                    setTextColor("green");
                    boldText("Android Toolkit - File Manager\n\n");
                    std::cout << "Please provide the path on the device to the file that should be copied.\n\n> ";

                    std::getline(std::cin, file);
                    clear();
                    if (file != "") {
                        setTextColor("green");
                        boldText("Android Toolkit - File Manager\n\n");
                        std::cout << "Please provide the path where the file should be copied to.\n\n> ";
                        
                        std::getline(std::cin, path);
                        clear();
                        if (path != "") {
                            setTextColor("green");
                            boldText("Android Toolkit - File Manager\n\n"); 
                            std::cout << file << path;
                            cmd = adb + "shell cp /sdcard/" + file + " /sdcard/" + path;
                            system(cmd.c_str());

                            std::getline(std::cin, null);
                        }
                    }
                        
                } else if (input == "3") {
                    setTextColor("green");
                    boldText("Android Toolkit - File Manager\n\n");
                    std::cout << "Please provide the path to the file to be opened.\n\n> ";

                    std::getline(std::cin, file);
                    clear();
                    if (file != "") {
                        if (!std::filesystem::exists("/tmp/.android-toolkit/openFile") == true) {
                            system("rm -rf /tmp/.android-toolkit/openFile/; mkdir -p /tmp/.android-toolkit/openFile");
                        }

                        cmd = adb + "pull " + "/sdcard/" + file + " /tmp/.android-toolkit/openFile";
                        system(cmd.c_str());

                        system("xdg-open /tmp/.android-toolkit/openFile/*");

                        std::getline(std::cin, null);
                    }   
                } else if (input == "4") {
                    setTextColor("green");
                    boldText("Android Toolkit - File Manager\n\n");
                    std::cout << "Please provide the path to the file to be edited.\n\n> ";

                    std::getline(std::cin, file);
                    clear();
                    if (file != "") {
                        setTextColor("green");
                        boldText("Android Toolkit - File Manager\n\n");
                        if (!std::filesystem::exists("/tmp/.android-toolkit/editFile")) {
                            std::filesystem::remove_all("/tmp/.android-toolkit/editFile/");
                            std::ofstream("/tmp/.android-toolkit/editFile/");
                        }

                        cmd = adb + "pull /sdcard/" + file + " /tmp/.android-toolkit/editFile/";
                        system(cmd.c_str());

                        system("nano /tmp/.android-toolkit/editFile/*");

                        std::cout << "\n\nFinished.\n\nPress ENTER to continue.";
                        std::getline(std::cin, null);
                        clear();
                    }
                }
            } else if (path == "5") {
                setTextColor("green");
                boldText("Android Toolkit - File Manager\n\n");
                std::cout << "Please provide the path to the file's containting folder.\n\n> ";
                std::getline(std::cin, path);

                clear();
                if (path != "") {
                    setTextColor("green");
                    boldText("Android Toolkit - File Manager\n\n");
                    std::cout << "Please provide the current name of the file.\n\n> ";
                    std::getline(std::cin, file);

                    clear();
                    if (file != "") {
                        setTextColor("green");
                        boldText("Android Toolkit - File Manager\n\n");
                        std::cout << "Please provide the desired name of the file\n\n> ";
                        std::getline(std::cin, input);

                        if (input != "") {
                            setTextColor("green");
                            boldText("Android Toolkit - File Manager\n\n");
                            cmd = adb + "shell mv " + path + "/" + file + " " + path + "/" + input;
                            std::cout << "\n\nFinished.\n\nPress ENTER to continue.";
                        }
                    }
                }
            } else if (path == "folder" || path == "Folder") {
                setTextColor("green");
                boldText("Android Toolkit - File Manager\n\n");
                std::cout << "Please choose an option.\n\n1. Delete Folder\n2. Copy Folder\n3. Make Folder\n\n> ";

                std::getline(std::cin, input);
                clear();
                if (input == "1") {
                    setTextColor("green");
                    boldText("Android Toolkit - File Manager\n\n");
                    std::cout << "Please provide the path to the folder on the device to be deleted\n\n> ";

                    std::getline(std::cin, path);
                    clear();
                    if (path != "") {
                        setTextColor("green");
                        boldText("Android Toolkit - File Manager\n\n");
                        cmd = adb + "shell rm -r /sdcard/" + path;
                        system(cmd.c_str());

                        std::cout << "\n\nFinished.\n\nPress ENTER to continue.";
                        std::getline(std::cin, null);
                    }
                    clear();
                } else if (input == "2") {
                    setTextColor("green");
                    boldText("Android Toolkit - File Manager\n\n");
                    std::cout << "Please provide the path to the folder to be copied.\n\n> ";

                    std::getline(std::cin, file);
                    clear();
                    if (file != "") {
                        setTextColor("green");
                        boldText("Android Toolkit - File Manager\n\n");
                        std::cout << "Please provide the path for the folder to be copied to.\n\n> ";

                        std::getline(std::cin, path);
                        clear();
                        if (path != "") {
                            setTextColor("green");
                            boldText("Android Toolkit - File Manager\n\n");
                            cmd = adb + "shell cp -R /sdcard/" + file + " /sdcard/" + path;
                            system(cmd.c_str());

                            std::cout << "\n\nFinished.\n\nPress ENTER to continue.";
                            std::getline(std::cin, null);
                            clear();
                            if (null == "dispVar" && isDebug == true) {
                                std::cout << "file " << file << "\npath " << path << "\ncmd " << cmd;
                                std::getline(std::cin, null);
                            }
                        }
                    }
                } else if (input == "3") {
                    setTextColor("green");
                    boldText("Android Toolkit - File Manager\n\n");
                    std::cout << "Please provide the path for the folder to be created in.\n\n> ";

                    std::getline(std::cin, path);
                    clear();
                    if (path != "") {
                        setTextColor("green");
                        boldText("Android Toolkit - File Manager\n\n");
                        std::cout << "Please provide a name for the folder.\n\n> ";
                        
                        std::getline(std::cin, file);
                        clear();
                        if (file != "") {
                            setTextColor("green");
                            boldText("Android Toolkit - File Manager\n\n");

                            cmd = adb + "shell mkdir /sdcard/" + path + "/" + file;
                            system(cmd.c_str());

                            std::cout << "\n\nFinished.\n\nPress ENTER to continue.";
                            std::getline(std::cin, null);
                        }
                    }
                }
            } else {
                setTextColor("green");
                boldText("Android Toolkit - File Manager\n\n");
                path = "/sdcard/" + path;
                std::cout << "Current Path: " << path << "\n\n";
                cmd = adb + "shell ls -r " + path;
                system(cmd.c_str());
            }
        }
        main();
    } else if (input == "d1") {
        if (isSCRCPYImplemented == true) {
            while (1 == 1) {
                clear();
                setTextColor("green");
                boldText("Android Toolkit - SCRCPY\n\n");
                std::cout << "Please choose an option.\n\n";
                if (scrcpyConfig != "") {
                    std::cout << "Loaded SCRCPY config.\n";
                } else {
                    setTextColor("green");
                    boldText("Options Selected:\n");
                    if (dktp != "") { std::cout << "Desktop mode is on.\n"; } if (uhms != "") { std::cout << "Uhid Mouse is on.\n"; } if (uhkb != "") { std::cout << "Uhid Keyboard is on.\n"; } if (fscr != "") { std::cout << "Fullscreen is on\n"; } if (alot != "") { std::cout << "Always on Top is on\n"; } if (dbau != "") { std::cout << "Audio is on Both Devices\n"; } if (dfps != "") { std::cout << "Display FPS is on\n"; } if (appl != "") { std::cout << "Open Application " << applName << " on start\n"; } if (kdpo != "") { std::cout << "Device Screen will turn Off\n"; } if (kdfs != "") {std::cout << "Device will not Sleep\n"; }
                }
                std::cout << "\n1. Desktop Mode\n2. Uhid Mouse\n3. Uhid Keyboard\n4. Fullscreen\n5. Always on top\n6. Play Audio on Both Devices\n7. Print FPS\n8. Open Application\n9. Turn Device Screen Off\n10. Prevent Screen from Sleeping\n\na. Add custom flag\n\nType Exit to exit.\n\nType Save to save current settings or Load to run SCRCPY with saved settings.\n\nPress ENTER to continue\n\n> ";
                std::getline(std::cin, input);

                clear();
                if (input == "") {
                    setTextColor("green");
                    boldText("Android Toolkit - SCRCPY");
                    if (scrcpyConfig == "") {
                        cmd = home + "/.android-toolkit/libs/SCRCPY/scrcpy --max-fps=60 --video-bit-rate=2M" + dktp + uhms + uhkb + fscr + alot + dbau + dfps + appl + kdpo + kdfs + cscf;
                    } else {
                        cmd = home + "/.android-toolkit/libs/SCRCPY/scrcpy --max-fps=60 --video-bit-rate=2M" + scrcpyConfig;
                    }
                    system(cmd.c_str());
                    std::cout << "\nFinished.\n\nPress ENTER to continue.";
                    std::getline(std::cin, null);
                    break;
                } else if (input == "1") {
                    setTextColor("green");
                    boldText("Android Toolkit - SCRCPY\n\n");
                    if (dktp == "") {
                        std::cout << "Please provide the desktop size.\n\nEx. (1920x1080)\n\n> ";
                        std::getline(std::cin, input);

                        if (input != "") { dktp = " --new-display=" + input; }
                    } else { dktp = ""; }
                } else if (input == "2") {
                    if (uhms == "") { uhms = " --mouse=uhid"; } else { uhms = ""; }
                } else if (input == "3") {
                    if (uhkb == "") { uhkb = " --keyboard=uhid"; } else { uhkb = ""; }
                } else if (input == "4") {
                    if (fscr == "") { fscr = " -f"; } else { fscr = ""; }
                } else if (input == "5") {
                    if (alot == "") { alot = " --always-on-top"; } else { alot = ""; }
                } else if (input == "6") {
                    if (dbau == "") { dbau = " --audio-dup"; } else{ dbau = ""; }
                } else if (input == "7") {
                    if (dfps == "") { dfps = " --print-fps"; } else { dfps = ""; }
                } else if (input == "8") {
                    if (appl == "") {
                        setTextColor("green");
                        boldText("Android Toolkit - SCRCPY\n\n");
                        std::cout << "Please provide a package to open at start.\n\n> ";

                        std::getline(std::cin, applName);
                        clear();
                        if (applName != "") { appl = " --start-app=" + applName; }
                    } else { appl = ""; }
                } else if (input == "9") {
                    if (kdpo == "") { kdpo = " --turn-screen-off"; } else { kdpo = ""; }
                } else if (input == "10") {
                    if (kdfs == "") { kdfs = " --stay-awake"; } else { kdfs = ""; }
                } else if (input == "a") {
                    setTextColor("green");
                    boldText("Android Toolkit - SCRCPY");
                    std::cout << "Please provide a flag for SCRCPY\n\n> ";
                    std::getline(std::cin, input);
                    cscf = " " + input;
                } else if (input == "Save" || input == "save") {
                    cmd = "printf '" + dktp + uhms + uhkb + fscr + alot + dbau + dfps + appl + "' > " + home + "/.android-toolkit/SCRCPY-config.txt";
                    system(cmd.c_str());
                } else if (input == "Load" || input == "load" ) {
                    if (scrcpyConfig == "") {
                        setTextColor("green");
                        boldText("SCRCPY - Load Settings\n\n");
                        std::ifstream file(home + "/.android-toolkit/SCRCPY-config.txt");
                        if (!file.is_open()) {
                            std::cerr << "Error opening file.";
                        }
                        std::getline(file, scrcpyConfig);

                        std::getline(std::cin, null);

                        file.close();

                    } else {
                        scrcpyConfig = "";
                    }
                } else if (input == "Exit" || input == "exit") {
                    break;
                } else if (input == "dispVar" && isDebug == true) {
                    setTextColor("green");
                    boldText("SCRCPY - dispVar\n\n");
                    std::cout << "cmd when loaded:  " << home << "/.android-toolkit/libs/SCRCPY/scrcpy --max-fps=60 --video-bit-rate=2M" << scrcpyConfig << "\n\nscrcpyConfig:  " << scrcpyConfig;
                    
                    std::getline(std::cin, null);
                }
            }
        } else {
            setTextColor("green");
            boldText("Android Toolkit - SCRCPY\n\n");
            std::cout << "SCRCPY is not implemented. To do so, download the latest release of SCRCPY from https://github.com/Genymobile/scrcpy/releases/, and when installing, type './install -s'.\n\nPress ENTER to continue.";
            std::getline(std::cin, null);

        }
        main();
    } else if (input == "d2") {
        setTextColor("green");
        boldText("Android Toolkit - Screenshot / Record\n\n");
        std::cout << "Please choose an option.\n\n1. Screenshot\n2. Screen Record\n\n> ";
        std::getline(std::cin, input);

        clear();
        if (input == "") {
            main();
        } else {
            setTextColor("green");
            boldText("Android Toolkit - Screenshot / Record\n\n");
            std::cout << "Please provide a path for the capture.\n\n> ";
            std::getline(std::cin, path);

            clear();
            if (path == "") {
                main();
            } else {
                setTextColor("green");
                boldText("Android Toolkit - Screenshot / Record\n\n");
                std::cout << "Please provide a name for the capture.\n\n> ";
                std::getline(std::cin, file);

                clear();
                if (input == "1") {
                    setTextColor("green");
                    boldText("Android Toolkit - Screenshot / Record\n\n");
                    cmd = adb + "shell screencap -p > " + path + "/" + file + ".png";
                    system(cmd.c_str());

                    std::cout << "\nIf an error about multiple displays showed, it most likely isn't a problem.\nIf however this is causing a problem, type 'display'.";

                    std::getline(std::cin, input);
                    clear();
                    if (input == "display") {
                        setTextColor("green");
                        boldText("Android Toolkit - Screenshot / Record\n\n");
                        std::cout << "Please provide a display number (The one to the right of Display).\n\n";

                        cmd = adb + "shell dumpsys SurfaceFlinger --display-id";
                        system(cmd.c_str());

                        std::cout << "\n> ";
                        std::getline(std::cin, display);
                        clear();
                        if (display != "") {
                            setTextColor("green");
                            boldText("Android Toolkit - Screenshot / Record\n\n");
                            cmd = adb + "shell screencap -pd > " + path + "/" + file + ".png " + display;
                            system(cmd.c_str());

                            std::getline(std::cin, null);
                        }
                    }
                    main();
                } else if (input == "2") {
                    setTextColor("green");
                    boldText("Android Toolkit - Screenshot / Record\n\n");
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
        setTextColor("green");
        boldText("Android Toolkit - Restart\n\n");
        std::cout << "Type RESTART to continue.\n\n> ";

        std::getline(std::cin, input);
        clear();
        if (input == "RESTART") {
            setTextColor("green");
            boldText("Android Toolkit - Restart Device\n\n");
            std::cout << "Restarting Device...\n\n";
            cmd = adb + "shell reboot";
            system(cmd.c_str());
            std::cout << "\n\nFinished.\n\nPress ENTER to continue.";
            
            std::getline(std::cin, null);
        }

        main();
            
    } else if (input == "e2") {
        setTextColor("green");
        boldText("Android Toolkit - Power Off Device\n\n");
        std::cout << "Powering Off Device...\n\n";
        cmd = adb + "shell reboot -p";
        system(cmd.c_str());
        std::cout << "\n\nFinished.\n\nPress ENTER to continue.";
        
        std::getline(std::cin, null);
        main();
    } else if (input == "f1") {
        setTextColor("green");
        boldText("Android Toolkit - ADB Shell\n\n");
        std::cout << "Type exit to exit Shell.\n\n";
        cmd = adb + "shell";
        system(cmd.c_str());
        main();
    }
    
    else if (input == "g1"){
        setTextColor("green");
        boldText("Android Toolkit - README\n\n");
        std::ifstream file(home + "/.android-toolkit/README.md");
        while (std::getline(file, tmp)) {
            std::cout << tmp << std::endl;
        }

        std::cout << "\n\nPress ENTER to continue.";
        std::getline(std::cin, null);
        main();
    } else if (input == "dev" && isDebug == true) {
        setTextColor("green");
        boldText("Android Toolkit - Debug Settings\n\n");
        std::cout << "1. Config for Release\n2. Execute bash command\n\n> ";
        std::getline(std::cin, input);

        clear();
        if (input == "1") {
            system("rm -r ./build; rm ./libs/SCRCPY/*; rm ./nohup.out; printf '' > ./libs/SCRCPY/null");
        } else if (input == "2") {
            std::cout << "Enter a bash command.\n\n> ";

            std::getline(std::cin, cmd);
            clear();
            system(cmd.c_str());

            std::getline(std::cin, null);
        }
        main();
    } else if (input == "") {
        if (std::filesystem::exists("/tmp/.android-toolkit/") == true) {
            system("rm -rf /tmp/.android-toolkit/");
        }
        std::cout << "Exiting Android Toolkit...\n\n";
        return 0;
    } else {
        clear();
        isError = true;
        main();
    }
}