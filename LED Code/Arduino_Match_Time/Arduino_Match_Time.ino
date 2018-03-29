#include "FastLED.h"

#define NUM_LEDS 37
#define DATA_PIN 6

int matchTime = 0, mapMatchTime;
bool matchStart = false;
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  rainbows();
  if (Serial.read() == 's') { //when the char 's' is recieved, execute. 's' serves as a starting event.
    matchStart = true;
    while (matchStart) {
      if (matchTime < 150) {
        matchTime = millis() / 1000;
        Serial.println(matchTime);
        mapMatchTime = map(matchTime, 0, 150, 0, NUM_LEDS);
        delay(1000);

        if (matchTime <= 15) {
          for (int i = 0; i < 37; i++) {
            Serial.println("Red Auto warning");
            leds[i] = CRGB::Red;
            delay(50);
          }
        } else if (matchTime > 15 && matchTime <= 120) {
          Serial.println("Solid green timer");
          leds[37 - mapMatchTime] = CRGB::Green;
        } else if (matchTime > 120 && matchTime < 150) {
          Serial.println("End game yellow");
          leds[37 - mapMatchTime] = CRGB::Yellow;
        } else {
          Serial.println("Rainbows");
          matchStart = false;
          //rainbows();
        }
        FastLED.show();
      }
    }
  }
}

void rainbows() {
  double loopSize = 255 / NUM_LEDS;
  for (int j = 0; !matchStart; j++) {
    for (int i = 0; i <= NUM_LEDS; i++) {
      leds[i] = CHSV((int)(i * loopSize + j  * loopSize) % 255, 255, 255);
      Serial.println(matchStart);
      FastLED.show();
    }
  }
}
