#ifndef StateCommanded_h
#define StateCommanded_h

#include "State.h"

#define COMMAND_DELAY 3000

class StateCommanded : public State {
	public:
		State *run();
		void setCommand(String cmd);
		void endCommand();
	private:
		String _command;
		boolean _ended;
};

#endif