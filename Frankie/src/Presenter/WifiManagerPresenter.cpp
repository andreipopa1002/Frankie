#include "WifiManagerPresenter.h"
#include "Logger/Logger.h"
#include "Arduino.h"

void WifiManagerPresenter::begin() { }

void WifiManagerPresenter::connectedToWifi(String wifiName) {
    _logger->clear();
    _logger->terminal_println("Connected \nwifi:");
    delay(500);
    _logger->terminal_println("\n" + wifiName);
    delay(2000);
}

void WifiManagerPresenter::enteringConfigMode(String wifiName) {
    _logger->clear();
    _logger->terminal_println("Config needed\n");
    delay(1500);
    _logger->clear();
    _logger->terminal_print("Connect to wifi:\n");
    delay(500);
    _logger->terminal_print("\n   " + wifiName);
}

void WifiManagerPresenter::failedToConnect() {
    Serial.println("failed to connect and hit timeout");
    _logger->clear();
    delay(500);
    _logger->terminal_println("Connection failed");
    delay(200);
    _logger->terminal_println("Hit timout");
    _logger->clear();
    delay(100);
    loading("     Retrying", 3);
    delay(500);
}