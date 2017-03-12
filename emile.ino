#include "RemoteCommand.h"
#include "Robot.h"
#include "StateMachine.h"

RemoteCommand command;
Robot robot;
StateMachine stateMachine;

void setup() {
	Serial.begin(115200);
	robot.init();
	command.init();
	stateMachine.init(&robot, &command);
}

void loop() {
	if (Serial.available()) {
		delay(100);
		Serial.println("available");
		//command.readCommand();
	}
	stateMachine.run();
	delay(100);
}

