#!/bin/bash

printf "Debug Menu\n- Delete Temporary Files & Uninstall android-toolkit (1)\n- Create SCRCPY folder link (2)\n- Implement SCRCPY (3)\n- Configure for Release (4)\n- Run a Command (5)"
read -p "> " ans
printf $ans > ./usr/src/ans