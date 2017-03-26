#include "MyServo.h"

MyServo::MyServo(byte pin, char *nom, byte min, byte rep, byte max) {
	_pin = pin;
	_nom = nom;
	_min = min;
	_rep = rep;
	_max = max;
}

void MyServo::write(byte angle) {
	// On défini les bornes
	if (_max > _min) {
		angle = constrain(angle, _min, _max);
	} else {
		angle = constrain(angle, _max, _min);
	}

	analogWrite(_pin, angle);
}

void MyServo::writeRepPos() {
	write(_rep);
}