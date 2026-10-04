#include <Arduino.h>

LEDController ledController(13);

void setup() {
<<<<<<< HEAD
  // setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  //main code here
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
=======
  Serial.begin(115200);
  ledController.init();
  if (!BMEI2CInterfaceInstance::instance().begin()) {
    Serial.println("Error: Failed to initialize BME280 sensor!");
    while (1);
  }
}

void loop() {
  float temperature = BMEI2CInterfaceInstance::instance().readTemperature();
  
  Serial.print("Temperature: ");
  Serial.println(temperature);

  ledController.updateBlinkRate(temperature);
>>>>>>> 4086bcc (Add BME280 I2C and SPI interfaces with LED blink rate)
}
