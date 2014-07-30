#ifndef adxl335_h
#define adxl335_h

#include "Arduino.h"

class ADXL335 {
 public:
  ADXL335(uint8_t, uint8_t, uint8_t);
  void begin(void);
  /* haven't figured out reading yet
  float readX(void);
  */
 private:
  uint8_t x;
  uint8_t y;
  uint8_t z;
};

#endif
