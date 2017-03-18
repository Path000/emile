#include "StateCommanded.h"

State *StateCommanded::run() {
	Serial.println("StateCommanded::run()");
	ParsedCommand data = _command->get();
	if(data.cmd == "") {
		return (State *)this;
	}
	_robot->_ecran.showCommand(data);
	if (data.cmd == COMMAND_START) {
	}
	if (data.cmd == COMMAND_STOP) {
		_robot->_ecran.clear();
		return _stateIdle;
	}
	if (data.cmd == COMMAND_ANGLE) {
		_robot->directMove(_selectedServo, data.arg.toInt());
	}
	if (data.cmd == COMMAND_SERVO) {
		_selectedServo = data.arg.toInt();
	}
	return (State *)this;
}

void StateCommanded::setCommand(RemoteCommand *command) {
	_command = command;
}
