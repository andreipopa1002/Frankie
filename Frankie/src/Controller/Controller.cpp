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
}

void Controller::begin() {
    _thermo->begin();
    _relay->begin();
    _presenter->begin();
    _presenter->setupScreen();
}

void Controller::loop() {
    float temperature = _thermo->temperature();

    bool isSwitch1_On = this->isSwitchOn(temperature, TOP_FAN_ON_TEMP, TOP_FAN_OFF_TEMP);
    bool isSwitch2_On = this->isSwitchOn(temperature, SIDE_FAN_ON_TEMP, SIDE_FAN_OFF_TEMP);
   
    _relay->activateSwitch1(isSwitch1_On);
    _relay->activateSwitch2(isSwitch2_On);

    _presenter->mainScreen(temperature, isSwitch1_On, isSwitch2_On);
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

