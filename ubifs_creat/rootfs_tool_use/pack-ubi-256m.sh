#!/bin/bash
./mkfs.ubifs –F -q -r ../rootfs_frank2 -m 2048 -e 126976 -c 2047 -o  ubifs.img
./ubinize -o rootfs.ubi -m 2048 -p 128KiB ubinize.cfg
[ -f ubifs.img ] && rm  ubifs.img
