#ifndef ml8511_h
#define ml8511_h

#include "Arduino.h"
#include "sensor.h"

class ML8511 : public Sensor<void, float> {
 public:
  ML8511(uint8_t, uint8_t);
  void begin(void);
  float read(void);
 private:
  uint8_t uvout;
  uint8_t ref_3v3;
};

#endif
