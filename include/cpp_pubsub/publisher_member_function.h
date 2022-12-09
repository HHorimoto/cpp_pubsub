#ifndef PUBLISHER_MEMBER_FUNCTION_H__
#define PUBLISHER_MEMBER_FUNCTION_H__

#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

namespace my_publisher
{
    class Publisher
    {

    public:
        Publisher();

        void spin(void);

    private:
        ros::NodeHandle nh_;

        ros::Publisher publisher_;

        int count_;
    };
}

#endif