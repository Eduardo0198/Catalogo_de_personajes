
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "grafo.h"
#include "personaje.h"

int main() {
    Grafo grafo;
    std::string dato_origen;
    std::string dato_destino;
    int opcion;

    do {
        std::cout << "\n\t Menu: " << std::endl;
        std::cout << "1. Crear vertices " << std::endl;
        std::cout << "2. Crear aristas " << std::endl;
        std::cout << "3. Mostrar grafo " << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "\nOpcion: " << std::endl;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Digite un numero para el vertice: " << std::endl;
                std::cin >> dato_origen;
                grafo.insertarVertice(dato_origen);
                system("pause");
                break;
            case 2:
                std::cout << "Digite el nodo origen: " << std::endl;
                std::cin >> dato_origen;
                std::cout << "Digite el nodo destino: " << std::endl;
                std::cin >> dato_destino;
                grafo.insertarArista(dato_destino);
                system("pause");
                break;
            case 3:
                grafo.verLista();
                std::cout << "  " << std::endl;
                system("pause");
                break;
        }
        system("cls");
    } while (opcion != 4);

    return 0;
}
