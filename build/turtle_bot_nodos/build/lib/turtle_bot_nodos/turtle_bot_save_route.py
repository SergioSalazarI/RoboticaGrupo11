from nodos_taller_1.srv import save_route

import rclpy
from rclpy.node import Node


class route_saver(Node):

    def __init__(self):
        super().__init__('route_saver')
        self.srv = self.create_service(save_route, 'save_route', self.save_routecallback)

    def save_route_callback(self, request, response):
        response.estado = request.name                                             
        #self.get_logger().info('Incoming request\na: %d b: %d c: %d' % (request.a, request.b, request.c)) 
        return response

def main(args=None):
    rclpy.init(args=args)

    route = route_saver()

    rclpy.spin(route)

    rclpy.shutdown()

if __name__ == '__main__':
    main()