#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>


// using namespace std;

int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);
    // glfwMakeContextCurrent(window);
  while (ros::ok() )
  {

    std_msgs::String msg;

    std::stringstream ss;

    std::string m;
    std::getline(std::cin,m);
    ss << m;
    msg.data = ss.str();
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}
