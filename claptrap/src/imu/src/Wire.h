#ifndef WIRE_H
#define WIRE_H


#include <iostream>
#include <stdint.h> //uint8_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <errno.h>

#include <ros/ros.h>

#define FILE_PATH "dev/i2c-2"

class Wire {
    public:
        void     helloWorld(); //Practice
        void     begin();
        int      requestFrom(int address, int quantity);
        void     beginTransmission(int address);
        int      endTransmission();
        int      write(uint8_t byte);
        int      available();
        uint8_t  read();
        void     onReceive(void(*handler) (int)); //Unused
        void     onRequest(void(*handler) (void)); //Unused

    private:
        int i2cFile;
};

#endif
