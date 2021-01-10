# mt_rpiprtcap

Capture print data via parallel port on PC and some measurement equipments.

Main purpose is for taking hardcopy on elder measurement equipments that don't have USB or modern hardcopy device.

The PCB design file for KiCAD is in "board" directory.

The software code depends on pigpiod is in "software_rpi" directory.

you can build software as following (comes from pigpio)

gcc -Wall -pthread -o prt prt.cpp -lpigpiod_if2 -lrt

I have tested on Raspbian GNU/Linux 10 (buster), gcc 8.3.0, pigpio 78 (get_pigpio_version reported) and Raspberry Pi 4B 2GB.

The software sometime failed to capture data (3 or 4 characters in 10MB).

There are no interpreters that convert from parallel port data to picture yet.

How to use

connect all devices.

power-on all devices.

start software_rpi/prt executable

start print on PC or equipment

when it seems ended, Ctrl-C on prt executable
