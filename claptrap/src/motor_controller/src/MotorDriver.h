#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include "Motor.h"
#include "geometry_msgs/Twist.h"
#include "motor_controller/WheelState.h"
#include <ros/ros.h>
#include <signal.h>

struct wheel_state{
  float wheelAngle;
  float wheelSpeed;
};

class MotorDriver {
    public:
        static MotorDriver* Instance();
        void forward(int speed);
        void turn(int speed);
        void test();
        void stop();
        void callback(const geometry_msgs::Twist& msg);
        void publishWheelState(ros::Publisher* pub);
        void motorSIGINTHandler(int sig);
    private:
        static MotorDriver* m_Instance;
        MotorDriver();
        Motor* rightMotor;
        void updateWheelState();
        struct wheel_state* curr_wheel_state;
};

#endif
