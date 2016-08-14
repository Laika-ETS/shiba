# code that control the turtlesim for demo

#include <ros/ros.h>
#include <turtlesim/Velocity.h>
#include <sensor_msgs/Joy.h>


class TeleopShibaDemo
{
public:
    TeleopShibaDemo();

private:
    void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);

    ros::NodeHandle nh_;

    int linear_, angular_;
    double l_scale_, a_scale_;
    ros::Publisher vel_pub_;
    ros::Subscriber joy_sub_;
};

TeleopShibaDemo::TeleopShibaDemo():
    linear_(1),
    angular_(2)
{

    nh_.param("axis_linear", linear_, linear_);
    nh_.param("axis_angular", angular_, angular_);
    nh_.param("scale_angular", a_scale_, a_scale_);
    nh_.param("scale_linear", l_scale_, l_scale_);


    vel_pub_ = nh_.advertise<turtlesim::Velocity>("turtle1/command_velocity", 1);

    joy_sub_= nh_.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopShibaDemo::joyCallback, this);

}

void TeleopShibaDemo::joyCallback(const sensor_msgs::Joy::ConstPtr &joy) {
    turtlesim::Velocity vel;
    vel.angular = a_scale_*joy->axes[angular_];
    vel.linear = l_scale_*joy->axes[linear_];
    vel_pub_.publish(vel);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "shiba_teleop_demo");
    TeleopShibaDemo shiba_teleop_demo;

    ros::spin();
}