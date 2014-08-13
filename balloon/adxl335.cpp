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
 
float ADXL335::getrawaxis(char axis) {
        uint16_t output = analogRead(axis);
        return output;
}

float ADXL335::readaxis(char axis) { 
        // The raw values won't give us Gs, which could be more useful.
        uint16_t rawvalue = ADXL335::getrawaxis(axis);
        // Is response linear across the entire range?
}
