#include "Arduino.h"
#include "TemperatureSensor.h"
#include <Adafruit_MAX31865.h>

const float RREF = 431.0;
const float RNOMINAL = 100.0;

TemperatureSensor::TemperatureSensor(int csPin, int diPin, int doPin, int clkPin) {
    _csPin = csPin;
    _diPin = diPin;
    _doPin = doPin;
    _clkPin = clkPin;
    _thermo = new Adafruit_MAX31865(csPin, diPin, doPin, clkPin);
}

void TemperatureSensor::begin() {
    _thermo->begin(MAX31865_2WIRE);
}

float TemperatureSensor::temperature() {
    return _thermo->temperature(RNOMINAL, RREF);
}

void TemperatureSensor::printRawValues() {
    Serial.println("Looping");
    uint16_t rtd = _thermo->readRTD();
    Serial.print("RTD value: "); Serial.println(rtd);
    float ratio = rtd;
    ratio /= 32768;
    Serial.print("Ratio = "); Serial.println(ratio,8);
    Serial.print("Resistance = "); Serial.println(RREF*ratio,8);
    Serial.print("Temperature = "); Serial.println(_thermo->temperature(RNOMINAL, RREF));
}

void TemperatureSensor::printSensorFaults() {
    uint8_t fault = _thermo->readFault();
    if (fault) {
        Serial.print("Fault 0x"); Serial.println(fault, HEX);
        if (fault & MAX31865_FAULT_HIGHTHRESH) {
            Serial.println("RTD High Threshold"); 
        }
        
        if (fault & MAX31865_FAULT_LOWTHRESH) {
            Serial.println("RTD Low Threshold"); 
        }
        
        if (fault & MAX31865_FAULT_REFINLOW) {
            Serial.println("REFIN- > 0.85 x Bias"); 
        }
        
        if (fault & MAX31865_FAULT_REFINHIGH) {
            Serial.println("REFIN- < 0.85 x Bias - FORCE- open"); 
        }
        
        if (fault & MAX31865_FAULT_RTDINLOW) {
            Serial.println("RTDIN- < 0.85 x Bias - FORCE- open"); 
        }
        
        if (fault & MAX31865_FAULT_OVUV) {
            Serial.println("Under/Over voltage"); 
        }

    _thermo->clearFault();
  }
}