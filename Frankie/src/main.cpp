#include <Arduino.h>
#include "WiFiManager.h"
#include <ESP_DoubleResetDetector.h>

#include "Temperature sensor/TemperatureSensor.h"
#include "Logger/Logger.h"
#include "Controller/Controller.h"
#include "Relay/Relay.h"
#include "Presenter/WifiManagerPresenter.h"
#include "Presenter/TemperaturePresenter.h"

DoubleResetDetector *resetDetector;

TemperatureSensor *thermo;
Logger *logger;
Controller *controller;
Relay *relay;
TemperaturePresenter *temperaturePresenter;
WifiManagerPresenter *wifiPresenter;
WiFiManager wifiManager;

void configModeCallback (WiFiManager *myWiFiManager) {
  wifiPresenter->enteringConfigMode(myWiFiManager->getConfigPortalSSID());
}

void checkForUserResetRequest() {
  if (resetDetector->detectDoubleReset()) {
    Serial.println("Double reset detected");
    wifiManager.resetSettings();
  }
}

void launchWifi() {
  wifiPresenter->loading("Loading", 5);
  wifiManager.setAPCallback(configModeCallback);
  if(!wifiManager.autoConnect("La Pavoni")) {
    wifiPresenter->failedToConnect();
    ESP.reset();
  } 

  wifiPresenter->connectedToWifi(WiFi.SSID());
  controller->begin();
}

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Setup started");

  resetDetector = new DoubleResetDetector(10, 0);
  checkForUserResetRequest();

  thermo = new TemperatureSensor(0, 13, 12, 14);
  relay = new Relay(2,3);
  logger = new Logger(5,4, 16);
  logger->begin();
  temperaturePresenter = new TemperaturePresenter(logger);
  controller = new Controller(thermo, relay, temperaturePresenter);
  wifiPresenter = new WifiManagerPresenter(logger);
  
  launchWifi();
  
  Serial.println("Setup finished");
}

void loop() {
  controller->loop();
  resetDetector->loop();
  delay(10);
}