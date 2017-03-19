#include "RemoteCommand.h"

void RemoteCommand::init() {
	_inputString = "";
	_stringComplete = false;
}


// Called from serialEvent()
void RemoteCommand::readCommand() {

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
	if (!_stringComplete) {
		return data;
	}

	int dataLength = _inputString.length();
	int firstSep = _inputString.indexOf(COMMAND_SEPARATOR);
	if(firstSep == -1) {
		data.cmd = _inputString;
		return data;
	}
	if(firstSep + 1 >= dataLength) return data;
	data.cmd = _inputString.substring(0,firstSep);
	// get args
	unsigned int index = 0;
	while(firstSep + 1 < dataLength && index < MAX_ARGS) {
		int secondSep = _inputString.indexOf(COMMAND_SEPARATOR, firstSep+1);
		// pour le dernier argument
		if(secondSep == -1) {
		  secondSep = dataLength;
		}
		String arg = _inputString.substring(firstSep+1, secondSep);
		firstSep = secondSep;
		data.arrayArgs[index] = arg;
		index++;
	}
/*
	ParsedCommand data;
	data.cmd = "";
	data.arg = "";
	if (!_stringComplete) {
		return data;
	}
	int dataLength = _inputString.length();
	int sepPos = _inputString.indexOf(COMMAND_SEPARATOR);
	if (sepPos == -1) {
		data.cmd = _inputString;
		return data;
	}
	if (sepPos + 1 >= dataLength) return data;

	data.cmd = _inputString.substring(0, sepPos);
	data.arg = _inputString.substring(sepPos, dataLength - 1);
	return data;
	*/
}

// Called from loop()
ParsedCommand RemoteCommand::get() {

	ParsedCommand data = _parse();

	_inputString = "";
	_stringComplete = false;

	return data;
}
