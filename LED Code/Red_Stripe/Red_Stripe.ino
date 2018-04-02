#include "FastLED.h"

#define NUM_LEDS 68
#define DATA_PIN 6
// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() { 
  for(int i = -1; i<NUM_LEDS;i++){
      leds[i] = CRGB::Blue;
      delay((int)(20*(NUM_LEDS-i)/NUM_LEDS));
      leds[i+1] = CRGB::Red;
      leds[i+2] = CRGB::Red;
      leds[i+3] = CRGB::Red;
      leds[i+4] = CRGB::Red;
      FastLED.show();
  }
  
}
