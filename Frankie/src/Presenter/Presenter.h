#ifndef Presenter_h
#define Presenter_h

#include "Arduino.h"
#include "Logger/Logger.h"

class Presenter {
    public:
        Presenter(Logger *logger);
        void begin();
        void setupScreen();
        void mainScreen(float temperature, bool isTopFanOn, bool isSideFanOn);
    private:
        Logger *_logger;
};

#endif