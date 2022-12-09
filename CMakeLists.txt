cmake_minimum_required(VERSION 3.5)
project(cpp_pubsub)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

unset(NODES)
set(NODES publisher_member_function;subscriber_member_function)
foreach(target IN LISTS NODES)
  add_executable(${target}_node src/${target}.cpp)
  ament_target_dependencies(${target}_node rclcpp std_msgs)
  install(TARGETS ${target}_node DESTINATION lib/${PROJECT_NAME})
  target_include_directories(${target}_node
    PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:include>
  )
endforeach()

ament_package()