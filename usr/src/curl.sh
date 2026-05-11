#!/bin/bash

clear

if [[ -d ~/.android-toolkit ]]; then

    rm -r ~/.android-toolkit/

fi

git clone https://github.com/AtlasJ2301/android-toolkit ~/.android-toolkit/

if [[ -f /usr/bin/android-toolkit ]]; then

    sudo rm /usr/bin/android-toolkit

fi

sudo git clone https://github.com/AtlasJ2301/android-toolkit/blob/main/usr/bin/android-toolkit /usr/bin/android-toolkit