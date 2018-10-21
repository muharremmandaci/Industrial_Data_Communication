#include "RS485.h"

#define LED 13

byte data[2];
int response;

RS485_Master RS485;

void setup() {
  pinMode(LED, OUTPUT);
  RS485.init();
}

void loop() {
  response = RS485.send_cmd(0, CMD_LED_ON);
  foo(response);

  response = RS485.send_cmd(0, CMD_LED_OFF);
  foo(response);


  response = RS485.send_cmd(1, CMD_LED_ON);
  foo(response);

  response = RS485.send_cmd(1, CMD_LED_OFF);
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




