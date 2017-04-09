#include "Robot.h"



void Robot::init() {
	_sensor.init();
	_ecran.init();
	_servoDriver = Adafruit_PWMServoDriver();
	_servoDriver.begin();
	_servoDriver.setPWMFreq(53);

// relevé des min max avec le driver 16 servos

	MyServo servoPD  ((char *)"Pied droit",      141, 300, 486); // 12
	MyServo servoGD  ((char *)"Genou droit",     95, 95, 270);   // 11
	MyServo servoHD  ((char *)"Hanche droite",   296, 296, 464); // 10
	MyServo servoCD  ((char *)"Coude droit",     117, 315, 315); // 9
	MyServo servoEDX ((char *)"Epaule droite X", 114, 114, 489); // 8
	MyServo servoEDZ ((char *)"Epaule droite Z", 125, 190, 460); // 7
	MyServo servoT   ((char *)"Tete",            238, 369, 500); // 6
	MyServo servoEGZ ((char *)"Epaule gauche Z", 115, 400, 470); // 5
	MyServo servoEGX ((char *)"Epaule gauche X", 117, 320, 320); // 4
	MyServo servoCG  ((char *)"Coude gauche",    279, 279, 430); // 3
	MyServo servoHG  ((char *)"Hanche gauche",   227, 372, 372); // 2
	MyServo servoGG  ((char *)"Genou gauche",    224, 414, 414); // 1
	MyServo servoPG  ((char *)"Pied gauche",     195, 377, 510); // 0

	_servos[SERVO_PIED_D]     = servoPD;
	_servos[SERVO_GENOU_D]    = servoGD;
	_servos[SERVO_HANCHE_D]   = servoHD;
	_servos[SERVO_COUDE_D]    = servoCD;
	_servos[SERVO_EPAULE_X_D] = servoEDX;
	_servos[SERVO_EPAULE_Z_D] = servoEDZ;
	_servos[SERVO_TETE]       = servoT;
	_servos[SERVO_EPAULE_Z_G] = servoEGZ;
	_servos[SERVO_EPAULE_X_G] = servoEGX;
	_servos[SERVO_COUDE_G]    = servoCG;
	_servos[SERVO_HANCHE_G]   = servoHG;
	_servos[SERVO_GENOU_G]    = servoGG;
	_servos[SERVO_PIED_G]     = servoPG;

	restPosition();
}

void Robot::restPosition() {
	for (byte i = 0; i < 13; i++) {
		directMove(i, _servos[i]._rep);
	}
}

void Robot::directMove(byte servo, uint16_t pos) {
	pos = constrain(pos, _servos[servo]._min, _servos[servo]._max);
	_servoDriver.setPWM(servo, 0, pos);
}

char *Robot::getServoName(byte servo) {
	servo = constrain(servo, 0, 12);
	return _servos[servo]._nom;
}