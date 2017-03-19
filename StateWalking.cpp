#include "StateWalking.h"

State *StateWalking::run() {
	start();
	Orient data = _robot->_sensor.getAll();
	_robot->_ecran.orientation(data.x, data.y, data.z);
	// Stopped by command interrupt
	// if (duration() > WALKING_DELAY) {
	// 	_robot->_ecran.clear();
	// 	stop();
	// 	return _stateIdle;
	// }
	return (State *)this;
}