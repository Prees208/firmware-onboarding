#pragma once
#include <Adafruit_BME280.h>
#include "BMEConstants.h"

class BMESPIInterface {
private:
    Adafruit_BME280 bme; // BME280 SPI instance using Chip Select pin

public:
    BMESPIInterface();
    bool init();
    float getTemperature();
    float getPressure();
    float getHumidity();
};