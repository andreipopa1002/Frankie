#ifndef Controller_h
#define Controller_h

#include "Arduino.h"
class TemperaturePresenter;
class TemperatureSensor;
class Relay;
class Controller {
    public:
        Controller(
            TemperatureSensor *thermo, 
            Relay *relay,
            TemperaturePresenter *temperaturePresenter
        );
        void begin();
        void loop();
    private:
        TemperatureSensor *_thermo;
        Relay *_relay;
        TemperaturePresenter *_presenter;
        float _lastTriggeringTemperature;

        bool isSwitchOn(float temperature, float turnOnTemp, float turnOffTemp);
        bool isTemperatureChangeSignificant(float temperature);
};

#endif