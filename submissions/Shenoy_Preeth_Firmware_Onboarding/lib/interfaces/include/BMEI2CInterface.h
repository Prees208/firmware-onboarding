#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
private:
    Adafruit_BME280 bme;
public:
    BMEI2CInterface() = default;
    bool begin() {
        return bme.begin(BMEConstants::BME_I2C_ADDR);
    }

    float readTemperature() {
        return bme.readTemperature();
    }
    float readPressure() {
        return bme.readPressure() / 100.0F; // Pa to hPa
    }
    float readHumidity() {
        return bme.readHumidity();
    }
};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;