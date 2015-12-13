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

#define FILE_PATH "/dev/i2c-1"

class Wire{
    public:
        Wire();
        void close(); //Closing the file will render all future calls to read and write useless.
        uint8_t read(uint8_t addr, uint8_t reg);//Read the value for device addr, and regisster.
        int write(uint8_t addr, uint8_t reg, uint8_t value); //Write the value to device addr, register.
    private:  
    	int filei2c;
    	uint8_t address;
};


#endif