#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

namespace my_subscriber
{
  class Subscriber : public rclcpp::Node
  {
    using String = std_msgs::msg::String;
    
    public:
      Subscriber();

    private:
      void topic_callback(const String::SharedPtr msg) const;
      rclcpp::Subscription<String>::SharedPtr subscription_;
  };
}

