# Zahir
Zahir is a research project dealing with music and contemporary dance improvisation interrelations. 
It is composed of a wearable device containing a sensor of your choice (standardised for certain adafruit sensors), a QT-PY esp32 C-3 and a lipo for power.
communication between the MCU and the sensor is done via I2C. Communication between the device and the computer is done via BLE (bluetooth low energy). The device sends MIDI messages to your computer. 

*note : the PETG shell is not needed, it just provides protection against water, sweat and various acts of god*

## list of the different parts : (see exploded view for an image of all the items)
---------------------------------------------
### THINGS YOU'LL NEED TO **BUY**

+ **MCU :** [adafruit QT-PY ESP32 C-3](https://www.adafruit.com/product/5405)
+ **sensor** (the one I use) : [Adafruit LSM6DSOX 6 DoF Accelerometer and Gyroscope](https://www.adafruit.com/product/4438)
+ **lipo :** [Lithium Ion Polymer Battery - 3.7v 150mAh](https://www.adafruit.com/product/1317)
+ **tiny threaded insert**
+ **elastic band** (size of your choice really)

### THINGS YOU'LL NEED TO **BUILD** (files)

+ **internal structure** : internalStructureV4.stl
+ **base** : ZahirCaseClosureV5.stl
+ **PETG or Cardboard shell** : ZahirCaseV1_2(littleSmaller).stl
+ **wristband attachment system** : (wip)

### THINGS YOU'LL NEED TO **CODE** (example file)

You'll find an example file (codeExample.ino) that does very basic stuff : it sends x acceleration values through port 20, and x rotation speed through port 21. You can map those values to whatever parameters you wish to play on (basic use of this device would be to alter a filter cutoff frequency, but it really is just an example).

---------------------------------------------
