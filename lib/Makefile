SHELL ?= /bin/bash

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

