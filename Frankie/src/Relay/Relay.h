#ifndef Relay_h
#define Relay_h

#include "Arduino.h"

class Relay {
    public:
        Relay(
            int pinSwitch1,
            int pinSwitch2,
            bool isSwitch1Active = false,
            bool isSwitch2Active = false
        );
        void begin();
        void activateSwitch1(bool isActive);
        void activateSwitch2(bool isActive);
        bool isSwitch1Active();
        bool isSwitch2Active();
        
    private:
        int _pinSwitch1;
        int _pinSwitch2;
        bool _isSwitch1Active;
        bool _isSwitch2Active;
};

#endif
