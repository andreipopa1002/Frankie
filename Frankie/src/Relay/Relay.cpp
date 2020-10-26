#include "Arduino.h"
#include "Relay.h"

Relay::Relay(int pinSwitch1, int pinSwitch2) {
    _pinSwitch1 = pinSwitch1;
    _pinSwitch2 = pinSwitch2;
}

void Relay::begin() {
    pinMode(_pinSwitch1, OUTPUT);
    pinMode(_pinSwitch2, OUTPUT);
    activateSwitch1(false);
    activateSwitch2(false);
}

void Relay::activateSwitch1(bool isOn) {
    digitalWrite(_pinSwitch1, isOn ? HIGH : LOW);
}

void Relay::activateSwitch2(bool isOn) {
    digitalWrite(_pinSwitch2, isOn ? HIGH : LOW);
}
