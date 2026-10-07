#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface {
private:
    Adafruit_BME280 bme; // BME280 SPI instance using Chip Select pin

public:
    BMESPIInterface();
    //bool init();
    bool begin() {
        return bme.begin();
    }
    //float getTemperature();
    float readTemperature() {
        return bme.readTemperature();
    }
    float getPressure();
    float getHumidity();
};
//added
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;