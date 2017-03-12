#include "RemoteCommand.h"

void RemoteCommand::init() {
	_inputString = "";
	_stringComplete = false;
}


// Called from serialEvent()
void RemoteCommand::readCommand() {
	if (Serial.available() && !_stringComplete) {
		delay(100);
	}
	while (Serial.available() && !_stringComplete) {
		char inChar = (char)Serial.read();
		if (inChar == '\n') {
			_stringComplete = true;
			Serial.print("RawCmd:");
			Serial.println(_inputString);
		} else {
			_inputString += inChar;
		}
	}
}

// Called from loop()
boolean RemoteCommand::received() {
	return _stringComplete;
}

ParsedCommand RemoteCommand::_parse() {

	ParsedCommand data;
	data.cmd = "";
	data.arg = "";
	if (!_stringComplete) {
		return data;
	}
	int dataLength = _inputString.length();
	int sepPos = _inputString.indexOf(COMMAND_SEPARATOR);
	if (sepPos == -1) return data;
	if (sepPos + 1 >= dataLength) return data;

	data.cmd = _inputString.substring(0, sepPos);
	data.arg = _inputString.substring(sepPos, dataLength - 1);
	return data;
}

// Called from loop()
ParsedCommand RemoteCommand::get() {

	ParsedCommand data = _parse();

	_inputString = "";
	_stringComplete = false;

	return data;
}
