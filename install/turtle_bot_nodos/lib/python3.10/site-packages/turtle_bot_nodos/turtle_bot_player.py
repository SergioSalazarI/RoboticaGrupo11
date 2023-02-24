#! /usr/bin/env python

import rclpy
from rclpy.node import Node

import tkinter as tk
from tkinter import filedialog
from geometry_msgs.msg import Twist
from time import perf_counter
from servicios.srv import ReproduceRoute
class player(Node):
        
    def __init__(self):
        super().__init__("turtle_bot_teleop")
        self.cmd_publisher = self.create_publisher(Twist,'/turtlebot_cmdVel',10)
        self.file_path=""
        self.get_logger().info("turtle_bot_player has been started correctly.")
        
    def callback_get_route(self):
        cliente = self.create_client(ReproduceRoute,"/RP")
        while not cliente.wait_for_service(1.0):
            self.get_logger().info("---------------")
        request = ReproduceRoute.Request()
        request.file_path = "self.file_path"

        self.future = cliente.call_async(request)
        rclpy.spin_until_future_complete(self,future=self.future)
        #future = cliente.call(request)
        print(self.future.result().ruta)
        self.file_path=self.future.result().ruta
        #if future.done():
        #    self.file_path=future.result().result
        #    print(self.file_path)
        #future = cliente.call(request)
        #future.add_done_callback(self.callback_get_route_future)
        
    def read_vels(self):
        f = open(self.file_path)
        lines = f.readlines()
        self.linear_vel = float(lines[0])
        self.angular_vel = float(lines[1])
        
    def callback_get_route_future(self, future):
        #try:
            response = future.result()
            print(response)
            print(response.ruta)
            print("111111111111111")
            response = future.result()
            self.file_path = str(response.result)
            print("22222222222222222")
            f = open(self.file_path)
            lines = f.readlines()
            self.linear_vel = float(lines[0])
            self.angular_vel = float(lines[1])
            f.close()
            print(self.file_path)
            self.get_logger().info(f'Se selecciono la ruta: {response.result}')
            
        #except Exception as e:
        #    self.get_logger().error("algo paso :(((")
    
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
            print("===========")
            print(self.file_path)
            f = open(self.file_path)
            print("________________")
            print(self.file_path)
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
    
    player_node = player()
    
    player_node.callback_get_route()
    print("-$$--$$--$$--$$--$$--$$--$$")
    player_node.read_vels()
    player_node.read_keys()
    #player_node.read_keys()
    #player_node.callback_save_route()
    #rclpy.spin(player_node)
    while rclpy.ok():
        rclpy.spin_once(player_node)
    
    player.destroy_node()
    rclpy.shutdown()
    
if __name__== "__main__":
    main()