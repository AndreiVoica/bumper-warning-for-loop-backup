#include <ros/ros.h>
#include <kobuki_msgs/BumperEvent.h>
#include <sensor_msgs/Image.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Accel.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
ros::Subscriber sub_bumper;
//ros::Subscriber sub_img;
ros::Subscriber sub_twist;
ros::Publisher cmd_vel;


void clbk_bumper(const kobuki_msgs::BumperEvent::ConstPtr& msg){
if(msg->state == kobuki_msgs::BumperEvent::PRESSED)
{
  ros::NodeHandle n;
  ros::Publisher pub_twist = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
  ros::Publisher pub_accl = n.advertise<geometry_msgs::Accel>("/cmd_vel", 1000);
  if(msg->bumper == 1){
    ROS_INFO("Center bumper activated!");
    system("/home/ros/ros_ws/src/bumper_warning/src/script.sh");

for (int a = 0; a < 7.15; a++){
    geometry_msgs::Twist msg;

      msg.linear.x = -1.0;
      msg.angular.z = 0;
      cout<< a << endl;
      pub_twist.publish(msg);
      ros::Duration(0.5).sleep();

      ros::spinOnce();
      }

for (int b = 0; b < 5; b++){
    geometry_msgs::Accel msg;

      msg.linear.x = -0.5;
      msg.angular.z = 0;
      cout<< b << endl;
      pub_accl.publish(msg);
      ros::Duration(0.5).sleep();
}
for (int a = 0; a < 6.9; a++){
    geometry_msgs::Twist msg;

      msg.linear.x = -1.0;
      msg.angular.z = -1.1;
      cout<< a << endl;
      pub_twist.publish(msg);
      ros::Duration(0.5).sleep();}
  }
  else if(msg->bumper == 0){
    ROS_INFO("Left bumper activated!");
    system("/home/ros/ros_ws/src/bumper_warning/src/script.sh");

    for (int a = 0; a < 5.3625; a++){
    geometry_msgs::Twist msg;

      msg.linear.x = 0;
      msg.angular.z = -1.1;
      cout<< a << endl;
      pub_twist.publish(msg);
      ros::Duration(0.5).sleep();}

for (int b = 0; b < 5; b++){
    geometry_msgs::Accel msg;

      msg.linear.x = 0.3;
      msg.angular.z = 0;
      cout<< b << endl;
      pub_accl.publish(msg);
      ros::Duration(0.5).sleep();
  }
  for (int a = 0; a < 6.9; a++){
      geometry_msgs::Twist msg;

        msg.linear.x = 0;
        msg.angular.z = 1.1;
        cout<< a << endl;
        pub_twist.publish(msg);
        ros::Duration(0.5).sleep();}
}
  else if(msg->bumper == 2){
    ROS_INFO("Right bumper activated!");
    system("/home/ros/ros_ws/src/bumper_warning/src/script.sh");

for (int a = 0; a < 5.3625; a++){
    geometry_msgs::Twist msg;

      msg.linear.x = 0;
      msg.angular.z = 1.1;
      cout<< a << endl;
      pub_twist.publish(msg);
      ros::Duration(0.5).sleep();}

for (int b = 0; b < 5; b++){
    geometry_msgs::Accel msg;

      msg.linear.x = 0.3;
      msg.angular.z = 0;
      cout<< b << endl;
      pub_accl.publish(msg);
      ros::Duration(0.5).sleep();
  }
  for (int a = 0; a < 6.9; a++){
      geometry_msgs::Twist msg;

        msg.linear.x = 0;
        msg.angular.z = 1.1;
        cout<< a << endl;
        pub_twist.publish(msg);
        ros::Duration(0.5).sleep();}

}

}
}


int main(int argc, char **argv)
{

  ros::init(argc, argv, "image_rover");
  ros::NodeHandle n;

sub_bumper = n.subscribe("/mobile_base/events/bumper", 1, clbk_bumper);

  //sub_img = n.subscribe("")

  ros::Publisher pub_twist = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
  ros::Publisher pub_accl = n.advertise<geometry_msgs::Accel>("/cmd_vel", 1000);
  ros::spin();}


//"turtle1/cmd_vel"has to be changed to the topic in the turtlebot!
