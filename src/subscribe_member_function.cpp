#include <cpp_pubsub/subscribe_member_function.h>

namespace my_subscriber
{
    Subscriber::Subscriber() : nh_()
    {
        subscription_ = nh_.subscribe("topic", 1, &Subscriber::call_back, this);
    }

    void Subscriber::call_back(const std_msgs::String::ConstPtr& msg)
    {
        ROS_INFO("I heard: '%s'", msg->data.c_str());
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener");

    my_subscriber::Subscriber node;

    ros::spin();

    return 0;
}