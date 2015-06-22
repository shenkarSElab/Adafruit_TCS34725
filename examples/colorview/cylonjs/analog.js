// analog.js
// http://cylonjs.com/documentation/drivers/analog-sensor/

var Cylon = require('cylon');

Cylon.robot({
  connections: {
    arduino: { adaptor: 'firmata', port: 'COM15' }
  },

  devices: {
    sensor: { driver: 'analog-sensor', pin: 0, lowerLimit: 100, upperLimit: 900 }
  },

  work: function(my) {
    var analogValue = 0;

    every((1).second(), function() {
      analogValue = my.sensor.analogRead();
      console.log('Analog value => ', analogValue);
    });

    my.sensor.on('lowerLimit', function(val) {
      console.log("Lower limit reached!");
      console.log('Analog value => ', val);
    });

    my.sensor.on('upperLimit', function(val) {
      console.log("Upper limit reached!");
      console.log('Analog value => ', val);
    });
  }
}).start();