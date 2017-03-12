#include "RemoteCommand.h"

void RemoteCommand::init() {
	_selectedServo = 0;
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
		} else {
			_inputString += inChar;
		}
	}
}

boolean RemoteCommand::isStartCommand() {
	// TODO
	return false;
}

boolean RemoteCommand::isStopCommand() {
	// TODO
	return false;
}

// Called from loop()
boolean RemoteCommand::received() {
	return _stringComplete;
}

ParsedCommand RemoteCommand::_parse() {
	Serial.print("RawCmd:");
	Serial.println(_inputString);

	ParsedCommand data;
	data.cmd = "";
	data.arg = "";
	int dataLength = _inputString.length();
	int sepPos = _inputString.indexOf(COMMAND_SEPARATOR);
	if (sepPos == -1) return data;
	if (sepPos + 1 >= dataLength) return data;

	data.cmd = _inputString.substring(0, sepPos);
	data.arg = _inputString.substring(sepPos, dataLength - 1);
	return data;
}

// TODO dispatch in StateCommanded or in robot
/*
void RemoteCommand::_dispatch(ParsedCommand data) {
  if(data.cmd == COMMAND_ANGLE) {
    _robot->directMove(_selectedServo, data.arg.toInt());
  }
  if(data.cmd == COMMAND_SERVO) {
    _selectedServo = data.arg.toInt();
  }
}
*/

// Called from loop()
// free flag _stringComplete
void RemoteCommand::execute() {

	if (!_stringComplete) {
		return;
	}

	ParsedCommand data = _parse();
	//_dispatch(data);

	_inputString = "";
	_stringComplete = false;

	Serial.print("Cmd:");
	Serial.println(data.cmd);
	Serial.print("Arg:");
	Serial.println(data.arg);
}
