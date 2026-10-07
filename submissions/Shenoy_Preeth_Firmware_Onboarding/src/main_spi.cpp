#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

//LEDController ledController(BMEConstants::LED_PIN);

void setup() {
    Serial.begin(115200);
    LEDControllerInstance::create(BMEConstants::LED_PIN);
    LEDControllerInstance::instance().init();

    if (!BMESPIInterfaceInstance::instance().begin()) {
        Serial.println("Error: Failed to initialize BME280 sensor via SPI!");
        while (1);
    }
}

void loop() {
    float temperature = BMESPIInterfaceInstance::instance().readTemperature();
    Serial.print("SPI Temperature: ");
    Serial.println(temperature);
    LEDControllerInstance::instance().updateBlinkRate(temperature);
}