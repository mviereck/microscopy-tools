r# microscopy-tools

Tools for microscopy and image focus stacking.

 - Tools ready for use:
   - [`imgruler`](#imgruler): Draw a ruler or micrometer into an image (Terminal)
 - Tools in active development, beta stage:
   - [`stackfuser`](#stackfuser): Combine focus stack images. (GUI)
   - [`stackshooter`](#stackshooter): Shoot focus stackshots with stepper motor and camera. (GUI)
   - [`camcfg`](#camcfg): Terminal dialog frontend for camera configuration. (Terminal)
   
`stackfuser` and `stackshooter` need some further development and documentation before they can be recommended for general use.
However, if you are already interested to try them out, please give me some feedback in the [issue tracker](https://github.com/mviereck/microscopy-tools/issues) and I'll help to set them up.


## imgruler

Draws a ruler into an image.
Intended to draw micrometers into micoscopic captures.
Contains a calibration instruction in english and german.

Runs on Linux, macOS and (in Cygwin) on MS Windows.
Considered to be ready for general use.

Dependencies:
 - `imagemagick`

## stackfuser

GUI frontend for image foto stacking with enfuse. In active development, beta stage.

Provides:
 - Image preprocessing with `imagemagick` to enhance contrast and sharpness. 
 - Image alignment with `ffmpeg`/[vidstab](https://github.com/georgmartius/vid.stab) or `align_image_stack`.
 - Generating multiple overall sharp images from stackshot with `enfuse`. Further combining of these results with `imagemagick`.
 - Animated videos of focus stackshots.
 
Expects a folder with name `stackshot` containing the source images. `stackshot` should be in an otherwise empty parent folder. The images in `stackshot` won't be changed.
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

Dependencies:
 - `align_image_stack` (hugin tools)
 - `enfuse`
 - `ffmpeg`
 - `geeqie`
 - `imagemagick`
 - [`imgruler`](#imgruler)
 - [`kaptain`](https://github.com/mviereck/kaptain)
 - `viewnior`
 
## stackshooter
GUI for foto stacking with a stepper motor controlled by an Arduino and a camera connected on USB. Beta stage, in active development.
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
 
## camcfg
`dialog` frontend for `gphoto2` camera configuration. Reads possible configurations of a camera and provides a dialog in terminal to choose desired settings. Beta stage, already useable.
 - `camcfg` shows all available configurations.
 - `camcfg ENTRY` shows configuration of entry ENTRY. Example: `camcfg iso`
 
Dependencies:
 - `dialog`
 - `gphoto2`

## Example
Image of pollen. Generated with `stackshooter` and `stackfuser`. 
Technic: Microscope from [Hund/Wetzlar](https://www.hund.de/en/) with a stepper motor and an arduino. 
Camera: Canon EOS 1000D. 
Stackshot result of 240 single captures with slightly different focus:

![screenshot](example.jpg)

Iconified excerpt of source stackshot:

![screenshot](sourcetable.jpg)

Animated video:

![screenshot](animate.gif)

## Related tools

### Free and Open Source
 - `enfuse`: Enfuse blends differently exposed images of the same scene into a nice output
image. Command line tool, used by `stackfuser`.
 - `entangle`: Entangle provides a graphical interface for "tethered shooting", aka
taking photographs with a digital camera completely controlled from the
computer.
 - `gphoto2`: The gphoto2 library allows access and control of various digital camera models. Command line tool, used by `stackfuser`.
 - `imagemagick`: ImageMagick is a powerful software suite to create, edit, and compose bitmap images. Command line tool, used by `stackfuser`.
 - `macrofusion`: GUI for stacking software `enfuse`. Fork with some bug fixes: https://github.com/mviereck/macrofusion
 - `rawtherapee`: RawTherapee is an advanced program for developing raw photos and for processing
non-raw photos.

### Closed Source freeware
 - [CombineZP](https://combinezp.software.informer.com/): Stacker for MS Windows. Works with wine on Linux, too.
 - [Picolay](http://www.picolay.de/): Stacker for MS Windows. Works with wine on Linux, too.
### Closed Source commercial
 - [Helicon Focus](https://www.heliconsoft.com/heliconsoft-products/helicon-focus/): 30 days trial version. Available for Mac and Windows.
 - [ZereneStacker](https://zerenesystems.com/cms/stacker): 30 days trial version. Available for Linux, Mac and Windows.
