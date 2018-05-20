#!/bin/sh
# To mount a virtualbox drive
sudo mount -t vboxsf -o uid=$UID,gid=$(id -g) share ~/Documents && cd Documents/lios/src
