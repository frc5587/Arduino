# Arduino
## LEDS: 
**RGB Channel LEDS:**
RGB LEDs allow for the combination of  three colors (Red, Green, and Blue), resulting in various colors. Each pixel on the strip can only be the color of its neighbor, as the color is a function of the combination of voltages received from the common red, green, and blue channels. RGB LEDS typically use between 6-17 volts. On the robot, the underlights are RGB LEDS.

<img src="/images/RGB Fritzing Diagram.png" width="40%"></img>


*Circuit design for RGB LED strip driver circuit*

<img src="/images/RGB Schematic.JPG" width="40%"></img>


*Schematic for RGB LED strip driver circuit*


**MOSFET:**
MOSFETS are used to adjust an input voltage based on a signal received. When used in the RGB LED controller, the Source pin receives 12 volts, and the PWM signal received from the Arduino on the gate pin determines how much voltage flows through the drain pin. Using three MOSFETs, the voltage for the Red, Green, and Blue channels can be controlled from the Arduino.


<img src="/images/MOSFET.JPG" width="40%"></img>

**Individually Addressable LED Strips:**
Individually addressable LED strips allow for each pixel in a strip to be lit a different color than its neighbor. Individually addressable LED Strips should receive 5 volts, but amperage changes based on length of strip, with a longer strip drawing more current. The lights on the Elevator of the robot and the lights embedded in the driver station are individually addressable LEDS


<img src="/images/Individually Addressable LED Fritzing.png" width="40%"></img>


*Circuit Design for individually addressable LEDS*


<img src="/images/Individually Addressable LED Schematic.JPG" width="40%"></img>


*Schematic for Individually Addressable LEDS Driver Board*


## Driver Station:
Buttons on driverstation can use either the DriverStationButtons sketch to be configured as a joystick input, or the KeyboardButtons sketch to be configured as a HID keyboard.




