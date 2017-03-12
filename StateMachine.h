#ifndef StateMachine_h
#define StateMachine_h

#include <Arduino.h>
#include "State.h"
#include "StateIdle.h"
#include "StateWalking.h"
#include "StateCommanded.h"
#include "StateWelcome.h"
#include "Robot.h"
#include "RemoteCommand.h"

class StateMachine {
	public:
		void init(Robot *robot, RemoteCommand *command);
		void setCurrentState(State *state);
		void run();
	private:
		State *_currentState;
		RemoteCommand *_command;
		StateWelcome stateWelcome;
		StateIdle stateIdle;
		StateWalking stateWalking;
		StateCommanded stateCommanded;
};

#endif
