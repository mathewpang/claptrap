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
#include <math.h>

#include <ros/ros.h>

#define SERIAL_ERROR -9999
#define DEGREE_FULL_ROTATION 360
#define RADIAN_FULL_ROTATION 6.283
#define DEGREE_MOTOR_SPEED_CONVERSION 0.375
#define RADIAN_MOTOR_SPEED_CONVERSION 0.006544

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
        float wheelAngle;
        float wheelSpeed;

        const uint8_t MOTOR_SAFE_START = 0x83;
        const uint8_t MOTOR_FWD = 0x85;
        const uint8_t MOTOR_REV = 0x86;
        const uint8_t MOTOR_BRAKE = 0x92;
        const uint8_t MOTOR_GET_VAR = 0xA1;
        const uint8_t MOTOR_SET_LIMIT = 0xA2;
        const uint8_t MOTOR_STOP = 0xE0;
    private:
        int file;
        ros::Time lastSpeedChange;
};

#endif
