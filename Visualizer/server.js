var express = require('express');
var app = express();
app.use(express.static('public'));

var http = require('http').Server(app);
var io = require('socket.io')(http);

var serialport = require("serialport");
var SerialPort = serialport.SerialPort;


serialPort = new SerialPort("/dev/ttyUSB0", 
	{
		baudrate: 115200,
		parser: serialport.parsers.readline("\n")
	}
);


serialPort.on("open", function () {
  console.log('open');
  serialPort.on('data', function(data) {
    console.log('data received: ' + data);
    io.emit('serialData',data);

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
