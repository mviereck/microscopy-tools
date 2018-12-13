# microscopy-tools

Some rather special tools customized for my needs.

## imgruler

Draws a ruler into an image. Needs ImageMagick.
Intended to draw a micrometer into micoscopic captures. Useful for measurement of funghi spores.
Contains a calibrating instruction.

Runs on Linux, macOS and (in Cygwin) on MS Windows.
Considered to be ready for general use.

## arduterm

Terminal to coordinate a camera on USB and an Arduino with a stepper motor. 
Designed for my microscope with a mounted camera and a steppermotor at the focus wheel.
It can show preview videos and make stackshots with tethered shooting and focus adjustment with stepper motor.
Useable, but in beta stage. `pololu_a4988.ino` is the code in use to control the stepper motor driver with an Arduino.

Contains code to fuse stackshot images with enfuse, imagemagick and hugin-tools. 
To use arduterm for stackshot fusing only, run it with the path to stackshot image folder as an argument.
```
# stackshot fusing
# needs ImageMagick, hugin-tools and enfuse

arduterm /path/to/folder/with/stackshot-images/
```

## fuse

Script to fuse microsope stackshot images with [enfuse](http://enblend.sourceforge.net/). Early experimental stage.

## xmeasure

Code snippet from https://code.google.com/archive/p/xmeasure/.
Might be used in future for spores measurement. 
Build with `gcc -o xmeasure xmeasure.c -L/usr/X11R6/lib -lX11`
