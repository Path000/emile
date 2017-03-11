#ifndef StateWelcome_h
#define StateWelcome_h

#include "State.h"

#define WELCOME_DELAY 1000

class StateWelcome : public State {
  public:
    State *run();
  private:
};


#endif