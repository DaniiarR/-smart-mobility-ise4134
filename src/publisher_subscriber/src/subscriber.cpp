#include <ros/ros.h>
#include <std_msgs/String.h>

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  // Initialize the ROS node
  ros::init(argc, argv, "subscriber_node");

  // Create a ROS node handle
  ros::NodeHandle nh;

  // Subscribe to the "chatter" topic with a callback function
  ros::Subscriber sub = nh.subscribe("chatter", 10, chatterCallback);

  // Spin until the node is shutdown
  ros::spin();

  return 0;
}

