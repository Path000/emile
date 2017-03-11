#include "MyServo.h"

MyServo::MyServo(byte pin, char *nom, unsigned int min, unsigned int rep, unsigned int max) {
  _nom = nom;
  _min = min;
  _rep = rep;
  _max = max;
  _servo.attach(pin);
  writeRep();
}

void MyServo::write(unsigned int pos) {
  // On défini les bornes
  if(_max > _min) {
    if(pos > _max) pos = _max;
  }
  else {
    if(pos < _min) pos = _min;
  }
  
  _servo.write(pos);
}

void MyServo::writeRep() {
  _servo.write(_rep);
}

