
#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <vector>


struct Personaje {
    
    std::string nombre;
    std::string casa;
    char sexo;
    std::string conyuge;
    std::string biografia;
    std::vector<Personaje> hijos;
};

#endif

