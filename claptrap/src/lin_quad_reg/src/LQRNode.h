#ifndef LQR_NODE_H
#define LQR_NODE_H

#include <ros/ros.h>
#include "imu/AccelGyro.h"
#include "geometry_msgs/Twist.h"
#include "IMUObserver.h"

class LQRNode{
	
	public:
		LQRNode(IMUObserver* observer, ros::Publisher* pub);
		void computeLQR();
	private:
		IMUObserver* observer; 
		ros::Publisher* pub;
	
};


#endif