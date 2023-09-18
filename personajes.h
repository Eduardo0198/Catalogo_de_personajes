
/*
Clase para definir a los personajes de game of thrones
*/

#ifndef PERSONAJES_H_
#define PERSONAJES_H_

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Personaje {
public:
    string nombre; 
    string casa; 
    string emblema; 
    int ano_nacimiento; 
    string linaje; 
    vector<Personaje*> hijos;

    // Constructor
    Personaje(string name, string house, string emblema_, int born_year, string lineage)
        : nombre(name), casa(house), emblema(emblema_), ano_nacimiento(born_year), linaje(lineage) {}

    // Getters para acceder a los atributos
    string getNombre() {
        return nombre;
    }
    string getCasa() {
        return casa;
    }
    string getemblema() {
        return emblema;
    }
    int getAno_nacimiento() {
        return ano_nacimiento;
    }
    string getLinaje() {
        return linaje;
    }

    // Setters para modificar los atributos
    void setNombre(string name) {
        nombre = name;
    }
    void setCasa(string house) {
        casa = house;
    }
    void setemblema(string emblema_) {
        emblema = emblema_;
    }
    void setAno_nacimiento(int born_year) {
        ano_nacimiento = born_year;
    }
    void setLinaje(string lineage) {
        linaje = lineage;
    }

    // Método estático para crear un nuevo personaje
    static Personaje crearpersonaje(string name, string house, string emblema_, int born_year, string lineage) {
        return Personaje(name, house, emblema_, born_year, lineage);
    }
    

   
    void bubbleSort(vector<Personaje*>& vec) {
    size_t n = vec.size();
    for (size_t i = 0; i < n-1; i++) {
        for (size_t j = 0; j < n-i-1; j++) {
            if (vec[j]->getAno_nacimiento() > vec[j+1]->getAno_nacimiento()) {
                swap(vec[j], vec[j+1]);
            }
            }   
        }
    }

 void printInfo( std::vector<Personaje*>& personajes) {
    for ( Personaje* personaje : personajes){
        cout << "Nombre: " << personaje->getNombre() << ", Ano de nacimiento: " << personaje->getAno_nacimiento() << endl;
     }
    }

    
    // Metodo que servia para comparar ambos personajes y comprobar cual es el de mayor edad pero no era un 
    // metodo de ordenamiento 
 /* 
    bool comparador(Personaje* a, Personaje* b) {
        return a->ano_nacimiento < b->ano_nacimiento;

    }
*/
   // Otra funcion que desarrolle donde se ordenaba por edad, sin embargo me parecio mas acertado 
   // de
/*
    void ordenamiento_por_año_de_nacimiento(Personaje& p){

        bool swapped;
        do{
            swapped = false;
            for (size_t i = 0; i < p.hijos.size() - 1; i++) {
                if (p.hijos[i]->ano_nacimiento > p.hijos[i + 1]->ano_nacimiento) {
                std::swap(p.hijos[i], p.hijos[i + 1]);
                swapped = true;
                }   
            }
        }
        while (swapped);
    }
*/

    
};

#endif
