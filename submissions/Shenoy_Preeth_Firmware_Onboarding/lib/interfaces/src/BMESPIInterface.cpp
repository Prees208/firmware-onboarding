#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface() 
    : bme(BMEConstants::BME_CS_PIN) {} // Pass CS pin for hardware SPI

bool BMESPIInterface::init() {
    return bme.begin();
}

float BMESPIInterface::getTemperature() {
    return bme.readTemperature();
}

float BMESPIInterface::getPressure() {
    return bme.readPressure() / 100.0F; // Convert Pa to hPa
}

float BMESPIInterface::getHumidity() {
    return bme.readHumidity();
}