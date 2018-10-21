#include "RS485.h"

#define LED 13
#define SLAVE_ONE 0
#define SLAVE_TWO 1

byte data[2];

int response;

RS485_Master RS485;

void setup() {
  pinMode(LED, OUTPUT);
  RS485.init();
}

void loop() {
  // send a command to slave 1 for led on
  response = RS485.send_cmd(SLAVE_ONE, CMD_LED_ON);
  // do something according to communication success or failure
  foo(response);

  // send a command to slave 1 for led off
  response = RS485.send_cmd(SLAVE_ONE, CMD_LED_OFF);
  // do something according to communication success or failure
  foo(response);

  // send a command to slave 2 for led on
  response = RS485.send_cmd(SLAVE_TWO, CMD_LED_ON);
  // do something according to communication success or failure
  foo(response);

  // send a command to slave 2 for led off
  response = RS485.send_cmd(SLAVE_TWO, CMD_LED_OFF);
  // do something according to communication success or failure
  foo(response);
}


void foo(int response) {
  if (1 == response) {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
  }
}




