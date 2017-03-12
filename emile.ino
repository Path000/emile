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

void serialEvent() {
	Serial.print("serialEvent()");
	command.readCommand();
}

void loop() {
	stateMachine.run();
	delay(100);
}

