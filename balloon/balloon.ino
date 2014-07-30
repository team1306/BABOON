#include "Wire.h"
#include "ml8511.h"
#include "t5403.h"
#include "adxl335.h"

T5403 barometer (MODE_I2C);
double barometertemp, absolutepressure, baselinepressure, deltaaltitude, absolutealtitude;
const double basealtitude = 270.0; // need to get more accurate altitude value at launch site

ML8511 uvsensor (A0, A1);

ADXL335 accelerometer (A3, A4, A5);

void setup() {
  Serial.begin(9600);
  uvsensor.begin();
  barometer.begin();
  baselinepressure = barometer.getPressure(MODE_ULTRA);
}

void loop() {
  delay(500);
  
  // Barometer measurements
  barometertemp = barometer.getTemperature(CELSIUS);
  absolutepressure = barometer.getPressure(MODE_ULTRA); // should we split this off and do it less often?
  /*
  MODE          Time
  
  MODE_LOW      5ms
  MODE_STANDARD 11ms
  MODE_HIGH     19ms
  MODE_ULTRA    67ms 
  */
  
  deltaaltitude = altitude(absolutepressure, baselinepressure);
  absolutealtitude = basealtitude + deltaaltitude;
  
  //
  
  //Data output
  Serial.println(uvsensor.read());
  Serial.println(absolutealtitude);
}

double altitude(double P, double P0) // Via SparkFun example implementation, since magic numbers are magical
// Given a pressure measurement P (Pa) and the pressure at a baseline P0 (Pa),
// return altitude (meters) above baseline.
{
	return(44330.0*(1-pow(P/P0,1/5.255)));
}


