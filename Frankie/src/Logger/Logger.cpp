#include "Arduino.h"
#include "Logger.h"
#include <U8g2lib.h>

uint8_t BUFFER[DISPLAY_HEIGHT * DISPLAY_WIDTH];

Logger::Logger(uint8_t clock, uint8_t data, uint8_t reset) {
    _display = new U8X8_SSD1306_128X32_UNIVISION_SW_I2C(clock, data, reset);
}

void Logger::begin() {
    _display->begin();
    _display->setFont(u8x8_font_pxplustandynewtv_f);

    _u8g2Logger.begin(*_display, DISPLAY_WIDTH, DISPLAY_HEIGHT, BUFFER);
    _u8g2Logger.setRedrawMode(1);/// 0: Update screen with newline, 1: Update screen for every char
}

void Logger::terminal_print(String line) {
    _u8g2Logger.print(line);
}

void Logger::terminal_print(float line) {
    _u8g2Logger.print(line);
}

void Logger::terminal_println(String line) {
    _u8g2Logger.println(line);
}

void Logger::terminal_println(float line) {
    _u8g2Logger.println(line);
}

void Logger::print4Lines(String title, String line1, String line2, String line3) {
    _display->drawString(0,0,title.c_str());
    _display->drawString(0,1,line1.c_str());
    _display->drawString(0,2,line2.c_str());
    _display->drawString(0,3,line3.c_str());
}