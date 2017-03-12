#ifndef State_h
#define State_h

#include <Arduino.h>
#include "Robot.h"

class State {
	public:
		void init(Robot *robot, State *stateIdle, State *stateWalking, State *stateCommanded, State *stateWelcome);
		virtual State *run();
		void start();
		void stop();
		unsigned long duration();
		boolean isFirstLoop();
	protected:
		Robot *_robot;
    State *_stateWelcome;
		State *_stateIdle;
		State *_stateWalking;
		State *_stateCommanded;
	private:
		unsigned long _startedAt;
};

#endif
