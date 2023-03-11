## Obstacle avoidance on turtlebot3 using lidar

1. We require turtlebot3 to be installed for the program to run

2. To run the teleop, we will need to run two commands(as turtlebot3 is already installed, these packages will be available for direct use):
	# this commands open the world file being used for autonomous navigation as well
	1. roslaunch turtlebot3_gazebo turtlebot3_world.launch
	
	# this launch file controls the teleop operation
	2. roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch 

3. Download the zipped folder inside of src folder of catkin_ws
4. run "catkin_make"
5. run "source devel/setup.bash"
6. run the command - "roslaunch robot_learning_ros robot_learning_hw3.launch"
7. the main.cpp file present in src, indicates the functioning of the turtlebot, where it looks for obstacle through lidar data and publishes yaw data so the robot can move until it doesn't detect empty space and then just moves forward.

Link to Video - https://youtu.be/RjKiTGLrF6w
