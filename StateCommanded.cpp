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

	}
	if (data.cmd == COMMAND_SERVO) {
		int index = data.arrayArgs[0].toInt();
		int angle = data.arrayArgs[1].toInt();
		_robot->directMove(index, angle);
	}
	return (State *)this;
}

void StateCommanded::setCommand(RemoteCommand *command) {
	_command = command;
}
