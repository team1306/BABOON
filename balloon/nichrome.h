#ifndef nichrome_h
#define nichrome_h

#include "Arduino.h"

class NiChrome {
public:
	NiChrome(uint8_t, double);
	bool cutDown(void);
private:
	uint8_t pin;
	double duration;
	bool on;

	unsigned long startTime;
};

#endif
