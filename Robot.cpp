#include "Robot.h"



void Robot::init() {
	_sensor.init();
	_ecran.init();
	_servoDriver = Adafruit_PWMServoDriver();
	_servoDriver.begin();
	_servoDriver.setPWMFreq(53);

// relevé des min max avec le driver 16 servos

	MyServo servoPD  ((char *)"Pied droit",      141, 300, 486);
	MyServo servoGD  ((char *)"Genou droit",     95, 95, 270);
	MyServo servoHD  ((char *)"Hanche droite",   296, 296, 464);
	MyServo servoCD  ((char *)"Coude droit",     117, 315, 315);
	MyServo servoEDX ((char *)"Epaule droite X", 114, 114, 489);
	MyServo servoEDZ ((char *)"Epaule droite Z", 125, 190, 460);
	MyServo servoT   ((char *)"Tete",            238, 369, 500);
	MyServo servoEGZ ((char *)"Epaule gauche Z", 115, 400, 470);
	MyServo servoEGX ((char *)"Epaule gauche X", 117, 320, 320);
	MyServo servoCG  ((char *)"Coude gauche",    279, 279, 430);
	MyServo servoHG  ((char *)"Hanche gauche",   227, 372, 372);
	MyServo servoGG  ((char *)"Genou gauche",    224, 414, 414);
	MyServo servoPG  ((char *)"Pied gauche",     195, 390, 510);

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

void Robot::directMove(byte servo, uint16_t pos) {
	pos = constrain(pos, servos[servo]._min, servos[servo]._max);
	_servoDriver.setPWM(servo, 0, pos);
}

char *Robot::getServoName(byte servo) {
	servo = constrain(servo, 0, 12);
	return servos[servo]._nom;
}