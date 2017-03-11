#include "StateWalking.h"

State *StateWalking::run() {
	start();
	Orient data = _robot->_sensor.getAll();
	_robot->_ecran.orientation(data.x, data.y, data.z);
	// Stopped by command interrupt
	return (State *)this;
}