#include "LQRNode.h"


LQRNode::LQRNode(IMUObserver* observer, ros::Publisher* pub){
	this->observer = observer;
	this->pub = pub;
}


void LQRNode::computeLQR(){
	//ROS_INFO("Compute LQR here");
	struct orientation* orient = observer->getOrientation();
	//That might be always the same but value is different
	//std::cout << "or_data roll::" << orient->roll << "orient roll d ::" << orient->roll_d << "\n";
    geometry_msgs::Twist msg;
    msg.linear.x = orient->roll*-1*100;
    pub->publish(msg);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "lqr_node");
    ros::NodeHandle n;
    ros::Rate loop_rate(10);

    ROS_INFO_STREAM("Starting lqr_node....");
    

    IMUObserver* observer = new IMUObserver();
    ros::Subscriber sub = n.subscribe("accel_gyro", 1000, &IMUObserver::imuCallback, observer);   
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

    LQRNode *lqr_node = new LQRNode(observer, &pub);

   

    while (ros::ok()){
    	lqr_node->computeLQR();
    	ros::spinOnce();
    }
    
    return 0;
}

