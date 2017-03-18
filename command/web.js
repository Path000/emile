var express = require('express');
var http = require('http');
var socketio = require('socket.io');
var EventEmitter = require('events').EventEmitter;
var util = require('util');

class WebServer extends EventEmitter {

  constructor(port) {
    this.app = express();
    this.server = http.Server(app);
    this.sio = socketio(server);

    this.sio.on('connection', (socket) => {
      emit('ready', {});
      socket.on('command', (data) => {
        receive(data);
      });
    });

    app.use(express.static(__dirname + '/static'));

    server.listen(port);
  }

  receive(data) {
    this.emit(data.action, data.data);
  }

  send(action, data) {
    this.sio.sockets.emit(action, data);
  }
}


module.exports = WebServer;
