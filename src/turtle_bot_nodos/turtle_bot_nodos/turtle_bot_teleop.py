#! /usr/bin/env python

import rclpy

from pynput import keyboard as kb
from rclpy.node import Node
from geometry_msgs.msg import Twist
from servicios.srv import SaveRoute
from functools import partial
from datetime import datetime

import time

class teleop(Node):
    
    def __init__(self):
        super().__init__("turtle_bot_teleop")
        self.route = []
        self.cmd_publisher = self.create_publisher(Twist,'/turtlebot_cmdVel',10)
        self.get_logger().info("Turtle Teleop has been started correctly.")
        
    def print_instructions(self):
        print("________________________________________________________________")
        print("                        Instrucciones")
        print("Presione 'W' para ir hacia adelante.")
        print("Presione 'S' para ir hacia atras.")
        print(f"Presione 'D' para rotar {self.angular_vel} grados a la derecha.")
        print(f"Presione 'A' para rotar {self.angular_vel} grados a la izquierda.")
        print("________________________________________________________________")
        
        #le pide al usuario los parametros de velocidad lineal y velocidad angular
        
    def receive_parameters(self):
        self.linear_vel = float(input("[INFO] Indique la velocidad lineal deseada:"))
        self.angular_vel = float(input("[INFO] Indique la velocidad angular deseada."))
        self.save_route = float(input("[INFO] ¿Desea guardar la ruta?"))
        self.print_instructions()
        
        #multiplica la velocidad lineal y angular por -1 o 1 dependiendo del casp
    def key_callback(self,a,l):
        twist_mss = Twist()
        twist_mss.linear.x = a*self.linear_vel #a=1 adelante
        twist_mss.angular.z = l*self.angular_vel #l=1 derecha
        self.cmd_publisher.publish(twist_mss)
        
        #para el movimiento cuando se deja de presionar la tecla
    def stops_movement(self):
        twist_mss = Twist()
        twist_mss.linear.x = 0.0
        twist_mss.angular.z = 0.0
        self.cmd_publisher.publish(twist_mss)
        
    def callback_SaveRoute(self,ruta):
        with open("aaa.txt",'w') as f:
            f.writelines(ruta)           
    
    #asigna valores a y l dependiendo de la tecla presionada
    def on_press(self,key):
        try:
            if key.char in ['w','a','s','d']:
                a = 0
                l = 0
                if key.char == 'w':
                    a = 1
                elif key.char =='s':
                    a = -1
                elif key.char == 'd':
                    l = -1
                else:
                    l = 1
                self.key_callback(a,l)
             
            else:
                print("La tecla presionada no tiene un movimiento asociado \n Siga las instrucciones.")
                self.print_instructions()
            
            self.current_time = datetime.now()
            #self.current_time = time.time()
            
            if key.char == 'n' and self.save_route==1:
                print("[INFO] Se guardo el recorrido.")
                self.callback_SaveRoute(self.route) 
        except:
            print("Caracter especial no identificado.")
            self.print_instructions()
        
        #llama a la función de parar cuando la tecla se deja de presionar
    def on_release(self,key):
        diff = datetime.now()-self.current_time
        
        #diff = time.time()-self.current_time
        
        if self.save_route==1:
            self.route.append(key.char+";"+str(diff.seconds)+"\n")
        self.stops_movement()
        
        #espera que se presione una tecla para escucharla y ejecutar alguna función
    def listen_keyboard(self):
        with kb.Listener(on_press=self.on_press,on_release=self.on_release) as listener:
            listener.join()
            
            
    def callback_save_route(self,entrada):
        cliente = self.create_client(SaveRoute,"turtle_bot_save_route")
        #while not cliente.wait_for_service(1.0):
        request = SaveRoute.Request()
        request.name = entrada
        
        future = cliente.call_async(request)
        future.add_done_callback(partial[self.callback_save_route_future])
        
    def callback_save_route_future(self, future):
        try:
            response = future.result()
        except Exception as e:
            self.get_logger().error("algo paso :(((") 

def main(args=None):
    rclpy.init(args=args)
    teleop_node = teleop()
    
    teleop_node.receive_parameters()
    teleop_node.listen_keyboard()
    
    rclpy.spin(teleop_node)
    
    teleop.destroy_node()
    rclpy.shutdown()
    
if __name__== "__main__":
    main()
