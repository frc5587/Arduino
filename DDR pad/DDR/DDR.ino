#include <XInput.h>

void setup()
{
    // initialize button pins
    XInput.begin(); 
    pinMode(2, INPUT_PULLUP); // pin 2 = Y (UP)
    pinMode(3, INPUT_PULLUP); // pin 3 = B (RIGHT)
    pinMode(4, INPUT_PULLUP); // pin 4 = A (DOWN)
    pinMode(5, INPUT_PULLUP); // pin 5 = X (LEFT)
    pinMode(LED_BUILTIN, OUTPUT);

    // init proccess
    delay(2000);
    digitalWrite(LED_BUILTIN, HIGH);
    XInput.press(BUTTON_START);
    XInput.press(BUTTON_A);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    XInput.release(BUTTON_A);
    XInput.release(BUTTON_START);

}


struct pin_button {   // data type used to store the button data
    int pin;
    uint8_t button;
    bool value;
};
pin_button pin_b[] = {{2, BUTTON_Y, false}, {3, BUTTON_B, false}, {4, BUTTON_A, false}, {5, BUTTON_X, false}};



void loop() {

    for (int i=0; i<=3; i++) {    
      boolean reading = digitalRead(pin_b[i].pin);  // false if the button is pressed
      
        if (!reading && !pin_b[i].value)  {   // if button is pressed and its not sending the button signal
          
            XInput.press(pin_b[i].button);
            digitalWrite(LED_BUILTIN, HIGH);
            pin_b[i].value = true;
            
        } else if (reading && pin_b[i].value) {   // if button is not pressed but it is sending the button signal
          
            XInput.release(pin_b[i].button);
            digitalWrite(LED_BUILTIN, LOW);
            pin_b[i].value = false;
        };
    };
};
