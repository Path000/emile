#ifndef StateWalking_h
#define StateWalking_h

#include "State.h"

class StateWalking : public State {
  public:
    State *run();
};

#endif