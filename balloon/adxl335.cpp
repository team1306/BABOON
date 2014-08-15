#include "adxl335.h"
#include "Arduino.h"

ADXL335::ADXL335(uint8_t xaxis, uint8_t yaxis, uint8_t zaxis) {
	x = xaxis;
	y = yaxis;
	z = zaxis;
}

void ADXL335::begin(void) {
	pinMode(x, INPUT);
	pinMode(y, INPUT);
	pinMode(z, INPUT);
}
 
uint16_t ADXL335::getRawAxis(uint8_t axis) {
        uint16_t output = analogRead(axis);
        return output;
}

acceleration ADXL335::read(void) {
  acceleration data;
  data.x = getRawAxis(x);
  data.y = getRawAxis(y);
  data.z = getRawAxis(z);
  return data;
}
