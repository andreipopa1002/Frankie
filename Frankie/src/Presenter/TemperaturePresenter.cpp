#include "Arduino.h"
#include "TemperaturePresenter.h"
#include "Logger/Logger.h"

void TemperaturePresenter::begin() {
    _logger->begin();
}

void TemperaturePresenter::setupScreen() {
    Serial.println("setup screen");
    _logger->terminal_println("** La Pavoni **\nSmart\n-active cooling-");
    delay(500);
    loading("Preparing data", 3);
}

void TemperaturePresenter::mainScreen(
    float temperature, 
    bool isTopFanOn,
     bool isSideFanOn
) {
    Serial.println(String("Temp: " + String(temperature) + "°C"));

    _logger->print4Lines(
        "** La Pavoni **",
        String("Temp:    " + String(temperature) + "\xb0" + "C"),
        String("Top fans:    ") + String(isTopFanOn ? " ON" : "OFF"),
        String("Side fans:   ") + String(isSideFanOn ? " ON" : "OFF")
    );
}