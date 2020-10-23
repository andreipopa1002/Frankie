#include <Arduino.h>
#include "Temperature sensor/TemperatureSensor.h"
#include <Adafruit_MAX31865.h>

TemperatureSensor *thermo;

void setup() {
  Serial.begin(9600);
  while(!Serial);

  thermo = new TemperatureSensor(D3, D4, D5, D6);
  Serial.println();
  Serial.println();
  Serial.println("Adafruit MAX31865 PT100 Sensor Test!");
  thermo->begin();

  pinMode(D1, OUTPUT);
  pinMode(D0, OUTPUT);
  digitalWrite(D1,LOW);
  digitalWrite(D0,LOW);
}


void loop() {
  float temperature = thermo->temperature();
  Serial.print("temperature:");
  Serial.println(temperature);
  

  if (temperature > 25) {
    digitalWrite(D0, HIGH);
  } else {
    digitalWrite(D0, LOW);
  }  

  if (temperature >27) {
    digitalWrite(D1, HIGH);
  } else {
    digitalWrite(D1, LOW);
  }

  delay(1000);
}