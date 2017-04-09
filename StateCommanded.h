#ifndef StateCommanded_h
#define StateCommanded_h

#include "State.h"
#include "RemoteCommand.h"

#define COMMAND_SERVO "SERVO"
#define COMMAND_START "START"
#define COMMAND_STOP "STOP"
#define COMMAND_REST "REST"

class StateCommanded : public State {
	public:
		State *run();
		void setCommand(RemoteCommand *command);
	private:
		RemoteCommand *_command;
};

#endif