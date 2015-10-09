#include "IMU_Node.h"

IMU_Node::IMU_Node(){
    my_wire = new Wire();
    gyro    = new Gyroscope(my_wire);
    accel   = new Accelerometer(my_wire);
}



int main(int argc, char **argv) {
    //Wire my_wire = Wire();
    //my_wire.helloWorld();
    ros::init(argc, argv, "imu_node");
    ros::start();
    ROS_INFO_STREAM("HELLO< WORLD");
    IMU_Node imu_node = IMU_Node();
    
    struct accel* accel_data = imu_node.accel->getRawData();
    std::cout << "accel_data ::" << accel_data->accel_x << accel_data->accel_y << accel_data->accel_z << "\n";
    // ros::Rate r(10);
    // r.sleep();
    return 0;
}
