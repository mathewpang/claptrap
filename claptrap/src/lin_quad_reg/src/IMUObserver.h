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


class IMUObserver{
	
	public:
		IMUObserver();
		void imuCallback(const imu::AccelGyro& msg);

		struct orientation* getOrientation (imu::AccelGyro& msg);
	private:
		struct orientation* curr_orientation;
		struct orientation* prev_orientation;
		ros::Time last_read;
};


#endif