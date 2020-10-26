#ifndef TemperatureSensor_h
#define TemperatureSensor_h

#include "Arduino.h"
#include <Adafruit_MAX31865.h>

class TemperatureSensor {
    public:
        TemperatureSensor(int csPin, int diPin, int doPin, int clkPin);
        
        void begin();
        float temperature();
        void printSensorFaults();
        void printRawValues();
    private:
        int _csPin;
        int _diPin;
        int _doPin;
        int _clkPin;
        Adafruit_MAX31865 *_thermo; 
};

#endif
