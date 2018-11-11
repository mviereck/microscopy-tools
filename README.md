# microscopy-tools

Some rather special tools customized for my needs.

## imgruler

Draws a ruler into an image. 
Intended to draw a micrometer into micoscopic captures. Useful for measurement of funghi spores.
Considered to be ready for general use.

## arduterm

Terminal to coordinate a camera on USB and an Arduino with a stepper motor. 
Designed for my microscope with a mounted camera to show preview videos and make stackshots.
Useable, but in beta stage. `pololu_a4988.ino` is the code in use to control the stepper motor.

## fuse

Script to fuse microsope stackshot images with enfuse. Early experimental stage.

## xmeasure

Code snippet from https://code.google.com/archive/p/xmeasure/.
Might be used in future for spores measurement. 
Build with `gcc -o xmeasure xmeasure.c -L/usr/X11R6/lib -lX11`
