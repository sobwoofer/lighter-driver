SHELL ?= /bin/bash

#run diskutil list and chose port like /dev/disk4
prepare-sd: ## make all methods
	diskutil eraseDisk ExFAT LUCERNA MBRFormat /dev/disk4 && \
	cp -R sounds/001.mp3 /Volumes/LUCERNA && \
	cp -R sounds/002.mp3 /Volumes/LUCERNA && \
	cp -R sounds/003.mp3 /Volumes/LUCERNA && \
	cp -R sounds/004.mp3 /Volumes/LUCERNA && \
	cp -R sounds/005.mp3 /Volumes/LUCERNA && \
	cp -R sounds/006.mp3 /Volumes/LUCERNA && \
	cp -R sounds/007.mp3 /Volumes/LUCERNA && \
	cp -R sounds/008.mp3 /Volumes/LUCERNA && \
	cp -R sounds/009.mp3 /Volumes/LUCERNA && \
	diskutil unmountDisk /dev/disk4

prepare-sd-bug: ## make all methods
	diskutil unmountDisk /dev/disk4
	sudo newfs_msdos -F 32 -v LUCERNA /dev/disk4 && \
	diskutil mountDisk /dev/disk4 && \
	cp -R sounds_bug/0001.mp3 /Volumes/LUCERNA && \
	cp -R sounds_bug/0002.mp3 /Volumes/LUCERNA && \
	cp -R sounds_bug/0003.mp3 /Volumes/LUCERNA && \
	cp -R sounds_bug/0004.mp3 /Volumes/LUCERNA && \
	cp -R sounds_bug/0005.mp3 /Volumes/LUCERNA && \
	cp -R sounds_bug/0006.mp3 /Volumes/LUCERNA && \
	cp -R sounds_bug/0007.mp3 /Volumes/LUCERNA && \
	cp -R sounds_bug/0008.mp3 /Volumes/LUCERNA && \
	cp -R sounds_bug/0009.mp3 /Volumes/LUCERNA && \
	diskutil unmountDisk /dev/disk4

