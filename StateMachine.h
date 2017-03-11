#ifndef StateMachine_h
#define StateMachine_h

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
		void interrupt();
	private:
		State *_currentState;
		StateWelcome stateWelcome;
		StateIdle stateIdle;
		StateWalking stateWalking;
		StateCommanded stateCommanded;
};

#endif
