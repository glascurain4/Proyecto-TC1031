# Proyecto-TC1031

### Vehicle Inventory Management System
Este programa permite gestionar un inventario de vehículos, proporcionando funcionalidades para ordenar el inventario por atributos como precio, año o marca, y buscar vehículos por precio utilizando una búsqueda binaria.

### Descripción del Proyecto
El Vehicle Inventory Management System es un programa diseñado para manejar un inventario de vehículos, permitiendo ordenar el inventario basado en diferentes atributos, como el precio, el año del vehículo o la marca. También incluye la funcionalidad de realizar una búsqueda binaria para encontrar un vehículo específico según su precio.

### Características
Mostrar inventario completo: Visualiza una lista de vehículos con su precio, color, tipo, marca y año.
Ordenar inventario: Ordena la lista de vehículos por:
- Precio
- Año
- Marca

Búsqueda binaria por precio: Busca un vehículo por su precio utilizando un algoritmo de búsqueda binaria optimizado.
Algoritmo de ordenación Merge Sort: El programa utiliza el algoritmo Merge Sort para garantizar una ordenación eficiente.

### Funcionamiento
Al iniciar el programa, se mostrará una lista de vehículos en su estado original (sin ordenar).
Luego, se pedirá que selecciones el criterio de ordenamiento:

1: Ordenar por precio.

2: Ordenar por año.

3: Ordenar por marca.

Después del ordenamiento, se mostrará el inventario ordenado según el criterio seleccionado.
Finalmente, se pedirá que ingreses un precio para buscar un vehículo específico.
Si el vehículo existe en el inventario, se mostrará su información.
Si no existe, se notificará que no se encontró el vehículo con el precio buscado.

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp` 
`./a.out` 

### Estructura del Código
main.cpp: Contiene el código principal que gestiona el inventario de vehículos y la lógica de ordenamiento y búsqueda.
Vehiculo.h: Define la clase Vehiculo y los métodos para obtener los datos de cada vehículo (precio, marca, etc.).

### Algoritmos Utilizados
Merge Sort: Utilizado para ordenar el inventario de vehículos de manera eficiente con una complejidad de O(n log n).
Búsqueda Binaria: Se utiliza después de ordenar los vehículos por precio para encontrar rápidamente un vehículo en el inventario basado en su precio, con una complejidad de O(log n).

Aquí están las secciones que faltaban sobre las entradas y salidas del proyecto:

## Descripción de las entradas del proyecto

El sistema recibe como entradas los siguientes datos sobre los vehículos:

- **Precio**: El precio del vehículo (float).
- **Color**: El color del vehículo (string).
- **Tipo**: El tipo de vehículo (sedán, camioneta, etc.) (string).
- **Marca**: La marca del vehículo (Volkswagen, Nissan, Audi, etc.) (string).
- **Año**: El año de fabricación del vehículo (int).

Las entradas pueden ingresarse manualmente en el código o bien ser cargadas desde un archivo de datos.

## Descripción de las salidas del proyecto

Las salidas del proyecto incluyen:

- **Inventario de vehículos**: Una lista con los vehículos que contiene la información de cada uno: precio, color, tipo, marca y año.
- **Inventario ordenado**: La lista de vehículos ordenada por el atributo seleccionado por el usuario (precio, año o marca).
- **Resultado de búsqueda**: El vehículo que coincide con el precio ingresado por el usuario. Si no se encuentra, se informa que no se encontró ningún vehículo con ese precio.

### Desarrollo de Competencias
## SICT0301: Evalúa los componentes
Análisis de Complejidad
Se realizó un análisis de complejidad correcto y completo para el algoritmo Merge Sort, que tiene una complejidad de O(n log n) en todos los casos. Es un algoritmo estable, ideal para manejar grandes volúmenes de datos en aplicaciones de inventario.

## SICT0302: Toma decisiones
Selección del Algoritmo
La decisión de usar Merge Sort fue la más adecuada para este proyecto, ya que garantiza la eficiencia en la ordenación de los vehículos, lo cual es fundamental para una gestión eficaz del inventario.
