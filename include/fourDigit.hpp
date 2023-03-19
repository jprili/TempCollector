/**
 * "fourDigit":
 * mini-library for four digit,
 * seven segment displays.
 *
 * (c) jprili 2023
 */

#pragma once

#ifndef fourDigit_hpp
#define fourDigit_hpp

#if defined(ARDUINO)
#include "Arduino.h"
#endif

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
#endif