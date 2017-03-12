#ifndef RemoteCommand_h
#define RemoteCommand_h

#include <Arduino.h>

#define COMMAND_SEPARATOR ':'
#define COMMAND_SERVO "SERVO"
#define COMMAND_ANGLE "ANGLE"

typedef struct {
	String cmd;
	String arg;
} ParsedCommand;

class RemoteCommand {
	public:
		void init();
		void readCommand();
		boolean received();
		boolean isStartCommand();
		boolean isStopCommand();
		void execute();
	private:
		// TODO dispatch in StateCommanded
		//void _dispatch(ParsedCommand data);
		ParsedCommand _parse();
		String _inputString;
		boolean _stringComplete;
		byte _selectedServo;
};

#endif
