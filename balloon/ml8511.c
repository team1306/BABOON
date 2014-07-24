#include "ml8511.h"
#include "Arduino.h"

ML8511::ML8511(uint8_t out, uint8_t ref) {
  uvout = out;
  ref_3v3 = ref;
}

void ML8511::begin(void) {
  pinMode(uvout, INPUT);
  pinMode(ref_3v3, INPUT);
}

float ML8511::read(void) {
  uint16_t refV = analogRead(ref_3v3);
  uint16_t uvV = analogRead(uvout);
  
  return 3.3 / refV * uvV;
}
