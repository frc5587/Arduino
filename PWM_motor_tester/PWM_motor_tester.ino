#include <Servo.h>

const int outPin = 9;
const boolean invertDirection = false;
const int dirPin = 2;
const int inputPin = A0;

Servo out;

void setup() {
  out.attach(outPin);
  if(invertDirection){
    pinMode(dirPin, INPUT_PULLUP);
  }
  else{
    pinMode(dirPin, INPUT);\
  }
  pinMode(inputPin, INPUT);
}

void loop() {
  int val = analogRead(inputPin);
  int pulsetime = map(val, 0, 1023, 0, 500);
  boolean direction = digitalRead(dirPin);
  if(direction){
    out.writeMicroseconds(1500+pulsetime);
  }
  else{
    out.writeMicroseconds(1500-pulsetime);
  }
}
