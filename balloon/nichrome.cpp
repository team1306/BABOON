#include "nichrome.h"
#include "Arduino.h"

NiChrome::NiChrome(uint8_t p, double time) {
	pin = p;
	duration = time;
	on = false;
	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
}

bool NiChrome::cutDown(void) {
	if(!on) {
		digitalWrite(pin, HIGH);
		return true;
	}
	else {
		if(millis() - startTime < duration) {
			digitalWrite(pin, HIGH);
			return true;
		}
		else {
			digitalWrite(pin, LOW);
			return false;
		}
	}
}
