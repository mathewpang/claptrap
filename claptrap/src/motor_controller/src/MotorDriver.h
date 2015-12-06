#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include "Motor.h"
#include "geometry_msgs/Twist.h"
#include <ros/ros.h>

class MotorDriver {
    public:
        MotorDriver();
        void forward(int speed);
        void turn(int speed);
        void test();
        void stop();
        void callback(const geometry_msgs::Twist& msg);
    private:
        Motor* leftMotor;
        Motor* rightMotor;
};

#endif
