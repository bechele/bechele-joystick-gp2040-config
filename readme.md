## Joystick firmware for RP2040-zero propagating as USB HID analog joystick to be used for the bechele project
This firmware is for RP2040-zero and is intended for the bechele project: 
https://github.com/bechele/bechele
For the animatronics software bechele it is very helpful to have a precise Joystick that has no dead zones. The Bechele software is running on Linux, usually on a raspberry Pi and the Joystick device /dev/js0 adds a large dead zone in the middle position of the stick. The dead zone is hard coded inside the kernel and cannot be changed easily. In other words, a conventional joystick is not good for the bechele software. It works, but you have to live with the dead zone. This firmware outwits the Kernel by propagating a Joystick with a conventional range of +/- 32767 steps, but never delivers the negative values. Since the bechele software has its own calibration values, still the full range of the joystick is possible, but this trick overcomes the deadzone. 

## The project is intended for the following 3D printable joystick:
https://www.thingiverse.com/thing:7164439

## Alternative projects using different electronics hardware 
Alternative electronics hardware exists, you may use for the same purpose. Note that the RP2040 has a ADC with 12 bit resolution, reflecting a value range of 0 to 4096. If you want to connect via USB to your computer this Package is the best choice. If you prefer to have a bluetooth device ESP32C3 may be your choice. If you choose the Arduino pro micro ( https://github.com/bechele/atmega32u4-Bechele-Joystick ) you need to keep in mind, that the resolution is just 10 bit 

## Installation onto a RP2040-zero board:
### Option 1 - only recommended, if you need to change some code. -  Build using visual code.
This firmware is based on the gp2040-ce project: https://https://gp2040-ce.info
Only minor changes have been made, so the resulting .uf2 file is pre-configured for the bechele joystick.
By setting up the joystick via the web interface of GP2040 manually, you may achieve the same functionality if set correctly.  So installing from source is rather unlikely to be necessary. 

Pre-conditions if you want to install from source:
Toolchain and installation according to https://gp2040-ce.info/development/build-environment/ 

#### Steps to downlad the original package from github:
- Open a terminal
- Move to an empty directory
```
 git clone https://github.com/OpenStickCommunity/GP2040-CE.git
```
- download the bechele addon from gitgub:
```
 git clone https://github.com/bechele/bechele-joystick-gp2040-config.git
```
- Add the bechele config and patch:
```
  cd GP-2040-CE
  cp -r ../bechele-joystick-gp2040-config/configs/BecheleJoystick configs/
```
The patch was created using "git diff" 
```
- cp ../bechele-joystick-gp2040-config/patches/analog.patch .
- git apply analog.patch
```
- In the terminal enter: 
```
$env:GP2040_BOARDCONFIG="BecheleJoystick"
```
- compile as explained in the toolchain build link above.


### Option 2 - upload the pre-compiled .uf2 file (recommended) 
- Download the .uf2 file from my web site http://bechele.de
- Connect the board using a USB cable to your Raspi

#### This way you may upload it to your RP2040-zero:
- You need to press the reset button and the boot-sel Button simultaneously
- Release first the reset button and then the boot-sel button - now the RP2040 shows up via usb as a usb drive
- Copy the file GP2040-CE_0.7.12_BecheleJoystick.uf2 onto the upcoming drive
- After a reset, the Board should show up as a HID device on your raspi - usually /dev/js0

## Necessary steps to use the joystick in the bechele software:
To use the joystick with the bechele software, the following steps are necessary:
Connect the Joystick via USB to your microcomputer running the bechele software.
- login to the microcomputer and type:
ls -l /dev    You should see a device called js0
- If js0 is existing, your joystick has been recognised by the operating system
- type: /usr/local/bin/gamepad.pl
This will show you the joystick functions
- Operate the joystick and note the axes numbers and their limit values, when you fully move to the either mechanical block. Also note the button numbers:
Should be axis 0 (X-direction) and 1 (Y-direction) and Button 0 and 1
- Open the file /usr/local/bin/bechele/Modules/ConfigL.pm and set the follwing variables accordingly:
```
$use_gamepad=1;                                 # Set this to 1, because you use a HID Joystick, not a serial
$gamepad_start=0;                               # define which gamepad button starts
$gamepad_stop=1;                                # define gamepad button that stops
$gamepad_axis_y=1;                              # define the gamepad axis y
$gamepad_axis_x=0;                              # define the gamepad axis x
```
- Enter the limit values of your axes - With the Atmega32U4 joystick they should be similar to the values below:
```
$gamepad_x_start=-32767;                        # The axis x mechanical start limit value
$gamepad_x_end=32767;                           # The axis x mechanical end limit value
$gamepad_y_start=32767;                         # The axis y mechanical start limit value
$gamepad_y_end=i-32767;                         # The axis y mechanical end limit value
```
- Depending on the direction the start and end values may be swapped. 
- Save and quit ConfigL.pm
