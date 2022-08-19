#include <iostream>
#include <stdio.h>
#include "serial.hpp"

Serial serial;
uint16_t deltaX, deltaY;
uint8_t x ,y;


int main(int argc, char * argv[])
{    
    if(!serial.connectSerialPort()) return -1;

    int i = 0;
    while (1)
    {
        serial.readSensorData(&x, &deltaX, &y, &deltaY);
        if (x == 1)
        {
            printf("x = %d\n", x);
            printf("deltaX = %d\n", deltaX);
        }
        
        if (y == 2)
        {
            printf("y = %d\n", y);
            printf("deltaY = %d\n", deltaY);
        }
        usleep(500000);
    }
    return 0;
}
