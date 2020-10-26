#ifndef Logger_h
#define Logger_h

#include "Arduino.h"
#include <U8g2lib.h>

const uint8_t DISPLAY_WIDTH = 16;
const uint8_t DISPLAY_HEIGHT = 4;

class Logger {
    public:
        Logger(uint8_t clock, uint8_t data, uint8_t reset);
        
        void begin();
        void print(String line);
        void print(float line);
        void println(String line);
        void println(float line);
        void print4Lines(String title, String line1, String line2, String line3);
    private:
        U8X8 *_display;
        uint8_t _buffer[DISPLAY_WIDTH * DISPLAY_HEIGHT];
        U8X8LOG _u8g2Logger;
};

#endif