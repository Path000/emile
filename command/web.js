var express = require('express');
var http = require('http');
var socketio = require('socket.io');
var EventEmitter = require('events').EventEmitter;
var util = require('util');

class WebServer extends EventEmitter {

  constructor(port) {
    var app = express();
    var server = http.Server(app);
    var sio = socketio(server);

    sio.on('connection', (socket) => {
      emit('ready', {});
      socket.on('command', (data) => {
        receive(data);
      });
    });

    app.use(express.static(__dirname + '/static'));

    server.listen(port);
  }

  receive(data) {
    emit(data.action, data.data);
  }

  send(action, data) {
    sio.sockets.emit(action, data);
  }
}


module.exports = WebServer;
