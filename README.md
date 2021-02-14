# microscopy-tools

Tools for microscopy and image focus stacking.

 - Tools already useable, in active development:
   - [`imfuse`](#imfuse): Fuse focus stackshot images with imagemagick. (Terminal)
   - [`stackfuser`](#stackfuser): Align, prepare and fuse focus stack images. (GUI)
 - Tools already useable, awaiting further development:
   - [`stackshooter`](#stackshooter): Shoot focus stackshots with stepper motor and camera. (GUI)
   - [`camcfg`](#camcfg): Terminal dialog frontend for camera configuration. (Terminal)
 - Tools considered to be ready:
   - [`imgruler`](#imgruler): Draw a ruler or micrometer into an image (Terminal)
   - [`imgview`](#imgview): Simple image viewer (GUI)

   
`stackfuser` and `stackshooter` need some further development and documentation before they can be recommended for general use.
However, if you are already interested to try them out, please give me some feedback in the [issue tracker](https://github.com/mviereck/microscopy-tools/issues) and I'll help to set them up.

## imfuse

Combines focus stackshot images to an overall sharp image.
Aims to be similar to enfuse, but based on ImageMagick.
In active development, beta stage. (Terminal) 

Dependencies:
 - `imagemagick`
 - `enfuse` (recommended, needed for some options)
 - [`imgview`](#imgview) (optional image viewer)
 - `exiftool` (optional to preserve exif meta data)

## imgruler

Draws a ruler into an image.
Intended to draw micrometers into micoscopic captures.
Contains a calibration instruction in english and german.

Runs on Linux, macOS and (in Cygwin) on MS Windows.
Considered to be ready for general use.

Dependencies:
 - `imagemagick`
 
## imgview

Simple image viewer that allows remote content refresh
without window flickering and without blocking the terminal.

Dependencies:
 - [`kaptain`](https://github.com/mviereck/kaptain)
 - `imagemagick` (optional to show some meta data)

## stackfuser

GUI frontend for image foto stacking with enfuse. In active development, beta stage.

Provides:
 - Image preprocessing with `imagemagick` to enhance contrast and sharpness. 
 - Image alignment with `ffmpeg`/[vidstab](https://github.com/georgmartius/vid.stab) or `align_image_stack`.
 - Generating multiple overall sharp images from stackshot with `enfuse`. Further combining of these results with `imagemagick`.
 - Animated videos of focus stackshots.
 
Especially supports a folder with name `stackshot` containing the source images. `stackshot` should be in an otherwise empty parent folder. The images in `stackshot` won't be changed.
Folder structure:
```
-.
 |--somedir--.
              |--stackshot--.
                            |--img001.jpg
                            |--img002.jpg
                            |--img003.jpg
              
```
`stackfuser` will create further subfolders in `somedir` containing intermediate and final results.

Dependencies, most essentiell:
 - `align_image_stack` (hugin tools)
 - `enfuse`
 - `imagemagick`
 - [`imgview`](#imgview) (optional image viewer)
 - [`imfuse`](#imfuse)
 - [`kaptain`](https://github.com/mviereck/kaptain)
 - `viewnior`

Dependencies, also recommended:
 - `ffmpeg`
 - `exiftool`
 - [`imgruler`](#imgruler)
 - `ufraw`
 
## stackshooter
GUI for foto stacking with a stepper motor controlled by an Arduino and a camera connected on USB. 
Beta stage, in active development. 
Note: The user must be in group `dialout` to access the Arduino.

Features:
 - Camera control with `gphoto2` for preview videos and tethered shooting.
 - Stepper motor control for focus adjustment.
 - Automated focus stackshots combining camera and stepper motor.
 
`pololu_a4988.ino` is my code to control my stepper motor driver with an Arduino. The control commands send by `stackshooter` to Arduino can be customized in `stackshooter` configuration dialog.

Dependencies:
 - `ffmpeg`
 - `geeqie`
 - `gphoto2`
 - `align_image_stack` (hugin tools)
 - [`kaptain`](https://github.com/mviereck/kaptain)
 - `xinput`
 
## camcfg
`dialog` frontend for `gphoto2` camera configuration. Reads possible configurations of a camera and provides a dialog in terminal to choose desired settings. Beta stage, already useable.
 - `camcfg` shows all available configurations.
 - `camcfg ENTRY` shows configuration of entry ENTRY. Example: `camcfg iso`
 
Dependencies:
 - `dialog`
 - `gphoto2`

## Example
Image of some flower pollen. Generated with `stackshooter` and `stackfuser`. 
Technic: Microscope from [Hund/Wetzlar](https://www.hund.de/en/) with a stepper motor and an arduino. 
Camera: Canon EOS 1000D. 
Stackshot result of 240 single captures with slightly different focus:

![screenshot](https://raw.githubusercontent.com/mviereck/microscopy-tools/images/example.jpg)

Iconified excerpt of source stackshot:

![screenshot](https://raw.githubusercontent.com/mviereck/microscopy-tools/images/sourcetable.jpg)

Animated video:

![screenshot](https://raw.githubusercontent.com/mviereck/microscopy-tools/images/animate.gif)

## Related tools

### Free and Open Source
 - `enfuse`: Enfuse blends differently exposed images of the same scene into a nice output
image. Command line tool, used by `stackfuser`.
 - `entangle`: Entangle provides a graphical interface for "tethered shooting", aka
taking photographs with a digital camera completely controlled from the
computer.
 - [`PetteriAimonen/focus-stack`](https://github.com/PetteriAimonen/focus-stack): A cross-platform tool for focus stacking images based on wavelet algorithms.
 - [`pulsar123/Macro-scripts`](https://github.com/pulsar123/Macro-scripts): A set of BASH scripts and C++ programs representing a complete workflow for processing macro focus stacking photographs.
 - `gphoto2`: The gphoto2 library allows access and control of various digital camera models. Command line tool, used by `stackshooter`.
 - `imagemagick`: ImageMagick is a powerful software suite to create, edit, and compose bitmap images. Command line tool, used by `stackfuser` and `stackshooter`.
 - `hugin`: Hugin is a panorama photo stitching program for several overlapping photos taken from the same location, transforming the photos to one larger image.
 - `rawtherapee`: RawTherapee is an advanced program for developing raw photos and for processing
non-raw photos.

### Closed Source freeware
 - [CombineZP](https://combinezp.software.informer.com/): Stacker for MS Windows. Works with wine on Linux, too.
 - [Picolay](http://www.picolay.de/): Stacker for MS Windows. Works with wine on Linux, too.
### Closed Source commercial
 - [Helicon Focus](https://www.heliconsoft.com/heliconsoft-products/helicon-focus/): 30 days trial version. Available for Mac and Windows.
 - [ZereneStacker](https://zerenesystems.com/cms/stacker): 30 days trial version. Available for Linux, Mac and Windows.
