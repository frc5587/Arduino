#include <Keyboard.h>

#define UP_PIN 9
#define DOWN_PIN 10
#define LEFT_PIN 11
#define RIGHT_PIN 12

typedef struct {
  int pin;
  char associatedKey;
  int state;
  int lastState;
} Button;

Button buttons[4] = {
  {UP_PIN, KEY_UP_ARROW, 0, 0},
  {DOWN_PIN, KEY_DOWN_ARROW, 0, 0},
  {LEFT_PIN, KEY_LEFT_ARROW, 0, 0},
  {RIGHT_PIN, KEY_RIGHT_ARROW, 0, 0}
};

void setup() {
  Serial.begin(9600);

  for(int i = 0; i < sizeof(buttons) / sizeof(Button); i++) {
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }
}

void loop() {
  // Update each button, and check for presses or releases
  for(int i = 0; i < sizeof(buttons) / sizeof(Button); i++) {
    Button *but = &buttons[i];

    but->lastState = but->state;
    but->state = digitalRead(but->pin);

    if(but->lastState != but->state) {
      if(but->state == 0) {
        // Button is now on
      Keyboard.press(but->associatedKey);
      } else {
        // Button just turned off
        Serial.println("Button was just released");
        Keyboard.release(but->associatedKey);
      }
    }
  }

  delay(10);
}
