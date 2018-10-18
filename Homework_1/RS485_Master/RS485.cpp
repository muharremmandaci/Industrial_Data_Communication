/* RS485 FUNCTIONS*/

#include "RS485.h"

RS485_Master::RS485_Master() {
  Serial.begin(9600);

  pinMode(MASTER_DIR, OUTPUT);
  pinMode(slave_one[DIR_PIN],  OUTPUT);
  pinMode(slave_two[DIR_PIN], OUTPUT);

  digitalWrite(MASTER_DIR, HIGH);
  digitalWrite(slave_one[DIR_PIN],  LOW);
  digitalWrite(slave_two[DIR_PIN], LOW);
}

void RS485_Master::init() {
  Serial.begin(9600);

  pinMode(MASTER_DIR, OUTPUT);
  pinMode(slaves[0][DIR_PIN],  OUTPUT);
  pinMode(slaves[1][DIR_PIN], OUTPUT);

  digitalWrite(MASTER_DIR, HIGH);
  digitalWrite(slaves[0][DIR_PIN],  LOW);
  digitalWrite(slaves[1][DIR_PIN], LOW);
}

int RS485_Master::send_cmd(int slave, byte command) {
  Serial.write(slaves[slave][ADDRESS]);
  Serial.write(command);

  digitalWrite(MASTER_DIR, LOW);
  digitalWrite(slaves[slave][DIR_PIN],  HIGH);

  int response = wait_response();

  digitalWrite(MASTER_DIR, HIGH);
  digitalWrite(slaves[slave][DIR_PIN],  LOW);

  return response;
}

int RS485_Master::wait_response() {
  while (!Serial.available());

  if (0x05 == Serial.read()) {
    return 1;
  }
  return -1;
}
