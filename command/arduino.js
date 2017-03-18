let serialPortModule = require("serialport");
let EventEmitter = require('events').EventEmitter;

/*
serialPortModule.list(function (err, ports) {
  ports.forEach(function(port) {
    var serialItem = "comName:"+port.comName;
    serialItem += " pnpId:"+port.pnpId
    serialItem += " manufacturer:"+port.manufacturer
    console.log(serialItem);
  });
});
*/

class Arduino extends EventEmitter {

  constructor() {
    super();
    this.serialIsOpened = false;

    this.serialPort = new serialPortModule.SerialPort("/dev/ttyACM0", {
      baudrate: 115200,
      parser: serialPortModule.parsers.readline('\n')
    });

    this.serialPort.on("open", () => {
      this.serialIsOpened = true;
      this.emit('ready', {});

      this.serialPort.on('data', (data) => {
        this.deserializeWhatDuinoSays(data);
      });
    });
  }

  deserializeWhatDuinoSays(data) {
    //console.log('[Arduino says]'+data);
    var splitedData = data.split(':');
    var command = splitedData.shift();
    this.emit(command, {args: splitedData});
  }

  writeSerial(message, next) {
    if(this.serialIsOpened) {
      //console.log(message);
      this.serialPort.write(message+"\n", function(err, results) {
        //console.log('err ' + err);
        //console.log('results ' + results);
        if(next)next();
      });
    }
  }
}


module.exports = Arduino;
