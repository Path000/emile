let Arduino = require('./arduino.js');
let WebServer = require('./web.js');

const exitHandler = (options, err) => {
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




const arduino = new Arduino();

arduino.on('ready', function() {
  console.log('Arduino ready');
});

arduino.on('CONSOLE', function(data) {
  console.log('[ARDUINO CONSOLE]'+data.args);
});





var webServer = new WebServer(8080);

webServer.on('ready', function() {
  console.log('WEB ready');
  webServer.send('ready', {});
});

webServer.on('slider', function(data) {
  console.log(`motor:${data.motor} - value:${data.value}`);
  arduino.writeSerial(`SERVO:${data.motor}`);
  arduino.writeSerial(`ANGLE:${data.value}`);
});

webServer.on('start', function(data) {
  console.log(`start`);
  arduino.writeSerial(`START`);
});

webServer.on('stop', function(data) {
  console.log(`stop`);
  arduino.writeSerial(`STOP`);
});
