#include "LQRNode.h"

LQRNode::LQRNode(IMUObserver* observer){
	this->observer = observer;
}


void LQRNode::computeLQR(){
	//ROS_INFO("Compute LQR here");
	struct orientation* orient = observer->getOrientation();
	//That might be always the same but value is different
	std::cout << "or_data roll::" << orient->roll << "\norient roll d ::" << orient->roll_d << "\ndd::" << orient->roll_dd << "\n";
    
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "lqr_node");
    ros::NodeHandle n;
    ros::Rate loop_rate(10);

    ROS_INFO_STREAM("Starting lqr_node....");
    

    IMUObserver* observer = new IMUObserver();
    LQRNode *lqr_node = new LQRNode(observer);
    
    ros::Subscriber sub = n.subscribe("accel_gyro", 1000, &IMUObserver::imuCallback, observer);   
    
    while (ros::ok()){
    	lqr_node->computeLQR();
    	ros::spinOnce();
    }
    
    return 0;
}
