//

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm> // Para std::shuffle
#include <random>  
#include "Personajes.h"
 

int main() {

// Árbol genealógico de Viserys con su primera esposa Aemma Arryn
   Personaje Vyserys("Vyserys", "Targaryen", "Dragon", 77, "legitimo");
   Personaje Aemma("Aemma", "Arryn", "Halcon", 82, "legitimo");
// Rhaenyra y sus hijos Leanor Velatyon y con Daemon
// Bastardos de Harwin StronG
   Personaje Rhaenyra("Rhaenyra", "Targaryen", "Dragon", 97, "legitimo");
   Personaje Laenor("Laenor", "Velaryon", "Caballo de mar", 94, "legitimo");
   Personaje Daemon("Demon", "Targaryen", "Dragon", 81, "legitimo");
 //Personaje Harwin("Harwin", "Strong", "Dragon", 81, "legitimo");
// hijos de reahynra 
   Personaje Jacaerys("Jacaerys", "Targaryen", "Dragon", 114, "bastardo Strong");
   Personaje Lucerys("Lucerys", "Targaryen", "Dragon", 115, "bastardo Strong");
   Personaje Joffrey("Joffrey", "Targaryen", "Dragon", 117, "bastardo Strong");
   Personaje Aegon_III("Aegon III", "Targaryen", "Dragon", 120, "legitimo");
   Personaje Viserys_II("Viserys II", "Targaryen", "Dragon", 122, "legitimo");
   Personaje Visenya("Visenya", "Targaryen", "Dragon", 129, "legitimo");
////////////////////////////////////////////////////////////////////////
// Árbol genealógico de Viserys con su segunda esposa Alicent Hightower
   Personaje Otto("Otto", "Hightower", "Faro de Oldtown", 71, "legitimo");
   Personaje Alicent("Alicent", "Hightower", "Faro de Oldtown", 88, "legitimo");
// Hijos de Alicent
   Personaje Aegon_II("Aegon", "Targaryen", "Dragon", 107, "legitimo");
   Personaje Helaena("Healena", "Targaryen", "Dragon", 109, "legitimo");
   Personaje Aemon("Aemon", "Targaryen", "Dragon", 110, "legitimo");
   Personaje Daeron("Daeron", "Targaryen", "Dragon", 114, "legitimo");
   

   std::vector<Personaje*> hijos_viserys_aemma = {&Rhaenyra};
   std::vector<Personaje*> hijos_rhaenyra_laenor = {&Jacaerys, &Lucerys, &Joffrey};
   std::vector<Personaje*> hijos_rhaenyra_daemon = {&Aegon_III, &Viserys_II, &Visenya};



   return 0;

}