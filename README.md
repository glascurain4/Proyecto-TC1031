# Proyecto-TC1031

### Vehicle Inventory Management
Este programa permite gestionar un inventario de vehículos, proporcionando funcionalidades para ordenar el inventario, almacenando y ordenandolos por precio en forma de un árbol Min-Heap. Y permitiéndonos buscar un vehiculo por su precio utilizando una búsqueda secuencial.

## Descripción del avance 1
En el primer avance desarrollamos un prototipo para el funcionamiento de este proyecto donde se hacía uso de un vector de objetos tipo Auto, aplicando el MergeSort para el ordenamiento del inventario bajo diferentes criterios como precio, año y marca. Utilizando búsqueda iterativa para encontrar una unidad en particular al ingresar el precio buscado.

## Descripción del avance 2
En el segundo avance cambiamos la estructura de datos de nuestro inventario, moviéndonos a un árbol de tipo Min-Heap, aprovechando sus propiedades y modificando ligeramente la funcion de heapify() para realizar un ordenamiento de los vehículos en base a su precio. Ordenando nuestro inventario a la vez que está siendo agregado y nuevamente implementando la búsqueda iterativa.

# Cambios sobre el primer avance

Cambio 1: MergeSort por Min-Heap. A pesar de ambos compartir la complejidad O(nlog(n)) en su caso promedio, el Min-Heap es más eficiente de ser necesario acceder más frecuentemente a los vehículos más baratos (O(1) en caso del más barato) y de requerir actualizaciones constantes del inventario, eliminando y agregando vehiculos constantemente. Considero que es un enfoque más apropiado para el propósito y uso del proyecto.

### Descripción del Proyecto
El Vehicle Inventory Management es un programa diseñado para manejar un inventario de vehículos, permitiendo agregar vehiculos al inventario conforme al precio, siguiendo una estructura similar a un arbol binario.

Búsqueda por precio: Busca un vehículo por su precio utilizando un algoritmo de búsqueda iterativa, ya que es facil de implementar en nuestra estructura de datos con forma de Min-Heap, donde el valor mínimo se encontrará siempre en la raíz o la primera línea de nuestro inventario.

Algoritmo de ordenación heapify: El programa utiliza un algoritmo de heapify de tipo Min-Heap, donde de manera recursiva acomoda cada nuevo elemento dentro del arbol, asegurando que esté balanceado.

### Funcionamiento
Al iniciar el programa, se mostrará una lista de opciones a elegir:

1: Agregar Vehiculo

2: Quitar Vehiculo

3: Imprimir Inventario

4: Buscar por precio

5: Salir

Y tal cual lo indica cada opción, nos permite agregar y eliminar vehículos de nuestro inventario (inicializado con lectura de archivos), para luego mostrarlos ordenados en el inventario en el mismo orden que se encuentran en nuestro arbol.

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ -std=c++11 main.cpp` 
`./a.out` 

## Descripción de las entradas del proyecto

El sistema recibe como entradas los siguientes datos sobre los vehículos:

Precio: El precio del vehículo (float)

Color: El color del vehículo (string)

Tipo: El tipo de vehículo (sedán, SUV, camioneta, etc.) (string)

Marca: La marca del vehículo (Toyota, Honda, Audi, etc.) (string)

Año: El año de fabricación del vehículo (int)

El programa utiliza lectura de archivos para cargar vehículos en grandes cantidades desde un archivo,
a su vez el programa le da al usuario la opción de agregar y quitar vehículos del inventario por medio de una interfaz que le da varias opciones a seleccionar y procede a pedirle las caracteristicas del vehiculo en cuestión.

## Descripción de las salidas del proyecto

Las salidas del proyecto incluyen:

Inventario de vehículos: Una lista con los vehículos que contiene la información de cada uno: precio, color, tipo, marca y año.

Resultado de eliminación: Un mensaje que indica el vehículo eliminado del inventario.

Resultado de búsqueda: El vehículo que coincide con el precio ingresado por el usuario. Si no se encuentra, se informa que no se encontró ningún vehículo con ese precio.

### Desarrollo de Competencias

## SICT0301: Evalúa los componentes

### Heapify (usado en la clase `Heap` para mantener el orden del min-heap)
- **Heapify** se utiliza para mantener las propiedades de un min-heap. En cada operación `add` o `remove`, se llama `heapify` para reajustar la posición de los elementos, lo cual tiene una complejidad de:
  - **Mejor caso**: \(O(1)\) si el elemento a ajustar ya está en la posición correcta.
  - **Caso promedio**: \(O(\log n)\), dado que en promedio el elemento debe desplazarse una cantidad de niveles equivalente al logaritmo de la cantidad de nodos.
  - **Peor caso**: \(O(\log n)\), en el que un elemento debe moverse desde la raíz hasta el último nivel del árbol.

### Comparación con Merge Sort
- **Merge Sort**, en cambio, tiene una complejidad constante en todos los casos: \(O(n \log n)\). Esto es menos eficiente en comparación con el min-heap en el mejor y promedio de los casos, ya que el min-heap puede obtener y eliminar el valor mínimo con \(O(1)\) acceso y \(O(\log n)\) para las operaciones de ajuste, lo cual lo hace más adecuado para sistemas que necesitan operaciones dinámicas y acceso rápido al mínimo, siendo el caso de nuestro poryecto al requerir actualizaciones dinámicas del inventario y al ser los vehículos de menor precio aquellos más revisados por los clientes y los mismos que se venden más rápido.

### 2. **Análisis de Complejidad de Estructuras de Datos**

#### Min-Heap (`Heap<T>`)
- **Inserción (`add`)**: 
  - **Mejor caso**: \(O(1)\) si el nuevo elemento es el mayor y no requiere ajustes.
  - **Caso promedio**: \(O(\log n)\), dado que en promedio el elemento necesita ser ajustado varias posiciones hasta alcanzar la correcta.
  - **Peor caso**: \(O(\log n)\), donde el elemento insertado necesita moverse desde una posición inferior hasta la raíz.

- **Eliminación (`remove`)**:
  - **Mejor caso**: \(O(\log n)\), ya que la eliminación del nodo mínimo (raíz) siempre requiere un ajuste en la estructura del heap.
  - **Caso promedio y peor caso**: \(O(\log n)\), ya que en el peor escenario el elemento movido a la raíz necesitará ser reajustado hasta las hojas.

- **Acceso al mínimo**: \(O(1)\) en todos los casos, porque el menor elemento está siempre en la raíz del heap, lo cual es útil para inventarios en los que el producto más económico tiende a venderse más rápido.

#### Vector de Datos (`data`)
- El arreglo `data` de la clase `Heap` actúa como una estructura contenedora interna. Acceder a un elemento específico en este arreglo tiene una complejidad constante, \(O(1)\). Sin embargo, el acceso secuencial para operaciones como `ImprimeInventario` y `BuscarVehiculoPorPrecio` tiene una complejidad de \(O(n)\), ya que debe recorrer todos los elementos.

### 3. **Análisis de Complejidad de Otros Componentes**

#### Búsqueda de Vehículo por Precio (`BuscarVehiculoPorPrecio`)
- Este método recorre todo el arreglo para encontrar coincidencias en el precio, por lo cual:
  - **Mejor caso**: \(O(1)\) si el primer vehículo coincide con el precio.
  - **Caso promedio y peor caso**: \(O(n)\) si debe recorrer el arreglo completo para encontrar el precio o confirmar su ausencia.
  
#### Imprimir Inventario (`ImprimeInventario`)
- Imprimir todo el inventario implica recorrer el arreglo completo y mostrar la información de cada vehículo, resultando en:
  - **Complejidad**: \(O(n)\) porque cada uno de los \(n\) elementos debe ser procesado.

### 4. **Complejidad Final del Programa**

Al considerar el flujo principal del programa, la complejidad global dependerá del uso de `Heap`. Ya que el programa efectúa una secuencia de operaciones de inserción, eliminación y búsqueda, la complejidad final del programa sería:

- **Complejidad para acceso rápido al menor precio**: \(O(1)\)
- **Inserción y eliminación de elementos**: \(O(\log n)\) para cada operación.
- **Búsqueda en el inventario por precio**: \(O(n)\)

## SICT0302: Toma decisiones

#### Selección del Algoritmo de Ordenamiento

Dado que los vehículos nás económicos suelen tener una mayor demanda y tienden a venderse rápidamente, resulta fundamental mantener un acceso inmediato a los elementos de menor precio. A diferencia de Merge Sort, que organiza una lista de manera estática y requiere una complejidad de \(O(n \log n)\) en el mejor, promedio y peor de los casos, un Min-Heap permite un acceso (\(O(1)\)) al elemento mínimo (el vehículo más económico en este caso), mientras que asegura una inserción y eliminación en tiempo logarítmico (\(O(\log n)\)).

- **Eficiencia en Acceso**: Con el Min-Heap, el vehículo de menor precio siempre se encuentra en la raíz, lo que permite un acceso inmediato y directo a este valor, optimizando los procesos de consulta y venta.
- **Adaptabilidad a Cambios Dinámicos**: Dado que el inventario está en constante cambio, el Min-Heap mantiene su estructura sin requerir una reorganización completa tras cada modificación. La operación de ordenamiento es continua y se ajusta tras cada inserción o eliminación, adaptándose al flujo constante de cambios en el inventario.

#### Selección de la Estructura de Datos

La estructura de Min-Heap fue elegida específicamente por su alineación con las necesidades del inventario:

1. **Acceso Prioritario al Mínimo**: Como se espera que el vehículo de menor precio sea el más solicitado y consultado, el Min-Heap proporciona acceso al elemento más económico en \(O(1)\), lo cual mejora la eficiencia en un contexto de ventas.
2. **Soporte para Actualización Dinámica**: Con una complejidad de \(O(\log n)\) para las operaciones de inserción y eliminación, el Min-Heap facilita la actualización constante del inventario sin tener que reordenar la lista completa, manteniendo siempre el mínimo en la raíz.

## SICT0303: Implementa acciones científicas

Considero que aprendí a utilizar correctamente los diferentes mecanismos de consulta de información para las estructuras de datos aprendidas en clase, ya que fui capaz de escoger entre diferentes opciones aquella que más se adoptara no solo a la eficiencia en el manejo de inventarios de manera general, sino comprendiendo el uso real que se le daría a un código de esta naturaleza y adaptando el poryecto en esa vía, pensando en la manera en la que el código será utilizado y haciéndolo lo más eficiente bajo mis conocimientos y habilidades para funcionar de dicha manera.

Creo que luego de muchos  intentos y mucho esfuerzo y mucho código que la verdad ni yo sé como logré que funcionara, considero que hice una buena implementación de la lectura de archivos, aprovechando los try y catches para prevenir la mayoría de errores que encontré que podían haber al leer el mismo. Finalmente conseguí que funcionara apropiadamente y estoy satisfecho con el resultado. 

#### Pendiente
Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.