# *Catalogo de personajes*

### Descripcion del programa

### Formato del Personaje

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
  <li>Inserción (add): La inserción en un árbol AVL tiene una complejidad de O(log n), donde n es el número de nodos en el árbol, esta funcion se ocupa para agregar objetos de tipo personaje al arbol AVL y a su 
      vez al archivo txt esto con el fin de que se puedan ir almacenando para despues poder consultarlos.</li>
  <li>Eliminación (remove): La eliminación en un árbol AVL tiene una complejidad de O(log n), esta funcion se utliza para poder eliminar personajes del arbol AVL y a su vez eliminarlos del archivo txt.</li>
  <li>Búsqueda (find): La búsqueda en un árbol AVL también tiene una complejidad de O(log n), esta funcion se utlizo para poder encontrar nodos (objetos de tipo personaje) solo que en el codigo hay 3 funciones 
      con la misma logica pero buscan diferentes atributos del personaje, esto quiere decir que puedes hacer 3 tipos de busqueda, con find (nombre del personaje), findCasa (Apellido del personaje), findFrase 
      (Frase del personaje)</li>
   <li>Recorridos (Inorder, Preorder): Realizar recorridos en un árbol AVL tiene una complejidad de O(n), donde n es el número de nodos en el árbol. estas funciones se utilizan para imprimir la información de 
       cada nodo durante la visualización del catálogo completo (6. Mostrar la catalogo completa).</li>
</ul>
Como tal el O(n log n) es la complejidad que define mas al AVL ya sea en sus mejores o peores casos. 

*Busqueda en Vector:*

Se realiza una búsqueda lineal en el vector para determinar la existencia de un personaje al mostrar opciones al usuario.
<ul>
  <li>Complejidad: La búsqueda lineal tiene una complejidad de O(n), donde n es el tamaño del vector.</li>
</ul
  
#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

*Complejidad Total:*

La operación dominante es el ordenamiento del vector de personajes con merge sort, lo que determina la complejidad final del programa: O(n log n). El resto de las operaciones contribuye en menor medida a la complejidad general ya que practicamente todas las acciones del arbol avl son de la misma complejidad que el merge sort.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

#### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructras correctos.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

#### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta.
