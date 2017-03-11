#include "StateIdle.h"

State *StateIdle::run() {
	if(isFirstLoop()) {
		_robot->_ecran.eyes();
	}
	start();
	if(duration() > IDLE_DELAY) {
		_robot->_ecran.clear();
		stop();
		return _stateWalking;
	}
	return (State *)this;
}
