#include "MyServo.h"

MyServo::MyServo(char *nom, uint16_t min, uint16_t rep, uint16_t max) {
	_nom = nom;
	_min = min;
	_rep = rep;
	_max = max;
}
