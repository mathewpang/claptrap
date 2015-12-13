#include "LQRNode.h"


LQRNode::LQRNode(IMUObserver* observer, ros::Publisher* pub){
    this->observer = observer;
    this->pub = pub;
}


void LQRNode::computeLQR(double reference, double K1, double K2, double K3, double K4, double scale){
    //ROS_INFO("Compute LQR here");
    //That might be always the same but value is different
    //std::cout << "or_data roll::" << orient->roll << "orient roll d ::" << orient->roll_d << "\n";

    double K[] = {K1, K2, K3, K4};
    struct state* x = observer->getStates();
    std::cout <<"current states: " << x->phi << " " << x->phi_d << " " << x->theta << " " << x->theta_d << "\n";
    
    double Kx = K[0]*x->phi + K[1]*x->phi_d + K[2]*(x->theta+2) + K[3]*x->theta_d;
    double u = scale*(reference - Kx);
    if(abs(x->theta) > 54){
        u = 0;
    }
    //DEMO CODE

    //struct orientation* orient = observer->getOrientation();
    //double u = orient->roll*-5;
    
    geometry_msgs::Twist msg;
    msg.linear.x = u;
    pub->publish(msg);
}

int main(int argc, char **argv) {
    if (argc != 7) {
        ROS_INFO_STREAM("Incorrect number of arguments.");
        return 0;
    }

    ros::init(argc, argv, "lqr_node");
    ros::NodeHandle n;
    ros::Rate loop_rate(atoi(argv[6]));

    ROS_INFO_STREAM("Starting lqr_node....");


    IMUObserver* observer = new IMUObserver();
    ros::Subscriber imu_sub = n.subscribe("accel_gyro", 1, &IMUObserver::imuCallback, observer);
    ros::Subscriber wheel_sub = n.subscribe("wheel_state", 1, &IMUObserver::wheelCallback, observer);
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1);

    LQRNode *lqr_node = new LQRNode(observer, &pub);

    

    while (ros::ok()){
        lqr_node->computeLQR(0, atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]));
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}

