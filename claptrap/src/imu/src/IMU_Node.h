#ifndef IMUNODE_H
#define IMUNODE_H

#include "Wire.h"
#include "Accelerometer.h"
#include "Gyroscope.h"
#include <ros/ros.h>

class IMU_Node{
	public:
		IMU_Node();
		Accelerometer* accel;
	private:
		Wire* my_wire;
		Gyroscope* gyro;
		
};

#endif

