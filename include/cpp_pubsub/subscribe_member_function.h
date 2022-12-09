#ifndef SUBSCRIBE_MEMBER_FUNCTION_H__
#define SUBSCRIBE_MEMBER_FUNCTION_H__

#include "ros/ros.h"
#include "std_msgs/String.h"

namespace my_subscriber
{
    class Subscriber
    {
    public:
        Subscriber();

    private:
        ros::NodeHandle nh_;
        ros::Subscriber subscription_;
        void call_back(const std_msgs::String::ConstPtr &msg);
    };
}

#endif