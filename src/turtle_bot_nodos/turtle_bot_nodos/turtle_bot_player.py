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
        """"
        Constructor de la clase 'route_saver'. Crea el nodo con nombre 'route_saver', el cual pública en el tópico
         '/turtlebot_cmdVel'. Tambien crea el servicio encargado de reproducir la ruta contenida en un archico .txt
        """
        super().__init__('route_saver')
        self.cmd_publisher = self.create_publisher(Twist,'/turtlebot_cmdVel',10)
        self.srv = self.create_service(ReproduceRoute, "/RP", self.replicate_route_callback)

    def replicate_route_callback(self, request, response):
        """"
        Respuesta del llamado del servicio.
        Dado un path por paŕametro en 'request', se réplica la ruta que describe el archivo txt del path indicado.
        
        Args:
            request: clase asociada a las entradas del servicio
            response:  clase asociada a las salidas del servicio
        """
        self.file_path = request.file_path
        
        self.read_vels()
        self.read_keys()
        
        response.ruta= "esta correcto :))"                                      
        self.get_logger().info('Funciona <3 <3 <3') 
        return response
        
    def read_vels(self):
        """"
        Abre el archivo txt del path indicado e identifica los parámetros de la ruta. Es decir, la velocidad lineal y
        la velocidad angular.
        """
        f = open(self.file_path)
        lines = f.readlines()
        self.linear_vel = float(lines[0])
        self.angular_vel = float(lines[1])
        f.close()
    
    def key_callback(self,a,l):
        """Multiplica la velocidad lineal y angular por -1 o 1 dependiendo de la tecla presionada. Publica el
        mensaje tipo Twist en el tópico '/turtlebot_cmdVel'."""
        twist_mss = Twist()
        twist_mss.linear.x = a*self.linear_vel #a=1 adelante
        twist_mss.angular.z = l*self.angular_vel #l=1 derecha
        self.cmd_publisher.publish(twist_mss)
        
    def replicate_route(self,key):
        """Cuando se presiona una tecla en el teclado, si es 'w','a','s' o 'd' asigna un valor a las variables
        a y l que multiplican por 1 o -1 las velocidades lineales y angulares respectivamente.
        
        Args:
            key: tecla presionada en el teclado
        """
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
        """Detiene el movimiento del robot cuando se deja de presionar una tecla. Publica el mensaje tipo
        Twist en el tópico '/turtlebot_cmdVel' con velocidad lineal y angular en cero."""
        twist_mss = Twist()
        twist_mss.linear.x = 0.0
        twist_mss.angular.z = 0.0
        self.cmd_publisher.publish(twist_mss)

        
    def read_keys(self):
        """"
        Dado el path del archivo txt, abre el archivo y lee cada linea. Luego, utiliza la función 
        'replicate_route' con la información de cada linea.
            key: letra que contiene la linea actual
            duration: tiempo que se presiono la letra
        """
        try:
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
            print("[INFO] Se réplico con éxito la ruta indicada.")
        except:
            print("[INFO] No fue posible replicar su ruta. Revise el archivo seleccionado.")

def main(args=None):
    
    rclpy.init(args=args)
    route = route_saver()

    while rclpy.ok():
        rclpy.spin_once(route)

    route.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()