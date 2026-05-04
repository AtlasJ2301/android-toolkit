#!/bin/bash

clear

mv ./usr/src/debug.sh ./usr/ect/debug.sh
mv ./usr/src/debugGUI.sh ./usr/ect/debugGUI.sh
touch ./usr/var/isCompiled

ARCH=x86_64 ./usr/bin/compile.AppImage ./ | ?=$(./usr/bin/yad --text-info --center --image ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --window-icon ./usr/share/icons/hicolor/48x48/apps/android-toolkit.png --title "Compile android-toolkit" --button "Run":0 --width=1200 --height=1200)

rm ./.DirIcon

mv ./usr/ect/debug.sh ./usr/src/debug.sh
mv ./usr/ect/debugGUI.sh ./usr/src/debugGUI.sh
rm ./usr/var/isCompiled

chmod +x *.AppImage

./*.AppImage