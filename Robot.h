#ifndef Robot_h
#define Robot_h

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "Ecran.h"
#include "BNOSensor.h"
#include "MyServo.h"

// Index in array
#define SERVO_PIED_D      12
#define SERVO_GENOU_D     11
#define SERVO_HANCHE_D    10
#define SERVO_COUDE_D     9
#define SERVO_EPAULE_X_D  8
#define SERVO_EPAULE_Z_D  7
#define SERVO_TETE        6
#define SERVO_EPAULE_Z_G  5
#define SERVO_EPAULE_X_G  4
#define SERVO_COUDE_G     3
#define SERVO_HANCHE_G    2
#define SERVO_GENOU_G     1
#define SERVO_PIED_G      0

#define NOMBRE_SERVO 13

class Robot {
	public:
		void init();
		Ecran _ecran;
		BNOSensor _sensor;
		void directMove(byte servo, uint16_t pos);
		char *getServoName(byte servo);
		void restPosition();
	private:
		MyServo _servos[NOMBRE_SERVO];
		Adafruit_PWMServoDriver _servoDriver;
};

#endif
