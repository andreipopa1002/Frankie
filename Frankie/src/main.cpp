#include <Arduino.h>
#include "Temperature sensor/TemperatureSensor.h"
#include <Adafruit_MAX31865.h>

TemperatureSensor *thermo;

void setup() {
  Serial.begin(9600);
  while(!Serial);

  thermo = new TemperatureSensor(D1, D2, D5, D6);
  Serial.println();
  Serial.println();
  Serial.println("Adafruit MAX31865 PT100 Sensor Test!");
  thermo->begin();
}


void loop() {
  Serial.print("temperature: ");
  Serial.println(thermo->temperature());

  delay(1000);
}