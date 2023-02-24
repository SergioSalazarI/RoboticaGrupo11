#! /usr/bin/env python
import rclpy
from rclpy.node import Node

import tkinter as tk
from tkinter import filedialog

from geometry_msgs.msg import Twist
from servicios.srv import ReproduceRoute

class route_saver(Node):
    def __init__(self):
        super().__init__('route_saver')
        self.srv = self.create_service(ReproduceRoute, "/RP", self.save_route_callback)

    def save_route_callback(self, request, response):
        root = tk.Tk()
        root.withdraw()
        self.file_path = filedialog.askopenfilename(
            defaultextension=".txt",
            filetypes=[("Archivo TXT","*.txt")])
        print(f"[INFO] Usted selecciono la ruta: {self.file_path}")
        
        response.ruta= self.file_path                                       
        self.get_logger().info('Funciona <3 <3 <3') 
        print(response)
        print(response.ruta)
        return response

def main(args=None):
    rclpy.init(args=args)

    route = route_saver()

    rclpy.spin(route)

    route.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()