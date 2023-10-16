/*
* Autor: jeviverose
* Clase Personaje
*
*/

#ifndef PERSONAJES_H_
#define PERSONAJES_H_
#include <iostream>
#include <string>
#include <vector>

#include <fstream>

class personaje {    
    public:
    std::string nombre; 
    std::string casa; 
    std::string emblema; 
    int ano_nacimiento; 
    std::string linaje; 
    std::vector<personaje*> hijos;

    
    Personaje::Personaje(const std::string& nombre, const std::string& casa, const std::string& biografia)
         :nombre(nombre), casa(casa), biografia(biografia), padre(nullptr) {}

    void Personaje::agregarHijo(Personaje* hijo) {
         hijos.push_back(hijo);
         hijo->padre = this;
};



#endif
