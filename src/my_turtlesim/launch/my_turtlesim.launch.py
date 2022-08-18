from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    
    turtle_node  = Node(
        package= "my_turtlesim",
        executable= "myTurtle_node"
    )    

    joy_node = Node(
        package= "joy",
        executable= "joy_node"
    )

    turtlesim_node = Node(
        package = "turtlesim",
        executable = "turtlesim_node"
    )


    ld.add_action(turtle_node)
    ld.add_action(joy_node)
    ld.add_action(turtlesim_node)


    return ld