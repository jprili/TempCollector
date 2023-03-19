/**
 * "fourDigit":
 * mini-library for four digit,
 * seven segment displays.
 * 
 * (c) James Paolo Rili 2023
*/

#pragma once
#include "Arduino.h"

class fourDigit {
    public:
        fourDigit();

        void dispNum(int   num);
        void dispNum(float num);

        void dispClr();
    private:
        uint8_t numToBitmask(int   num);
        uint8_t numToBitmask(float num);

};
