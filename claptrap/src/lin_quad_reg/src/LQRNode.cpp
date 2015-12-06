#include "LQRNode.h"

LQRNode::LQRNode(){

}


int main(int argc, char **argv) {
    ros::init(argc, argv, "lqr_node");
    ros::NodeHandle n;
    
    ROS_INFO_STREAM("Starting lqr_node....");
    LQRNode *lqr_node = new LQRNode();
    IMUObserver* observer = new IMUObserver();
    ros::Subscriber sub = n.subscribe("accel_gyro", 1000, &IMUObserver::imuCallback, observer);   
    ros::spin();
    return 0;
}
