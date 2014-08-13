#ifndef adxl335_h
#define adxl335_h

#include "Arduino.h"

class ADXL335 {
 public:
  ADXL335(uint8_t xaxis, uint8_t yaxis, uint8_t zaxis);
  void begin(void);
  float getrawaxis(char axis);
  float readaxis(char axis);
 private:
  uint8_t x;
  uint8_t y;
  uint8_t z;
};

#endif
