#include "Wire.h"
#include "ml8511.h"
#include "t5403.h"

T5403 barometer (MODE_I2C);
ML8511 uvsensor (A0, A1);

void setup() {
  Serial.begin(9600);
  uvsensor.begin();
}

void loop() {
  delay(500);
  Serial.println(uvsensor.read());
}


