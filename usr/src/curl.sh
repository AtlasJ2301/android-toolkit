#!/bin/bash

clear

    rm -r ~/.android-toolkit/

git clone https://github.com/AtlasJ2301/android-toolkit ~/.android-toolkit/

    sudo rm /usr/bin/android-toolkit

sudo git clone https://github.com/AtlasJ2301/android-toolkit/blob/main/usr/bin/android-toolkit /usr/bin/android-toolkit