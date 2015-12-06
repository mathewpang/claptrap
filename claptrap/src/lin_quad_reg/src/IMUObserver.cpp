#include "IMUObserver.h"

IMUObserver::IMUObserver(){
	curr_orientation = (struct orientation*) malloc(sizeof(struct orientation));
	prev_orientation = (struct orientation*) malloc(sizeof(struct orientation));
	tmp = (struct orientation*) malloc(sizeof(struct orientation));
	
	prev_orientation->roll = 0;
	prev_orientation->pitch = 0;
	prev_orientation->roll_d = 0;
	prev_orientation->pitch_d = 0;

	last_read = ros::Time::now();
}

void IMUObserver::imuCallback(const imu::AccelGyro& msg){
    ROS_INFO("Got a call back\n");
    std::cout << "gyro_data x::" << msg.accel_x << "\ngyro_data y::" << msg.accel_y << "\ngyro_data z::" << msg.gyro_z << "\n";
    struct accel* copy = (struct accel*) malloc(sizeof(struct accel));
    copy->accel_x = msg.accel_x;
    copy->accel_y = msg.accel_y;
    copy->accel_z = msg.accel_z;
    computeOrientation(copy);
}

void IMUObserver::computeOrientation (struct accel* msg){
	//Roll: Rotation around X-axis
	memcpy(tmp, prev_orientation, sizeof(struct orientation));
	memcpy(prev_orientation, curr_orientation, sizeof(struct orientation));
	//tmp = prev_orientation;
	//prev_orientation = curr_orientation;
	float temp_roll = (float)atan2(msg->accel_y, msg->accel_z);
	//Pitch
	float temp_pitch = 0;
	if(msg->accel_y * sin(temp_roll) + msg->accel_z * cos(temp_roll) == 0){
		if(msg->accel_x > 0){
			temp_pitch = 3.14159265F/2;
		}
		else{
			temp_pitch = -3.14159265F/2;
		}
	}
	else{
		temp_pitch = (float)atan(-1*msg->accel_x/(msg->accel_y*sin(temp_roll) + msg->accel_z * cos(temp_roll)));
	}
	//Get the time delta since last orientation check
	ros::Time current = ros::Time::now();
	double delta = (current - last_read).toSec();

	//Set the values in current orientation
	curr_orientation->roll = temp_roll;
	curr_orientation->pitch = temp_pitch;
	curr_orientation->roll_d = (curr_orientation->roll - tmp->roll)/delta;
	curr_orientation->pitch_d = (curr_orientation->pitch - tmp->pitch)/delta;

    
}

struct orientation* IMUObserver::getOrientation(){
	return curr_orientation;
}
