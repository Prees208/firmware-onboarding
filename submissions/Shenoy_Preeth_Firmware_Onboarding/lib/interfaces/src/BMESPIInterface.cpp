#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
private:
    Adafruit_BME280 bme;

public:
    BMESPIInterface() : bme(BMEConstants::BME_CS_PIN) {}

    bool begin() {
        return bme.begin();
    }

    float readTemperature() {
        return bme.readTemperature();
    }

    float readPressure() {
        return bme.readPressure() / 100.0F;
    }

    float readHumidity() {
        return bme.readHumidity();
    }
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;