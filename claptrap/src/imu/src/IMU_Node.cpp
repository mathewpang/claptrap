//#include "Wire.h"
#include "IMU_Node.h"

int main(int argc, char **argv) {
    //Wire my_wire = Wire();
    //my_wire.helloWorld();
    ros::init(argc, argv, "imu_node");
    ros::start();
    ROS_INFO_STREAM("HELLO< WORLD");
    ros::Rate r(10);
  //  Wire my_wire = Wire();
    //my_wire.helloWorld();
    ROS_INFO_STREAM("HELLO< WORLD2");
    
    Adafruit_9DOF dof   = Adafruit_9DOF();
    Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30301);
    Adafruit_LSM303_Mag_Unified   mag   = Adafruit_LSM303_Mag_Unified(30302);
    
    if(!accel.begin())
    {

        ROS_INFO_STREAM("No accel detected");
        while(1);

    }
    if(!mag.begin())
    {

        ROS_INFO_STREAM("No mag detected");
        while(1);
    }

    ROS_INFO_STREAM("HELLO< WORL3D");
    
    while(1){
        sensors_event_t accel_event;
        sensors_event_t mag_event;
        sensors_vec_t   orientation;
        ROS_INFO_STREAM("Heading: ");
        /* Calculate pitch and roll from the raw accelerometer data */
      
        accel.getEvent(&accel_event);
        ROS_INFO_STREAM("Heading: 2");
        if (dof.accelGetOrientation(&accel_event, &orientation))
        {
            /* 'orientation' should have valid .roll and .pitch fields */
            ROS_INFO_STREAM("Roll: ");
            ROS_INFO_STREAM(orientation.roll);
            ROS_INFO_STREAM("; ");
            ROS_INFO_STREAM("Pitch: ");
            ROS_INFO_STREAM(orientation.pitch);
            ROS_INFO_STREAM("; ");
        }
          ROS_INFO_STREAM("Heading: ");
        /* Calculate the heading using the magnetometer */
        mag.getEvent(&mag_event);
        if (dof.magGetOrientation(SENSOR_AXIS_Z, &mag_event, &orientation))
        {
          /* 'orientation' should have valid .heading data now */
          ROS_INFO_STREAM("Heading: ");
          ROS_INFO_STREAM(orientation.heading);
          ROS_INFO_STREAM("; ");
        }

        ROS_INFO_STREAM("");
        ros::spinOnce();
        r.sleep();
    }
    ROS_INFO_STREAM("Why stopping?");
    printf("HELLO WORLD EXTIGIN");
    return 0;
}
