#include "Robot.h"



void Robot::init() {
	_sensor.init();
	_ecran.init();

// TODO câblage
// On the Arduino Mega, it works on pins 2 - 13 and 44 - 46.
// Virer 5 et 6  https://www.arduino.cc/en/Reference/analogWrite

	MyServo servoPD(  4,  (char *)"Pied droit",      130, 200, 235); // 0
	MyServo servoGD(  3,  (char *)"Genou droit",     130, 200, 235); // 1
	MyServo servoHD(  2,  (char *)"Hanche droite",   130, 200, 235); // 2
	MyServo servoCD(  7,  (char *)"Coude droit",     130, 200, 235); // 3
	MyServo servoEDX( 6,  (char *)"Epaule droite X", 130, 200, 235); // 4
	MyServo servoEDZ( 5,  (char *)"Epaule droite Z", 130, 200, 235); // 5
	MyServo servoT(   44, (char *)"Tete",            130, 200, 235); // 6
	MyServo servoEGZ( 10, (char *)"Epaule gauche Z", 130, 200, 235); // 7
	MyServo servoEGX( 9,  (char *)"Epaule gauche X", 130, 200, 235); // 8
	MyServo servoCG(  8,  (char *)"Coude gauche",    130, 200, 235); // 9
	MyServo servoHG(  13, (char *)"Hanche gauche",   130, 200, 235); // 10
	MyServo servoGG(  12, (char *)"Genou gauche",    130, 200, 235); // 11
	MyServo servoPG(  11, (char *)"Pied gauche",     130, 200, 235); // 12
	servos[SERVO_PIED_D] =     servoPD;
	servos[SERVO_GENOU_D] =    servoGD;
	servos[SERVO_HANCHE_D] =   servoHD;
	servos[SERVO_COUDE_D] =    servoCD;
	servos[SERVO_EPAULE_X_D] = servoEDX;
	servos[SERVO_EPAULE_Z_D] = servoEDZ;
	servos[SERVO_TETE] =       servoT;
	servos[SERVO_EPAULE_Z_G] = servoEGZ;
	servos[SERVO_EPAULE_X_G] = servoEGX;
	servos[SERVO_COUDE_G] =    servoCG;
	servos[SERVO_HANCHE_G] =   servoHG;
	servos[SERVO_GENOU_G] =    servoGG;
	servos[SERVO_PIED_G] =     servoPG;

	for (byte i = 0; i < 13; i++) {
		//servos[i].writeRepPos();
	}
}

void Robot::directMove(byte servo, byte pos) {
	servos[servo].write(pos);
}

