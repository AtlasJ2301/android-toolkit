#!/bin/bash

ans=$(

    yad --form \
        --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
        --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png \
        --center \
        --title "Android Toolkit Debug" \
        --button "Cancel":27 \
        --button "Exit":1 \
        --button "Clear Temp Files":21 \
        --button "SCRCPY link":22 \
        --button "Implement SCRCPY":23 \
        --button "Configure for Release":24 \
        --button "Run a Command":25 \
        --button "Compile atk":26 \
        --button "Chmod all":27

)

printf $? > ./usr/var/ans