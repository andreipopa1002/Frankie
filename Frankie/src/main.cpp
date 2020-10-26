#include <Arduino.h>
#include <Adafruit_MAX31865.h>
#include <U8g2lib.h>

#include "Temperature sensor/TemperatureSensor.h"
#include "Logger/Logger.h"
#include "Controller/Controller.h"
#include "Relay/Relay.h"

TemperatureSensor *thermo;
Logger *logger;
Controller *controller;
Relay *relay;
Presenter *presenter;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Setup started");
  // 13,12,14,2 - works
  // also work:
  //      0

  thermo = new TemperatureSensor(13,12,14,0);
  logger = new Logger(5,4, 16);
  relay = new Relay(0,0);
  presenter = new Presenter(logger);
  controller = new Controller(thermo, relay, presenter);
  controller->begin();

  Serial.println("Setup finished");
}


void loop() {
  controller->loop();
  
  delay(10);
}