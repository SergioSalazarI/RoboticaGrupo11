#! /usr/bin/env python

import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist

import pygame
from pygame.locals import *

import tkinter as tk
from tkinter import filedialog

class Cell:
    """Crea objetos tipo casilla y los pinta en la pantalla de pygame.
    
    Args:
        size: Tamaño de la casilla
        color: Color con el cual se debe pintar la casilla
        row: Fila en que está ubicada la casilla dentro de la cuadrícula
        col: columna en que está ubicada la casilla dentro de la cuadrícula
    """
    def __init__(self,size,color,row,col):
        """ Constructor de la clase cell. 

        Args:
            size: Tamaño de la casilla en pixeles.
            color: Color con el cual se debe pintar la casilla
            row(int): Fila en que está ubicada la casilla dentro de la cuadrícula
            col: columna en que está ubicada la casilla dentro de la cuadrícula
        """
        self.size = size
        self.color = color
        self.row = row
        self.col = col

        #Calculamos las coordenadas (en pixeles) en las que se pintara la casilla:
        self.x = col*self.size
        self.y = row*self.size

    def paint(self,screen):
        """Pinta la casilla en la pantalla de pygame a partir de su posición en la cuadrícula y el tamaño en pixeles.
        
        Args:
            screen: pantalla en la cual se quiere pintar la casilla
        """
        pygame.draw.rect(screen,self.color,(self.x,self.y,self.size,self.size))

class Circle:
    """Crea objetos de tipo círculo y los dibuja en la pantalla de pygame.
    
    Args:
        center: indica las coordenadas (x,y) donde se desea centrar el círculo
        radius: radio del círculo
        color: color (RBG) con el cual se desea dibujar el círculo
    """
    def __init__(self,center,radius,color):
        """ Constructor de la clase circle. 
        
        Args:
            center: indica las coordenadas (x,y) donde se desea centrar el círculo
            radius: radio del círculo
            color: color con el cual se desea dibujar el círculo
        """
        self.center = center
        self.radius = radius
        self.color = color

    def paint(self,screen):
        """ Dibuja un círculo en la pantalla de pygame.
        
        Args:
            screen: pantalla en la cual se quiere pintar la el círculo
        """
        pygame.draw.circle(screen,self.color,self.center,self.radius,self.radius)

class Plant(Circle):
    """Crea objetos de tipo planta que heredan de la superclase círculo.
    
    Args: 
        center: indica las coordenadas (x,y) donde se desea centrar la planta
        radius: radio de la planta
        color: color (RBG) con el cual se desea dibujar la planta
    """
    def __init__(self, center, radius, color):
        """Constructor de la clase plant.
        
        Args: 
            center: indica las coordenadas (x,y) donde se desea centrar la planta
            radius: radio de la planta
            color: color (RBG) con el cual se desea dibujar la planta
        """
        super().__init__(center, radius, color)

class Robot(Circle):
    """Crea objetos de tipo robot que heredan de la superclase círculo.
    
    Args: 
        center: indica las coordenadas (x,y) donde se desea centrar el robot
        radius: radio del robot
        color: color (RBG) con el cual se desea dibujar la el robot
    """
    def __init__(self, center, radius, color):
        """Constructor de la clase robot.
        
        Args: 
            center: indica las coordenadas (x,y) donde se desea centrar el robot
            radius: radio del robot
            color: color (RBG) con el cual se desea dibujar el robot
        """
        super().__init__(center, radius, color)

    def move(self,x,y):
        """El robot se mueve a las coordenadas (x,y) indicadas.
        
        Args:
            x: Posición x, en el marco de referencia de coppelia, a la cual se mueve el robot
            y: posición y, en el marco de referencia de coppelia, a la cual se mueve el robot
        """
        xp = x*100+250 # Hallamos la equivalencia de la posición x en coppelia con los pixeles de la pantalla de pygame
        yp = -1*y*100+250 # Hallamos la equivalencia de la posición x en coppelia con los pixeles de la pantalla de pygame

        self.center = (xp,yp)

class Board:
    """Crea objetos de tipo tablero y los pinta en la pantalla de pygame. Este objeto está compuesto de una cuadrícula (grid), 
    una lista de plantas, un robot y un camino (path) que deja el robot al desplazarse.
    
    Args:
        dimension: Cantidad de casillas por fila (y columnas) de la cuadrícula (ej: cuadricula de 8x8 dimension = 8)
        size: Tamaño de la cuadricula en pixeles
        color1: color(RGB) con el cual se desea pintar las casillas impares de la cuadricula
        color2: color(RGB) con el cual se desea pintar las casillas pares de la cuadricula
        plants: Lista de objetos tipo planta
        robot: Objeto de tipo robot
    """
    def __init__(self,dimension,size,color1,color2,plants,robot):
        """Constructor de la clase grid.
        
        Args:
            dimension: Cantidad de casillas por fila (o columna) de la cuadricula (ej: cuadricula de 8x8 dimension = 8)
            size: Tamaño de la cuadricula en pixeles
            color1: color(RGB) con el cual se desea pintar las casillas impares de la cuadricula
            color2: color(RGB) con el cual se desea pintar las casillas pares de la cuadricula
            plants: Lista de objetos tipo planta
            robot: Objeto de tipo robot
        """
        self.dimension = dimension
        self.size = size
        self.color1 = color1
        self.color2 = color2
        self.grid = self.createGrid()
        self.plants = plants
        self.robot = robot

        #Creamos la variable path que guarda las diferentes ubicaciones del robot para poder pintar su recorrido
        self.path = []


    def createGrid(self):
        """Crea un arreglo bidimensional de celdas según la dimensión del tablero.
        
        Returns: 
            grid: Arreglo que contiene los objetos de tipo casilla que compondrán el tablero
        """
        cellsize = self.size/self.dimension #Determinamos el tamaño de la celda a partir del tamaño del tablero y las dimensiones deseadas
        grid = [] #Variable en la cual se va a guardar el arreglo

        for y in range(self.dimension):
            row = []
            for x in range(self.dimension):
                if (x + y)% 2 == 0: #Sacamos el modulo para determinar si es una casilla par o impar y asi pintarla de un color determinado
                    cell = Cell(cellsize,self.color2,y,x)
                else: 
                    cell = Cell(cellsize,self.color1,y,x)
                row.append(cell)
            grid.append(row)
        return grid

    def paintPath(self,screen):
        """Pinta el camino que ha recorrido el robot sobre la pantalla de pygame.

        Args: 
            screen: pantalla en la cual se quiere pintar el camino recorrido
        """
        for i in range(1,len(self.path)): #Recorremos la lista del recorrido del robot y la dibujamos en la pantalla de pygame
            pygame.draw.line(screen,self.robot.color, self.path[i-1], self.path[i])
        
    def paint(self,screen):
        """Pinta todo el escenario compuesto por el grid, las plantas, el robot y el recorrido del robot en la pantalla de pygame.
        
        Args:
            screen: Pantalla en la cual se quiere pintar el tablero
        """
        self.screen = screen

        for i in range(self.dimension): #Recorremos el arreglo de casillas para pintar el tablero
            for j in range(self.dimension):
                self.grid[i][j].paint(screen)

        for i in range(len(self.plants)): #Recorremos la lista de plantas y pintamos cada una de ellas sobre el tablero
            self.plants[i].paint(screen)

        self.robot.paint(screen) #Pintamos el robot
        self.paintPath(screen) #Pintamos su recorrido

    def moveRobot(self, msgx, msgy):
        """Mueve el robot a la posición (x,y) contenida en msg.

        Args:
            msg: contiene las coordenadas (x,y) de la ubicación del robot contenidas en el mensaje recibido a través del tópico 'turtlebot_position'
        """
        self.robot.move(msgx,msgy)
        self.path.append(self.robot.center)
        self.paint(self.screen)

    def saveImage(self, img_name):
        """Guarda la imagen del tablero en la ruta deseada con el nombre indicado por el usuario.
        
        Args:
            img_name: Nombre con el cual el usuario quiere guardar la imagen
        """
        root = tk.Tk()
        root.withdraw()
        file_path = filedialog.asksaveasfilename(initialfile = img_name, defaultextension=".jpg",
                                filetypes=[("Archivo JPG", "*.jpg")])
        if file_path:
            # Save the image to the selected file path
            pygame.image.save(self.screen, file_path)
            img = pygame.image.load(file_path)
            tablero = pygame.Rect(0,0,500,500)
            tab_recortado = img.subsurface(tablero)
            pygame.image.save(tab_recortado, file_path)
        root.destroy()

class TextBox():
    """Crea objetos de tipo 'caja de texto' con un tipo de letra, color y ubicación.
    
    Args:
        text: texto que se quiere escribir en la caja de texto
        fuente: tipo de letra que se va a utilizar
        color: color del texto que se va a escribir
        center: ubicación de la caja de texto en la pantalla de pygame (pixeles)
    """
    def __init__(self, text, fuente, color, center):
        """Constructor de la clase 'TextBox'.
        Args:
            text: texto que se quiere escribir en la caja de texto
            fuente: tipo de letra que se va a utilizar
            color: color del texto que se va a escribir
            center: ubicación de la caja de texto en la pantalla de pygame (pixeles)
        """
        self.fuente = fuente
        self.color = color
        self.center = center
        self.setText(text)

    def setText(self, text):
        self.text = text
        self.surface = self.fuente.render(text, True, self.color)
        self.box = self.surface.get_rect()
        self.box.center = self.center

    def paint(self, screen):
        screen.blit(self.surface, self.box)

class Button():
    def __init__(self, rectangle, fuente, backgroundColor, textColor):
        self.rectangle = rectangle
        self.color = backgroundColor
        self.surface = fuente.render("Guardar", True, textColor)
        self.box = self.surface.get_rect()
        self.box.center = self.rectangle.center

    def paint(self, screen):
        pygame.draw.rect(screen, self.color, self.rectangle)
        screen.blit(self.surface, self.box)

class DialogBox():
    def __init__(self, screen, button, instructionsTextBox, nameTextBox):
        self.screen = screen
        self.button = button
        self.instructionsTextBox = instructionsTextBox
        self.nameTextBox = nameTextBox

    def eventListener(self):
        running = True
        img_name = self.nameTextBox.text
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_BACKSPACE:
                    img_name = img_name[:-1]
                else:
                    img_name += event.unicode
            elif event.type == pygame.MOUSEBUTTONUP:
                if self.button.rectangle.collidepoint(event.pos):
                    root = tk.Tk()
                    root.withdraw()
                    file_path = filedialog.asksaveasfilename(
                        initialfile = self.nameTextBox.text, 
                        defaultextension=".jpg", 
                        filetypes=[("Archivo JPG", "*.jpg")]
                    )
                    if file_path:
                            # Save the image to the selected file path
                        pygame.image.save(self.screen, file_path)
                        img = pygame.image.load(file_path)
                        tablero = pygame.Rect(0,0,500,500)
                        tab_recortado = img.subsurface(tablero)
                        pygame.image.save(tab_recortado, file_path)
                    root.destroy()
        self.nameTextBox.setText(img_name)
        self.paintDialog()
        return running

    def paintDialog(self):
        pygame.draw.rect(self.screen, (250,250,250),(0,500, 500, 80))
        self.nameTextBox.paint(self.screen)
        self.instructionsTextBox.paint(self.screen)
        self.button.paint(self.screen)


class Interface(Node):
    """Crea la interfaz. Hereda de la superclase Node"""

    def __init__(self, screen, board, dialogBox):
        """Cosntructor de la clase interfaz. Crea el nodo 'turtle_bot_interface' y se suscribe al tópico 'turtlebot_position'
        para conocer la posición en tiempo real del robot sobre el entorno de coppelia.
        """
        super().__init__('turtle_bot_interface')

        self.subscription = self.create_subscription(Twist,'turtlebot_position',self.listener_callback,10)

        self.screen = screen
        self.board = board
        self.dialogBox = dialogBox
        
    def listener_callback(self, msg):
        msgx = msg.linear.x
        msgy = msg.linear.y

        '''Revisa que en el caso de tener un evento de tipo QUIT, es decir, que se presione la x en la ventana de
        pygame, esta se cierre cambiando la variable running a false'''
        running = self.dialogBox.eventListener()

        if  running:
            '''Mueve el robot a la posición que viene de Coppelia'''        
            self.board.moveRobot(msgx,msgy)

            '''Actualiza la pantalla de pygame para que aparezca en pantalla el movimiento del robot'''
            pygame.display.flip()
        else:
            print("------> Tratando de destruir <-------")
            pygame.quit()
            self.destroy_node()
            rclpy.shutdown()
            

class App():
    def createDisplay(self, coordinate):
        """Crea la pantalla en la cual se dibuja el recorrido del robot"""
        screen = pygame.display.set_mode(coordinate)
        pygame.display.set_caption("Turtle Bot Interface")
        return screen

    def createPlants(self, color):
        """Crea el arreglo de plantas y les asigna un color.
        
        Args:
            color: color (RGB) con el cual se desea pintar las plantas en la interfaz
        """
        plants = []
        plants.append(Plant((250,150),25,color))
        plants.append(Plant((100,275),25,color))
        plants.append(Plant((400,275),25,color))
        plants.append(Plant((250,350),25,color))
        
        return plants

    def run(self):
        """Inicializa la interfaz de pygame dandole valor a las constantes y creando los diferentes objetos que se dibujan
        en pantalla.
        """

        #CONSTANTS:

        #Tamaño de la pantalla de pygame en pixeles:
        screen_width = 500
        screen_height = 580

        #Colores en RGB:
        White = (255,255,255)
        Black = (0,0,0)
        LigthGrey = (250, 250, 250)
        Grey = (205,205,205)
        Green = (0,143,57)
        Red = (255,0,0)

        #Tamaño del tablero:
        board_size = 500

        #Dimensiones de la cuadricula:
        dimension = 10

        #Se crea una nueva pantalla:
        screen = self.createDisplay((screen_width, screen_height))
        pygame.display.set_caption("Turtle Bot Interface")

        #creamos las fuentes a utilizar:
        pygame.font.init()
        fuente = pygame.font.SysFont("Arial Black",20)
        fuente2 = pygame.font.SysFont("Arial",20)

        #creamos el cuadro de texto para dar indicaciones:
        instructionsTextBox = TextBox("Nombre de Archivo:", fuente, Black, (80, 512))

        #creamos el cuadro de texto en el que se va a guardar el nombre de la imagen:
        nameTextBox = TextBox("", fuente2, Black, (250, 530))

        #Creamos el boton "guardar":
        button = Button(pygame.Rect(200, 550, 100, 25), fuente, Grey, Black)

        #Creamos la lista de plantas y añadimos 4 objetos de tipo planta que recreen las observadas en Coppelia:
        plants = self.createPlants(Green)

        #creamos el objeto tipo robot y lo inicializamos en el centro de la pantalla:
        robot = Robot((board_size/2, board_size/2), 20, Red)

        #creamos el onjeto tipo tablero:
        board = Board(dimension,board_size,White,Grey,plants,robot)

        #Pintamos la escena en la pantalla de pygame creada:
        board.paint(screen)
        nameTextBox.paint(screen)
        instructionsTextBox.paint(screen)
        button.paint(screen)

        dialogBox = DialogBox(screen, button, instructionsTextBox, nameTextBox)
        dialogBox.paintDialog()

        
        rclpy.init()
        interface_node = Interface(screen, board, dialogBox)
        rclpy.spin(interface_node)

        
        interface_node.destroy_node()
        rclpy.shutdown()
        

        running = True
        while running:
            pygame.display.flip()
            running = dialogBox.eventListener()


def main(args=None):
    app = App()
    app.run()

if __name__ == '__main__':
    main()