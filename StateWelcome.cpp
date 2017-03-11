#include "StateWelcome.h"

State *StateWelcome::run() {
	if(isFirstLoop()) {
		_robot->_ecran.welcome();
	}
	start();
	if(duration() > WELCOME_DELAY) {
		_robot->_ecran.clear();
		stop();
		return _stateIdle;
	}
	return (State *)this;
}
