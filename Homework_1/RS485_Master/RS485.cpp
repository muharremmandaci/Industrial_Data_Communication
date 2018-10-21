/* RS485 FUNCTIONS*/

#include "RS485.h"

// constructor
RS485_Master::RS485_Master() {

}

//initialize communication pin configs
void RS485_Master::init() {
  Serial.begin(9600);

  // config pin directions
  pinMode(MASTER_DIR, OUTPUT);
  pinMode(slaves[0][DIR_PIN],  OUTPUT);
  pinMode(slaves[1][DIR_PIN], OUTPUT);

  // Master Tx, Slaves Rx
  digitalWrite(MASTER_DIR, HIGH);
  digitalWrite(slaves[0][DIR_PIN],  LOW);
  digitalWrite(slaves[1][DIR_PIN], LOW);
}

// send a command to the slave and return communication success
int RS485_Master::send_cmd(int slave, byte command) {
  /* send command to the slave */

  // send slave address
  Serial.write(slaves[slave][ADDRESS]);
  // send command
  Serial.write(command);
  
  /****************************/

  // delay to finish transmit
  delay(10);

  // change communication direction (Master Rx, Slave Tx)
  digitalWrite(MASTER_DIR, LOW);
  digitalWrite(slaves[slave][DIR_PIN],  HIGH);

  // wait for acknowledge
  int response = wait_response();

  // change communication direction (Master Tx, Slave Rx)
  digitalWrite(MASTER_DIR, HIGH);
  digitalWrite(slaves[slave][DIR_PIN],  LOW);

  return response;
}

// wait for acknowledge and return 1(success) or -1(failure)
int RS485_Master::wait_response() {
  while (!Serial.available());

  // check communication success
  if (ACKNOWLEDGE == Serial.read()) {
    // Success
    return 1;
  }
  // Failure
  return -1;
}
