#include "Robot.h"



void Robot::init() {
	_sensor.init();
	_ecran.init();
	_servoDriver = Adafruit_PWMServoDriver();
	_servoDriver.begin();
	_servoDriver.setPWMFreq(50);

	MyServo servoPD  ((char *)"Pied droit",      100, 200, (uint8_t)500); // 0
	MyServo servoGD  ((char *)"Genou droit",     100, 200, (uint8_t)500); // 1
	MyServo servoHD  ((char *)"Hanche droite",   100, 200, (uint8_t)500); // 2
	MyServo servoCD  ((char *)"Coude droit",     100, 200, (uint8_t)500); // 3
	MyServo servoEDX ((char *)"Epaule droite X", 100, 200, (uint8_t)500); // 4
	MyServo servoEDZ ((char *)"Epaule droite Z", 100, 200, (uint8_t)500); // 5
	MyServo servoT   ((char *)"Tete",            100, 200, (uint8_t)500); // 6
	MyServo servoEGZ ((char *)"Epaule gauche Z", 100, 200, (uint8_t)500); // 7
	MyServo servoEGX ((char *)"Epaule gauche X", 100, 200, (uint8_t)500); // 8
	MyServo servoCG  ((char *)"Coude gauche",    100, 200, (uint8_t)500); // 9
	MyServo servoHG  ((char *)"Hanche gauche",   100, 200, (uint8_t)500); // 10
	MyServo servoGG  ((char *)"Genou gauche",    100, 200, (uint8_t)500); // 11
	MyServo servoPG  ((char *)"Pied gauche",     100, 200, (uint8_t)500); // 12

	servos[SERVO_PIED_D]     = servoPD;
	servos[SERVO_GENOU_D]    = servoGD;
	servos[SERVO_HANCHE_D]   = servoHD;
	servos[SERVO_COUDE_D]    = servoCD;
	servos[SERVO_EPAULE_X_D] = servoEDX;
	servos[SERVO_EPAULE_Z_D] = servoEDZ;
	servos[SERVO_TETE]       = servoT;
	servos[SERVO_EPAULE_Z_G] = servoEGZ;
	servos[SERVO_EPAULE_X_G] = servoEGX;
	servos[SERVO_COUDE_G]    = servoCG;
	servos[SERVO_HANCHE_G]   = servoHG;
	servos[SERVO_GENOU_G]    = servoGG;
	servos[SERVO_PIED_G]     = servoPG;

	for (byte i = 0; i < 13; i++) {
		directMove(i, servos[i]._rep);
	}
}

void Robot::directMove(byte servo, uint8_t pos) {
	pos = constrain(pos, servos[servo]._min, servos[servo]._max);
	_servoDriver.setPWM(servo, 0, pos);
}

char *Robot::getServoName(byte servo) {
	servo = constrain(servo, 0, 12);
	return servos[servo]._nom;
}