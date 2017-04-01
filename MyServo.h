#ifndef MyServo_h
#define MyServo_h

#include <Arduino.h>

class MyServo {
	public:
		inline MyServo() {};
		MyServo(char *nom, uint8_t min, uint8_t rep, uint8_t max);
		char *_nom;
		uint8_t _min;
		uint8_t _rep;
		uint8_t _max;
};

#endif
