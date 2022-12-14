#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

namespace my_publisher
{
  class Publisher : public rclcpp::Node
  {
    using String = std_msgs::msg::String;
    
    public:
      Publisher();

    private:
      void timer_callback();
      rclcpp::TimerBase::SharedPtr timer_;
      rclcpp::Publisher<String>::SharedPtr publisher_;
      size_t count_;
  };
}