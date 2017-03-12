#ifndef RemoteCommand_h
#define RemoteCommand_h

#include <Arduino.h>

#define COMMAND_SEPARATOR ':'

typedef struct {
	String cmd;
	String arg;
} ParsedCommand;

class RemoteCommand {
	public:
		void init();
		void readCommand();
		boolean received();
		ParsedCommand get();
	private:
		// TODO dispatch in StateCommanded
		//void _dispatch(ParsedCommand data);
		ParsedCommand _parse();
		String _inputString;
		boolean _stringComplete;
};

#endif
