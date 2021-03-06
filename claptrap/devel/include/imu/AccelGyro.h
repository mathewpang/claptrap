// Generated by gencpp from file imu/AccelGyro.msg
// DO NOT EDIT!


#ifndef IMU_MESSAGE_ACCELGYRO_H
#define IMU_MESSAGE_ACCELGYRO_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace imu
{
template <class ContainerAllocator>
struct AccelGyro_
{
  typedef AccelGyro_<ContainerAllocator> Type;

  AccelGyro_()
    : accel_x(0.0)
    , accel_y(0.0)
    , accel_z(0.0)
    , gyro_x(0.0)
    , gyro_y(0.0)
    , gyro_z(0.0)  {
    }
  AccelGyro_(const ContainerAllocator& _alloc)
    : accel_x(0.0)
    , accel_y(0.0)
    , accel_z(0.0)
    , gyro_x(0.0)
    , gyro_y(0.0)
    , gyro_z(0.0)  {
    }



   typedef float _accel_x_type;
  _accel_x_type accel_x;

   typedef float _accel_y_type;
  _accel_y_type accel_y;

   typedef float _accel_z_type;
  _accel_z_type accel_z;

   typedef float _gyro_x_type;
  _gyro_x_type gyro_x;

   typedef float _gyro_y_type;
  _gyro_y_type gyro_y;

   typedef float _gyro_z_type;
  _gyro_z_type gyro_z;




  typedef boost::shared_ptr< ::imu::AccelGyro_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::imu::AccelGyro_<ContainerAllocator> const> ConstPtr;

}; // struct AccelGyro_

typedef ::imu::AccelGyro_<std::allocator<void> > AccelGyro;

typedef boost::shared_ptr< ::imu::AccelGyro > AccelGyroPtr;
typedef boost::shared_ptr< ::imu::AccelGyro const> AccelGyroConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::imu::AccelGyro_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::imu::AccelGyro_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace imu

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'imu': ['/home/ubuntu/claptrap/claptrap/claptrap/src/imu/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::imu::AccelGyro_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::imu::AccelGyro_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::imu::AccelGyro_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::imu::AccelGyro_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::imu::AccelGyro_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::imu::AccelGyro_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::imu::AccelGyro_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5d2302ff0837b48049232075997b7be7";
  }

  static const char* value(const ::imu::AccelGyro_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5d2302ff0837b480ULL;
  static const uint64_t static_value2 = 0x49232075997b7be7ULL;
};

template<class ContainerAllocator>
struct DataType< ::imu::AccelGyro_<ContainerAllocator> >
{
  static const char* value()
  {
    return "imu/AccelGyro";
  }

  static const char* value(const ::imu::AccelGyro_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::imu::AccelGyro_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 accel_x\n\
float32 accel_y\n\
float32 accel_z\n\
float32 gyro_x\n\
float32 gyro_y\n\
float32 gyro_z\n\
";
  }

  static const char* value(const ::imu::AccelGyro_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::imu::AccelGyro_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.accel_x);
      stream.next(m.accel_y);
      stream.next(m.accel_z);
      stream.next(m.gyro_x);
      stream.next(m.gyro_y);
      stream.next(m.gyro_z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct AccelGyro_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::imu::AccelGyro_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::imu::AccelGyro_<ContainerAllocator>& v)
  {
    s << indent << "accel_x: ";
    Printer<float>::stream(s, indent + "  ", v.accel_x);
    s << indent << "accel_y: ";
    Printer<float>::stream(s, indent + "  ", v.accel_y);
    s << indent << "accel_z: ";
    Printer<float>::stream(s, indent + "  ", v.accel_z);
    s << indent << "gyro_x: ";
    Printer<float>::stream(s, indent + "  ", v.gyro_x);
    s << indent << "gyro_y: ";
    Printer<float>::stream(s, indent + "  ", v.gyro_y);
    s << indent << "gyro_z: ";
    Printer<float>::stream(s, indent + "  ", v.gyro_z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // IMU_MESSAGE_ACCELGYRO_H
