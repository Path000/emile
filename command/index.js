"use strict";

//var Arduino = require('./modules/arduino.js');
let WebServer = require('./modules/web.js');

exitHandler(options, err) => {
  //clean all
  if (options.cleanup) console.log('clean');
  if (err) console.log(err.stack);
  if (options.exit) process.exit();
}

//do something when app is closing
process.on('exit', exitHandler.bind(null,{cleanup:true}));
//catches ctrl+c event
process.on('SIGINT', exitHandler.bind(null, {exit:true}));
//catches uncaught exceptions
process.on('uncaughtException', exitHandler.bind(null, {exit:true}));


/*

var arduino = new Arduino();

arduino.on('ready', function() {
  console.log('Arduino ready');
});

arduino.on('COUNT', function(data) {
  console.log('Arduino COUNT left: '+data.args[0])
  console.log('Arduino COUNT right: '+data.args[1])
  speedHelper.setCoderCount(data.args[0], data.args[1]);
  var speedCurrentTicksPerMSec = speedHelper.getSpeedCurrentTicksPerMSec();
  inclinaisonSetpoint = pidSpeed2SetpointAngle.getPID(speedSetpointTicksPerMSec, speedCurrentTicksPerMSec);
})

arduino.on('CONSOLE', function(data) {
  console.log('[ARDUINO CONSOLE]'+data.args);
});

*/



var webServer = new WebServer(8080);

webServer.on('changePID', function(data) {
  if(data.kp) pidSpeed2SetpointAngle.setKP(data.kp);
  if(data.ki) pidSpeed2SetpointAngle.setKI(data.ki);
  if(data.kd) pidSpeed2SetpointAngle.setKD(data.kd);
});

webServer.on('stopMotors', function(data) {
  stopMotors();
});
webServer.on('startMotors', function(data) {
  doDriveMotors = true;
});

webServer.on('forward', function(data) {
  speedSetpointTicksPerMSec = DEFAULT_SPEED;
});
webServer.on('backward', function(data) {
  speedSetpointTicksPerMSec = DEFAULT_SPEED * -1;
});
webServer.on('left', function(data) {
  // TODO
});
webServer.on('right', function(data) {
  // TODO
});
webServer.on('stop', function(data) {
  speedSetpointTicksPerMSec = 0;
});
webServer.on('ready', function() {
  console.log('WEB ready');
  var data = {};
  data.kp = pidSpeed2SetpointAngle.getKP();
  data.ki = pidSpeed2SetpointAngle.getKI();
  data.kd = pidSpeed2SetpointAngle.getKD();

  webServer.send('reset', data);
});
