#include "BNOSensor.h"

Adafruit_BNO055 bno = Adafruit_BNO055(55);

BNOSensor::BNOSensor() {

}

void BNOSensor::init() {
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  bno.setExtCrystalUse(true);

}

Orient BNOSensor::getAll() {
  Orient data;
  sensors_event_t event;
  bno.getEvent(&event);
  data.x = event.orientation.x;
  data.y = event.orientation.y;
  data.z = event.orientation.z;
  return data;
}

