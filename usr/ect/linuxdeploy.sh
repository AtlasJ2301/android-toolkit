#!/bin/bash

#YAD
ls
./usr/bin/linuxdeploy.AppImage \
  --appdir ./ \
  --executable /usr/bin/yad \
  --desktop-file ./usr/lib/yad-14.2/yad.desktop \
  --output appimage
