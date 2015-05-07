var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);

// List serial ports
var serialPort = require("serialport");
serialPort.list(function (err, ports) {
  ports.forEach(function(port) {
    console.log(port.comName);
    console.log(port.pnpId);
    console.log(port.manufacturer);
  });
});

app.get('/', function(req, res){
  res.sendFile(__dirname + '/index.html');
});

io.on('connection', function(socket){
  console.log('a user connected');

  // Send Welcome
  io.emit('WelcomeMessage','Welcome to "ME" server');

  socket.on('WelcomeMessage', function(msg){
    console.log('Client said:' + msg);
  });

  socket.on('disconnect', function(){
    console.log('user disconnected');
  });
});

http.listen(3000, function(){
  console.log('listening on *:3000');
});
