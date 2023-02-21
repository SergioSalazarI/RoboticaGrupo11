#! /usr/bin/env python

import rclpy
from rclpy.node import Node

class player(Node):
    
    time_stop = 0
    
    def __init__(self):
        super().__init__("turtle_bot_teleop")
        #self.cmd_publisher = self.create_publisher(Twist,'/turtlebot_cmdVel',10)
        self.get_logger().info("turtle_bot_player has been started correctly.")


def main(args=None):
    rclpy.init(args=args)
    player_node = player()
    
    rclpy.spin(player_node)
    
    player.destroy_node()
    rclpy.shutdown()
    
if __name__== "__main__":
    main()