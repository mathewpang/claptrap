#ifndef IMUNODE_H
#define IMUNODE_H

#include "Wire.h"
#include "Accelerometer.h"
#include "Gyroscope.h"
#include "imu/AccelGyro.h"
#include <ros/ros.h>

class IMU_Node{
	public:
		IMU_Node();
		Accelerometer* accel;
		Gyroscope* gyro;
	private:
		Wire* my_wire;
		
};

#endif

