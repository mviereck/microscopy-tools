# microscopy-tools

Tools for microscopy and image focus stacking.
Some rather special tools customized for my needs.

## imgruler

Draws a ruler into an image.
Intended to draw micrometers into micoscopic captures.
Contains a calibration instruction.

Runs on Linux, macOS and (in Cygwin) on MS Windows.
Considered to be ready for general use.

Dependencies:
 - imagemagick

## fusewizard

GUI frontend for image foto stacking with enfuse. 
Provides image preprocessing with imagemagick to enhane contrast and sharpiness. 
Image alignment with ffmpeg/vidstab. 
Expect a folder `stackshot` containing the source images. `stackshot` should be in an empty parent folder.

In development, beta stage.

Dependencies: 
 - enfuse
 - ffmpeg
 - geeqie
 - imagemagick
 - imgruler
 - [kaptain](https://github.com/mviereck/kaptain)
 - viewnior

## arduterm

Terminal to coordinate a camera on USB and an Arduino with a stepper motor. 
Designed for my microscope with a mounted camera and a steppermotor at the focus wheel.
It can show preview videos and make stackshots with tethered shooting and focus adjustment with stepper motor.
`pololu_a4988.ino` is the code in use to control the stepper motor driver with an Arduino.

Useable, but in beta stage. Currently not recommended for production use.

Dependencies:
 - ffmpeg
 - geeqie
 - gphoto2

## Example

Image of pollen. Generated with the tools from this repository and a [microscope from Hund/Wetzlar](https://www.hund.de/en/). Stackshot result of 69 single captures with slightly different focus.

![screenshot](example.jpg)
