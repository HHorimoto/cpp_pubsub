#include <cpp_pubsub/publisher_member_function.hpp>

namespace my_publisher
{
  Publisher::Publisher() : Node("publisher"), count_(0)
  {
    publisher_ = this->create_publisher<String>("topic", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&Publisher::timer_callback, this));
  }

  void Publisher::timer_callback()
  {
    auto message = String();
    message.data = "Hello, world! " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<my_publisher::Publisher>());
  rclcpp::shutdown();
  return 0;
}