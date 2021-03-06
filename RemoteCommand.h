#ifndef RemoteCommand_h
#define RemoteCommand_h

#include <Arduino.h>

#define COMMAND_SEPARATOR ':'
#define MAX_ARGS 4

typedef struct {
	String cmd;
	String arrayArgs[MAX_ARGS];
} ParsedCommand;

class RemoteCommand {
	public:
		void init();
		void readCommand();
		boolean received();
		ParsedCommand get();
	private:
		ParsedCommand _parse();
		String _inputString;
		boolean _stringComplete;
};

#endif
