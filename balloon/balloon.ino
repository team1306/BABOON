#include "Wire.h"
#include "ml8511.h"
#include "t5403.h"
#include "adxl335.h"

T5403 barometer (MODE_I2C);
ML8511 uvsensor (A0, A1);

// ADXL335 accelerometer (A3, A4, A5);
// will need to give a way to normalize analog reads to Gs.

void setup() {
  Serial.begin(9600);
  Serial.println("serial works");
  uvsensor.begin();
  Serial.println("UV Sensor Works");
  barometer.begin(270.0); // initialize barometer with altitude
  Serial.println("Barometer initialized");
}

uint32_t lastTime;

void loop() {
  lastTime = millis();
  Serial.println(barometer.getAltitude());
  Serial.println(barometer.read());
  
  Serial.println(uvsensor.read());

  while(millis() - lastTime < 500) {} // better than delaying since this accounts for the time it took to perform the measurements
}

