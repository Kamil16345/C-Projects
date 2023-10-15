# Exercise 1
# Write your own Publisher that will be responsible for publishing
# speed "cmd_vel" of turtle. Import appropriate library which contains type of
# of published message. Message is of type Twist and for linear speed in field x there
# is progressive speed, while for the rotational speed in the field with the rotational speed.
import rospy
from geometry_msgs.msg import Twist
def publishTopic():
    rospy.init_node('turtle_publisher', anonymous=True)
    cmd_vel_publisher = rospy.Publisher('cmd_vel', Twist, queue_size=10)
    rate = rospy.Rate(10)#publikacja 10Hz
    #while not rospy.is_shutdown():
        
    twist_msg = Twist()
    twist_msg.linear.x=0.1
    twist_msg.angular.z=0.1
    cmd_vel_publisher.publish(twist_msg)   

if __name__ == '__main__':
    publishTopic()
# Exercise 2
# Write your own Subscriber that will be responsible for receiving current position 
# of a robot. Display message of coords x,y and theta degree recalculated from radians. 
# For this use method math.degrees from library math.
import rospy
from geometry_msgs.msg import Pose2D
from math import degrees

def main():
    rospy.init_node('turtle_pose_sub', anonymous=True)
    rospy.Subscriber('turtle1/pose', Pose2D, pose_check)
    rospy.spin() #rozpoczęcie nasłuchu
    
def pose_check(data):
    x=data.x
    y=data.y
    #katy na stopnie
    theta_deg = degrees(data.theta)
    rospy.loginfo("x=%.2f, y=%.2f, theta=%.2f",x,y,theta_deg)

if __name__ == '__main__':
    main()
# Exercise 3
# Based on above code create it to receive information about turtle position (/turtle1/pose)
# Additionally simultaneously there has to be published message including speed (/turtle1/cmd_vel).
# If axis x is in range <4,6> then speed should be half smaller than normal. The translational 
# and rotational speeds can be freely set selecting them experimentally so that after 
# a longer activation the movement is repeatable and so that the turtle does not stop on the outskirts.
import rospy
from geometry_msgs.msg import Pose2D
from geometry_msgs.msg import Twist
from math import degress

def main():
    rospy.init_node('turtle_controller', anonymous=True)
    cmd_vel_publisher = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
    rospy.Subscriber('/turtle1/pose', Pose2D, pose_check, cmd_vel_publisher)
    rospy.spin()
    
def pose_check(data, cmd_vel_publisher):
    x=data.x
    
    if 4.0 <= x <= 6.0:
        twist_msg=Twist()
        twist_msg.angular.z=0.05#zmniejszenie prędkości obr o połowę
        cmd_vel_publisher.publish(twist_msg)
    else:
        twist_msg=Twist()
        twist_msg.angular.z=0.1
        cmd_vel_publisher.publish(twist_msg)
        
if __name__ == '__main__':
    try:
        main()
        