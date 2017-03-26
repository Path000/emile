#ifndef MyServo_h
#define MyServo_h

#include <Arduino.h>

class MyServo {
	public:
		inline MyServo() {};
		MyServo(byte pin, char *nom, byte min, byte rep, byte max);
		void write(byte pos);
		void writeRepPos();
	private:
		byte _pin;
		char *_nom;
		byte _min;
		byte _rep;
		byte _max;
};

#endif
