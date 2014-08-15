#ifndef adxl335_h
#define adxl335_h

#include "Arduino.h"
#include "sensor.h"

struct acceleration {
  uint16_t x, y, z;
};

class ADXL335 : Sensor<void, acceleration>{
 public:
  ADXL335(uint8_t xaxis, uint8_t yaxis, uint8_t zaxis);
  void begin(void);
  acceleration read(void);
  uint16_t getRawAxis(uint8_t axis);
  uint16_t readAxis(uint8_t axis);
 private:
  uint8_t x;
  uint8_t y;
  uint8_t z;
};

#endif
