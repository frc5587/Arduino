#include <Joystick.h>

Joystick_ Joystick;
RxAxis_ = 0;
RyAxis_ = 0;
XAxis_ = 0;
YAxis_ = 0;

const bool initAutoSendState = true;

void setup(){
  Joystick.begin();

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
}

int lastButtonState[4] = {0,0,0,0};

void loop() {
  if (digitalRead(2) == HIGH) {
    Joystick.pressButton(0);
  }
  else {
    Joystick.releaseButton(0);
  }
  if (digitalRead(3) == HIGH) {
    Joystick.pressButton(1);
  }
  else {
    Joystick.releaseButton(1);
  }
  if (digitalRead(4) == HIGH) {
    Joystick.pressButton(2);
  }
  else {
    Joystick.releaseButton(2);
  }
  if (digitalRead(5) == HIGH) {
    Joystick.pressButton(3);
  }
  else {
    Joystick.releaseButton(3);
  }
  if (digitalRead(6) == LOW) {
    Joystick.pressButton(4);
  }
  else {
    Joystick.releaseButton(4);
  }
   if (digitalRead(7) == HIGH) {
    Joystick.pressButton(5);
  }
  else {
    Joystick.releaseButton(5);
  }
}
