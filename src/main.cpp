#include <vector>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "imports.h"

/**
 * @brief Construct a new Listener:: Listener object 
 *and initialize the global nodel handle, publisher and 
 *subcriber objects. Also initialize the count and distance threshold
 * 
 * @param n = node handle 
 */
Listener::Listener(ros::NodeHandle n) {
  node_h = n;
  velocity_publisher = node_h.advertise<geometry_msgs::Twist>("cmd_vel", 100);
  subscriber = node_h.subscribe("scan", 100, &Listener::scanCallback, this);
  ros::spinOnce();
  count = 0;
  threshold = 0.8;
}

/**
 * @brief A callback function to provide twist according to distance from obstacle
 * 
 * @param received laser scan object
 */
void Listener::scanCallback(const sensor_msgs::LaserScan::ConstPtr& msg) {
  std::vector<float> laser_scan = msg->ranges;
  geometry_msgs::Twist cmd_velocity;

  if(msg->ranges[330]<0.3 || msg->ranges[0] < 0.3) {
    cmd_velocity.linear.x = 0;
    cmd_velocity.angular.z = 0.6;
    velocity_publisher.publish(cmd_velocity); }
  else if (msg->ranges[30] < 0.3) {
    cmd_velocity.linear.x = 0;
    cmd_velocity.angular.z = -0.6;
    velocity_publisher.publish(cmd_velocity); }
  else {
    cmd_velocity.linear.x = 0.2;
    cmd_velocity.angular.z = 0;
    velocity_publisher.publish(cmd_velocity); }

  std::cout << "Command Velocity:" << cmd_velocity << std::endl;
}

/**
 * @brief main function which creates a node handles 
 * 
 * @return int 
 */
int main(int argc, char **argv) {
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  Listener node_handle(n);
  ros::spin();

  return 0;
}
