#include "Wire.h"
#include "ml8511.h"
#include "t5403.h"
#include "adxl335.h"

T5403 barometer (MODE_I2C);
double barometerTemp, absolutePressure, baselinePressure, deltaAltitude, absoluteAltitude;
const double baseAltitude = 270.0; // need to get more accurate altitude value at launch site

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
  baselinePressure = barometer.getPressure(MODE_ULTRA);
  Serial.println("baseline pressure established");
}

double pressureToAltitude(double P) // Via SparkFun example implementation, since magic numbers are magical
// Given a pressure measurement P (Pa) and the baseline pressure from setup, return altitude (in meters) above baseline.
{
	return(44330.0*(1-pow(P/baselinePressure,1/5.255)));
}

double getAltitude(void) {
 absolutePressure = barometer.getPressure(MODE_ULTRA);
  /*
  MODE          Time
  
  MODE_LOW      5ms
  MODE_STANDARD 11ms
  MODE_HIGH     19ms
  MODE_ULTRA    67ms 
  */
  
  deltaAltitude = pressureToAltitude(absolutePressure);
  absoluteAltitude = baseAltitude + deltaAltitude; 
}


void loop() {
  delay(500);
  
  // Barometer measurements
  barometerTemp = barometer.getTemperature(CELSIUS);
  // altitude = getAltitude()
  
  //Data output
  Serial.println(uvsensor.read());
  Serial.println(getAltitude());
//  Serial.print("X raw value: ");
//  Serial.println(accelerometer.getRawAxis(A5));
  
}

