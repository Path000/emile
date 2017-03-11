#ifndef Robot_h
#define Robot_h

#include <Arduino.h>
#include "Ecran.h"
#include "BNOSensor.h"
#include "MyServo.h"

// Index in array
#define SERVO_PIED_D      0
#define SERVO_GENOU_D     1
#define SERVO_HANCHE_D    2
#define SERVO_COUDE_D     3
#define SERVO_EPAULE_X_D  4
#define SERVO_EPAULE_Z_D  5
#define SERVO_TETE        6
#define SERVO_EPAULE_Z_G  7
#define SERVO_EPAULE_X_G  8
#define SERVO_COUDE_G     9
#define SERVO_HANCHE_G    10
#define SERVO_GENOU_G     11
#define SERVO_PIED_G      12

#define NOMBRE_SERVO 13

class Robot {
	public:
		void init();
		Ecran _ecran;
		BNOSensor _sensor;
		void directMove(byte servo, int angle);
	private:
		MyServo servos[NOMBRE_SERVO];
};

#endif
