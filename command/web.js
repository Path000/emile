"use strict";
var express = require('express');
var http = require('http');
var socketio = require('socket.io');
var EventEmitter = require('events').EventEmitter;
var util = require('util');

var WebServer = function(port) {
	EventEmitter.call(this);
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
util.inherits(WebServer, EventEmitter);

WebServer.prototype.receive = function (data) {
	this.emit(data.action, data.data);
}

WebServer.prototype.send = function (action, data) {
	this.sio.sockets.emit(action, data);
}

module.exports = WebServer;
