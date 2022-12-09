cmake_minimum_required(VERSION 3.0.2)
project(cpp_pubsub)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(publisher_member_function_node src/publisher_member_function.cpp)
target_link_libraries(publisher_member_function_node
  ${catkin_LIBRARIES}
)