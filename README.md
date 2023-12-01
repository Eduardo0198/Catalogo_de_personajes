# *Catalogo de personajes*

### Descripcion del programa
El programa "Catálogo de Personajes" constituye una aplicación en C++ destinada a gestionar información sobre personajes de la serie "Game of Thrones". Utiliza un árbol AVL para optimizar búsquedas y un vector para almacenar y manipular datos de manera eficiente. A través de funciones de lectura y escritura de archivos, el programa carga y guarda información, garantizando consistencia entre las estructuras internas y el archivo de texto. Su funcionalidad principal incluye la búsqueda, adición y eliminación de personajes, todo con el fin de poder simular un porgrama de consulta de informacion que trabaje con archivos txt existentes.
### Formato del Personaje
El formato del personaje se define por Nombre, Casa y Frase. El formato en el que el codigo lo lee, es que no tenga comas y que tenga espacios entre los atributos del personaje. 
```
Nombre Casa Frase
Aerys Targaryen El_rey_loco
Cersei Lannister We_wil_defeat_it
Eddard Stark The_Honourable_Man
Joefrey Baratheon El_peor_rey
Olena Tyrell Tell_Cersei_it_was_me
```
### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
*Ordenamiento (Merge Sort):*
<ul>
  <li>El algoritmo de ordenamiento merge sort se utiliza para ordenar el vector de personajes en tres ocasiones: por nombre, por casa y por frase.</li>
  <li>Complejidad: La complejidad de merge sort es O(n log n), donde n es el número de elementos en el vector. Dado que se realizan 3 tipos de busqueda acorde a los tres atributos del personaje (nombre, casa y frase), se podría expresar como 3 * O(n log n), pero asintóticamente se simplifica a O(n log n)</li>
</ul>

#### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa.

*Estructuras de Datos (Árbol AVL):*
<ul>
  <li>Inserción (add): La inserción en un árbol AVL tiene una complejidad de _O(log n)_ donde n es el número de nodos en el árbol, esta funcion se ocupa para agregar objetos de tipo personaje al arbol AVL y a su vez al archivo txt esto con el fin de que se puedan ir almacenando para despues poder consultarlos.</li>
  <li>Eliminación (remove): La eliminación en un árbol AVL tiene una complejidad de _O(log n)_ , esta funcion se utliza para eliminar nodos del arbol AVL y a su vez eliminarlos del archivo txt.</li>
  <li>Búsqueda (find): La búsqueda en un árbol AVL también tiene una complejidad de _O(log n)_ , esta funcion se utlizo para poder encontrar nodos (objetos de tipo personaje) solo que en el codigo hay 3 funciones con la misma logica pero buscan diferentes atributos del personaje, esto quiere decir que puedes hacer 3 tipos de busqueda, con find (nombre del personaje), findCasa (Apellido del personaje), findFrase 
(Frase del personaje)</li>
</ul>
0omo tal el O(n log n) es la complejidad que define mas al AVL ya sea en sus mejores o peores casos.  

*Busqueda en Vector:*

Se realiza una búsqueda lineal en el vector para determinar la existencia de un personaje al mostrar opciones al usuario.

- Complejidad: La búsqueda lineal tiene una complejidad de O(n), donde n es el tamaño del vector.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
*Complejidad Total:*

- La operación dominante es el ordenamiento del vector de personajes con merge sort, lo que determina la complejidad final del programa: O(n log n). El resto de las operaciones contribuye en menor medida a la complejidad general ya que practicamente todas las acciones del arbol avl son de la misma complejidad que el merge sort.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
*Estructuras de Datos (Árbol AVL):*
Utlice esta estructura de datos ya que era la que mas se acopla a lo que quiero lograr, al inicie intente usar las listas enlazadas pero me di cuenta que era una mejor opcion usar una tipo de arbol, particularmente el AVL. 

- *Búsqueda Eficiente:* Los árboles AVL están diseñados para mantenerse balanceados, lo que garantiza una altura mínima del árbol. Esto se traduce en búsquedas más eficientes con una complejidad de O(log n), donde "n" es el número de elementos en el árbol. Dado que el catálogo de personajes podría crecer, esta eficiencia en las operaciones de búsqueda es crucial.

- *Inserción y Eliminación Eficientes:* La eficiencia en las operaciones de inserción y eliminación también es fundamental para mantener actualizado el catálogo de personajes. Los árboles AVL ajustan automáticamente su estructura durante estas operaciones para mantener el equilibrio, asegurando así un rendimiento eficiente incluso en escenarios de modificación frecuente.

- *Ordenamiento Automático:* Los árboles AVL mantienen una estructura de ordenación intrínseca. Cada nodo en el árbol tiene una relación de orden con sus nodos secundarios. Esto facilita la implementación de operaciones de búsqueda ordenada y recorridos en orden, como se evidencia en las funciones que buscan personajes por nombre, casa y frase.

#### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.

- *Eficiencia:* Merge Sort tiene una complejidad temporal de O(n log n), lo que lo hace eficiente para grandes conjuntos de datos.

- *Estabilidad:* Merge Sort es un algoritmo estable, lo que significa que mantiene el orden relativo de los elementos con claves iguales. En este caso, es importante mantener el orden alfabético de los personajes con el mismo nombre.

- *Aprovecha Mejor las Características de los Vectores:* Merge Sort se adapta bien a las capacidades de dividir y combinar eficientemente en vectores.
  
### SICT0303: Implementa acciones científicas  

#### Implementa mecanismos para consultar información de las estructras correctos.
- En la clase AVL, se tienen funciones específicas para buscar personajes por nombre (find), por casa (findCasa), y por frase (findFrase). Estas funciones utilizan la propiedad de los árboles AVL para realizar búsquedas eficientes.
Estos metodos tienen la misma estructura, lo unico que cambia es el argumento para poder filtrar a los personajes, 
#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
- En el main.cpp, se utiliza un bucle while para leer cada línea del archivo "GoT.txt" con un ifstream.
- La información leída se utiliza para crear objetos de la clase personaje y se agregan tanto al árbol AVL (arbolAVL) como al vector de personajes (catalogo).
#### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta.
- Al agregar un nuevo personaje, se abre el archivo "GoT.txt" en modo ios::app (append) y se escribe el nuevo personaje.
Al eliminar un personaje, se actualiza el archivo escribiendo el contenido actualizado del vector catalogo en el archivo.
Esto asegura que en el txt se pueda visualizar los personajes que sean eliminados o agregados, en el caso de que un personaje nuevo se agregue, este nuevo objeto entra en toda la estrucutra del codigo, es decir que tambien pordrias acceder a el por nombre, casa y frase.
