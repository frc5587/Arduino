#include <Wire.h>
char recieved = ' ';
void setup() {
Wire.begin(8);
Wire.onReceive(receiveEvent);
Serial.begin(9600);
}

void receiveEvent() {
   while(Wire.available()){
       recieved = Wire.read() & 0xFF;
       Serial.println(recieved);
   }
}
 void loop(){
}  
