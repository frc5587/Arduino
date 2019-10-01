#include <XInput.h>

void setup()
{
    // initialize button pins
    pinMode(2, INPUT_PULLUP); // pin 2 = Y (UP)
    pinMode(3, INPUT_PULLUP); // pin 3 = B (RIGHT)
    pinMode(4, INPUT_PULLUP); // pin 4 = A (DOWN)
    pinMode(5, INPUT_PULLUP); // pin 5 = X (LEFT)
}


struct pin_button {
    int pin;
    uint8_t button;
    bool value;
};
pin_button pin_b[] = {{2, BUTTON_Y, false}, {3, BUTTON_B, false}, {4, BUTTON_A, false}, {5, BUTTON_X, false}};



void loop() {

    for (pin_button set : pin_b) {    
        if (!digitalRead(set.pin) && !set.value)  {   // if button is pressed and its not sending the signal
            press(set.button);
        };
        else if (digitalRead(set.pin) && set.value) {   // if button is not pressed but it is sending the signal
            release(set.button);
        };
    };
};
