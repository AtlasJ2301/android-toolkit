#!/bin/bash

#functions
header() {
clear
echo "   ___     ___   _   __    ____     __    __   __"
echo "  /   \   |   \ | | |  \  |   _|   /  \  |  | |  \ "
echo " /  _  \  | |\ \| | |   | |    \  |    |  ||  |   |"
echo "/__| |__\ |_| \___| |__/  |__|\_\  \__/  |__| |__/"
printf "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
echo "   _____    __     __    _     _  _  __   _____"
echo "  |_   _|  /  \   /  \  | |   | |// |  | |_   _|"
echo "    | |   |    | |    | | |_  |  \   ||    | |"
printf "    |_|    \__/   \__/  |___| |_|_\ |__|   |_|\n\n"
}

outro() {
    clear
    echo "   ___     ___   _   __    ____     __    __   __"
    echo "  /   \   |   \ | | |  \  |   _|   /  \  |  | |  \ "
    echo " /  _  \  | |\ \| | |   | |    \  |    |  ||  |   |"
    echo "/__| |__\ |_| \___| |__/  |__|\_\  \__/  |__| |__/"
    printf "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
    echo "   _____    __     __    _     _  _  __   _____"
    echo "  |_   _|  /  \   /  \  | |   | |// |  | |_   _|"
    echo "    | |   |    | |    | | |_  |  \   ||    | |"
    echo "    |_|    \__/   \__/  |___| |_|_\ |__|   |_|"
    sleep .1
    clear
    echo "   ___     ___   _   __    ____     __    __   __"
    echo "  /   \   |   \ | | |  \  |   _|   /  \  |  | |  \ "
    echo " /  _  \  | |\ \| | |   | |    \  |    |  ||  |   |"
    echo "/__| |__\ |_| \___| |__/  |__|\_\  \__/  |__| |__/"
    printf "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
    echo "   _____    __     __    _     _  _  __   _____"
    echo "  |_   _|  /  \   /  \  | |   | |// |  | |_   _|"
    echo "    | |   |    | |    | | |_  |  \   ||    | |"
    sleep .1
    clear
    echo "   ___     ___   _   __    ____     __    __   __"
    echo "  /   \   |   \ | | |  \  |   _|   /  \  |  | |  \ "
    echo " /  _  \  | |\ \| | |   | |    \  |    |  ||  |   |"
    echo "/__| |__\ |_| \___| |__/  |__|\_\  \__/  |__| |__/"
    printf "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
    echo "   _____    __     __    _     _  _  __   _____"
    echo "  |_   _|  /  \   /  \  | |   | |// |  | |_   _|"
    sleep .1
    clear
    echo "   ___     ___   _   __    ____     __    __   __"
    echo "  /   \   |   \ | | |  \  |   _|   /  \  |  | |  \ "
    echo " /  _  \  | |\ \| | |   | |    \  |    |  ||  |   |"
    echo "/__| |__\ |_| \___| |__/  |__|\_\  \__/  |__| |__/"
    printf "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
    echo "   _____    __     __    _     _  _  __   _____"
    sleep .1
    clear
    echo "   ___     ___   _   __    ____     __    __   __"
    echo "  /   \   |   \ | | |  \  |   _|   /  \  |  | |  \ "
    echo " /  _  \  | |\ \| | |   | |    \  |    |  ||  |   |"
    echo "/__| |__\ |_| \___| |__/  |__|\_\  \__/  |__| |__/"
    printf "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
    sleep .1
    clear
    echo "   ___     ___   _   __    ____     __    __   __"
    echo "  /   \   |   \ | | |  \  |   _|   /  \  |  | |  \ "
    echo " /  _  \  | |\ \| | |   | |    \  |    |  ||  |   |"
    echo "/__| |__\ |_| \___| |__/  |__|\_\  \__/  |__| |__/"
    sleep .1
    clear
    echo "   ___     ___   _   __    ____     __    __   __"
    echo "  /   \   |   \ | | |  \  |   _|   /  \  |  | |  \ "
    echo " /  _  \  | |\ \| | |   | |    \  |    |  ||  |   |"
    sleep .1
    clear
    echo "   ___     ___   _   __    ____     __    __   __"
    echo "  /   \   |   \ | | |  \  |   _|   /  \  |  | |  \ "
    sleep .1
    clear
    echo "   ___     ___   _   __    ____     __    __   __"
    clear
}

returnIn() {
    header
    for num in "3" "2" "1"; do echo "Returning in ${num}..."; sleep 1; header; done;
    exec "$0" "$@"
}

returnNow() {
    exec "$0" "$@"
}

#initial prompt

header
printf "ver alpha 0.2.2 (DEPRECATED) \n\n- Install (1)\n- Uninstall (2)\n- Re-Install (3)\n- Debloat (4)\n- List Packages (5)\n- Check ADB Devices (6)"
printf "\n- Backup / Restore Device (7)\n- Push / Pull File (8)\n- SCRCPY (9)\n- Exit android-toolkit (Enter Key)\n"
if [ -f ./usr/src/debug.sh ]; then
    printf "\n- Enter Debug Mode (dev)\n"
fi
read -p "> " ans

#commands according to input

if [ "${ans}" = '' ]; then
    outro
    exit
fi

if [ $ans = '1' ]; then
    header
    printf "Please provide the location and name of the APK file.\nEx: /home/user/Downloads/file.apk\n*Case Sensitive\n\nPress the Enter Key to return\n"
    read -p "> " apk
    if [ $apk =  ]; then
        returnNow
    else
        header

        adb install $apk
        sleep 1

        returnIn
    fi
fi

if [ $ans = '2' ]; then
    header

    printf "Please provide the name of the package on your android device to be uninstalled.\nEx: com.android.phone\n*Case Sensitive\n\nPress the Enter Key to return\n"
    read -p "> " pkg

    if [ $pkg =  ]; then
        returnNow
    else
        header

        adb shell pm uninstall --user 0 $pkg
        sleep 1

        returnIn
    fi
fi

if [ $ans = '3' ]; then
    header
    
    printf "Please provide the name of the uninstalled package that you wish to reinstall.\nNote: This only works with uninstalled system files.\nEx: com.android.phone\n\n*Case Sensitive\n"
    read -p "> " pkg
    if [ $pkg = ]; then
        returnNow
    else
        header
        
        adb shell pm install-existing --user 0 $pkg
        sleep 1

        returnIn
    fi
fi

if [ $ans = '4' ]; then
    header

    printf "Please provide the brand / operating system of the android device.\nNote: Error messages may occur, this is normal and means the packages were not on the device already.\n\nSamsung / OneUI (1)\n\nPress the Enter Key to return\n"
    read -p "> " os
    if [ $os =  ]; then
        returnNow
    fi

    if [ $os = '1' ]; then
        header

        for cmd in "com.att.csoiam.mobilekey" "com.samsung.android.kidsinstaller" "com.att.csoiam.mobilekey" "com.samsung.android.kidsinstaller" "com.att.personalcloud" "com.facebook.system" "com.facebook.katana" "com.facebook.appmanager" "com.google.android.healthconnect.controller" "com.android.bookmarkprovider" "com.android.dreams.basic" "com.android.dreams.phototable" "com.android.hotwordenrollment.xgoogle" "com.android.mms.service" "com.android.providers.partnerbookmarks" "com.google.android.apps.docs.editors.sheets" "com.google.mainline.adservices" "com.google.android.adservices.api" "com.google.android.apps.messaging" "com.google.android.apps.docs" "com.google.android.apps.photos" "com.google.android.apps.tachyon" "com.google.android.feedback" "com.google.android.googlequicksearchbox" "com.google.android.inputmethod.latin" "com.google.android.marvin.talkback" "com.google.android.syncadapters.calendar" "com.google.android.tts" "com.google.android.apps.youtube.music" "com.google.ar.core" "com.samsung.android.app.settings.bixby" "com.samsung.android.bixby.wakeup" "com.samsung.android.bixby.agent" "com.samsung.android.bixbyvision.framework" "com.sec.android.app.shealth" "com.samsung.android.arzone" "com.samsung.android.video" "com.sec.android.app.samsungapps" "com.samsung.android.dynamiclock" "com.samsung.android.tvplus" "com.samsung.android.app.watchmanagerstub" "com.samsung.android.app.watchmanager" "com.samsung.android.waterplugin" "com.samsung.android.accessibility.talkback" "com.samsung.android.lool" "com.samsung.android.messaging" "com.sec.android.easyonehand" "com.sec.android.app.sbrowser" "com.sec.android.easyMover.Agent" "com.sec.android.daemonapp" "com.sec.android.app.voicenote" "com.samsung.android.oneconnect" "com.samsung.android.voc" "com.samsung.android.calendar" "com.sec.android.app.popupcalculator" "com.samsung.android.app.dressroom" "com.samsung.android.scloud" "com.samsung.android.sdk.handwriting" "com.samsung.android.universalswitch" "com.samsung.safetyinformation" "com.samsung.storyservice" "com.samsung.android.service.aircommand" "com.samsung.android.samsungpassautofill" "com.samsung.android.samsungpass" "com.samsung.android.spay" "com.samsung.android.spayfw" "com.samsung.android.da.daagent" "com.samsung.android.aremoji" "com.sec.android.mimage.avatarstickers" "com.samsung.android.aremojieditor" "com.samsung.android.stickercenter" "com.android.bips" "com.google.android.printservice.recommendation" "com.samsung.android.game.gametools" "com.samsung.android.app.camera.sticker.facearavatar.preload" "com.samsung.android.service.peoplestripe" "com.samsung.android.app.appsedge" "com.sec.android.dexsystemui" "com.sec.android.desktopmode.uiservice" "com.sec.android.app.desktoplauncher" "com.vcast.mediamanager" "com.samsung.vmmhux" "com.vzw.hss.myverizon" "com.asurion.android.verizon.vms" "com.motricity.verizon.ssodownloadable" "com.vzw.hs.android.modlite" "com.samsung.vvm" "com.att.dh" "com.att.dtv.shaderemote" "com.att.tv" "com.samsung.attvvm" "com.att.myWireless" "com.asurion.android.protech.att" "com.att.android.attsmartwifi" "com.synchronoss.dcs.att.r2g" "com.wavemarket.waplauncher" "com.pandora.android" "com.sec.penup" "com.wb.goog.got.conquest" "com.playstudios.popslots" "com.gsn.android.tripeaks" "com.foxnextgames.m3" "com.microsoft.skydrive" "com.android.egg" "com.aura.oobe.att" "com.android.chrome" "com.sec.android.app.chromecustomizations" "com.google.android.youtube" "com.google.android.apps.maps" "com.android.browser" "com.android.cellbroadcastreceiver" "com.android.cellbroadcastreceiver.overlay.common" "com.android.deskclock" "com.android.dreams.basic" "com.android.emergency" "com.android.hotwordenrollment.okgoogle" "com.android.mms" "com.android.printspooler" "com.android.statementservice" "com.android.wallpaper.livepicker" "com.android.wallpaperbackup" "com.android.wallpapercropper" "com.android.providers.downloads.ui" "com.android.sharedstoragebackup" "com.google.android.gm" "com.google.android.videos" "com.samsung.android.coldwalletservice" "com.google.android.apps.aiwallpapers" "com.google.android.health.connect.backuprestore" "com.google.android.apps.bard" "com.samsung.android.smartswitchassistant" "com.microsoft.appmanager" "com.microsoft.office.officehubrow" "com.microsoft.office.outlook" "com.sec.android.gallery3d" "com.samsung.android.visionintelligence" "com.android.cameraextensions" "com.sec.android.iaft" "com.sec.factory.camera" "com.samsung.android.knox.attestation" "com.sec.bcservice" "com.sec.android.app.camera" "com.att.mobilesecurity" "com.amazon.mShop.android.shopping" "com.samsung.android.app.updatecenter" "com.test.LTEfunctionality" "com.samsung.android.audiomirroring" "com.sec.android.autodoodle.service" "com.samsung.android.rampart" "com.samsung.android.mdecservice" "com.android.calllogbackup" "com.samsung.android.hwresourceshare" "com.samsung.android.app.clipboardedge" "com.samsung.android.app.taskedge" "com.sec.android.easyMover" "com.google.android.documentsui" "com.sec.android.app.myfiles" "com.aura.jet.att" "com.sec.android.app.quicktool" "com.samsung.android.dialer" "com.samsung.android.app.contacts" "com.samsung.android.app.interpreter" "com.sec.hearingadjust" "com.google.android.as" "com.sec.providers.assisteddialing" "com.samsung.android.authfw" "com.sec.spp.push" "com.samsung.android.knox.pushmanager" "com.samsung.android.mdx" "com.att.iqi" "com.samsung.android.app.parentalcare" "com.samsung.android.smartsuggestions" "com.samsung.android.app.omcagent" "android.autoinstalls.config.samsung" "com.amazon.appmanager" "com.google.android.apps.restore" "com.google.android.partnersetup" "com.samsung.aasaservice" "com.samsung.android.allshare.service.mediashare" "com.samsung.android.app.routines" "com.samsung.android.aware.service" "com.samsung.android.beaconmanager" "com.samsung.android.easysetup" "com.samsung.android.mdm" "com.samsung.android.mobileservice" "com.samsung.android.net.wifi.wifiguider" "com.samsung.android.networkdiagnostic" "com.samsung.android.samsungpositioning" "com.samsung.android.svcagent" "com.samsung.android.wifi.softap.resources" "com.samsung.crane" "com.samsung.ipservice" "com.sec.android.app.factorykeystring" "com.sec.android.app.hwmoduletest" "com.sec.android.app.magnifier" "com.sec.android.app.parser" "com.sec.android.app.SecSetupWizard" "com.sec.android.app.setupwizard" "com.sec.android.app.setupwizardlegalprovider" "com.sec.facatfunction" "com.sec.android.diagmonagent" "com.samsung.android.widget.pictureframe" "com.samsung.android.hdmapp" "com.sec.android.mimage.photoretouching" "com.sec.android.RilServiceModeApp" "com.sec.app.RilErrorNotifier" "com.sec.hiddenmenu" "com.sec.phone" "com.sec.location.nsflp2" "com.sem.factoryapp" "com.android.providers.calendar" "com.samsung.klmsagent" "com.samsung.android.brightnessbackupservice" "com.samsung.android.incall.contentprovider" "com.sec.imslogger" "com.sec.android.app.servicemodeapp" "com.samsung.oda.service" "com.samsung.android.knox.analytics.uploader" "com.samsung.android.app.earphonetypec" "com.samsung.android.dkey" "com.samsung.android.ipsgeofence" "com.samsung.android.knox.containercore" "com.samsung.android.knox.zt.framework" "com.samsung.android.sdm.config" "com.samsung.android.service.livedrawing" "com.samsung.android.shortcutbackupservice" "com.sec.location.nfwlocationprivacy" "com.android.traceur" "com.google.android.gms.supervision" "com.google.android.overlay.modules.captiveportallogin.forframework" "com.google.android.overlay.modules.documentsui" "com.google.android.overlay.modules.permissioncontroller" "com.google.android.overlay.gmsconfig.photos" "com.android.virtualmachine.res" "com.google.android.overlay.gmsconfig.asi" "com.samsung.InputEventApp" "com.android.cts.ctsshim" "com.samsung.sait.sohservice" "com.sec.android.app.wlantest" "com.sec.android.smartfpsadjuster" "com.google.android.federatedcompute" "com.qualcomm.location" "com.sec.android.app.uwbtest" "com.sec.android.app.soundalive" "com.samsung.android.mocca" "com.samsung.android.inputshare" "com.qti.qcc" "com.qti.snapdragon.qdcm_ff" "com.samsung.android.cameraxservice" "com.android.rkpdapp" "com.sec.android.app.billing" "com.skms.android.agent"
        do
            printf "\n$cmd | "; adb shell pm uninstall --user 0 $cmd;
        done
        printf "\ncom.samsung.android.game.gos | "
        adb shell pm disable --user 0 com.samsung.android.game.gos
        printf "\n\n"
        read -p "Press Enter Key to Return" null

        returnIn
    fi
fi

if [ $ans = '5' ]; then
    header

    adb shell pm list packages
    read -p "Press Enter to Return" null
    exec "$0" "$@"
fi

if [ $ans = '6' ]; then
    header

    adb devices
    read -p "Press Enter to Return" null
    exec "$0" "$@"
fi


if [ $ans = '7' ]; then
    header

    printf "Please choose an action.\n- Backup (1)\n- Restore (2)\n"
    read -p "> " ans

    if [ $ans =  ]; then
        returnNow
    fi

    if [ $ans = '1' ]; then
        header

        printf "Please provide the location for where the backup will be created. Type 1 for default path (~/.android-toolkit/Backups)\nEx: /home/user/Downloads\n"
        read -p "> " pth

        if [ "${pth}" = '1' ]; then
            pth="/home/$USER/.android-toolkit/Backups"
            if [ ! -d /home/$USER/.android-toolkit/Backups ]; then
                mkdir -p /home/$USER/.android-toolkit/Backups
            fi
        fi

        header

        printf "What should the name of the backup be?\n"
        read -p "> " name

        adb backup -all -f $pth/$name.ab
        sleep 1

        header

        printf "What is your encryption key?\n"
        read -p "> " enc

        printf $enc > "${pth}/encryption-key.txt"

        returnIn
    fi

    if [ $ans = '2' ]; then
        header
        
        printf "Please provide the location of your backup.Type 1 for default path (~/.android-toolkit/Backups)\nEx: /home/user/Downloads\n\n*Case Sensitive\n"
        read -p "> " bkp

        header

        if [ "${bkp}" = '1' ]; then
            bkp="/home/$USER/.android-toolkit/Backups"
        fi

        header

        printf "What is the name of the backup?\n"
        read -p "> " name

        if [ ! -f $bkp/$name ]; then
            header
            printf "Error: Backup does not exist!"
            sleep 3
            exec "$0" "$@"
        fi

        header
        
        adb restore $bkp
        sleep 1

        returnIn
    fi
fi

if [ $ans = '8' ]; then
    header

    printf "Please choose an action.\n\n- Push File (1)\n- Pull File (2)\n\nPress the Enter Key to return\n"
    read -p "> " ans

    if [ $ans =  ]; then
        returnNow
    fi

    if [ $ans = '1' ]; then
        header

        printf "Please provide the path on the computer to the file to be pushed.\nEx: /home/user/Downloads/File.txt\nNote: To create a space in a file or folder name, type '\ ' where a space would go\n\n*Case Sensitive"
        read -p "> " $file
        
        header
        
        printf "Please provide the path on the android device to where file will be pushed to.\nEx: sdcard/Downloads/\n"
        read -p "> " $path

        header
        
        adb push $file $path
        sleep 1
        
        returnIn
    fi

    if [ $ans = '2' ]; then
        header

        printf "Please provide the path to the file on the android device to be pulled.\nEx: sdcard/Downloads/File.txt\nNote: To create a space in a file or folder name, type '\ ' where a space would go\n\n*Case Sensitive\n"
        read -p "> " $file

        header

        printf "Please provide the path on the computer to where the file will be pushed to.\nEx: /home/user/Downloads/\n"
        read -p ">" $path

        header

        adb pull $file $path
        sleep 1

        returnIn
    fi
fi

if [ $ans = '9' ]; then
    header
    if [ ! -f ./usr/bin/SCRCPY/scrcpy ]; then
        echo "SCRCPY files do not exist. Please download them from https://github.com/Genymobile/scrcpy and place them in the SCRCPY folder in the index folder before installing"
        read -p "Press enter to return" confirm
        returnNow
    else
        read -p "Desktop Mode (y/n)" idsk
        if [ $idsk = 'y' ]; then
            read -p "Desktop Size? Ex:1920x1080:" dskSze
            dsk="--new-display=${dskSze}/240"
        fi
        read -p "Uhid Mouse (y/n)" iums
        if [ $iums = 'y' ]; then
            ums="--mouse=uhid"
        fi
        read -p "Uhid Keyboard (y/n)" iukb
        if [ $iukb = 'y' ]; then
            ukb="--keyboard=uhid"
        fi
        read -p "Fullscreen (y/n)" ifsc
        if [ $ifsc = 'y' ]; then
            fsc="-f"
        fi
        cd ./usr/src
        nohup ./../bin/SCRCPY/scrcpy $dsk $ums $ukb $fsc & 
        disown $!
        outro
        exit
    fi 
fi

if [ $ans = 'dev' ] || [ -f ./usr/src/debug.sh ]; then
    header

    ./usr/src/debug.sh

    ans="$(cat ./usr/src/ans)"

    if [ "${ans}" = ''  ]; then
        returnNow
    fi

    if [ $ans = '1' ]; then
        clear
        rm -r ~/.android-toolkit/
        rm ./usr/src/ans
        rm ./usr/ect/backupTest/*.*
        rm ./usr/src/nohup.out
        echo "Complete"
        sleep 1
        returnIn
    fi

    if [ $ans = '2' ]; then
        ln -sfd ./usr/bin/SCRCPY/ ./
        sleep 1
        returnNow
    fi

    if [ $ans = '3' ]; then
        cp -r ./../SCRCPY/ ./usr/bin/
        returnNow
    fi

    if [ $ans = '4' ]; then
        clear
        for file in "*.AppImage" rm "./usr/ect/backupTest/*.*" "./usr/src/nohup.out" "./usr/bin/SCRCPY/adb" "./usr/bin/SCRCPY/icon.png" "./usr/bin/SCRCPY/scrcpy" "./usr/bin/SCRCPY/scrcpy.1" "./usr/bin/SCRCPY/scrcpy-server" "./.DirIcon" "-r /home/$USER/.android-toolkit/"; do rm $file; done;
        sudo rm /usr/bin/android-toolkit
        printf "Complete"
        sleep 1
        returnNow
    fi

    if [ $ans = '5' ]; then
        read -p "> " cmd
        bash -c "${cmd}"
    fi

    rm ./usr/src/ans
fi
exit
