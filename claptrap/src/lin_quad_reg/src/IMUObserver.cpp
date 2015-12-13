#include "IMUObserver.h"

IMUObserver::IMUObserver(){
    curr_orientation = (struct orientation*) malloc(sizeof(struct orientation));
    prev_orientation = (struct orientation*) malloc(sizeof(struct orientation));
    wheel_state = (struct wheel*) malloc(sizeof(struct wheel));
    system_state = (struct state*) malloc(sizeof(struct state));
    tmp = (struct orientation*) malloc(sizeof(struct orientation));

    prev_orientation->roll = 0;
    prev_orientation->roll_d = 0;
    wheel_state->angle = 0;
    wheel_state->speed = 0;

    system_state->phi = 0;
    system_state->phi_d = 0;
    system_state->theta = 0;
    system_state->theta_d = 0;

    last_read = ros::Time::now();
}

void IMUObserver::imuCallback(const imu::AccelGyro& msg){
    struct accel* copy = (struct accel*) malloc(sizeof(struct accel));
    copy->accel_x = msg.accel_x;
    copy->accel_y = msg.accel_y;
    copy->accel_z = msg.accel_z;
    computeOrientation(copy);
}

void IMUObserver::wheelCallback(const motor_controller::WheelState& msg) {
    wheel_state->angle = msg.wheel_angle;
    wheel_state->speed = msg.wheel_speed;
}

void IMUObserver::computeOrientation (struct accel* msg){
    //Roll: Rotation around X-axis
    memcpy(tmp, prev_orientation, sizeof(struct orientation));
    memcpy(prev_orientation, curr_orientation, sizeof(struct orientation));
    //tmp = prev_orientation;
    //prev_orientation = curr_orientation;
    float temp_roll = (float)atan2(msg->accel_y, msg->accel_z);

    //Get the time delta since last orientation check
    ros::Time current = ros::Time::now();
    double delta = (current - last_read).toSec();
    last_read = current;
    //std::cout << "Delta: " << delta;
    //Set the values in current orientation
    curr_orientation->roll = temp_roll*180/PI;
    curr_orientation->roll_d = (curr_orientation->roll - tmp->roll)/delta;

    //std::cout << "or_data roll::" << curr_orientation->roll << "orient roll d ::" << curr_orientation->roll_d << "\n";

}

struct orientation* IMUObserver::getOrientation(){
    return curr_orientation;
}

struct state* IMUObserver::getStates() {
    system_state->phi = wheel_state->angle;
    system_state->phi_d = wheel_state->speed;
    system_state->theta = curr_orientation->roll;
    system_state->theta_d = curr_orientation->roll_d;
    return system_state;
}
