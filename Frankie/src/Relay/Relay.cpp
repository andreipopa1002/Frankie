#include "Arduino.h"
#include "Relay.h"

Relay::Relay(
    int pinSwitch1,
    int pinSwitch2,
    bool isSwitch1Active, 
    bool isSwitch2Active
) {
    _pinSwitch1 = pinSwitch1;
    _pinSwitch2 = pinSwitch2;
    _isSwitch1Active = isSwitch1Active;
    _isSwitch2Active = isSwitch2Active;
}

void Relay::begin() {
    pinMode(_pinSwitch1, OUTPUT);
    pinMode(_pinSwitch2, OUTPUT);
    activateSwitch1(_isSwitch1Active);
    activateSwitch2(_isSwitch2Active);
}

bool Relay::isSwitch1Active() {
    return _isSwitch1Active;
}

bool Relay::isSwitch2Active() {
    return _isSwitch2Active;
}

void Relay::activateSwitch1(bool isActive) {
    if (_isSwitch1Active != isActive) {
        digitalWrite(_pinSwitch1, isActive ? HIGH : LOW);
        _isSwitch1Active = isActive;
    }
}

void Relay::activateSwitch2(bool isActive) {
    if (_isSwitch2Active != isActive) {
        digitalWrite(_pinSwitch2, isActive ? HIGH : LOW);
        _isSwitch2Active = isActive;
    }
}
