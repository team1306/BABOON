#include "ml8511.h"
#include "Arduino.h"

ML8511::ML8511(uint8_t out) {
  uvout = out;
}

void ML8511::begin(void) {
  pinMode(uvout, INPUT);
  pinMode(ref_3v3, INPUT);
}

float ML8511::read(void) {
  uint16_t refV = 663;
  uint16_t uvV = analogRead(uvout);
  
  return 3.3 / refV * uvV;
}
