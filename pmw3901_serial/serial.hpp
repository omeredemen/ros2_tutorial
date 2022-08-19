#include <stdio.h>
#include <string.h>
#include <iostream>
// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()


class Serial
{

private:
    void disconnectSerialPort();
    bool configureSerialPort();

    int serial_port_;
    char read_buff_[6];
    char* dev = "/dev/ttyUSB0";

public:
    bool connectSerialPort();
    void readSensorData(uint8_t* x, uint16_t* deltaX, uint8_t* y, uint16_t* deltaY);
};




