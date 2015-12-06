#ifndef LQR_NODE_H
#define LQR_NODE_H

#include <ros/ros.h>
#include "imu/AccelGyro.h"
#include "IMUObserver.h"

class LQRNode{
	
	public:
		LQRNode(IMUObserver* observer);
		void computeLQR();
	private:
		IMUObserver* observer; 
	
};


#endif