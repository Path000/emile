#ifndef MyServo_h
#define MyServo_h

#include <Arduino.h>

class MyServo {
	public:
		inline MyServo() {};
		MyServo(char *nom, uint16_t min, uint16_t rep, uint16_t max);
		char *_nom;
		uint16_t _min;
		uint16_t _rep;
		uint16_t _max;
};

#endif
