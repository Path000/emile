#ifndef BNOSensor_h
#define BNOSensor_h

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

typedef struct {
  int x;
  int y;
  int z;
} Orient;

class BNOSensor {
  public:
    BNOSensor();
    void init();
    Orient getAll();
};

#endif
