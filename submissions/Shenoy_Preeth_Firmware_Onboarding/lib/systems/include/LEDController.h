#pragma once
#include <Arduino.h>
#include "BMEConstants.h"

class LEDController {
private:
    uint8_t pin;

public:
    LEDController(uint8_t ledPin = BMEConstants::LED_PIN);
    void init();
    void updateBlinkRate(float temperature);
};