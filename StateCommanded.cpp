#include "StateCommanded.h"

State *StateCommanded::run() {
	if (isFirstLoop()) {
		_robot->_ecran.showCommand(_command);
	}
	start();
	if (_ended) {
		_ended = false;
		_robot->_ecran.clear();
		stop();
		return _stateIdle;
	}
	return (State *)this;
}

void StateCommanded::setCommand(String cmd) {
	_command = cmd;
}

void StateCommanded::endCommand() {
	_ended : true;
}