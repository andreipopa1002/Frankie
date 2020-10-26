#include "Presenter.h"

Presenter::Presenter(Logger *logger) {
    _logger = logger;
}

void Presenter::begin() {
    _logger->begin();
}

void Presenter::setupScreen() {
    Serial.println("setup screen");
    _logger->print4Lines(
        "",
        "** La Pavoni **",
        "",
        "-active cooling-"
    );
    delay(3000);
}

void Presenter::mainScreen(
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