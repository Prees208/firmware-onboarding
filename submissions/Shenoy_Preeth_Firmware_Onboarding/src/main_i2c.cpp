#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"
LEDController ledController(BMEConstants::LED_PIN);
void setup() {
    Serial.begin(115200);
    ledController.init();
    if (!BMEI2CInterfaceInstance::instance().begin()) {
        Serial.println("Error: Failed to initialize BME280 sensor via I2C!");
        while (1);
    }
}
void loop() {
    float temperature = BMEI2CInterfaceInstance::instance().readTemperature();

    Serial.print("I2C Temperature: ");
    Serial.println(temperature);
    ledController.updateBlinkRate(temperature);
}