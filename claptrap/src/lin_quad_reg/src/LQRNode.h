#ifndef LQR_NODE_H
#define LQR_NODE_H

#include <ros/ros.h>
#include "imu/AccelGyro.h"
#include "geometry_msgs/Twist.h"
#include "motor_controller/WheelState.h"
#include "IMUObserver.h"
#include <stdlib.h>
#include <string>

class LQRNode{

    public:
        LQRNode(IMUObserver* observer, ros::Publisher* pub);
        void computeLQR(double reference, double K1, double K2, double K3, double K4, double scale);
    private:
        IMUObserver* observer;
        ros::Publisher* pub;

};


#endif
