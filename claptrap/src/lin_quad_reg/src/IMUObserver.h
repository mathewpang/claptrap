#ifndef IMU_OBS_H
#define IMU_OBS_H

#include <ros/ros.h>
#include "imu/AccelGyro.h"

struct orientation{
  float roll;
  float roll_d;
  float roll_dd;
  float pitch;
  float pitch_d;
};

struct accel{
	float accel_x;
	float accel_y;
	float accel_z;
};

class IMUObserver{
	
	public:
		IMUObserver();
		void imuCallback(const imu::AccelGyro& msg);

		void computeOrientation (struct accel* msg);
		struct orientation* getOrientation();
	private:
		struct orientation* curr_orientation;
		struct orientation* prev_orientation;
		struct orientation* tmp;
		ros::Time last_read;
};


#endif