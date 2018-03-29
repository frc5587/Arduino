#include <FastLED.h>
#include <Wire.h>

#define NUM_LEDS 68
#define DATA_PIN 6


// Highest possible height of the elevator in inches
int maxElevatorHeight = 40;
int red = 10;
int green = 9;
int blue = 11;
int pins[] = {red, green, blue};
int heightLED = 0;

CRGB leds[NUM_LEDS];

union {
  float f;
  unsigned char bytes[4];
} byteUnion;

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event  
  Serial.begin(9600); 

  for(int i = 0; i < 3; i++){
    pinMode(pins[i], OUTPUT);
  }
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent() {
    char recieved,aColor;
      while(Wire.available()){
        recieved = Wire.read() & 0xFF;
//                    Serial.println(recieved);
         if(recieved == 'u'){
            aColor = Wire.read() & 0xFF;
            Serial.println(aColor);
            displayUnderLightColor(aColor);
            
         }else if(recieved == 'e') {
          // Byte array is recieved in little endian
          uint32_t integer = (((uint32_t)Wire.read()) & 0xFF)
           + (((uint32_t)(Wire.read() << 8)) & 0xFFFF)
           + (((uint32_t)(Wire.read() << 16)) & 0xFFFFFF)
           + ((uint32_t)(Wire.read() << 24));
            displayElevatorHeight(integer,aColor);
        }
      }
}

void displayUnderLightColor(char allianceColor){
        //Serial.println(allianceColor);
  if(allianceColor != NULL){
      clearPins();
      if(allianceColor == 'w'){
           analogWrite(red, 255);
           analogWrite(green, 255);
           analogWrite(blue, 255);
      }else if(allianceColor == 'b'){
           analogWrite(blue, 255);
      }else if(allianceColor == 'r'){
           analogWrite(red, 255);
      }
   }
}

void displayElevatorHeight(uint32_t height, char colorScheme){
         heightLED = map(height,0,maxElevatorHeight,6,NUM_LEDS/2);  
}

void clearPins(){
   analogWrite(green, 0);
   analogWrite(red, 0);
   analogWrite(blue, 0);
}

void loop(){
   double loopSize = 255/(34);
    for(int i = 0; i<=NUM_LEDS/2;i++){
        leds[i] = CHSV((int)(i * loopSize) % 255,255, 255);
        leds[heightLED] = CRGB::Green;
        leds[heightLED + 1] = CRGB::Green;
        leds[heightLED - 1] = CRGB::Green;
        leds[heightLED - 2] = CRGB::White;
        leds[heightLED + 2] = CRGB::White;
        leds[heightLED - 3] = CRGB::White;
        leds[heightLED + 3] = CRGB::White;

        leds[NUM_LEDS - i] = CHSV((int)(i * loopSize) % 255,255, 255);
        leds[NUM_LEDS - heightLED] = CRGB::Green;
        leds[NUM_LEDS - heightLED + 1] = CRGB::Green;
        leds[NUM_LEDS - heightLED - 1] = CRGB::Green;
        leds[NUM_LEDS - heightLED - 2] = CRGB::White;
        leds[NUM_LEDS - heightLED + 2] = CRGB::White;
        leds[NUM_LEDS - heightLED - 3] = CRGB::White;
        leds[NUM_LEDS - heightLED + 3] = CRGB::White;
        FastLED.show();
    }
}
