/*
 * Created By: Gareth Ellis
 * Created On: July 16th, 2016
 * Description: An example node that subscribes to a topic publishing strings,
 *              and re-publishes everything it receives to another topic with
 *              a "!" at the end
 */

#ifndef SAMPLE_PACKAGE_MYNODE_H
#define SAMPLE_PACKAGE_MYNODE_H

#include <iostream>
#include <cmath>
#include <std_msgs/String.h>
#include <std_msgs/Int64.h>
#include <std_msgs/Float32.h>
#include <ros/ros.h>
#include <sb_utils.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/PointCloud.h>
#include <geometry_msgs/Twist.h>
#include <iostream>


class MyClass {
public:
    MyClass(int argc, char **argv, std::string node_name);
    /**
     * Adds an exclamation point to a given string
     *
     * Some Longer explanation should go here
     *
     * @param input_string the string to add an exclamation point to
     *
     * @return input_string with an exclamation point added to it
     */
     //static std::string addCharacterToString(std::string input_string, std::string suffix);
     std::string suffix;
     void convertToPointCloud(float * ranges, sensor_msgs::PointCloud* cloud, int size, float angle_min, float angle_incr);
    float locateTheHole(sensor_msgs::PointCloud* cloud, geometry_msgs::Point32* output_points, int size, float angle_min, float angle_incr);
    void MoveTowardsHole(geometry_msgs::Twist* twist, float hole_angle);


private:
    /**
     * Callback function for when a new string is received
     *
     * @param msg the string received in the callback
     */
    void subscriberCallBack(const sensor_msgs::LaserScan::ConstPtr& msg);
    /**
     * Publishes a given string
     *
     * @param msg_to_publish the string to publish
     */
    //void republishMsg(std::string msg_to_publish);


    ros::Subscriber my_subscriber;
    ros::Publisher my_publisher;




};

#endif //SAMPLE_PACKAGE_MYNODE_H
