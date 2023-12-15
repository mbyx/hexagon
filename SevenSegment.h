#include <Arduino.h>

struct SevenSegment {
    byte Zero = ~0b01111110;
    byte One = ~0b00010010;
    byte Two = ~0b10111100;
    byte Three = ~0b10110110;
    byte Four = ~0b11010010;
    byte Five = ~0b11100110;
    byte Six = ~0b11101110;
    byte Seven = ~0b00110010;
    byte Eight = ~0b11111110;
    byte Nine = ~0b11110110;
    byte A = ~0b11111010;
    byte B = ~0b11001110;
    byte C = ~0b01101100;
    byte D = ~0b10011110;
    byte E = ~0b11101100;
    byte F = ~0b11101000;

    word get_number(int n) {
        word emptyWord = 0x0000;
        unsigned ones = (n / 1U) % 10;
        unsigned tens = (n / 10U) % 10;
        emptyWord = get_digit(ones);
        emptyWord = (emptyWord << 8) | get_digit(tens);

        return emptyWord;
    }

    word get_hex(int n) {
        word emptyWord = 0x0000;
        unsigned ones = (n / 1U) % 16;
        unsigned sixteenths = (n / 16U) % 16;
        emptyWord = get_digit(ones);
        emptyWord = (emptyWord << 8) | get_digit(sixteenths);

        return emptyWord;
    }

    byte get_digit(int digit) {
        switch (digit) {
            case 0:
                return Zero;
            case 1:
                return One;
            case 2:
                return Two;
            case 3:
                return Three;
            case 4:
                return Four;
            case 5:
                return Five;
            case 6:
                return Six;
            case 7:
                return Seven;
            case 8:
                return Eight;
            case 9:
                return Nine;
            case 10:
                return A;
            case 11:
                return B;
            case 12:
                return C;
            case 13:
                return D;
            case 14:
                return E;
            case 15:
                return F;
        };

        return 0xFF;
    }
};