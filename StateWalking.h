#ifndef StateWalking_h
#define StateWalking_h

#include "State.h"
#define WALKING_DELAY 5000

class StateWalking : public State {
	public:
		State *run();
};

#endif