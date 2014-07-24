#include "ml8511.h"

ML8511 uvsensor (A0, A1);

void setup() {
  Serial.begin(9600);
  uvsensor.begin();
}

void loop() {
  delay(500);
  Serial.println(uvsensor.read());
}


