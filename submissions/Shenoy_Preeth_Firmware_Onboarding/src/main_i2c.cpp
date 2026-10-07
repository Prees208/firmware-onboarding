#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

void setup() {
    Serial.begin(115200);
    // Initialize singleton instance
    
    LEDControllerInstance::create(BMEConstants::LED_PIN);
    LEDControllerInstance::instance().init();

    if (!BMEI2CInterfaceInstance::instance().begin()) {
        Serial.println("Error: Failed to initialize BME280 sensor via I2C!");
        while (1);
    }
}
void loop() {
    float temperature = BMEI2CInterfaceInstance::instance().readTemperature();

    Serial.print("I2C Temperature: ");
    Serial.println(temperature);
    //ledController.updateBlinkRate(temperature);
    LEDControllerInstance::instance().updateBlinkRate(temperature);
}