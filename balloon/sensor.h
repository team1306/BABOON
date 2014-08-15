#ifndef sensor_h
#define sensor_h

template <typename parameter, typename returnType> class Sensor {
 public:
  virtual void begin(parameter);
  virtual returnType read(void);
};

template <typename returnType> class Sensor<void, returnType> {
 public:
  virtual void begin(void);
  virtual returnType read(void);
};

#endif
