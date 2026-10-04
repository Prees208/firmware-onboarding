#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    // I2C Sensor Settings
    constexpr uint8_t BME_I2C_ADDR = 0x76; // Default BME280 I2C address

    // SPI Sensor Settings (CS pin for Chip Select)
    constexpr uint8_t BME_CS_PIN = 10;

    // LED Hardware Settings
    constexpr uint8_t LED_PIN = 13;        // Onboard LED pin

  
    constexpr float TEMP_MIN_C = 20.0f;
    constexpr float TEMP_MAX_C = 40.0f;
    constexpr uint16_t BLINK_DELAY_FAST_MS = 200;
    constexpr uint16_t BLINK_DELAY_SLOW_MS = 1000;
}