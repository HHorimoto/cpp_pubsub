#include <cpp_pubsub/subscriber_member_function.hpp>

namespace my_subscriber
{
    Subscriber::Subscriber() : Node("subscriber")
    {
        subscription_ = this->create_subscription<String>("topic", 10, std::bind(&Subscriber::topic_callback, this, _1));
    }

    void Subscriber::topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    {
        RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
    }
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<my_subscriber::Subscriber>());
  rclcpp::shutdown();
  return 0;
}