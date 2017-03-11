#include "State.h"

void State::init(Robot *robot, State *stateIdle, State *stateWalking, State *stateCommanded, State *stateWelcome) {
	_robot = robot;
	_stateIdle = stateIdle;
	_stateWalking = stateWalking;
	_stateCommanded = stateCommanded;
	_stateWelcome = stateWelcome;
	_startedAt = 0;
}

void State::start() {
	if (_startedAt == 0) {
		_startedAt = millis();
	}
}

unsigned long State::duration() {
	return (millis() - _startedAt);
}

void State::stop() {
	_startedAt = 0;
}

boolean State::isFirstLoop() {
	if (_startedAt == 0) {
		return true;
	}
	return false;
}