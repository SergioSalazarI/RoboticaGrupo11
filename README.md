# RoboticaGrupo11

<h2> Dependencias </h2>

Para el correcto funcionamiento de los paquetes se debe tener a disposición las siguientes dependencias.
<ul> 
  <li>rclpy</li>
  <li>keyboard</li>
  <li>geometry_msgs</li>
  <li>std_msgs</li>
  <li>pynput</li>
  <li>pygame</li>
  <li>tkinter</li>
  <li>time</li>
</ul>

## Nodos

El paquete de ROS esta compuesto por 4 nodos:
- turtle_bot_interface
- turtle_bot_player
- turtle_bot_save_route
- turtle_bot_teleop

### turtle_bot_interface

Es el nodo asignado a la visualización de los algoritmos y funciones realizadas. El nodo provee una interfaz gráfica para visualizar la trayectoria del robot, dados unos comando. Además, permite guardar la imagen de la trayectoria realizada, así como un generar un archivo *.txt*.

Para ejecutar el nodo escriba el siguiente comando en su terminal.

```
ros2 run turtle_bot_nodos turtle_bot_interface
```