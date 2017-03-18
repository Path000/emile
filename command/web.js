"use strict";
var express = require('express');
var http = require('http');
var socketio = require('socket.io');
var EventEmitter = require('events').EventEmitter;
var util = require('util');

class WebServer extends EventEmitter {

  constructor(port) {
    var app = express();
    var server = http.Server(app);
    this.sio = socketio(server);

    var self = this;
    this.sio.on('connection', function (socket) {
      self.emit('ready', {});
      socket.on('command', function(data) {
        self.receive(data);
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
