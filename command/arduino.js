"use strict";

var serialPortModule = require("serialport");
var EventEmitter = require('events').EventEmitter;
var util = require('util');

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

function Arduino() {
  EventEmitter.call(this);

  this.serialIsOpened = false;
  var self = this;

  this.serialPort = new serialPortModule.SerialPort("/dev/ttyACM0", {
    baudrate: 115200,
  	parser: serialPortModule.parsers.readline('\n')
  });

  this.serialPort.on("open", function () {
  	self.serialIsOpened = true;
    self.emit('ready', {});

    self.serialPort.on('data', function(data) {
      self.deserializeWhatDuinoSays(data);
    });
  });
}
util.inherits(Arduino, EventEmitter);

Arduino.prototype.deserializeWhatDuinoSays = function(data) {
  //console.log('[Arduino says]'+data);
  var splitedData = data.split(':');
  var command = splitedData.shift();
  this.emit(command, {args: splitedData});
}

Arduino.prototype.writeSerial = function(message, next) {
  if(this.serialIsOpened) {
    //console.log(message);
    this.serialPort.write(message+"\n", function(err, results) {
      //console.log('err ' + err);
      //console.log('results ' + results);
      if(next)next();
    });
  }
}

module.exports = Arduino;
