#ifndef Controller_h
#define Controller_h

#include "Arduino.h"
#include "Temperature sensor/TemperatureSensor.h"
#include "Relay/Relay.h"
#include "Presenter/Presenter.h"

class Controller {
    public:
        Controller(
            TemperatureSensor *thermo, 
            Relay *relay,
            Presenter *presenter
            );
        void begin();
        void loop();
    private:
        TemperatureSensor *_thermo;
        Relay *_relay;
        Presenter *_presenter;
        bool isSwitchOn(float temperature, float turnOnTemp, float turnOffTemp);
};

#endif