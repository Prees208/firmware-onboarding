#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  //main code here
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
