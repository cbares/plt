#!/bin/sh

set -e

echo USERNAME=plt > ./.env
echo USER_UID = $(id -u) >> ./.env
echo USER_GID = $(id -g) >> ./.env

echo "Checking for display server..."
local display_server=$XDG_SESSION_TYPE
if [ "$display_server" != "wayland" ]; then
    xhost +SI:localuser:$(id -un)
    echo DISPLAY = $DISPLAY >> ./.env

