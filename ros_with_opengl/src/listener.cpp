#include "ros/ros.h"
#include "std_msgs/String.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <thread>
using std::thread;

float c = 0.0f;

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

   // Draw a Red 1x1 Square centered at origin
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, c, 0.0f); // Red
      glVertex2f(-0.5f, -0.5f);    // x, y
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
      glVertex2f(-0.5f,  0.5f);
   glEnd();

   glFlush();  // Render now
}


void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("chatter : %s", msg->data.c_str());
  c = 1.0f;
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);                 // Initialize GLUT
  glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
  glutInitWindowSize(320, 320);   // Set the window's initial width & height
  glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  GLenum err = glewInit();
  if(GLEW_OK != err){
    std::cout<<glewGetErrorString(err)<<std::endl;
    return -1;
  }
  else
    std::cout<<glewGetErrorString(err)<<std::endl;
  glutDisplayFunc(display); // Register display callback handler for window re-paint
  thread t1(glutMainLoop);           // Enter the infinitely event-processing loop
  ros::spin();
  t1.join();

  return 0;
}
