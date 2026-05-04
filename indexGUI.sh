#!/bin/bash

clear

# Variables

if [[ -f ./usr/src/gui ]]; then     # Check if running as installation or
                                    # as appimage and tells how to open
    yad="./usr/bin/yad"             # Yet Another Dialog.

else

    yad="yad"
    
fi

ver="Beta 0.5.3.1"

#functions

exec() {

    "${cmd[@]}"

}

# For initial page, use 0 for exit, 1_ for switching pages, 
# and all other digits for options 

pageZero() {

    cmd=(

        "${yad}" --form
        --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
        --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
        --center 
        --title "Android Toolkit" 
        --text "Welcome to Android Toolkit Version $ver!\nPlease Choose an Option:\n\n\n" 
        --button "Install":1 
        --button "Uninstall":2 
        --button "Re-Install":3 
        --button "DeBloat":4 
        --button "Next Page"\!go-next\!:11 
        --button "Exit"\!gtk-cancel\!:0 

    )

    exec

    ans=$?  # this sets the 'ans' variable to the last 
            # input by the user, which is the YAD input
            # in this case

    if [[ "${ans}" = '0' ]]; then # Exit

        exit

    fi

    if [[ "${ans}" = '1' ]]; then # Install

        apk=$(

            "$yad" --file \
            --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
            --center \
            --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
            --title "Android Toolkit - Install" \
            --text="Please select an APK file"
        
        )
        
        if [[ "$?" = 1 ]]; then

            pageZero

        else

            adb install "$apk" 2>&1 | "$yad" --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --title "Android Toolkit | Install" --text-info --center --height=200 --width=600

            if [[ "$?" = 1 ]]; then

                exit

            else

                pageZero

            fi

        fi

    fi

    if [[ "${ans}" = '2' ]]; then # Uninstall
        
        pkg=$(
        
            "$yad" --entry \
                --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                --center \
                --title "Android Toolkit - Uninstall" \
                --text "Please provide the name of the package on your android device to be uninstalled.\nEx: com.android.phone\n*Case Sensitive\n\n\n" 
        
        )
        
        if [[ "$?" = 1 ]]; then # Cancel

            pageZero

        else
        
            adb shell pm uninstall --user 0 "$pkg" 2>&1 | "$yad" --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --text-info --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --title "Android Toolkit - Uninstall" --center --height=200 --width=600

            if [[ $? = 1 ]]; then

                exit

            else

                pageZero

            fi
        
        fi
    fi

    if [[ "${ans}" = '3' ]]; then # Re-Install
        
        pkg=$(
       
            "$yad" --entry \
                --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                --center \
                --title "Android Toolkit - Re-Install" \
                --text="Please provide the name of the uninstalled package that you wish to reinstall.\nNote: This only works with uninstalled system files.\nEx: com.android.phone\n*Case Sensitive\n\n\n"
      
        )
        
        if [[ "$?" = 1 ]]; then # Cancel

            pageZero

        else

            adb shell pm install-existing --user 0 "$pkg" 2>&1 | "$yad" --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --center --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --text-info --title "Android Toolkit - Re-Install" --height=200 --width=600

            if [[ "$?" = 1 ]]; then

                exit

            else

                pageZero

            fi

        fi
    fi

    if [[ "${ans}" = '4' ]]; then # DeBloat
        
        cmd=(

            "$yad" --question
                --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                --center
                --title "Android Toolkit - DeBloat"
                --text "Please provide the brand / operating system of the android device.\nNote: Error messages may occur, this is normal and means the packages were not on the device already.\n\n\n"
                --button "Return"\!gtk-cancel\!:0
                --button "Samsung / OneUI":1

        )

        exec
         
        os=$?

        if [[ "${os}" = '0' ]]; then # Cancel

            pageZero

        fi

        if [[ "${os}" = '1' ]]; then # OneUI

            null=$(
                "$yad" --question \
                    --center \
                    --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                    --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                    --title "Android Toolkit - Debloat" \
                    --text "$(printf "Choose a Debloating Level:\n- Low: Useless System Packages.\n- Medium: Non-Essential System Packages.\n- High: Non-Essential System Packages and Certain Google / Samsung Apps.\n\nNote: it is HIGHLY recommended that you choose Medium or High, because\nLow will not delete some spyware packages such as OK Google Hotword,\nwhich constantly listens to your microphone")." --button "Low":1 --button "Medium":2 --button "High":3 --button "Return"\!gtk-cancel\!:0
            )

            if [[ "$?" = 0 ]]; then

                pageZero

            else

                if [[ "$?" = 1 ]]; then # Low

                    (

                    for cmd in "com.att.csoiam.mobilekey" "com.samsung.android.dqagent" "com.wsomacp" "com.att.personalcloud" "com.sec.android.app.bluetoothagent" "com.facebook.system" "com.facebook.katana" "com.samsung.android.camerasdkservice" "com.samsung.android.server.wifi.mobilewips" "com.sec.vsim.ericssonnsds.webapp" "com.android.mms.service" "com.android.providers.partnerbookmarks" "com.google.android.apps.docs.editors.sheets" "com.google.mainline.adservices" "com.google.android.adservices.api" "com.google.android.ondevicepersonalization.services" "com.google.android.apps.docs" "com.google.android.feedback" "com.google.android.inputmethod.latin" "com.google.android.marvin.talkback" "com.sec.android.app.shealth" "com.samsung.android.arzone" "com.samsung.android.tvplus" "com.samsung.android.waterplugin" "com.samsung.android.accessibility.talkback" "com.sec.android.app.voicenote" "com.samsung.android.oneconnect" "com.samsung.android.voc" "com.samsung.android.calendar" "com.sec.android.app.popupcalculator" "com.samsung.android.universalswitch" "com.samsung.android.bbc.bbcagent" "com.samsung.safetyinformation" "com.samsung.android.service.aircommand" "com.knox.vpn.proxyhandler" "com.samsung.android.dck.timesync" "com.android.theme.font.notoserifsource" "com.samsung.android.app.appsedge" "com.vcast.mediamanager" "com.samsung.vmmhux" "com.vzw.hss.myverizon" "com.asurion.android.verizon.vms" "com.motricity.verizon.ssodownloadable" "com.vzw.hs.android.modlite" "com.att.dtv.shaderemote" "com.att.tv" "com.asurion.android.protech.att" "com.att.android.attsmartwifi" "com.synchronoss.dcs.att.r2g" "com.wavemarket.waplauncher" "com.pandora.android" "com.sec.penup" "com.wb.goog.got.conquest" "com.playstudios.popslots" "com.gsn.android.tripeaks" "com.foxnextgames.m3" "com.android.egg" "com.aura.oobe.att" "com.sec.android.app.chromecustomizations" "com.sec.android.CcInfo" "com.android.browser" "com.android.cellbroadcastreceiver" "com.android.cellbroadcastreceiver.overlay.common" "com.android.deskclock" "com.android.emergency" "com.android.hotwordenrollment.okgoogle" "com.android.mms" "com.android.statementservice" "com.sec.modem.settings" "com.sec.epdgtestapp" "com.android.sharedstoragebackup" "com.google.android.apps.bard" "com.samsung.android.smartswitchassistant" "com.microsoft.office.officehubrow" "com.microsoft.office.outlook" "com.samsung.android.visionintelligence" "com.sec.android.iaft" "com.sec.factory.camera" "com.sec.bcservice" "com.att.mobilesecurity" "com.amazon.mShop.android.shopping" "com.sec.enterprise.knox.cloudmdm.smdms" "com.test.LTEfunctionality" "com.monotype.android.font.foundation" "com.samsung.android.rampart" "com.samsung.android.app.clipboardedge" "com.aura.jet.att" "com.samsung.android.app.contacts" "com.sec.providers.assisteddialing" "com.samsung.android.authfw" "com.sec.spp.push" "com.samsung.android.knox.pushmanager" "com.att.iqi" "android.autoinstalls.config.samsung" "com.amazon.appmanager" "com.google.android.partnersetup" "com.samsung.aasaservice" "com.samsung.android.mdm" "com.samsung.gpuwatchapp" "com.samsung.android.networkdiagnostic" "com.samsung.android.samsungpositioning" "com.samsung.android.svcagent" "com.samsung.android.wifi.softap.resources" "com.samsung.ipservice" "com.sec.android.app.factorykeystring" "com.sec.android.app.hwmoduletest" "com.sec.android.app.parser" "com.sec.android.app.setupwizard" "com.sec.android.app.setupwizardlegalprovider" "com.sec.facatfunction" "com.samsung.android.hdmapp" "com.sec.android.RilServiceModeApp" "com.sec.app.RilErrorNotifier" "com.sec.hiddenmenu" "com.sem.factoryapp" "com.samsung.klmsagent" "com.sec.imslogger" "com.sec.android.app.servicemodeapp" "com.samsung.oda.service" "com.samsung.android.service.stplatform" "com.samsung.android.knox.analytics.uploader" "com.google.android.onetimeinitializer" "com.samsung.android.dkey" "com.samsung.android.ipsgeofence" "com.samsung.android.knox.zt.framework" "com.samsung.android.sdm.config" "com.sec.location.nfwlocationprivacy" "com.android.traceur" "com.google.android.overlay.modules.captiveportallogin.forframework" "com.google.android.overlay.modules.documentsui" "com.samsung.android.carkey" "com.sec.android.diagmonagent" "com.google.android.overlay.gmsconfig.photos" "com.android.virtualmachine.res" "com.monotype.android.font.samsungone" "com.samsung.android.smartface.overlay" "com.google.android.overlay.gmsconfig.asi" "com.samsung.InputEventApp" "com.android.cts.ctsshim" "com.samsung.sait.sohservice" "com.sec.android.app.wlantest" "com.sec.android.smartfpsadjuster" "com.google.android.federatedcompute" "com.qualcomm.location" "com.sec.android.app.uwbtest" "com.sec.android.app.hwmoduletest" "com.qti.qcc" "com.qti.snapdragon.qdcm_ff" "com.samsung.android.cameraxservice" "com.android.rkpdapp" "com.skms.android.agent"; do 
                            
                        printf "\n$cmd "

                        adb shell pm uninstall --user 0 "$cmd" 2>&1

                    done

                    ) | "yad" --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --center --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --text-info --title "Android Toolkit - DeBloat" --height=700 --width=800

                    if [[ "$?" = 1 ]]; then

                        exit

                    else

                        pageZero

                    fi

                fi

                if [[ "$?" = 2 ]]; then # Medium

                    (

                        for cmd in "com.att.csoiam.mobilekey" "com.samsung.android.kidsinstaller" "com.samsung.android.dqagent" "com.wsomacp" "com.att.personalcloud" "com.sec.android.app.bluetoothagent" "com.facebook.system" "com.samsung.faceservice" "com.facebook.katana" "com.facebook.appmanager" "com.samsung.android.camerasdkservice" "com.samsung.android.vtcamerasettings" "com.android.dreams.phototable" "com.samsung.android.server.wifi.mobilewips" "com.sec.vsim.ericssonnsds.webapp" "com.android.hotwordenrollment.xgoogle" "com.android.mms.service" "com.android.providers.partnerbookmarks" "com.google.android.apps.docs.editors.sheets" "com.google.mainline.adservices" "com.google.android.adservices.api" "com.google.android.ondevicepersonalization.services" "com.google.android.apps.docs" "com.google.android.feedback" "com.google.android.inputmethod.latin" "com.google.android.marvin.talkback" "com.google.android.tts" "com.sec.android.app.shealth" "com.samsung.android.dbsc" "com.samsung.android.arzone" "com.samsung.android.tvplus" "com.samsung.android.waterplugin" "com.samsung.android.accessibility.talkback" "com.google.android.apps.accessibility.voiceaccess" "com.sec.android.easyonehand" "com.sec.android.app.voicenote" "com.samsung.android.oneconnect" "com.samsung.android.voc" "com.samsung.android.calendar" "com.sec.android.app.popupcalculator" "com.samsung.android.sdk.handwriting" "com.google.android.safteycenter.resources" "com.samsung.android.universalswitch" "com.samsung.android.bbc.bbcagent" "com.samsung.safetyinformation" "com.samsung.storyservice" "com.samsung.android.service.aircommand" "com.samsung.android.service.aircommandmanager" "com.samsung.android.da.daagent" "com.knox.vpn.proxyhandler" "com.samsung.android.aremoji" "com.sec.android.mimage.avatarstickers" "com.samsung.android.dck.timesync" "com.samsung.android.aremojieditor" "com.android.bips" "com.google.android.printservice.recommendation" "com.samsung.android.game.gametools" "com.android.theme.font.notoserifsource" "com.samsung.android.app.camera.sticker.facearavatar.preload" "com.samsung.android.app.appsedge" "com.vcast.mediamanager" "com.samsung.vmmhux" "com.samsung.android.themestore" "com.vzw.hss.myverizon" "com.asurion.android.verizon.vms" "com.motricity.verizon.ssodownloadable" "com.sec.android.widgetapp.easymodecontactswidget" "com.vzw.hs.android.modlite" "com.att.dh" "com.att.dtv.shaderemote" "com.att.tv" "com.att.myWireless" "com.asurion.android.protech.att" "com.samsung.android.smartcallprovider" "com.att.android.attsmartwifi" "com.synchronoss.dcs.att.r2g" "com.wavemarket.waplauncher" "com.pandora.android" "com.sec.penup" "com.wb.goog.got.conquest" "com.hiya.star" "com.playstudios.popslots" "com.samsung.android.scpm" "com.gsn.android.tripeaks" "com.foxnextgames.m3" "com.android.egg" "com.aura.oobe.att" "com.sec.android.app.chromecustomizations" "com.sec.android.CcInfo" "com.android.browser" "com.android.cellbroadcastreceiver" "com.android.cellbroadcastreceiver.overlay.common" "com.android.deskclock" "com.android.dreams.basic" "com.android.emergency" "com.android.hotwordenrollment.okgoogle" "com.android.mms" "com.android.statementservice" "com.sec.modem.settings" "com.android.wallpaper.livepicker" "com.android.wallpaperbackup" "com.android.wallpapercropper" "com.samsung.android.dsms" "com.sec.epdgtestapp" "com.android.sharedstoragebackup" "com.google.android.apps.aiwallpapers" "com.google.android.apps.bard" "com.samsung.android.smartswitchassistant" "com.microsoft.appmanager" "com.microsoft.office.officehubrow" "com.microsoft.office.outlook" "com.samsung.android.visionintelligence" "com.android.cameraextensions" "com.sec.android.iaft" "com.sec.factory.camera" "com.samsung.android.knox.attestation" "com.sec.bcservice" "com.att.mobilesecurity" "com.samsung.android.lool" "com.google.android.apps.turbo" "com.amazon.mShop.android.shopping" "com.sec.enterprise.knox.cloudmdm.smdms" "com.test.LTEfunctionality" "com.sec.android.autodoodle.service" "com.monotype.android.font.foundation" "com.samsung.android.rampart" "com.samsung.android.mdecservice" "com.android.calllogbackup" "com.samsung.android.app.clipboardedge" "com.aura.jet.att" "com.samsung.android.app.contacts" "com.sec.providers.assisteddialing" "com.samsung.android.authfw" "com.sec.spp.push" "com.samsung.android.knox.pushmanager" "com.google.audio.hearing.visualization.accessibility.scribe" "com.samsung.android.mdx" "com.att.iqi" "com.samsung.android.smartsuggestions" "android.autoinstalls.config.samsung" "com.amazon.appmanager" "com.google.android.apps.restore" "com.google.android.partnersetup" "com.samsung.aasaservice" "com.samsung.android.allshare.service.mediashare" "com.samsung.android.app.routines" "com.samsung.android.beaconmanager" "com.samsung.android.easysetup" "com.samsung.android.mdm" "com.samsung.android.net.wifi.wifiguider" "com.samsung.gpuwatchapp" "com.samsung.android.networkdiagnostic" "com.samsung.android.samsungpositioning" "com.samsung.android.svcagent" "com.samsung.android.wifi.softap.resources" "com.samsung.crane" "com.samsung.ipservice" "com.sec.android.app.factorykeystring" "com.sec.android.app.hwmoduletest" "com.sec.android.app.magnifier" "com.sec.android.app.parser" "com.sec.android.app.setupwizard" "com.sec.android.app.setupwizardlegalprovider" "com.sec.facatfunction" "com.sec.android.diagmonagent" "com.samsung.android.widget.pictureframe" "com.samsung.android.hdmapp" "com.sec.android.RilServiceModeApp" "com.sec.app.RilErrorNotifier" "com.sec.hiddenmenu" "com.sem.factoryapp" "com.samsung.klmsagent" "com.samsung.android.brightnessbackupservice" "com.sec.imslogger" "com.sec.android.app.servicemodeapp" "com.samsung.oda.service" "com.samsung.android.service.stplatform" "com.samsung.android.knox.analytics.uploader" "com.google.android.onetimeinitializer" "com.samsung.android.app.earphonetypec" "com.samsung.android.dkey" "com.samsung.android.incall.contentprovider" "com.samsung.android.ipsgeofence" "com.samsung.android.knox.zt.framework" "com.samsung.android.sdm.config" "com.samsung.android.service.livedrawing" "com.sec.location.nfwlocationprivacy" "com.android.traceur" "com.google.android.overlay.modules.captiveportallogin.forframework" "com.google.android.overlay.modules.documentsui" "com.samsung.android.carkey" "com.sec.android.diagmonagent" "com.diotek.sec.lookup.dictionary" "com.google.android.overlay.modules.permissioncontroller" "com.google.android.overlay.gmsconfig.photos" "com.android.virtualmachine.res" "com.monotype.android.font.samsungone" "com.samsung.android.smartface.overlay" "com.google.android.overlay.gmsconfig.asi" "com.samsung.InputEventApp" "com.samsung.cmh" "com.android.cts.ctsshim" "com.samsung.sait.sohservice" "com.sec.android.app.wlantest" "com.samsung.android.smartface" "com.sec.android.smartfpsadjuster" "com.google.android.federatedcompute" "com.qualcomm.location" "com.sec.android.app.uwbtest" "com.sec.android.app.hwmoduletest" "com.samsung.android.mocca" "com.samsung.android.inputshare" "com.qti.qcc" "com.qti.snapdragon.qdcm_ff" "com.samsung.android.knox.kpecore" "com.samsung.android.cameraxservice" "com.android.rkpdapp" "com.skms.android.agent" "com.sec.location.nsflp2" "com.samsung.android.app.omcagent" "com.google.android.gms.location.history"; do 
                            
                            printf "\n$cmd "

                            adb shell pm uninstall --user 0 "$cmd" 2>&1

                        done

                    ) | "yad" --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --center --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --text-info --title "Android Toolkit - DeBloat" --height=700 --width=800

                    if [[ "$?" = 1 ]]; then

                        exit

                    else

                        pageZero

                    fi

                fi

                if [[ "$?" = 3 ]]; then # High
            
                    (
                        for cmd in "com.att.csoiam.mobilekey" "com.samsung.android.app.contacts" "com.wsomacp" "com.sec.android.app.bluetoothagent" "com.samsung.android.knox.kpecore" "com.android.bluetoothmidiservice" "com.samsung.android.dqagent" "com.samsung.android.kidsinstaller" "com.att.personalcloud" "com.facebook.system" "com.facebook.katana" "com.facebook.appmanager" "com.samsung.faceservice" "com.samsung.android.camerasdkservice" "com.samsung.android.vtcamerasettings" "com.google.android.healthconnect.controller" "com.android.bookmarkprovider" "com.sec.vsim.ericssonnsds.webapp" "com.samsung.android.server.wifi.mobilewips" "com.android.dreams.basic" "com.android.dreams.phototable" "com.android.mms.service" "com.android.providers.partnerbookmarks" "com.google.android.apps.docs.editors.sheets" "com.google.android.ondevicepersonalization.services" "com.google.mainline.adservices" "com.google.android.adservices.api" "com.google.android.apps.docs" "com.google.android.apps.photos" "com.google.android.apps.tachyon" "com.google.android.feedback" "com.samsung.android.dbsc" "com.google.android.googlequicksearchbox" "com.google.android.inputmethod.latin" "com.google.android.marvin.talkback" "com.google.android.syncadapters.calendar" "com.google.android.tts" "com.google.android.apps.youtube.music" "com.google.ar.core" "com.samsung.android.app.settings.bixby" "com.samsung.android.dynamiclock" "com.samsung.android.bixby.wakeup" "com.samsung.android.bixby.agent" "com.samsung.android.bbc.bbcagent" "com.google.android.apps.accessibility.voiceaccess" "com.samsung.android.bixbyvision.framework" "com.sec.android.app.shealth" "com.samsung.android.arzone" "com.samsung.android.video" "com.google.android.safteycenter.resources" "com.sec.android.app.volumemonitorprovider" "com.samsung.android.service.aircommandmanager" "com.sec.android.app.samsungapps" "com.samsung.android.dck.timesync" "com.samsung.android.tvplus" "com.samsung.android.app.watchmanagerstub" "com.samsung.android.app.watchmanager" "com.samsung.android.waterplugin" "com.knox.vpn.proxyhandler" "com.samsung.android.accessibility.talkback" "com.samsung.android.lool" "com.samsung.android.messaging" "com.sec.android.app.ve.vebgm" "com.sec.android.easyonehand" "com.samsung.android.stickercenter" "com.sec.android.app.sbrowser" "com.sec.android.easyMover.Agent" "com.samsung.android.themestore" "com.sec.android.daemonapp" "com.android.theme.font.notoserifsource" "com.sec.android.widgetapp.easymodecontactswidget" "com.sec.android.app.voicenote" "com.samsung.android.oneconnect" "com.samsung.android.voc" "com.samsung.android.calendar" "com.sec.android.app.popupcalculator" "com.samsung.android.app.dressroom" "com.samsung.android.scloud" "com.samsung.android.sdk.handwriting" "com.samsung.android.universalswitch" "com.samsung.safetyinformation" "com.samsung.android.smartcallprovider" "com.google.android.projection.gearhead" "com.samsung.storyservice" "com.samsung.android.service.aircommand" "com.samsung.android.samsungpassautofill" "com.sec.android.CcInfo" "com.android.hotwordenrollment.xgoogle" "com.hiya.star" "com.samsung.android.samsungpass" "com.samsung.android.spay" "com.samsung.android.spayfw" "com.samsung.android.scpm" "com.samsung.android.da.daagent" "com.samsung.android.aremoji" "com.sec.android.mimage.avatarstickers" "com.samsung.android.aremojieditor" "com.android.bips" "com.google.android.printservice.recommendation" "com.samsung.android.mcfds" "com.samsung.android.game.gametools" "com.samsung.android.app.camera.sticker.facearavatar.preload" "com.samsung.android.dsms" "com.samsung.android.service.peoplestripe" "com.sec.epdgtestapp" "com.samsung.android.appseparation" "com.samsung.android.app.appsedge" "com.sec.modem.settings" "com.sec.android.dexsystemui" "com.sec.android.desktopmode.uiservice" "com.sec.android.app.dexonpc" "com.sec.android.app.desktoplauncher" "com.vcast.mediamanager" "com.samsung.vmmhux" "com.vzw.hss.myverizon" "com.asurion.android.verizon.vms" "com.samsung.android.rampart" "com.samsung.android.authfw" "com.google.android.contactkeys" "com.motricity.verizon.ssodownloadable" "com.google.android.apps.turbo" "com.vzw.hs.android.modlite" "com.samsung.vvm" "com.att.dh" "com.google.android.as" "com.att.dtv.shaderemote" "com.att.tv" "com.samsung.attvvm" "com.att.myWireless" "com.asurion.android.protech.att" "com.sec.enterprise.knox.cloudmdm.smdms" "com.att.android.attsmartwifi" "com.synchronoss.dcs.att.r2g" "com.google.android.as.oss" "com.wavemarket.waplauncher" "com.pandora.android" "com.monotype.android.font.foundation" "com.sec.penup" "com.wb.goog.got.conquest" "com.samsung.android.forest" "com.playstudios.popslots" "com.samsung.android.fmm" "com.gsn.android.tripeaks" "com.foxnextgames.m3" "com.microsoft.skydrive" "com.android.egg" "com.aura.oobe.att" "com.android.chrome" "com.sec.android.app.chromecustomizations" "com.google.android.youtube" "com.google.android.apps.maps" "com.android.browser" "com.android.cellbroadcastreceiver" "com.android.cellbroadcastreceiver.overlay.common" "com.android.deskclock" "com.android.emergency" "com.samsung.android.emergency" "com.android.hotwordenrollment.okgoogle" "com.android.mms" "com.android.printspooler" "com.android.statementservice" "com.android.wallpaper.livepicker" "com.android.wallpaperbackup" "com.android.wallpapercropper" "com.google.audio.hearing.visualization.accessibility.scribe" "com.android.providers.downloads.ui" "com.android.sharedstoragebackup" "com.google.android.gm" "com.google.android.videos" "com.samsung.android.coldwalletservice" "com.google.android.apps.aiwallpapers" "com.google.android.health.connect.backuprestore" "com.samsung.android.smartswitchassistant" "com.microsoft.appmanager" "com.samsung.gpuwatchapp" "com.microsoft.office.officehubrow" "com.microsoft.office.outlook" "com.sec.android.gallery3d" "com.samsung.android.visionintelligence" "com.android.cameraextensions" "com.sec.android.iaft" "com.sec.factory.camera" "com.sec.bcservice" "com.samsung.knox.securefolder" "com.att.mobilesecurity" "com.amazon.mShop.android.shopping" "com.samsung.android.app.updatecenter" "com.test.LTEfunctionality" "com.samsung.android.audiomirroring" "com.sec.android.autodoodle.service" "com.samsung.android.rampart" "com.samsung.android.mdecservice" "com.android.calllogbackup" "com.samsung.android.hwresourceshare" "com.samsung.android.app.clipboardedge" "com.samsung.android.app.taskedge" "com.sec.android.easyMover" "com.google.android.documentsui" "com.sec.android.app.myfiles" "com.aura.jet.att" "com.sec.android.app.quicktool" "com.samsung.android.dialer" "com.samsung.android.app.contacts" "com.samsung.android.app.interpreter" "com.google.android.onetimeinitializer" "com.sec.hearingadjust" "com.diotek.sec.lookup.dictionary" "com.sec.providers.assisteddialing" "com.sec.android.diagmonagent" "com.samsung.android.authfw" "com.samsung.android.carkey" "com.sec.spp.push" "com.samsung.android.knox.attestation" "com.samsung.android.smartswitchassistant" "com.samsung.android.app.clipboardedge" "com.samsung.android.smartface.overlay" "com.samsung.cmh" "com.samsung.android.wifi.softap.resources" "com.samsung.android.knox.pushmanager" "com.samsung.android.mdx" "com.att.iqi" "com.samsung.android.app.parentalcare" "com.samsung.android.smartsuggestions" "com.samsung.android.app.omcagent" "android.autoinstalls.config.samsung" "com.amazon.appmanager" "com.google.android.apps.restore" "com.google.android.partnersetup" "com.samsung.aasaservice" "com.samsung.android.allshare.service.mediashare" "com.samsung.android.app.routines" "com.samsung.android.beaconmanager" "com.samsung.android.easysetup" "com.samsung.android.mdm" "com.samsung.android.mobileservice" "com.samsung.android.net.wifi.wifiguider" "com.samsung.android.networkdiagnostic" "com.samsung.android.samsungpositioning" "com.monotype.android.font.samsungone" "com.samsung.android.svcagent" "com.samsung.android.wifi.softap.resources" "com.samsung.crane" "com.samsung.ipservice" "com.sec.android.app.factorykeystring" "com.sec.android.app.hwmoduletest" "com.sec.android.app.magnifier" "com.sec.android.app.parser" "com.samsung.android.smartface" "com.sec.android.app.setupwizard" "com.sec.android.app.setupwizardlegalprovider" "com.sec.facatfunction" "com.sec.android.diagmonagent" "com.samsung.android.widget.pictureframe" "com.samsung.android.hdmapp" "com.sec.android.mimage.photoretouching" "com.sec.android.RilServiceModeApp" "com.sec.app.RilErrorNotifier" "com.google.android.gms.location.history" "com.sec.hiddenmenu" "com.sec.location.nsflp2" "com.sem.factoryapp" "com.android.providers.calendar" "com.samsung.klmsagent" "com.samsung.android.brightnessbackupservice" "com.samsung.android.incall.contentprovider" "com.sec.imslogger" "com.sec.android.app.servicemodeapp" "com.samsung.oda.service" "com.samsung.android.knox.analytics.uploader" "com.samsung.android.app.earphonetypec" "com.samsung.android.dkey" "com.samsung.android.ipsgeofence" "com.samsung.android.knox.containercore" "com.samsung.android.knox.zt.framework" "com.samsung.android.sdm.config" "com.samsung.android.service.stplatform" "com.samsung.android.service.livedrawing" "com.samsung.android.shortcutbackupservice" "com.sec.location.nfwlocationprivacy" "com.android.traceur" "com.google.android.gms.supervision" "com.google.android.overlay.modules.captiveportallogin.forframework" "com.google.android.overlay.modules.documentsui" "com.google.android.overlay.modules.permissioncontroller" "com.google.android.overlay.gmsconfig.photos" "com.android.virtualmachine.res" "com.google.android.overlay.gmsconfig.asi" "com.samsung.InputEventApp" "com.android.cts.ctsshim" "com.samsung.sait.sohservice" "com.sec.android.app.wlantest" "com.sec.android.smartfpsadjuster" "com.google.android.federatedcompute" "com.qualcomm.location" "com.sec.android.app.uwbtest" "com.sec.android.app.soundalive" "com.samsung.android.mocca" "com.samsung.android.inputshare" "com.qti.qcc" "com.qti.snapdragon.qdcm_ff" "com.samsung.android.app.omcagent" "com.samsung.android.cameraxservice" "com.android.rkpdapp" "com.sec.android.app.billing" "com.skms.android.agent"; do 
                            
                            printf "\n$cmd "

                            adb shell pm uninstall --user 0 "$cmd" 2>&1

                        done

                    ) | "yad" --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --center --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --text-info --title "Android Toolkit - DeBloat" --height=700 --width=800

                    if [[ "$?" = 1 ]]; then

                        exit

                    else

                        pageZero

                    fi

                fi

                

            fi

        fi

    fi

    if [[ "${ans}" = '11' ]]; then

        pageOne

    fi

}

pageOne() {
    
    cmd=(

        "$yad" --form 
            --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
            --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
            --center
            --title "Android Toolkit"
            --text "Welcome to Android Toolkit Version $ver!\nPlease Choose an Option:\n\n\n"
            --button "List Packages":5
            --button "ADB Devices":6
            --button "Backup / Restore":7
            --button "Push / Pull":8
            --button "Previous Page"\!go-previous\!:10
            --button "Next Page"\!go-next\!:11
            --button "Exit"\!gtk-cancel\!:0

    )

    exec

    ans=$? 

    if [[ "${ans}" = '10' ]]; then
    
        pageZero

    fi

    if [[ "${ans}" = '11' ]]; then

        pageTwo

    fi

    if [[ "${ans}" = '5' ]]; then # List Packages

        adb shell pm list packages 2>&1 | "$yad" --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --center --text-info --title "Android Toolkit - List Packages" --width=650 --height=550

        if [[ $? = 1 ]]; then

            exit

        else

            pageOne

        fi

    fi

    if [[ "${ans}" = '6' ]]; then # ADB Devices

        adb devices 2>&1 | "$yad" --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --center --text-info --title "Android Toolkit - ADB Devices" --width=650 --height=550

        if [[ $? = 1 ]]; then

            exit

        else

            pageOne

        fi

    fi


    if [[ "${ans}" = '7' ]]; then # Backup / Restore

        cmd=(

            "$yad" --question
                --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                --center
                --title "Android Toolkit - Backup | Restore"
                --text "Please choose an action:"
                --button "Return"\!gtk-cancel\!:0
                --button "Backup":1
                --button "Restore":2
                --height 150
                --weight 300

        )

        exec

        bkRs=$?

        if [[ "${bkRs}" = '0' ]]; then # Cancel

            pageOne

        fi

        if [[ "${bkRs}" = '1' ]]; then # Backup

            pth=$(

                "$yad" --file \
                    --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                    --directory \
                    --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                    --center \
                    --title "Android Toolkit - Backup" \
                    --text "Please select the location where the backup will be created.\nDefault Path: ~/.android-toolkit/Backups" \
                    --button "Cancel"\!gtk-cancel\!:1 \
                    --button "Ok"\!gtk-ok\!:0 \
                    --button "Default Path":2
            
            )

            if [[ "$?" = 1 ]]; then

                pageOne

            else

                if [[ "$?" = '2' ]]; then

                    if [[ ! -d /home/$USER/.android-toolkit/Backups ]]; then

                        mkdir -p /home/$USER/.android-toolkit/Backups

                    fi

                    pth="/home/$USER/.android-toolkit/Backups"

                fi

                if [[ "$?" = 0 ]]; then

                    name=$(

                        "$yad" --entry \
                            --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                            --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                            --center \
                            --title "Android Toolkit - Backup" \
                            --text "What should the name of the backup be?" \
                            --width 400

                    )

                    if [[ "$?" = 1 ]]; then

                        pageOne

                    else

                        adb backup -all -f "$pth"/"$name".ab 2>&1 | "$yad" --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --center --text-info --title "Android Toolkit - Backup" --height 550 --width 650

                        if [[ "$?" = 1 ]]; then

                            pageOne

                        else

                            enc=$(
                            
                                "${yad}" --entry \
                                    --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                                    --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                                    --center \
                                    --title "Android Toolkit - Backup" \
                                    --text "What is your encryption key?" \
                                    --width 650

                            )

                            if [[ "$?" = 1 ]]; then

                                exit

                            else

                                printf $enc > "${pth}/encryption-key.txt"

                                pageOne

                            fi

                        fi

                    fi

                fi

            fi

        fi

        if [[ "${bkRs}" = '2' ]]; then # Restore

            bkp=$( "$yad" --file --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --center --title "Android Toolkit - Restore" --text "Please select the backup.\nDefault Path: ~/.android-toolkit/Backups" )

            if [[ "${bkp}" = '1' ]]; then

                pageOne

            else

                if [[ ! -f "$bkp" ]]; then

                    "$yad" --error --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --center --title "Android Toolkit - Restore" --text "Developer Error: File Directory Parse Error"

                    if [[ "$?" = 0 ]]; then
                    
                        pageOne

                    else

                        exit

                    fi

                else
            
                    adb restore "$bkp" 2>&1 | "$yad" --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --center --text-info --title "Android Toolkit - Restore" --width=800 --height=400
                
                    if [[ "$?" = 0 ]]; then
                    
                        pageOne

                    else

                        exit

                    fi

                    pageOne

                fi

            fi

            if [[ "${bkp}" = '0' ]]; then

                if [[ ! -f "$bkp" ]]; then

                    "$yad" --error --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --center --title "Android Toolkit - Restore" --text "Error: Backup does not exist!"

                    pageOne

                else
            
                adb restore "$bkp"/"$name" 2>&1 | "$yad" --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --center --text-info --title "Android Toolkit - Restore"
                
                pageOne

                fi

            fi
            
        fi

    fi

    if [[ "$ans" = '8' ]]; then # Push / Pull

        cmd=(

            "$yad" --question
                --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                --center
                --title "Android Toolkit - Push | Pull"
                --text "Please choose an action."
                --button "Return"\!gtk-cancel\!:0
                --button "Push":1
                --button "Pull":2

        )

        exec

        psPl=$?

        if [[ "$psPl" = '0' ]]; then # Cancel

            pageOne

        fi

        if [[ "$psPl" = '1' ]]; then # Push

            file=$(

                "$yad" --file \
                    --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                    --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                    --center \
                    --title "Android Toolkit - Push" \
                    --text "Please select the file to be pushed to the android device"
            
            )

            if [[ "$?" = 1 ]]; then

                pageOne

            else

                path=$(

                    "$yad" --entry \
                        --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                        --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                        --center \
                        --title "Android Toolkit - Push" \
                        --text "Please provide the path on the android device to where file will be pushed to.\nEx: sdcard/Download"

                )

                if [[ "$?" = 1 ]]; then

                    pageOne

                else

                    adb push "$file" "$path" 2>&1 | "$yad" --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --text-info --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --title "Android Toolkit - Push" --center --width=600 --height=400
                
                    if [[ "$?" = 0 ]]; then
                    
                        pageOne

                    else

                        exit

                    fi

                fi

            fi

        fi

        if [[ "$psPl" = '2' ]]; then # Pull

            file=$(

                "$yad" --entry \
                    --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                    --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                    --center \
                    --title "Android Toolkit - Pull" \
                    --text "Please provide the path to the file on the android device to be pulled.\nEx: sdcard/Download/File.txt\nNote: To create a space in a file or folder name, type a backslash directly before the space.\n*Case Sensitive"
            
            )

            if [[ "$?" = 1 ]]; then

                pageOne

            else
            
                path=$(

                    "$yad" --file \
                        --directory \
                        --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                        --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                        --center \
                        --title "Android Toolkit - Push" \
                        --text "Please provide the path on the computer to where the file will be pushed to.\nEx: /home/user/Downloads/"
                
                )

                if [[ "$?" = 1 ]]; then

                    pageOne

                else

                    adb pull "$file" "$path" | "$yad" --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --text-info --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --title "Android Toolkit - Pull" --center --width=600 --height=400
                    
                    if [[ "$?" = 0 ]]; then

                        pageOne

                    else

                        exit

                    fi

                fi

            fi

        fi

    fi

}

pageTwo() {

    if [[ -f ./usr/src/debugGUI.sh ]]; then

        cmd=(

            "$yad" --form 
                --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png 
                --center 
                --title "Android Toolkit" 
                --text "Welcome to Android Toolkit Version $ver!\nPlease Choose an Option:\n" 
                --button "SCRCPY":9 
                --button "Screenshot / Record":21
                --button "Install / Uninstall atk":22
                --button "Debug Mode":20
                --button "Previous Page"\!go-previous\!:10
                --button "Next Page"\!go-next\!:11 
                --button "Exit"\!gtk-cancel\!:0 

        )

        exec

        ans=$?
    
    else

        cmd=(

            "$yad" --form 
                --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png 
                --center 
                --title "Android Toolkit" 
                --text "Welcome to Android Toolkit Version $ver!\nPlease Choose an Option:\n" 
                --button "SCRCPY":9 
                --button "Screenshot / Record":21
                --button "Install / Uninstall atk":22
                --button "Previous Page"\!go-previous\!:10
                --button "Next Page"\!go-next\!:11 
                --button "Exit"\!gtk-cancel\!:0 

        )

        exec

        ans=$?

    fi

    if [[ "${ans}" = '0' ]]; then # Exit

        exit

    fi

    if [[ "${ans}" = '10' ]]; then # Previous Page

        pageOne

    fi

    if [[ "${ans}" = '11' ]]; then # Next Page

        pageThree

    fi


    if [[ "${ans}" = '9' ]]; then # SCRCPY

        if [ ! -f ./usr/bin/SCRCPY/scrcpy ]; then

            "$yad" --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --center --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --error --title "Android Toolkit - SCRCPY" --text="SCRCPY files do not exist. Please download them from https://github.com/Genymobile/scrcpy and place them in the SCRCPY folder in the index folder before installing / compiling"
            
            pageTwo

        else

            cmd=(

                "$yad" --question 
                    --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                    --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                    --center
                    --title "Android Toolkit - SCRCPY"
                    --text "Desktop Mode?"
                    --button "Cancel"\!gtk-cancel\!:0
                    --button "Yes":1
                    --button "No"
        
            )

            exec

            idsk=$?

            if [[ "${idsk}" = '0' ]]; then

                pageTwo
                
            fi

            if [[ "${idsk}" = '1' ]]; then

                cmd=(

                        "$yad" --entry
                            --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                            --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                            --center
                            --title "Android Toolkit - SCRCPY"
                            --text "$(printf "Desktop Size?\nEx:1920x1080")"

                )

                exec

                dskSze=$?
                        
                dsk="--new-display=${dskSze}/240"

            fi

            cmd=(

                "$yad" --question
                    --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                    --center
                    --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                    --title "Android Toolkit - SCRCPY"
                    --text "Uhid Mouse?"
                    --button "Cancel"\!gtk-cancel\!:0
                    --button "Yes":1
                    --button "No"

            )

            exec

            iums=$?

            if [[ "${iums}" = '0' ]]; then

                pageTwo

            fi

            if [[ "${iums}" = '1' ]]; then

                ums="--mouse=uhid"

            fi
            
            cmd=(
                
                "$yad" --question
                    --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                    --center
                    --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                    --title "Android Toolkit - SCRCPY"
                    --text "Uhid Keyboard?"
                    --button "Cancel"\!gtk-cancel\!:0
                    --button "Yes":1
                    --button "No"
            
            )

            exec

            iukb=$?

            if [[ "${iukb}" = '0' ]]; then

                pageTwo

            fi

            if [[ "${iukb}" = '1' ]]; then

                ukb="--keyboard=uhid"

            fi

            cmd=(

                "$yad" --question
                    --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                    --center
                    --title "Android Toolkit - SCRCPY"
                    --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                    --text "Fullscreen?"
                    --button "Cancel"\!gtk-cancel\!:0
                    --button "Yes":1
                    --button "No"

            )

            exec

            ifsc=$?

            if [[ "${ifsc}" = '0' ]]; then
            
                pageTwo
            
            fi

            if [[ "${ifsc}" = '1' ]]; then
            
                fsc="-f"
            
            fi

            if [[ "${idsk}" != '0' ]] && [[ "${iums}" != '0' ]] && [[ "${iukb}" != '0' ]] && [[ "${ifsc}" != '0' ]]; then

                ogDir=$( pwd ) # Save Current Directory

                cd ./usr/src # For nohup output

                nohup ./../bin/SCRCPY/scrcpy $dsk $ums $ukb $fsc & disown $! # To detach

                cd "$ogDir" # Return to Original Directory

                pageTwo 

            fi

        fi 
        
    fi

    if [[ "$ans" = '21' ]]; then # Screenshot / Record

        cmd=(
            
            "$yad" --question 
                --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png 
                --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png 
                --center 
                --title "Android Toolkit - Screenshot / Record" 
                --text "Please select an option." 
                --button "Return"\!gtk-cancel\!:0 
                --button "Screenshot":1 
                --button "Record":2

        )

        exec

        ans=$?

        if [[ "$ans" = 0 ]]; then # Cancel

            pageTwo
        
        else

            if [[ "$ans" = 1 ]]; then # Screenshot

                path=$(

                    "$yad" --file \
                        --center \
                        --directory \
                        --title "Android Toolkit - Screenshot" \
                        --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                        --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                        --text "Please select a location for the screenshot"

                )

                if [[ "$?" = 1 ]]; then
                
                    pageTwo

                else

                    name=$(

                        "$yad" --entry \
                            --center \
                            --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                            --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                            --title "Android Toolkit - Screenshot" \
                            --text "What should the name of the screenshot be?"

                    )

                    if [[ "$?" = 1 ]]; then

                        pageTwo

                    else

                        adb shell screencap -p > "$path/$name.png"

                        screenshot=$(
                            
                            "$yad" --info \
                            --center \
                            --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                            --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                            --title "Android Toolkit - Screenshot" \
                            --text "Capture Finished as $name.png"

                        )

                        if [[ "$?" = 1 ]]; then

                            exit

                        else

                            pageTwo

                        fi

                    fi

                fi

            fi

            if [[ "$ans" = 2 ]]; then

                adb shell mkdir /sdcard/tmp # Create temporary location on device to store video

                    
                adb shell screenrecord /sdcard/tmp/tmp.mp4 & # Record

                PID=$(pgrep -f "adb shell screenrecord /sdcard/tmp/tmp.mp4") # Get Process ID

                cmd=$(
                    "$yad" --info --center --title "Android Toolkit - Recording..." --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --text "Recording..." --button "Stop":0
                )

                if [[ "$?" = 0 ]]; then

                    kill "$PID"

                    path=$(
                        "$yad" --file \
                            --save \
                            --title "Android Toolkit - Record" \
                            --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                            --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                            --file-filter "MP4 Video File | *.mp4" \
                            --text "$(printf "Recording Finished.\n\nPlease save the screen capture\n")"
                    )

                    if [[ "$?" = 1 ]]; then

                        adb shell rm -r /sdcard/tmp/

                        pageTwo

                    else

                        adb pull /sdcard/tmp/tmp.mp4 "$path".mp4

                        adb shell rm -r /sdcard/tmp/

                        pageTwo

                    fi

                fi

            fi

        fi
        # adb shell screencap -p "$name"

    fi

    if [[ "$ans" = '22' ]]; then # Install / Uninstall atk

        if [[ ! -f ./usr/var/isCompiled ]] && [[ ! -f ./usr/var/gui ]]; then # Is Compiled and or Installed

            xterm -e ./install

            pageTwo
        
        else

            

            null=$(

                "$yad" --info \
                    --title "Android Toolkit - Error" \
                    --center \
                    --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                    --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                    --text "Error: Can't install from compiled or installed version.\nCompiled: The way the AppImage runs prevents certain file modifications.\ninstall process skips some neccessary files for compilation."

            )

            if [[ "$?" = 1 ]]; then

                exit

            else

                pageTwo

            fi

        fi

    fi

    if [[ "$ans" = '20' ]]; then # Debug

        ./usr/src/debugGUI.sh

        ans="$(cat ./usr/var/ans)"

        if [[ "$ans" = 1 ]]; then

            exit $0

        else

            if [[ "$ans" = 27 ]]; then

                pageTwo

            else

                if [[ "$ans" = 21 ]]; then # Clear Temporary Files

                    rm -r ~/.android-toolkit/

                    rm ./usr/src/ans

                    rm ./usr/ect/backupTest/*.*

                    rm ./usr/src/nohup.out

                    ./usr/src/debugGUI.sh # Return

                fi

                if [[ "$ans" = 22 ]]; then # SCRCPY Link

                    ln -sfd ./usr/bin/SCRCPY/ ./

                    ./usr/src/debugGUI.sh

                fi

                if [[ "$ans" = 23 ]]; then # Implement SCRCPY

                    cp -r ./../SCRCPY/ ./usr/bin/ #Only works when the SCRCPY folder is in the parent directory

                    ./usr/src/debugGUI.sh

                fi

                if [[ "$ans" = 24 ]]; then # Configure for Release

                    for file in "*.AppImage" "./usr/ect/backupTest/*.*" "./usr/src/nohup.out" "./usr/bin/SCRCPY/adb" "./usr/bin/SCRCPY/icon.png" "./usr/bin/SCRCPY/scrcpy" "./usr/bin/SCRCPY/scrcpy.1" "./usr/bin/SCRCPY/scrcpy-server" "./.DirIcon"; do 
                        
                        rm $file

                    done
                    
                    xterm -e "pkexec rm /usr/bin/android-toolkit"

                    sed -i '/Name=android-toolkit-/d' ./android-toolkit.desktop

                    out="$(sed "2a\Name=android-toolkit-$ver" < android-toolkit.desktop )"

                    printf "$out" > ./android-toolkit.desktop

                    ./usr/src/debugGUI.sh

                fi

                if [[ "$ans" = 25 ]]; then # Run a Command

                    command=$(

                        "$yad" --entry \
                            --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                            --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                            --center \
                            --title "Android Toolkit Debug" \
                            --text "Enter a Command:"

                    )

                    bash -c "$command" 2>&1 | "$yad" --text-info --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --title "Android Toolkit Debug" --center --width=600 --height=1200
                
                fi

                if [[ "$ans" = 26 ]]; then # Compile

                    ./usr/src/compile.sh

                    exit

                fi
            
            fi
                    
        fi

        rm ./usr/var/ans

        pageTwo

    fi

}

pageThree() {

    cmd=(

            "$yad" --form
                --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png
                --center
                --title "Android Toolkit"
                --text "Welcome to Android Toolkit Version $ver!\nPlease Choose an Option:\n"
                --button "Open README":23
                --button "File Manager":24
                --button "Previous Page"\!go-previous\!:10
                --button "Exit"\!gtk-cancel\!:0 

    )

    exec

    ans="$?"

    if [[ "$ans" = 0 ]]; then # Exit

        exit

    fi

    if [[ "$ans" = 10 ]]; then # Previous Page

        pageTwo

    fi

    if [[ "$ans" = 23 ]]; then # Open README

        null=$(

            cat ./README.md | "$yad" --text-info \
                --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
                --center \
                --width=1200 \
                --height=1200

        )

        if [[ "$?" = 1 ]]; then

            exit

        else

            pageThree

        fi

    fi

    if [[ "$ans" = 24 ]]; then # File Manager

        changeDir() {

            adb shell ls -r "$path" 2>&1 | "$yad" --text-info --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --title "$path" --center --width=1200 --height=1200 &

            PID=$(pgrep -f "yad")

            sleep .2

            pathAdd=$("$yad" --entry --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --center --title "Android Toolkit - File Manager" --text "Provide the name for the path to be displayed.\nInput is absolute, so you must state the full length of the directory.\n\n/sdcard is the user root directory.\nDisplay Contents: Open the file first and then click Display Contents" --button "Exit":1 --button "Open Absolute Path / File":0 --button "Open Relative Path / File":2 --button "Display Contents":3 )

            ans="$?"

            echo "$pathAdd"

            if [[ "$ans" = 1 ]]; then 

                kill "$PID"

                pageThree

            else

                if [[ "$ans" = 2 ]]; then

                    path="$path/$pathAdd"
                        
                    kill "$PID"

                    changeDir

                else

                    if [[ "$ans" = 3 ]]; then

                        kill "$PID"

                        file="$path"

                        adb shell cat "$file"

                        echo "$file $pathAdd"

                        adb shell cat "$file" | "$yad" --text-info --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --title "$path/$pathAdd" --center --width=1200 --height=1200

                        changeDir

                    else

                        path="$pathAdd"

                        kill "$PID"

                        changeDir

                    fi

                fi
                

            fi

        }

        changeDir

    fi

}

#initial prompt

pageZero

exit