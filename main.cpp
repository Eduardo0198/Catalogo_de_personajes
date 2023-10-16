/*
* Autor: jeviverose
* Clase Arbol
*
*/

#ifndef ARBOL_H_
#define ARBOL_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "personaje.h"

class arbolgenealogico {
public:
    personaje* raiz;

    arbolgenealogico();

    // Cargar datos desde un archivo 
    void cargarDesdeArchivo(const std::string& archivo);

    // Buscar un personaje en el árbol
    void buscarPersonaje(const std::string& nombre);

    // Imprimir el árbol genealógico
    void imprimirArbol();

    // Agregar un personaje al árbol
    void agregarPersonaje(personaje* personaje);

    arbolgenealogico::arbolgenealogico() : raiz(nullptr){
    }

    void arbolgenealogico::cargarDesdeArchivo(const std::string& archivo){
    }

    void arbolgenealogico::buscarPersonaje(const std::string& nombre) {
    }

    void arbolgenealogico::imprimirArbol() {
    }
    
    void arbolgenealogico::agregarPersonaje(personaje* personaje) {
    if (raiz == nullptr) {
        raiz = personaje;
    } 
    else {}
    
    }
};
#endif
