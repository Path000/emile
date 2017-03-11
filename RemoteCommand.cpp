#include "RemoteCommand.h"

void RemoteCommand::init() {
  _selectedServo = 0;
  _inputString = "";
  _stringComplete = false;
  Serial1.begin(9600);
}


// Called from serialEvent1()
void RemoteCommand::readCommand() {
  if(Serial1.available() && !_stringComplete) {
    delay(100);
  }
  while (Serial1.available() && !_stringComplete) {
    char inChar = (char)Serial1.read();
    if (inChar == '\n') {
      _stringComplete = true;
    }
    else {
      _inputString += inChar;
    }
  }
}

// Called from loop()
boolean RemoteCommand::received() {
  return _stringComplete;
}

ParsedData RemoteCommand::_parse() {
  Serial.print("RawCmd:");
  Serial.println(_inputString);

  ParsedData data;
  data.cmd = "";
  data.arg = "";
  int dataLength = _inputString.length();
  int sepPos = _inputString.indexOf(COMMAND_SEPARATOR);
  if(sepPos == -1) return data;
  if(sepPos + 1 >= dataLength) return data;

  data.cmd = _inputString.substring(0, sepPos);
  data.arg = _inputString.substring(sepPos, dataLength-1);
  return data;
}

// TODO dispatch in StateCommanded
/*
void RemoteCommand::_dispatch(ParsedData data) {
  if(data.cmd == COMMAND_ANGLE) {
    _robot->directMove(_selectedServo, data.arg.toInt());
  }
  if(data.cmd == COMMAND_SERVO) {
    _selectedServo = data.arg.toInt();
  }
}
*/

// Called from loop()
void RemoteCommand::execute() {

  if(!_stringComplete) {
    return;
  }

  ParsedData data = _parse();
  //_dispatch(data);

  _inputString = "";
  _stringComplete = false;

  Serial.print("Cmd:");
  Serial.println(data.cmd);
  Serial.print("Arg:");
  Serial.println(data.arg);
}

String RemoteCommand::getAsString() {
  return _inputString;
}
