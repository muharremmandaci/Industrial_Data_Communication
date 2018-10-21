#include "RS485.h"

#define MY_ADDRESS  0x02
#define LED 13

byte data[2];

RS485_Slave RS485;

void setup() {
  pinMode(LED, OUTPUT);
  RS485.init();
}

void loop() {

  // read data from master
  RS485.read_data(data, 2);

  // check slave address of the command
  if(data[ADDRESS] == MY_ADDRESS) {
    // apply the master's command
    RS485.apply_command(data[COMMAND]);
  }
}
