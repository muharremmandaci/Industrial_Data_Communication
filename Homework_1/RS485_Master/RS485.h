#ifndef RS485_h
#define RS485_h

#include <Arduino.h>

#define MASTER_DIR 2

#define DIR_PIN 1
#define ADDRESS 0

#define CMD_LED_ON  0x01
#define CMD_LED_OFF 0x00

#define ACKNOWLEDGE 0x05

class RS485_Master
{
  private:
    byte slave_one[2] = {0x01, 0x03};
    byte slave_two[2] = {0x02, 0x04};

  public:
    byte* slaves[2] = {slave_one, slave_two};
    RS485_Master();
    void init();
    int send_cmd(int slave, byte command);
    int wait_response();
};

#endif
