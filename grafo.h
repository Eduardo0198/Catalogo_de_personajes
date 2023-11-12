#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "personaje.h"
#include <vector>

struct Nodo {
    Personaje personaje;
    struct Arista* liga_arista;
    struct Nodo* liga_vertice;
};

struct Arista {
    Nodo* vertice;
    int peso;
    struct Arista* liga_arista;
};


class Grafo {
private:
    Nodo* sig_vertice;
    Nodo* ant_vertice;
    Nodo* cab_ver;
    Nodo* dir1;
    Nodo* dir2;

    Nodo* nuevo_vertice(const Personaje& p) {
        Nodo* reg_vertice = new Nodo;
        reg_vertice->personaje = p;
        reg_vertice->liga_vertice = nullptr;
        reg_vertice->liga_arista = nullptr;
        return reg_vertice;
    }

    Nodo* recorrer_vertice(const std::string& nombre) {
        Nodo* dir = nullptr;
        sig_vertice = cab_ver;

        while (sig_vertice != nullptr) {
            if (sig_vertice->personaje.nombre == nombre) {
                dir = sig_vertice;
            }
            sig_vertice = sig_vertice->liga_vertice;
        }
        return dir;
    }

    Arista* nueva_arista(Nodo* vertice, int peso) {
        Arista* reg_arista = new Arista;
        reg_arista->vertice = vertice;
        reg_arista->peso = peso;
        reg_arista->liga_arista = nullptr;
        return reg_arista;
    }

public:
    Grafo() : sig_vertice(nullptr), ant_vertice(nullptr), cab_ver(nullptr), dir1(nullptr), dir2(nullptr) {}

    ~Grafo() {
        // Puedes implementar la liberación de memoria aquí si es necesario
    }

    void insertarVertice(const std::string& nombre) {
        Personaje nuevoPersonaje;
        nuevoPersonaje.nombre = nombre;

        int sw = 0;
        ant_vertice = cab_ver;
        sig_vertice = cab_ver;

        while (sig_vertice != nullptr && sw == 0) {
            if (sig_vertice->personaje.nombre == nuevoPersonaje.nombre) {
                sw = 1;
            } else {
                ant_vertice = sig_vertice;
                sig_vertice = sig_vertice->liga_vertice;
            }
        }

        if (sw == 1) {
            std::cout << "\n\nPersonaje ya existe, no se puede adicionar" << std::endl;
        } else {
            if (cab_ver == nullptr) {
                cab_ver = nuevo_vertice(nuevoPersonaje);
            } else {
                ant_vertice->liga_vertice = nuevo_vertice(nuevoPersonaje);
            }
            std::cout << "Personaje adicionado" << std::endl;
        }
    }

    void insertarArista(const std::string& nombre) {
        Personaje nuevoPersonaje;
        nuevoPersonaje.nombre = nombre;

        int sw2 = 0;
        int pes = 0;
        ant_vertice = nullptr;
        sig_vertice = cab_ver;

        while (sig_vertice != nullptr && sw2 == 0) {
            if (sig_vertice->personaje.nombre == nuevoPersonaje.nombre) {
                sw2 = 1;
            } else {
                ant_vertice = sig_vertice;
                sig_vertice = sig_vertice->liga_vertice;
            }
        }

        if (sw2 == 0) {
            std::cout << "\n\t Nodo destino no existe, revise otra vez" << std::endl;
            return;
        }

        dir1 = ant_vertice;
        dir2 = recorrer_vertice(nombre);

        if (dir1 == nullptr || dir2 == nullptr) {
            std::cout << "\n\t Nodo origen o destino no existe, revise otra vez" << std::endl;
        } else {
            std::cout << "Peso del arista: ";
            std::cin >> pes;
            if (dir1->liga_arista == nullptr) {
                dir1->liga_arista = nueva_arista(dir2, pes);
            } else {
                Arista* temp = dir1->liga_arista;
                while (temp->liga_arista != nullptr) {
                    temp = temp->liga_arista;
                }
                temp->liga_arista = nueva_arista(dir2, pes);
            }
            std::cout << "Arista adicionada" << std::endl;
        }
    }

    void verLista() {
        std::cout << "\n\n Ver lista de personajes y sus relaciones" << std::endl;
        sig_vertice = cab_ver;

        while (sig_vertice != nullptr) {
            std::cout << "\n Nombre: " << sig_vertice->personaje.nombre << std::endl;
            std::cout << " Relaciones: \n";

            Arista* temp = sig_vertice->liga_arista;
            while (temp != nullptr) {
                std::cout << " " << temp->vertice->personaje.nombre << " (Peso: " << temp->peso << ")";
                temp = temp->liga_arista;
            }

            sig_vertice = sig_vertice->liga_vertice;
        }
    }
};

#endif
