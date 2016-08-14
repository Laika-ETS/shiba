#!/usr/bin/env python

PACKAGE_NAME = 'shiba_teleop'

import roslib
roslib.load_manifest(PACKAGE_NAME)
import rospy
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Joy
import rospkg


FORWARD = 1
BACKWARDS = 2
SPINNING = 3
STOPPED = 4

linear_increment = 0.3
max_linear_vel = 1.0
min_linear_vel = -1.0
default_linear_vel = 0.1

angular_increment = 0.1
max_angular_vel = 0.6

spin_speed = 1.0

last_joy_message = None
linear_vel = 0.0
angular_vel = 0.0
last_angular_acceleration = 0
rotating = False
state = STOPPED


