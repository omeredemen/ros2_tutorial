cmake_minimum_required(VERSION 3.8)
project(rviz_tutorial)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)

add_executable(laser_node src/fakeLaser_node.cpp)
target_include_directories(laser_node PRIVATE include)
ament_target_dependencies(laser_node rclcpp sensor_msgs)

add_executable(range_node src/fakeRange_node.cpp)
target_include_directories(range_node PRIVATE include)
ament_target_dependencies(range_node rclcpp sensor_msgs)

install(TARGETS
  laser_node
  range_node
  DESTINATION lib/${PROJECT_NAME}  
)

ament_package()
