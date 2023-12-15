#include <Arduino.h>

struct DipSwitch
{
    int pins[8] = {2, 3, 4, 5, 6, 7, 8, 9};

    void init()
    {
        for (int i = 0; i < 8; i++)
        {
            pinMode(pins[i], INPUT);
        }
    }

    int read_byte()
    {
        int emptyByte = 0x00;
        for (int i = 0; i < 8; i++)
        {
            bitWrite(emptyByte, 7 - i, digitalRead(pins[i]));
        }
        return emptyByte;
    }
};
