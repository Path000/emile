#include "MyServo.h"

MyServo::MyServo(byte pin, char *nom, byte min, byte rep, byte max) {
	_pin = pin;
	_nom = nom;
	_min = min;
	_rep = rep;
	_max = max;
}

void MyServo::write(byte pos) {
	// On défini les bornes
	if (_max > _min) {
		pos = constrain(pos, _min, _max);
	} else {
		pos = constrain(pos, _max, _min);
	}

	analogWrite(_pin, pos);
}

void MyServo::writeRepPos() {
	write(_rep);
}