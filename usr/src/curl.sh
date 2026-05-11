#!/bin/bash

if [[ -d ~/.android-toolkit ]]; then

    rm -r ~/.android-toolkit/

fi

git clone https://github.com/AtlasJ2301/android-toolkit ~/.android-toolkit/

if [[ -f /usr/bin/android-toolkit ]]; then

    rm /usr/bin/android-toolkit

fi

git clone https://github.com/AtlasJ2301/android-toolkit/blob/main/usr/bin/android-toolkit /usr/bin/android-toolkit