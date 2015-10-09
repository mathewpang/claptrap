#include "IMU_Node.h"

IMU_Node::IMU_Node(){
    my_wire = new Wire();
    gyro    = new Gyroscope(my_wire);
    accel   = new Accelerometer(my_wire);
}



int main(int argc, char **argv) {
    ros::init(argc, argv, "imu_node");
    ros::start();
    
    ros::Rate r(10);
    
    ROS_INFO_STREAM("Starting imu_node....");
    IMU_Node imu_node = IMU_Node();
    
    while(ros::ok()){
        struct accel* accel_data = imu_node.accel->getAcceleration();
        std::cout << "accel_data x::" << accel_data->accel_x << "\naccel_data y::" << accel_data->accel_y << "\naccel_data z::" << accel_data->accel_z << "\n";
        
        struct gyro* gyro_data = imu_node.gyro->getGyroData();
        std::cout << "gyro_data x::" << gyro_data->gyro_x << "\ngyro_data y::" << gyro_data->gyro_y << "\ngyro_data z::" << gyro_data->gyro_z << "\n";
        
        r.sleep();
    }    
    return 0;
}
