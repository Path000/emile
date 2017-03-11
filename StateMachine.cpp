#include "StateMachine.h"


void StateMachine::init(Robot *robot, RemoteCommand *command) {
	stateIdle.init(robot, (State *)&stateIdle, (State *)&stateWalking, (State *)&stateCommanded, (State *)&stateWelcome);
	stateWalking.init(robot, (State *)&stateIdle, (State *)&stateWalking, (State *)&stateCommanded, (State *)&stateWelcome);
	stateCommanded.init(robot, (State *)&stateIdle, (State *)&stateWalking, (State *)&stateCommanded, (State *)&stateWelcome);
	stateWelcome.init(robot, (State *)&stateIdle, (State *)&stateWalking, (State *)&stateCommanded, (State *)&stateWelcome);

	setCurrentState((State *)&stateWelcome);
}

void StateMachine::setCurrentState(State *state) {
  _currentState = state;
}

void StateMachine::interrupt() {
	_currentState->stop();
	setCurrentState(&stateCommanded);
}

void StateMachine::run() {

	// TODO
/*
	if(command.received()) {
		interrupt();
		stateCommanded.setCommand(command.getAsString());
		command.execute();
	}
*/
	State *newState = _currentState->run();
	setCurrentState(newState);
}
