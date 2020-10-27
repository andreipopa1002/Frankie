#include "Arduino.h"
#include "Presenter.h"
#include "Logger/Logger.h"

Presenter::Presenter(Logger *logger) {
    _logger = logger;
}

void Presenter::loading(String message, int duration) {
    _logger->terminal_print("\n" + message);
    for (int i = 0; i < duration; i++) {
        delay(500);
    _logger->terminal_print(".");
    }
    delay(500);
}