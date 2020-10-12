# Arduino

## Servo PWM Emulator

The PWM_motor_tester sketch emulates the Pulse Width Modulation output of a roboRIO as outlined [on this page](https://wpilib.screenstepslive.com/s/currentCS/m/java/l/599702-driving-motors-with-speed-controller-objects-victors-talons-and-jaguars), so as to communicate with a motor controller for easy testing of motors.

## Driver Station

Buttons on the driver station can use either the DriverStationButtons sketch to be configured as a joystick input, or the KeyboardButtons sketch to be configured as a HID keyboard.

## I2C

I2CTest is a simple sketch for testing to see that there is communication between any foreign peripheral (such as a roboRIO) and an Arduino.

## DDR

First you must install XInput from the library manager.

Then you need to unzip ![this](https://github.com/dmadison/ArduinoXInput_AVR/releases) into (arduino installation) --> hardware (e.i. on arch its `/opt/share/arduino/hardware`). (then the restart arduino IDE)

After that, when you upload a sketch you should select the board and "w/ XInput" e.i. `leonardo w/ XInput` as your board, enable show verbose output, then upload your first sketch

Finally, when you want to upload subsequent sketches you **MUST** select the same board as above (but no port will show up), then hit upload and when the thingy says "uploading..." hit the restart button on the arduino **TWICE** and even though it will say like no port found, if you have verbose output enabled it will say `avrdude done. thank you!` after a bit. Once you do that you're done!

## LEDS

### RGB Channel LEDS

RGB LEDs allow for the combination of three component colors (red, green, and blue), resulting in various colors. Each pixel on the strip can only be the color of its neighbor, as the color is a function of the combination of voltages received from the common red, green, and blue channels. RGB LEDs typically use between 6-17 volts. On the robot, the under-lights are RGB LEDs.

Circuit design for RGB LED strip driver circuit:

![RGB LED Driver Breadboard Diagram](https://github.com/Team5587/Arduino/blob/master/images/RGB%20Fritzing%20Diagram.png)

Schematic for RGB LED strip driver circuit:

![RGB LED Driver Schematic](https://github.com/Team5587/Arduino/blob/master/images/RGB%20Schematic.JPG)

### MOSFETs

MOSFETs are used to adjust an input voltage based on a signal received. When used in the RGB LED controller, the source pin receives 12 volts, and the PWM signal received from the Arduino on the gate pin determines how much voltage flows through the drain pin. Using three MOSFETs, the voltage for the red, green, and blue channels can be controlled from the Arduino.

Pin-out for MOSFETs:

![MOSFET Pin-out Diagram](https://github.com/Team5587/Arduino/blob/master/images/MOSFET.JPG)

### Individually Addressable LED Strips

Individually addressable LED strips allow for each pixel in a strip to be lit a different color than its neighbor. Individually addressable LED Strips should receive 5 volts, but amperage changes based on length of strip, with a longer strip drawing more current. The lights on the elevator of the 2018 robot and the lights embedded in the driver station are individually addressable LEDS.

Circuit Design for individually addressable LEDS:

![Individually Addressable LED Schematic](https://github.com/Team5587/Arduino/blob/master/images/Individually%20Addressable%20LED%20Fritzing.png)

Schematic for Individually Addressable LEDS Driver Board:

![Individually Addressable LED Driver Schematic](https://github.com/Team5587/Arduino/blob/master/images/Individually%20Addressable%20LED%20Schematic.JPG)
