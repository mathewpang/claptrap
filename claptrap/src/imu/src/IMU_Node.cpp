#include "IMU_Node.h"

IMU_Node::IMU_Node(){
    my_wire = new Wire();
    gyro    = new Gyroscope(my_wire);
    accel   = new Accelerometer(my_wire);
}



int main(int argc, char **argv) {
   ros::init(argc, argv, "imu_node");

    ros::NodeHandle n;

    ros::Publisher chatter_pub = n.advertise<imu::AccelGyro>("accel_gyro", 1);
    ros::Rate r(100);

    ROS_INFO_STREAM("Starting imu_node....");
    IMU_Node imu_node = IMU_Node();
    imu::AccelGyro msg;
    ros::start();

    while(ros::ok()){

        struct accel* accel_data = imu_node.accel->getAcceleration();

        struct gyro* gyro_data = imu_node.gyro->getGyroData();

        msg.accel_x = accel_data->accel_x;
        msg.accel_y = accel_data->accel_y;
        msg.accel_z = accel_data->accel_z;

        msg.gyro_x = gyro_data->gyro_x;
        msg.gyro_y = gyro_data->gyro_y;
        msg.gyro_z = gyro_data->gyro_z;

        chatter_pub.publish(msg);

        r.sleep();
    }
    return 0;
}
