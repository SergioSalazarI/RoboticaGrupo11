#! /usr/bin/env python
import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist
from servicios.srv import SaveRoute

class route_saver(Node):
    def __init__(self):
        print("llega")
        super().__init__('route_saver')
        self.cmd_publisher = self.create_publisher(Twist,'/turtlebot_cmdVel',10)
        self.srv = self.create_service(SaveRoute, "SaveRoute", self.save_route_callback)
        print("qqqqq")

    def save_route_callback(self, request, response):
        print("aaaaaa")
        response.result = request.file_path                                            
        self.get_logger().info('Incoming request\na: b:c:') 
        return response

def main(args=None):
    rclpy.init(args=args)

    route = route_saver()

    rclpy.spin(route)

    route.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()