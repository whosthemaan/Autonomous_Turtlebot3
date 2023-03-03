cmake_minimum_required(VERSION 3.0.2)
project(robot_learning_ros)
## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp tf rospy std_msgs genmsg)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(RL src/main.cpp)
target_link_libraries(RL ${catkin_LIBRARIES})


