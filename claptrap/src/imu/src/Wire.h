#ifndef WIRE_H
#define WIRE_H


#include <iostream>
#include <stdint.h> //uint8_t, int32_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <errno.h>
#include <ctime>

#include <ros/ros.h>

#define FILE_PATH "/dev/i2c-2"
typedef unsigned char byte;

unsigned long millis();

class TwoWire {
    public:
        TwoWire();
        
        void     helloWorld(); //Practice
        void     begin();
        int      requestFrom(int address, int quantity);
        void     beginTransmission(int address);
        int      endTransmission();
        int      send(uint8_t byte);
        int      write(uint8_t byte);
        int      available();
        uint8_t  receive();
        void     onReceive(void(*handler) (int)); //Unused
        void     onRequest(void(*handler) (void)); //Unused

    private:
        int i2cFile;
        uint8_t* read_buffer;
        int read_pointer;
        int read_max;

};

extern TwoWire Wire;


#endif
