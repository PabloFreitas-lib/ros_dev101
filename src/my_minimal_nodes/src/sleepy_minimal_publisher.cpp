#include <ros/ros.h>
#include <std_msgs/Float64.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "sleepy_minimal_publisher"); // Name of the node
	ros::NodeHandle n;
	ros::Publisher my_publisher_object = n.advertise<std_msgs::Float64>("topic1", 1);
	// Intend to publish float64 msgs, named the topic1 and has a 1 buffer to wait list at the queue

	std_msgs::Float64 input_float;

	ros::Rate naptime(2.0); 
	// The desired rate to run at in Hz

	input_float.data = 0.0;

	while (ros::ok())
	{
		input_float.data = input_float.data + 0.001;

		my_publisher_object.publish(input_float);

		naptime.sleep();
	}
}