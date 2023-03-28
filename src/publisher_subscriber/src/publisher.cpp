#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char **argv)
{
  // Initialize the ROS node
  ros::init(argc, argv, "publisher_node");

  // Create a ROS node handle
  ros::NodeHandle nh;

  // Create a publisher for the "chatter" topic with a queue size of 10
  ros::Publisher pub = nh.advertise<std_msgs::String>("chatter", 10);

  // Set the loop rate to 10Hz
  ros::Rate loop_rate(10);

  // Loop until the node is shutdown
  while (ros::ok())
  {
    // Create a message to send on the "chatter" topic
    std_msgs::String msg;
    msg.data = "Hello, world!";

    // Publish the message
    pub.publish(msg);

    // Sleep for the remaining time until we reach 10Hz
    loop_rate.sleep();
  }

  return 0;
}

