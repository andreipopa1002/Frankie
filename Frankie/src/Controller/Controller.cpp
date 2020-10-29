#include "Arduino.h"
#include "Controller.h"
#include "Temperature sensor/TemperatureSensor.h"
#include "Presenter/TemperaturePresenter.h"
#include "Relay/Relay.h"

const float TOP_FAN_ON_TEMP = 85.0;//23;
const float TOP_FAN_OFF_TEMP = 80.0;//22;
const float SIDE_FAN_ON_TEMP = 90.0;//30;
const float SIDE_FAN_OFF_TEMP = 85.0;//25;

Controller::Controller(
    TemperatureSensor *thermo, 
    Relay *relay,
    TemperaturePresenter *temperaturePresenter
) {
    _thermo = thermo;
    _relay = relay;
    _presenter = temperaturePresenter;
    _lastTriggeringTemperature = 0.0;
}

void Controller::begin() {
    _thermo->begin();
    _relay->begin();
    _presenter->begin();
    _presenter->setupScreen();
}

void Controller::loop() {
    float temperature = _thermo->temperature();

    bool shouldActivateSwitch1 = isSwitchOn(temperature, TOP_FAN_ON_TEMP, TOP_FAN_OFF_TEMP);
    bool shouldActivateSwitch2 = isSwitchOn(temperature, SIDE_FAN_ON_TEMP, SIDE_FAN_OFF_TEMP);
   
    if (_relay->isSwitch1Active() != shouldActivateSwitch1
        && isTemperatureChangeSignificant(temperature)) {
        _relay->activateSwitch1(shouldActivateSwitch1);
        _lastTriggeringTemperature = temperature;
    }

    if (_relay->isSwitch2Active() != shouldActivateSwitch2
        && isTemperatureChangeSignificant(temperature)) {
        _relay->activateSwitch2(shouldActivateSwitch2);
        _lastTriggeringTemperature = temperature;
    }

    _presenter->mainScreen(temperature, _relay->isSwitch1Active(), _relay->isSwitch2Active());
}

bool Controller::isSwitchOn(float temperature, float turnOnTemp, float turnOffTemp) {
    bool isSwitchOn = false;
   
    if (temperature > turnOnTemp) {
        isSwitchOn = true;
    } else if (temperature < turnOffTemp) {
        isSwitchOn = false;
    } else if (temperature <= turnOnTemp && temperature >= turnOffTemp) {
        isSwitchOn = true;
    }

    return isSwitchOn;
}

bool Controller::isTemperatureChangeSignificant(float temperature) {
    return abs(_lastTriggeringTemperature - temperature) >= 0.25;
}
