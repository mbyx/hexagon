#include <Arduino.h>

struct ToggleButton
{
    int pin = 10;
    bool toggle = true;
    int prevState = LOW;

    void init()
    {
        pinMode(pin, INPUT);
    }

    bool toggle_read()
    {
        int currState = digitalRead(pin);
        if (prevState != currState and currState == LOW)
        {
            toggle = not toggle;
        }
        prevState = currState;
        
        return toggle;
    }
};