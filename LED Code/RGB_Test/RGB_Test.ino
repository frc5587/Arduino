int red = 9, green = 10, blue = 11;
int pins[] = {red, green, blue};

void setup() {
    Serial.begin(9600); 

  for(int i = 0; i < 3; i++){
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0; i < 255; i++){
    analogWrite(blue, i);
    Serial.println(i);
  }
  for(int i = 255; i > 0; i--){
    analogWrite(blue, i);
    Serial.println(i);
  }
  for(int i = 0; i < 255; i++){
    analogWrite(red, i);
    Serial.println(i);
  }
  for(int i = 255; i > 0; i--){
    analogWrite(red, i);
    Serial.println(i);
  }
  for(int i = 0; i < 255; i++){
    analogWrite(green, i);
    Serial.println(i);
  }
  for(int i = 255; i > 0; i--){
    analogWrite(green, i);
    Serial.println(i);
  }
}
