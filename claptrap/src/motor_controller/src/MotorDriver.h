#ifndef DRIVER_H
#define DRIVER_H

#include "Motor.h"

class MotorDriver {
    public:
        MotorDriver();
        void forward(int speed);
        void turn(int speed);
        void test();
        void stop();
    private:
        Motor* leftMotor;
        Motor* rightMotor;
};

#endif