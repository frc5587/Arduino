#include "FastLED.h"

#define NUM_LEDS 143
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() { 
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() { 
  for(int j = 0; j < NUM_LEDS;j++){
    for(int i = -1; i<NUM_LEDS;i++){
      leds[i] = CRGB(((i*255/NUM_LEDS)+(j*255/NUM_LEDS))%255,255,255);
      FastLED.show();
    }
  }
}
