#include "StateCommanded.h"

State *StateCommanded::run() {
	//Serial.println("StateCommanded::run()");
	ParsedCommand data = _command->get();
	if(data.cmd == "") {
		return (State *)this;
	}



	if (data.cmd == COMMAND_START) {
		_robot->_ecran.showCommandStart();
	}
	if (data.cmd == COMMAND_STOP) {
		_robot->_ecran.clear();
		return _stateIdle;
	}
	if (data.cmd == COMMAND_SERVO) {
		byte index = data.arrayArgs[0].toInt();
		long pos = data.arrayArgs[1].toInt();
		char *name = _robot->getServoName(index);
		_robot->_ecran.showCommand(name, pos);

		//Serial.print("CONSOLE:");
		//Serial.print(name);
		//Serial.print(",");
		//Serial.println(pos);

		_robot->directMove(index, pos);
	}
	return (State *)this;
}

void StateCommanded::setCommand(RemoteCommand *command) {
	_command = command;
}
