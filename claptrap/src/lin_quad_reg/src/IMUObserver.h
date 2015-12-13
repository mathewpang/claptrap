#ifndef IMU_OBS_H
#define IMU_OBS_H

#include <ros/ros.h>
#include "imu/AccelGyro.h"
#include "motor_controller/WheelState.h"

#define PI 3.14159265F

struct orientation{
  float roll;
  float roll_d;
};

struct accel{
    float accel_x;
    float accel_y;
    float accel_z;
};

struct wheel{
    float angle;
    float speed;
};

struct state{
    float phi;
    float phi_d;
    float theta;
    float theta_d;
};

class IMUObserver{

    public:
        IMUObserver();
        void imuCallback(const imu::AccelGyro& msg);
        void wheelCallback(const motor_controller::WheelState& msg);
        void computeOrientation (struct accel* msg);
        struct orientation* getOrientation();
        struct state* getStates();
        struct wheel* wheel_state;
        struct state* system_state;
    private:
        struct orientation* curr_orientation;
        struct orientation* prev_orientation;
        struct orientation* tmp;
        ros::Time last_read;
};


#endif
