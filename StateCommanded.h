#ifndef StateCommanded_h
#define StateCommanded_h

#include "State.h"
#include "RemoteCommand.h"

#define COMMAND_DELAY 3000

class StateCommanded : public State {
	public:
		State *run();
		void setCommand(ParsedCommand *command);
	private:
		RemoteCommand *_command;
};

#endif