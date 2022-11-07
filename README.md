# microscopy-tools

Tools for microscopy and image focus stacking.

 - Tools already useful, in active development:
   - [`imfuse`](#imfuse): Fuse focus stackshot images with ImageMagick. (Terminal)
   - [`preparestack`](#preparestack): Batch processing of image stack for contrast, crop, gamma etc. 
 - Tools considered to be ready:
   - [`align`](#align): Align image stack with the help of [focus-stack]((https://github.com/PetteriAimonen/focus-stack)) and ImageMagick.
   - [`imgruler`](#imgruler): Draw a ruler or micrometer into an image. (Terminal)
 - Tools awaiting further development, currently less useful:
   - [`stackshooter`](#stackshooter): Shoot focus stackshots with stepper motor and camera. (GUI)
   - [`camcfg`](#camcfg): Terminal dialog frontend for camera configuration. (Terminal)
 - Deprecated, stored for partial code reuse:
   - [`stackfuser`](#stackfuser): Align, prepare and fuse focus stack images. (GUI)

`stackfuser` and `stackshooter` need some further development and documentation before they can be recommended for general use.
Especially they need a new GUI backend because the currently used `kaptain` GUI is outdated and does not run on up-to-date systems.

## imfuse

Combines focus stackshot images to an overall sharp image.
Aims to be similar to enfuse, but based on ImageMagick.

Dependencies:
 - `imagemagick` version 7.
 - [`PetteriAimonen/focus-stack`](https://github.com/PetteriAimonen/focus-stack) (optional for option `--align`)
 - `enfuse` (optional, needed for some options)
 - `geeqie` and `viewnior` (optional image viewers)
 - `exiftool` (optional to preserve exif meta data)

## align

Aligns image stack.

Dependencies:
 - [`PetteriAimonen/focus-stack`](https://github.com/PetteriAimonen/focus-stack)
 - `imagemagick`

The core work is done by `focus-stack`, this tool helps to crop the images to the usable common area.

## preparestack

Batch processing of image stack for contrast, crop, gamma etc.

Dependencies:
 - `imagemagick`

## imgruler

Draws a ruler into an image.
Intended to draw micrometers into micoscopic captures.
Contains a calibration instruction in english and german.

Runs on Linux, macOS and (in Cygwin) on MS Windows.
Considered to be ready for general use.

Dependencies:
 - `imagemagick`
 
## camcfg
`dialog` frontend for `gphoto2` camera configuration. Reads possible configurations of a camera and provides a dialog in terminal to choose desired settings. Beta stage, already useable.
 - `camcfg` shows all available configurations.
 - `camcfg ENTRY` shows configuration of entry ENTRY. Example: `camcfg iso`
 
Dependencies:
 - `dialog`
 - `gphoto2`

## stackfuser

GUI frontend for image foto stacking with enfuse.
Deprecated, will be replaced by multiple single tools.

Provides:
 - Image preprocessing with `imagemagick` to enhance contrast and sharpness. 
 - Image alignment with `ffmpeg`/[vidstab](https://github.com/georgmartius/vid.stab) or `align_image_stack`.
 - Generating multiple overall sharp images from stackshot with `enfuse`. Further combining of these results with `imagemagick`.
 - Animated videos of focus stackshots.

Dependencies, most essentiell:
 - `align_image_stack` (hugin tools)
 - `enfuse`
 - `geeqie`
 - `imagemagick`
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
Note: The user must be in group `dialout` to access the Arduino.

Beta stage, in development, needs severe rework. 

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
 - `xdotool`

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
 - `hugin`: Hugin is a panorama photo stitching program for several overlapping photos taken from the same location, transforming the photos to one larger image.
 - `imagemagick`: ImageMagick is a powerful software suite to create, edit, and compose bitmap images. Command line tool, used by `stackfuser` and `stackshooter`.
 - [`mfkter`](https://github.com/hqhoang/mftker): GUI for enfuse. Replaces former MacroFusion.
 - `rawtherapee`: RawTherapee is an advanced program for developing raw photos and for processing
non-raw photos.

### Closed Source freeware
 - [CombineZP](https://combinezp.software.informer.com/): Stacker for MS Windows. Works with wine on Linux, too.
 - [Picolay](http://www.picolay.de/): Stacker for MS Windows. Works with wine on Linux, too.
 - [stacky](https://www.bewie.de/stacky.php): Stacker for MS Windows. Works with wine on Linux, too.
### Closed Source commercial
 - [Helicon Focus](https://www.heliconsoft.com/heliconsoft-products/helicon-focus/): 30 days trial version. Available for Mac and Windows.
 - [ZereneStacker](https://zerenesystems.com/cms/stacker): 30 days trial version. Available for Linux, Mac and Windows.
