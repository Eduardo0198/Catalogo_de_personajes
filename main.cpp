/*
* Autor: jeviverose
* Main
*
*/

#include <iostream>
#include "arbolgenealogico.h"
#include "personaje.h"

int main() {

    
    arbolgenealogico arbol;

    // Cargar datos desde un archivo 
    arbol.cargarDesdeArchivo("datos.txt");

    // Implementar la interfaz de usuario
    int opcion;
    do {
        std::cout << "1. Buscar personaje\n";
        std::cout << "2. Imprimir árbol\n";
        std::cout << "3. Salir\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Introduce el nombre del personaje a buscar: ";
                std::string nombre;
                std::cin >> nombre;
                arbol.buscarPersonaje(nombre);
                break;
            case 2:
                arbol.imprimirArbol();
                break;
            case 3:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 3);

    return 0;
}
