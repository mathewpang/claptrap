//#include "Wire.h"
#include "IMU_Node.h"

int main(int argc, char **argv) {
    //Wire my_wire = Wire();
    //my_wire.helloWorld();
    ros::init(argc, argv, "imu_node");
    ros::start();
    ROS_INFO_STREAM("HELLO< WORLD");

  //  Wire my_wire = Wire();
    //my_wire.helloWorld();

    Adafruit_9DOF dof   = Adafruit_9DOF();
    Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30301);
    Adafruit_LSM303_Mag_Unified   mag   = Adafruit_LSM303_Mag_Unified(30302);

    ros::spin();
    ros::shutdown();

    return 0;
}
