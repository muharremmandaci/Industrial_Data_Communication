#include "RS485.h"
#define MY_ADDRESS  0x02
byte data[2];

RS485_Slave RS485;

void setup() {
  pinMode(13, OUTPUT);
  RS485.init();
}

void loop() {

  RS485.read_data(data, 2);

  if(data[ADDRESS] == MY_ADDRESS) {
    RS485.apply_command(data[COMMAND]);
  }
}
