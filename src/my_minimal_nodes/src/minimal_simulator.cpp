#include <ros/ros.h>
#include <std_msgs/Float64.h>


// global var
std_msgs::Float64 g_velocity, g_force;

void myCallback(const std_msgs::Float64 & message_holder)
{
    ROS_INFO_STREAM("received force value is:" << message_holder.data);
    g_force.data = message_holder.data;
}


int main(int argc,char ** argv)
{
    ros::init(argc,argv,"minimal_simualtor");
    ros::NodeHandle nh;

    ros::Subscriber my_subscriber_object = nh.subscribe("force_cmd", 1,myCallback);

    ros::Publisher my_publisher_object = nh.advertise<std_msgs::Float64>("velocity", 1);

    double mass=1.0;
    double dt = 0.01;
    double sample_rate = 1.0/dt;

    ros::Rate naptime(sample_rate);
    g_velocity.data = 0;
    g_force.data = 0;

    while(ros::ok())
    {
        g_velocity.data = g_velocity.data + (g_force.data/mass)*dt;

        my_publisher_object.publish(g_velocity);

        ROS_INFO_STREAM("velocity =" << g_velocity.data);
        ros::spinOnce(); // allow data update from callback
        naptime.sleep(); // wait for remainder fo specified period: this loop rate is faster than the update rate of the 10Hz controller
        // that specifies force_cmd, however, simulator must advence each 10ms regardless
    }
    return(0);
}