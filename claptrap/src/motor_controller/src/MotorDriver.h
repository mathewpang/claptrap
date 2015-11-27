#ifndef DRIVER_H
#define DRIVER_H

#include "Motor.h"

class MotorDriver {
    public:
        MotorDriver();
        Motor* leftMotor;
        Motor* rightMotor;
    private:
};

#endif