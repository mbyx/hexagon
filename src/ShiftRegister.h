#include <Arduino.h>

struct ShiftRegister
{
    int latchPin = 13;
    int clockPin = 12;
    int dataPin = 11;

    void init()
    {
        pinMode(latchPin, OUTPUT);
        pinMode(clockPin, OUTPUT);
        pinMode(dataPin, OUTPUT);
    }

    void write_word(word word)
    {
        digitalWrite(latchPin, LOW);
        // shift out the bits:
        shiftOut(dataPin, clockPin, LSBFIRST, (word >> 8));
        shiftOut(dataPin, clockPin, LSBFIRST, word);
        // take the latch pin high so the LEDs will light up:
        digitalWrite(latchPin, HIGH);
    }
};
