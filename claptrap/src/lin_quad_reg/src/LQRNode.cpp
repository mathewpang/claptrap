#include "LQRNode.h"

LQRNode::LQRNode(){

}

void LQRNode::imuCallback(const imu::AccelGyro& msg){
    ROS_INFO("Got a call back\n");
    std::cout << "gyro_data x::" << msg.gyro_x << "\ngyro_data y::" << msg.gyro_y << "\ngyro_data z::" << msg.gyro_z << "\n";

}


int main(int argc, char **argv) {
    ros::init(argc, argv, "lqr_node");
    ros::NodeHandle n;
    
    ROS_INFO_STREAM("Starting lqr_node....");
    LQRNode lqr_node = LQRNode();
    
    ros::Subscriber sub = n.subscribe("accel_gyro", 1000, &LQRNode::imuCallback, &lqr_node);   
    ros::spin();
    return 0;
}

