#include "MotorDriver.h"

MotorDriver* MotorDriver::m_Instance = NULL;

MotorDriver::MotorDriver() {
    ROS_INFO_STREAM("Motor starts up successfully!2");
    rightMotor = new Motor("/dev/ttyACM0");
    curr_wheel_state = (struct wheel_state*) malloc(sizeof(struct wheel_state));


}

MotorDriver* MotorDriver::Instance(){
    if(!m_Instance){
        m_Instance = new MotorDriver();
    }
    return m_Instance;
}

void MotorDriver::forward(int speed) {
    if (speed > 100) {
        speed = 100;
    } else if (speed < -100) {
        speed = -100;
    }
    rightMotor->setSpeed(speed);
}

void MotorDriver::turn(int speed) {
    if (speed > 100) {
        speed = 100;
    } else if (speed < -100) {
        speed = -100;
    }
    rightMotor->setSpeed(speed);
}

void MotorDriver::stop() {
    rightMotor->setSpeed(0);
}

void MotorDriver::test() {
    forward(100);
    sleep(2);
    turn(100);
    sleep(2);
    turn(-100);
    sleep(2);
    forward(0);
    sleep(1);
    forward(100);
    forward(-100);
    forward(100);
    sleep(1);
    stop();
}

void MotorDriver::updateWheelState() {
    // Currently just uses right motor states, change the relationship here
    curr_wheel_state->wheelAngle = rightMotor->wheelAngle;
    curr_wheel_state->wheelSpeed = rightMotor->wheelSpeed;
}

void MotorDriver::publishWheelState(ros::Publisher* pub) {
    updateWheelState();
    motor_controller::WheelState msg;
    //msg.wheel_angle = curr_wheel_state->wheelAngle;
    msg.wheel_angle = 0;
    msg.wheel_speed = curr_wheel_state->wheelSpeed;
    pub->publish(msg);
}

void MotorDriver::callback(const geometry_msgs::Twist& msg) {
    ROS_INFO_STREAM("callback in motor\n");
    if (abs(msg.angular.z) > 4) {
        turn(msg.angular.z);
    } else if (abs(msg.linear.x) > 4) {
        forward(msg.linear.x);
    } else {
        stop();
    }
}


void motorSIGINTHandler(int sig){
    MotorDriver* m = MotorDriver::Instance();
    m->forward(0);
    ROS_INFO_STREAM("Shutting down\n");
    ros::shutdown();
}


int main(int argc, char **argv) {

    ros::init(argc, argv, "motor_controller");
    ros::NodeHandle n;
    ROS_INFO_STREAM("HELLO WORLD from motor_controller");
    ros::Rate loop_rate(100);
ROS_INFO_STREAM("Motor starts up successfully!4");
    MotorDriver* driver = MotorDriver::Instance();
ROS_INFO_STREAM("Motor starts up successfully!3");
    ros::Subscriber motor_sub = n.subscribe("cmd_vel", 1, &MotorDriver::callback, driver);
    ros::Publisher motor_pub = n.advertise<motor_controller::WheelState>("wheel_state", 1);
    ROS_INFO_STREAM("MotorDriver setup finished");

    signal(SIGINT, motorSIGINTHandler);

    while (ros::ok()) {
        driver->publishWheelState(&motor_pub);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
