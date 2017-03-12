#include "StateMachine.h"

void StateMachine::init(Robot *robot, RemoteCommand *command) {
	stateWelcome.init(robot, (State *)&stateIdle, (State *)&stateWalking, (State *)&stateCommanded, (State *)&stateWelcome);
	stateIdle.init(robot, (State *)&stateIdle, (State *)&stateWalking, (State *)&stateCommanded, (State *)&stateWelcome);
	stateWalking.init(robot, (State *)&stateIdle, (State *)&stateWalking, (State *)&stateCommanded, (State *)&stateWelcome);
	stateCommanded.init(robot, (State *)&stateIdle, (State *)&stateWalking, (State *)&stateCommanded, (State *)&stateWelcome);
	_command = command;
	stateCommanded.setCommand(command);
	setCurrentState((State *)&stateWelcome);
}

void StateMachine::setCurrentState(State *state) {
	_currentState = state;
}

void StateMachine::run() {
	if (_command->received()) {
		Serial.println("received");
		// start and stop are not used by stateCommanded
		//_currentState->stop();
		//setCurrentState(&stateCommanded);
	}
	State *newState = _currentState->run();
	setCurrentState(newState);
}
