#include "Wire.h"
#include "ml8511.h"
#include "t5403.h"
#include "adxl335.h"

T5403 barometer (MODE_I2C);
double barometertemp, absolutepressure, baselinepressure, deltaaltitude, absolutealtitude;
const double basealtitude = 270.0; // need to get more accurate altitude value at launch site

ML8511 uvsensor (A0, A1);

// ADXL335 accelerometer (A3, A4, A5);
// will need to give a way to normalize analog reads to Gs.

void setup() {
  Serial.begin(9600);
  Serial.println("serial works");
  uvsensor.begin();
  Serial.println("UV Sensor Works");
  barometer.begin();
  Serial.println("Barometer initialized");
  baselinepressure = barometer.getPressure(MODE_ULTRA);
  Serial.println("baseline pressure established");
}

double pressuretoaltitude(double P) // Via SparkFun example implementation, since magic numbers are magical
// Given a pressure measurement P (Pa) and the baseline pressure from setup, return altitude (in meters) above baseline.
{
	return(44330.0*(1-pow(P/baselinepressure,1/5.255)));
}

double getaltitude(void) {
 absolutepressure = barometer.getPressure(MODE_ULTRA);
  /*
  MODE          Time
  
  MODE_LOW      5ms
  MODE_STANDARD 11ms
  MODE_HIGH     19ms
  MODE_ULTRA    67ms 
  */
  
  deltaaltitude = pressuretoaltitude(absolutepressure);
  absolutealtitude = basealtitude + deltaaltitude; 
}


void loop() {
  delay(500);
  
  // Barometer measurements
  barometertemp = barometer.getTemperature(CELSIUS);
  // altitude = getaltitude()
  
  //Data output
  Serial.println(uvsensor.read());
  Serial.println(getaltitude());
//  Serial.print("X raw value: ");
//  Serial.println(accelerometer.getrawaxis(A5));
  
}

