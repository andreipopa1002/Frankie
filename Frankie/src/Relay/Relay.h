#ifndef Relay_h
#define Relay_h

#include "Arduino.h"

class Relay {
    public:
        Relay(int pinSwitch1, int pinSwitch2);
        void begin();
        void activateSwitch1(bool isOn);
        void activateSwitch2(bool isOn);
        
    private:
        int _pinSwitch1;
        int _pinSwitch2;
};

#endif
