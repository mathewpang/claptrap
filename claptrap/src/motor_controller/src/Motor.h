#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <stdint.h> //uint8_t, int32_t
#include <pthread.h> // for sleep
#include <string>

#define SERIAL_ERROR -9999

class Motor {
    public:
        Motor(const char* device);
        int exitSafeStart();
        int getCurrentSpeed();
        int getTargetSpeed();
        int setSpeed(int speed);
        int getBrake();
        int setBrake(int brake);
        int getVariable(uint8_t variableId);

        const uint8_t MOTOR_SAFE_START = 0x83;
        const uint8_t MOTOR_FWD = 0x85;
        const uint8_t MOTOR_REV = 0x86;
        const uint8_t MOTOR_BRAKE = 0x92;
        const uint8_t MOTOR_GET_VAR = 0xA1;
        const uint8_t MOTOR_SET_LIMIT = 0xA2;
        const uint8_t MOTOR_STOP = 0xE0;
    private:
        int file;
};

#endif