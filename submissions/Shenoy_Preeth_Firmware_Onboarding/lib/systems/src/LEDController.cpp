#include "LEDController.h"

LEDController::LEDController(uint8_t ledPin) : pin(ledPin) {}

void LEDController::init() {
    pinMode(pin, OUTPUT);
}

void LEDController::updateBlinkRate(float temperature) {
    uint16_t delayMs = (temperature > BMEConstants::TEMP_MAX_C) 
                        ? BMEConstants::BLINK_DELAY_FAST_MS 
                        : BMEConstants::BLINK_DELAY_SLOW_MS;

    digitalWrite(pin, HIGH);
    delay(delayMs);
    digitalWrite(pin, LOW);
    delay(delayMs);
}