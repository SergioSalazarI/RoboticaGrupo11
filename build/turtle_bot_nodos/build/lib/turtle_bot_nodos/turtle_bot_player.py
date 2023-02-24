#! /usr/bin/env python
import rclpy
from rclpy.node import Node

import tkinter as tk
from tkinter import filedialog

from time import perf_counter

from geometry_msgs.msg import Twist
from servicios.srv import ReproduceRoute

class route_saver(Node):
    def __init__(self):
        super().__init__('route_saver')
        self.cmd_publisher = self.create_publisher(Twist,'/turtlebot_cmdVel',10)
        self.srv = self.create_service(ReproduceRoute, "/RP", self.replicate_route_callback)

    def replicate_route_callback(self, request, response):
        self.file_path = request.file_path
        
        self.read_vels()
        self.read_keys()
        
        response.ruta= "esta correcto :))"                                      
        self.get_logger().info('Funciona <3 <3 <3') 
        return response

    """ def callback_get_route(self):
        cliente = self.create_client(ReproduceRoute,"/RP")
        while not cliente.wait_for_service(1.0):
            self.get_logger().info("---------------")
        request = ReproduceRoute.Request()
        request.file_path = "self.file_path"

        self.future = cliente.call_async(request)
        rclpy.spin_until_future_complete(self,future=self.future)

        self.file_path=self.future.result().ruta """
        
    def read_vels(self):
        f = open(self.file_path)
        lines = f.readlines()
        self.linear_vel = float(lines[0])
        self.angular_vel = float(lines[1])
        f.close()
    
    def key_callback(self,a,l):
        twist_mss = Twist()
        twist_mss.linear.x = a*self.linear_vel #a=1 adelante
        twist_mss.angular.z = l*self.angular_vel #l=1 derecha
        self.cmd_publisher.publish(twist_mss)
        
    def replicate_route(self,key):
        if key in ['w','a','s','d']:
            a = 0
            l = 0
            if key== 'w':
                a = 1
            elif key=='s':
                a = -1
            elif key== 'd':
                l = -1
            else:
                l = 1
            self.key_callback(a,l)
        else:
            print("La tecla presionada no tiene un movimiento asociado \n Siga las instrucciones.")
            
    def stops_movement(self):
        twist_mss = Twist()
        twist_mss.linear.x = 0.0
        twist_mss.angular.z = 0.0
        self.cmd_publisher.publish(twist_mss)

        
    def read_keys(self):
        #try:
            f = open(self.file_path)
            lines = f.readlines()[2::]
            for l in lines:
                ll = l.split(sep=';')
                key = ll[0]
                duration = float(ll[1].split(sep="\n")[0])
                print(f"Tecla:{key} / Duración: {duration}")
                current_time = perf_counter()
                diff = 0
                while diff <= duration:
                    self.replicate_route(key)
                    diff = perf_counter()-current_time
                self.stops_movement()
            print("fin")
        #except:
        #    print("[INFO] No fue posible replicar su ruta. Revise el archivo seleccionado.")

def main(args=None):
    rclpy.init(args=args)

    route = route_saver()

    #route.callback_get_route()
    #print("-$$--$$--$$--$$--$$--$$--$$")
    #route.read_vels()
    #route.read_keys()
    while rclpy.ok():
        rclpy.spin_once(route)

    route.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()