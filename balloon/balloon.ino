#include "Wire.h"
#include "ml8511.h"
#include "t5403.h"
#include "adxl335.h"
#include "max6675.h"

T5403 barometer (MODE_I2C);
ML8511 uvsensor (A0);
ADXL335 accelerometer (A1, A2, A3);
MAX6675 thermocouple (13, 10, 12);

void setup() {
  Serial.begin(9600);
  Serial.print("\n\n\n");
  Serial.println("Serial Initialized");
  uvsensor.begin();
  Serial.println("UV Sensor Initialized");
  barometer.begin(0.0); // initialize barometer with altitude
  Serial.println("Barometer Initialized");
  accelerometer.begin();
  Serial.println("Accelerometer Initialized");
  thermocouple.readCelsius();
  Serial.println("Thermocouple Initialized");
  Serial.println();

  Serial.print("altitude,pressure,uv,x-axis,y-axis,z-axis,temp");
}

void loop() {
  Serial.print("DATA: ");

  Serial.print(barometer.getAltitude());
  Serial.print(",");
  Serial.print(barometer.read());
  Serial.print(",");

  Serial.print(uvsensor.read());
  Serial.print(",");

  acceleration data = accelerometer.read();
  Serial.print(data.x);
  Serial.print(",");
  Serial.print(data.y);
  Serial.print(",");
  Serial.print(data.z);
  Serial.print(",");

  Serial.print(thermocouple.readCelsius());
  Serial.print("\n");
}
