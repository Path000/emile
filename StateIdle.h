#ifndef StateIdle_h
#define StateIdle_h

#define IDLE_DELAY 1000

#include "State.h"

class StateIdle : public State {
	public:
		State *run();
	private:
};

#endif