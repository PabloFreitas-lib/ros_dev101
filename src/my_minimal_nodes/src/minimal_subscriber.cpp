#include <ros/ros.h>
#include <std_msgs/Float64.h>

void myCallback(const std_msgs::Float64 & message_holder)
{
    // ROS_INFO_STREAM( "Received value is : " << message_holder.data);
    // the real work is done in this callback function
    // it wakes up every time a new message is published on "topic1"
    // Since this function is prompted by a message event
    // it does not consume CPU time polling for new data
    // the ROS_INFO() function i s like  printf(), except
    // it publishes its output to the default rosout topic, which prevents
    // slowing down this function for display calls, and it makes the
    // data available for viewing and logging purposes
    ROS_INFO("received value is: %f" ,message_holder.data);
    // really could do something interesting here with the received data.. but all we do is print it
}

int main(int argc, char ** argv)
{
    ros::init(argc,argv,"minimal_subscriber");
    ros::NodeHandle n;
    ros::Subscriber my_subscriber_object = n.subscribe("topic1", 1, myCallback);

    ros::spin(); // this is essentially a "while(1)", statment, execpt it
    // forces refreshing wakeups upon new data arrival
    // main program essentially hangs here, but it must stay alive to keep the callback fuction alive.
    
    return(0); // should neve get here
}