#! /usr/bin/env python

import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist
from std_msgs.msg import Bool
#from servicios.srv import SaveRoute
from functools import partial

from pynput import keyboard as kb

import tkinter as tk
from tkinter import filedialog

from time import perf_counter

class teleop(Node):
    
    def listener_callback_save(self,msg_save):
        """Escucha el mensaje de tipo BOOL que llega al tópico 'turtlebot_save' y lo asigna a la variable 'save_route'.
         
          Args:
            msg: Mensaje tipo BOOL que llega al tópico 'turtlebot_save'
        """
        print("________________________________________________________________")
        print(f"msg_save ={msg_save.data}")
        print("________________________________________________________________")
        if msg_save.data:
          self.save_route = 1
          print("________________________________________________________________")
          print("        save_route = 1")

    def listener_callback_end(self,msg_end):
        """Escucha el mensaje de tipo BOOL que llega al tópico 'turtlebot_end' y lo asigna en la variable 'end'.
         
          Args:
            msg: Mensaje tipo BOOL que llega al tópico 'turtlebot_end'
        """
        print("________________________________________________________________")
        print(f"msg_end = {msg_end.data}")
        print("________________________________________________________________")
        if msg_end.data:
            self.end = 1
            print("________________________________________________________________")
            print("        end = 1")
    
    def __init__(self):
        super().__init__("turtle_bot_teleop")
        self.route = []
        self.current_key = 'q'
        self.cmd_publisher = self.create_publisher(Twist,'/turtlebot_cmdVel',10)
        self.get_logger().info("Turtle Teleop has been started correctly.")
        
        #Creamos la subscripción al tópico 'turtlebot_save' que indica si se quiere o no guardar el recorrido:
        print("aquiaaaaaa")
        self.subscription_save = self.create_subscription(Bool,'/turtlebot_save',self.listener_callback_save,10)
        #Creamos la subscripción al tópico 'turtlebot_end' que indica cuando se quiere guardar el recorrido:
        self.subscription_end = self.create_subscription(Bool,'/turtlebot_end',self.listener_callback_end,10)
        
    def print_instructions(self):
        print("________________________________________________________________")
        print("                        Instrucciones")
        print("    Presione 'W' para ir hacia adelante.")
        print("    Presione 'S' para ir hacia atras.")
        print(f"    Presione 'D' para rotar {self.angular_vel} grados a la derecha.")
        print(f"    Presione 'A' para rotar {self.angular_vel} grados a la izquierda.")
        print("________________________________________________________________")
        
        #le pide al usuario los parametros de velocidad lineal y velocidad angular
    def receive_parameters(self):
        self.linear_vel = float(input("[INFO] Indique la velocidad lineal deseada:"))
        self.angular_vel = float(input("[INFO] Indique la velocidad angular deseada:"))
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
        root = tk.Tk()
        root.withdraw()
        file_path = filedialog.asksaveasfilename(
            defaultextension=".txt",
            filetypes=[("Archivo TXT","*.txt")]
        )
        with open(file_path,'w') as f:
            f.writelines([str(self.linear_vel)+"\n",str(self.angular_vel)])
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
                
            if key.char != self.current_key:
                self.current_time = perf_counter()
                self.current_key = key.char
            
            if key.char == 'n' and self.save_route==1:
                print("[INFO] Se guardo el recorrido.")
                self.callback_SaveRoute(self.route) 
        except:
            print("Caracter especial no identificado.")
            self.print_instructions()
        
        #llama a la función de parar cuando la tecla se deja de presionar
    def on_release(self,key):
        diff = perf_counter()-self.current_time
        self.current_time = perf_counter()
        try:
            if self.save_route==1 :
                self.route.append("\n"+key.char+";"+str(diff))
        except:
            print("hay un problema :))")
        self.stops_movement()
        
        #espera que se presione una tecla para escucharla y ejecutar alguna función
    def listen_keyboard(self):
        with kb.Listener(on_press=self.on_press,on_release=self.on_release) as listener:
            listener.join()
            
        

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