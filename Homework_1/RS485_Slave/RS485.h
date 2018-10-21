#ifndef RS485_h
#define RS485_h

#include <Arduino.h>

#define CMD_LED_ON  0x01
#define CMD_LED_OFF 0x00

#define ADDRESS 0
#define COMMAND 1

#define ACKNOWLEDGE 0x05

class RS485_Slave
{
  public:
    // RS485 function prototypes
    RS485_Slave();
    void init();
    void apply_command(byte command);
    void read_data(byte *data, int length);
};

#endif
