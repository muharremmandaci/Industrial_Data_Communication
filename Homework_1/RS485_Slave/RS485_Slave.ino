#include "RS485.h"

byte data[2];

RS485_Slave RS485;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {

  RS485.read_data(data, 2);

  if(data[ADDRESS] == MY_ADDRESS) {
    RS485.apply_command(data[COMMAND]);
  }
}
