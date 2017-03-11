#ifndef RemoteCommand_h
#define RemoteCommand_h

#include <Arduino.h>

#define COMMAND_SEPARATOR ':'
#define COMMAND_SERVO "SERVO"
#define COMMAND_ANGLE "ANGLE"

typedef struct {
  String cmd;
  String arg;
} ParsedData;

class RemoteCommand {
  public:
    void init();
    void readCommand();
    boolean received();
    void execute();
    String getAsString();
  private:
    // TODO dispatch in StateCommanded
    //void _dispatch(ParsedData data);
    ParsedData _parse();
    String _inputString;
    boolean _stringComplete;
    byte _selectedServo;
};

#endif
