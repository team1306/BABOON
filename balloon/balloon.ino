#include "Wire.h"
#include "ml8511.h"
#include "t5403.h"
#include "adxl335.h"

T5403 barometer (MODE_I2C);
ML8511 uvsensor (A0, A1);
ADXL335 accelerometer (A3, A4, A5);

void setup() {
  Serial.begin(9600);
  Serial.println("Serial Initialized");
  uvsensor.begin();
  Serial.println("UV Sensor Initialized");
  barometer.begin(270.0); // initialize barometer with altitude
  Serial.println("Barometer Initialized");
  accelerometer.begin();
  Serial.println("Accelerometer Initialized");
}

uint32_t lastTime;

void loop() {
  lastTime = millis();
  Serial.print(barometer.getAltitude());
  Serial.print(" | ");
  Serial.print(barometer.read());
  Serial.print(" || ");
  
  Serial.print(uvsensor.read());
  Serial.print(" || ");

  acceleration data = accelerometer.read();
  Serial.print(data.x);
  Serial.print(" | ");
  Serial.print(data.y);
  Serial.print(" | ");
  Serial.println(data.z);

  while(millis() - lastTime < 500) {} // better than delaying since this accounts for the time it took to perform the measurements
}

