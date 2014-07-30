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

/* Need more hammock time to design the methods and figure out how we should interact with the accelerometer

float ADXL335::readX(void) {
	uint16_t xV = analogRead(x);
}

*/
