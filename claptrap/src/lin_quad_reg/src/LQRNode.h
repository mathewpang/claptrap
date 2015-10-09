#ifndef LQR_NODE_H
#define LQR_NODE_H

#include <ros/ros.h>
#include "imu/AccelGyro.h"

class LQRNode{
	
	public:
		LQRNode();
		void imuCallback(const imu::AccelGyro& msg);
	private:

	
};


#endif