#include <cpp_pubsub/publisher_member_function.h>

namespace my_publisher
{
    Publisher::Publisher() : nh_()
    {
        publisher_ = nh_.advertise<std_msgs::String>("topic", 1);
        count_ = 0;
    }
    void Publisher::spin(void)
    {
        std_msgs::String msg;

        std::stringstream ss;
        ss << "Hello, world! " << count_;
        msg.data = ss.str();
        publisher_.publish(msg);
        ROS_INFO("Publishing: '%s'", msg.data.c_str());
        count_ += 1;
    }
}

int main(int argc, char**argv)
{
	ros::init(argc, argv, "talker");
	
	my_publisher::Publisher node;

	ros::Rate loop_rate(10);
	while(ros::ok()){
		node.spin();
		ros::spinOnce();
		loop_rate.sleep();
	}
    return 0;
}