# Proyecto-TC1031

### Vehicle Inventory Management
Este programa permite gestionar un inventario de vehículos, proporcionando funcionalidades para ordenar el inventario, almacenando y ordenandolos por precio en forma de un árbol Min-Heap. Y permitiéndonos buscar un vehiculo por su precio utilizando una búsqueda secuencial.

### Descripción del Proyecto
El Vehicle Inventory Management es un programa diseñado para manejar un inventario de vehículos, permitiendo agregar vehiculos al inventario conforme al precio, siguiendo una estructura similar a un arbol binario.

### Características
Mostrar inventario completo: Visualiza una lista de vehículos con su precio, color, tipo, marca y año.
Ordenar inventario: Ordena la lista de vehículos por precio.

Búsqueda por precio: Busca un vehículo por su precio utilizando un algoritmo de búsqueda secuencial o iterativa, ya que es facil de implementar en nuestra estructura de datos con forma de Min-Heap, donde el valor mínimo se encontrará siempre en la raíz o la primera línea de nuestro inventario.

Algoritmo de ordenación heapify: El programa utiliza un algoritmo de heapify de tipo Min-Heap, donde de manera recursiva acomoda cada nuevo elemento dentro del arbol, asegurando que esté balanceado.

Todo esto lo decidí ya que fue el último método que vimos en clase, el cual me gustó bastante, me pareció un reto el implementarlo y al permitir organizar los vehiculos en el proceso de agregarlos a nuestro árbol, hace que el funcionamiento del código sea más eficiente y satisfactorio. (Espero que esta vez si le compile)

### Funcionamiento
Al iniciar el programa, se mostrará una lista de opciones a elegir:

1: Agregar Vehiculo

2: Quitar Vehiculo

3: Imprimir Inventario

4: Buscar por precio

5: Salir

Y tal cual lo indica cada opción, nos permite agregar y eliminar vehículos de nuestro inventario (La intención sería agregar un inventario inicial al heap por medio de lectura de archivos, pero en esta entrega a pesar de intentarlo una gran cantidad de veces, no lo pude lograr jaja), para luego mostrarlos ordenados en el inventario en el mismo orden que se encuentran en nuestro arbol.

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp` 
`./a.out` 

### Estructura del Código
main.cpp: Contiene el código principal que interactua con el usuario, muestra el menú, inventario y realiza la busqueda por precio.
Vehiculo.h: Define la clase Vehiculo y los métodos para obtener los datos de cada vehículo (precio, marca, etc.).
Heap.h: Basado en el ejercicio visto en clase, pero adaptado a las necesidades de nuestro proyecto. Administra el heap formado por objetos de la clase vehículo, responsable principal del ordenamiento de nuestro arbol.

### Algoritmos Utilizados
Heap: Se utiliza un heap para almacenar y gestionar el inventario de vehículos. Esto permite insertar y eliminar vehículos de manera eficiente.
Búsqueda Lineal: Dado que el heap no permite búsquedas rápidas por valor, se utiliza una búsqueda lineal para encontrar vehículos en el inventario basado en el precio. Esto tiene una complejidad de O(n).

## Descripción de las entradas del proyecto

El sistema recibe como entradas los siguientes datos sobre los vehículos:

Precio: El precio del vehículo (float).
Color: El color del vehículo (string).
Tipo: El tipo de vehículo (sedán, SUV, camioneta, etc.) (string).
Marca: La marca del vehículo (Toyota, Honda, Audi, etc.) (string).
Año: El año de fabricación del vehículo (int).

## Descripción de las salidas del proyecto

Las salidas del proyecto incluyen:

Inventario de vehículos: Una lista con los vehículos que contiene la información de cada uno: precio, color, tipo, marca y año.
Resultado de eliminación: Un mensaje que indica el vehículo eliminado del inventario.
Resultado de búsqueda: El vehículo que coincide con el precio ingresado por el usuario. Si no se encuentra, se informa que no se encontró ningún vehículo con ese precio.

### Desarrollo de Competencias
## SICT0301: Evalúa los componentes
Análisis de Complejidad
Se realizó un análisis de complejidad correcto y completo para el algoritmo Merge Sort, que tiene una complejidad de O(n log n) en todos los casos. Es un algoritmo estable, ideal para manejar grandes volúmenes de datos en aplicaciones de inventario.

## SICT0302: Toma decisiones
Selección del Algoritmo
La decisión de usar Merge Sort fue la más adecuada para este proyecto, ya que garantiza la eficiencia en la ordenación de los vehículos, lo cual es fundamental para una gestión eficaz del inventario.
