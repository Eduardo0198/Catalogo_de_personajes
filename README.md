# *Catalogo de personajes*

El programa simula las relaciones que existen en un arbol genealogico, esto se puede lograr atreves de los grafos, estos son mas sencillos de usar pues los nodos de un grafo son mas faciles de manipular para poder crear relaciones complejas. Ya que el programa trata de simular a la Casa Targeryan de la serie de TV de Game of Thrones y House of the Dragon, podemos darnos cuentas que las relaciones familiares tienden ser mas complejas de lo habitual.

Esto funcionaria de la siguiente manera.
Hay dos tipo de Nodos, uno que representa al Hombre y el otro a la mujer, dichos nodos se podran conectar atraves de arcos con distintos pesos, ya que en un arbol genalogico so representan las relaciones de conyuge y de hijos, decidi tener un diferenciador en el peso de los arcos: 

- a) 1 representara la relacion de conyuge entre un nodo mujer y un nodo hombre
- b) 2 representara la relacion de hijos, en este caso solo un nodo mujer es quien se podra enlazar a mas nodos

Esto se leeria atraves de los archivos txt, para esto abria un formato en especifico en el que los personajes se relacionen, es decir que si quieres que los personajes sean acamodados de una manera en especifico primero necesitamos establecerlo en el archivo txt, un ejemplo claro que se puede ver seria  el siguiete. 

```
Nombre, Casa, Sexo, Conyuge, Biografia
Deanerys, Targeryan, F, Jon, Madre de Dragones y rompededora de cadenas
Jon, Stark, M, Deanerys, El principe que fue prometido
Tryion, Lanister, M, Sansa, La mano de la reina
```
Los cinco atributos de los personajes serian Nombre, casa, sexo, conyuge y biografia. Puede haber personajes que no sean tan importantes para el arbol genealogico de los Targeryan o simplemente no nos interesen tanto sus atributos, mas haya del nombre, sexo y casa. En dado caso lo que hariamos seria:
```
Nombre, Casa, Sexo, Conyuge, Biografia
Ramsey, Bolton, M, null, El bastardo de fuerte terror
Walder, Frey, M, null, null
```
Por ahora parte delo proyecto solo tiene como tal la base de la logica, es decir falta agregar un metodo de lectura de archivos para que este pueda obtener datos y poder ordenarlos
