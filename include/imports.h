#ifndef INCLUDE_IMPORTS_H_
#define INCLUDE_IMPORTS_H_

#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"


class Listener {
 public:
    /**
    * @brief Constructor
    * 
    * @param n : node handle
    */
     explicit Listener(ros::NodeHandle n);
     /**
      * @brief keeps track of number of turns the robot has turned
      * 
      */
     int count;

 private:
     /**
      * @brief ros node handle
      * 
      */
     ros::NodeHandle node_h;
     /**
      * @brief ros velocity publisher object
      * 
      */
     ros::Publisher velocity_publisher;
     /**
      * @brief ros subscriber object
      * 
      */
     ros::Subscriber subscriber;
     /**
      * @brief laser scan callback
      * 
      * @param msg : laser scan message
      */
     void scanCallback(const sensor_msgs::LaserScan::ConstPtr& msg);
     float threshold;
};
#endif 
