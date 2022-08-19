#include "serial.hpp"


bool Serial::connectSerialPort(){
    serial_port_ = open(dev, O_RDWR);

    if(serial_port_<0){
        printf("Serial port %s couldn't opened\n", dev);
        return false;
    }

    if (!configureSerialPort()) {
        disconnectSerialPort();
        printf("Serial Port Couldn't Configure\n");
        return false;
    } 

    return true;

}

void Serial::disconnectSerialPort(){
    close(serial_port_);
}

bool Serial::configureSerialPort(){
    // Create new termios struct, we call it 'uart_config_' for convention
    struct termios uart_config_;

    // Read in existing settings, and handle any error
    if(tcgetattr(serial_port_, &uart_config_) != 0) {
        printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
        return false;
    }

    uart_config_.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
    uart_config_.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
    uart_config_.c_cflag &= ~CSIZE; // Clear all bits that set the data size 
    uart_config_.c_cflag |= CS8; // 8 bits per byte (most common)
    uart_config_.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
    uart_config_.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

    uart_config_.c_lflag &= ~ICANON;
    uart_config_.c_lflag &= ~ECHO; // Disable echo
    uart_config_.c_lflag &= ~ECHOE; // Disable erasure
    uart_config_.c_lflag &= ~ECHONL; // Disable new-line echo
    uart_config_.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
    uart_config_.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
    uart_config_.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

    uart_config_.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
    uart_config_.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed

    uart_config_.c_cc[VTIME] = 10;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
    uart_config_.c_cc[VMIN] = 0;

    // Set in/out baud rate to be 9600
    cfsetispeed(&uart_config_, B9600);
    cfsetospeed(&uart_config_, B9600);

    // Save uart_config_ settings, also checking for error
    if (tcsetattr(serial_port_, TCSANOW, &uart_config_) != 0) {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
        return false;
    }
    return true;
}

void Serial::readSensorData(uint8_t* x, uint16_t* deltaX, uint8_t* y, uint16_t* deltaY){

    int num_bytes = read(serial_port_, read_buff_, sizeof(read_buff_));

    if (num_bytes < 0) {
      printf("Error reading: %s\n", strerror(errno));
    }

    printf("\nRead %i bytes. Received message: %s\n", num_bytes, read_buff_);
    
    *x = read_buff_[0];
    *y = read_buff_[3];

    *deltaX = ((int16_t)read_buff_[1] << 8) | read_buff_[2];
    *deltaY = ((int16_t)read_buff_[4] << 8) | read_buff_[5];  
}

