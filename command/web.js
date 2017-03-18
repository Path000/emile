let express = require('express');
let http = require('http');
let socketio = require('socket.io');
let EventEmitter = require('events').EventEmitter;
let util = require('util');

class WebServer extends EventEmitter {
  constructor(port) {
    super();
    this.app = express();
    this.server = http.Server(this.app);
    this.sio = socketio(this.server);
    this.sio.on('connection', (socket) => {
      this.emit('ready', {});
      socket.on('command', (data) => {
        this.receive(data);
      });
    });

    this.app.use(express.static(__dirname + '/static'));

    this.server.listen(port, ()=>{
      console.log(`Listening ${port}`);
    });
  }

  receive(data) {
    this.emit(data.action, data.data);
  }

  send(action, data) {
    this.sio.sockets.emit(action, data);
  }
}


module.exports = WebServer;
