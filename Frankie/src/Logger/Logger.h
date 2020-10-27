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
        void terminal_print(String line);
        void terminal_print(float line);
        void terminal_println(String line);
        void terminal_println(float line);
        void print4Lines(String title, String line1, String line2, String line3);
        void clear();
    private:
        U8X8 *_display;
        uint8_t _buffer[DISPLAY_WIDTH * DISPLAY_HEIGHT];
        U8X8LOG _u8g2Logger;
};

#endif