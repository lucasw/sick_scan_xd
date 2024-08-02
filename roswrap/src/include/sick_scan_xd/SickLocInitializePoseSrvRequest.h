#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/SickLocInitializePoseSrvRequest.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCINITIALIZEPOSESRVREQUEST_H
#define SICK_SCAN_MESSAGE_SICKLOCINITIALIZEPOSESRVREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace sick_scan_xd
{
template <class ContainerAllocator>
struct SickLocInitializePoseSrvRequest_
{
  typedef SickLocInitializePoseSrvRequest_<ContainerAllocator> Type;

  SickLocInitializePoseSrvRequest_()
    : x(0)
    , y(0)
    , yaw(0)
    , sigmatranslation(0)  {
    }
  SickLocInitializePoseSrvRequest_(const ContainerAllocator& _alloc)
    : x(0)
    , y(0)
    , yaw(0)
    , sigmatranslation(0)  {
  (void)_alloc;
    }



   typedef int32_t _x_type;
  _x_type x;

   typedef int32_t _y_type;
  _y_type y;

   typedef int32_t _yaw_type;
  _yaw_type yaw;

   typedef uint32_t _sigmatranslation_type;
  _sigmatranslation_type sigmatranslation;





  typedef std::shared_ptr< ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocInitializePoseSrvRequest_

typedef ::sick_scan_xd::SickLocInitializePoseSrvRequest_<std::allocator<void> > SickLocInitializePoseSrvRequest;

typedef std::shared_ptr< ::sick_scan_xd::SickLocInitializePoseSrvRequest > SickLocInitializePoseSrvRequestPtr;
typedef std::shared_ptr< ::sick_scan_xd::SickLocInitializePoseSrvRequest const> SickLocInitializePoseSrvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.yaw == rhs.yaw &&
    lhs.sigmatranslation == rhs.sigmatranslation;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan_xd

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1feb9f336f9d6f0d1c23b8b3110ffc00";
  }

  static const char* value(const ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1feb9f336f9d6f0dULL;
  static const uint64_t static_value2 = 0x1c23b8b3110ffc00ULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocInitializePoseSrvRequest";
  }

  static const char* value(const ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Definition of ROS service SickLocInitializePose for sick localization\n"
"# Automatically adjusts the given input pose according to the map of the environment and the current LiDAR measurements.\n"
"# Example call (ROS1):\n"
"# rosservice call SickLocInitializePose \"{x: 100, y: -100, yaw: 2000, sigmatranslation: 1000}\"\n"
"# Example call (ROS2):\n"
"# ros2 service call SickLocInitializePose sick_scan/srv/SickLocInitializePoseSrv \"{x: 100, y: -100, yaw: 2000, sigmatranslation: 1000}\"\n"
"# \n"
"\n"
"# \n"
"# Request (input)\n"
"# \n"
"\n"
"int32 x # Vehicle x position relative to map origin. [<min>, <max>] in [mm] \n"
"int32 y # Vehicle y position relative to map origin. [<min>, <max>] in [mm] \n"
"int32 yaw # Vehicle yaw angle relative to map origin. [-180000, 180000] in [mdeg] \n"
"uint32 sigmatranslation # Standard deviation of the initial position describing the uncertainty. [300, 5000] in [mm] \n"
"\n"
;
  }

  static const char* value(const ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.yaw);
      stream.next(m.sigmatranslation);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocInitializePoseSrvRequest_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan_xd::SickLocInitializePoseSrvRequest_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<int32_t>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<int32_t>::stream(s, indent + "  ", v.y);
    s << indent << "yaw: ";
    Printer<int32_t>::stream(s, indent + "  ", v.yaw);
    s << indent << "sigmatranslation: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.sigmatranslation);
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_SICKLOCINITIALIZEPOSESRVREQUEST_H