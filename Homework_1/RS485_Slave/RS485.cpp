/* RS485 FUNCTIONS*/

#include "RS485.h"

// constructor
RS485_Slave::RS485_Slave() {

}

void RS485_Slave::init() {
  Serial.begin(9600);
}

// apply the received command
void RS485_Slave::apply_command(byte command) {
  if (command == 0x01) {
      digitalWrite(13, HIGH);
      delay(15);
      Serial.write(ACKNOWLEDGE);
    }
    else if(command == 0x00){
      digitalWrite(13, LOW);
      delay(15);
      Serial.write(ACKNOWLEDGE);
    }
}

// read data 
void RS485_Slave::read_data(byte *data, int length) {
  
  for(int index = 0; index < length; index++)
  {
    while (!Serial.available());
    
    data[index] = Serial.read();
    if (index == 1) {
      break;
    }
  }
}
