#ifndef MyServo_h
#define MyServo_h

#include <Arduino.h>
#include <Servo.h>

class MyServo {
	public:
		inline MyServo() {};
		MyServo(byte pin, char *nom, unsigned int min, unsigned int rep, unsigned int max);
		void write(unsigned int pos);
		void writeRep();
	private:
		char *_nom;
		unsigned int _min;
		unsigned int _rep;
		unsigned int _max;
		Servo _servo;
};

#endif
