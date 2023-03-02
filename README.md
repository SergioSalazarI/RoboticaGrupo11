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

### turtle_bot_player

Es el nodo que contiene el servicio **/RP**, el cual permite replicar una ruta dado un archivo *.txt*.

Para ejecutar el nodo escriba el siguiente comando en su terminal.

```
ros2 run turtle_bot_nodos turtle_bot_player
```

### turtle_bot_save_route

El nodo no es necesario para el desarrollo de las tareas del taller. *turtle_bot_save_route* permite utilizar el servicio de *turtle_bot_player* sin utilizar la interfaz gráfica.

Para ejecutar el nodo escriba el siguiente comando en su terminal.

```
ros2 run turtle_bot_nodos turtle_bot_save_route
```

### turtle_bot_teleop

Es el nodo asignado a la teleoperación del robot. La tarea principal es identificar la presión de teclas en el teclado, si estas tienen algun movimiento asociado, publica dicho movimiento en un tópico ('/turtlebot_cmdVel') generando el movimiento del robot.

Para ejecutar el nodo escriba el siguiente comando en su terminal.

```
ros2 run turtle_bot_nodos turtle_bot_teleop
```

### Indicaciones para el correcto funcionamiento

## Mover el robot con teclas sin .txt

Para mover el robot en *Coppelia* sin guardar el recorrido se recomienda:
1. Correr la escena en Coppelia.
2. Ejecutar el nodo *turtle_bot_interface* si desea tener la opción de guardar la trayectoria (imagen .jpg).
3. Ejecutar el nodo *turtle_bot_teleop*

## Mover el robot con teclas y guardar la ruta

1. Correr la escena en Coppelia.
2. Ejecutar el nodo *turtle_bot_interface*.
3. Ejecutar el nodo *turtle_bot_teleop*
4. Antes de guardar la ruta en formato *.txt* cerrar la terminal donde se ejecuta el nodo de teleoperación.
5. Seleccionar *Terminar recorrido* y elegir la dirección y nombre del archivo *.txt*.

## Mover el robot con un archivo .txt

1. Correr la escena en Coppelia.
2. Ejecutar el nodo turtle_bot_player.
3. Ejecutar el nodo *turtle_bot_interface*.
4. Seleccionar "Mover con .TXT".
5. Cuando se abra el explorador de archivos, diríjase a la dirección donde está almacenado el archivo, luego escriba su nombre, incluya la extensión *.txt.*
