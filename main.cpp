//

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm> // Para std::shuffle
#include <random>  
#include "Personajes.h"
 

int main() {

   //Padre
    // Objeto declarado como personaje
   Personaje Reyloco("Aerys", "Targaryen", "Dragon", 215, "legitimo");
   

    // Imprime el nombre del personaje 1 utilizando el getter
   cout << "\n\nARBOL GENEALOGICO DE LOS TARGERYAN"<<endl;
   cout << "\n\nNombre: " << Reyloco.getNombre() << endl;
   cout << "Casa: " << Reyloco.getCasa() << endl;
   cout << "Animal: " << Reyloco.getAnimal() << endl;
   cout << "Ano de nacimiento: " << Reyloco.getAno_nacimiento() << endl;
   cout << "Linaje: " << Reyloco.getLinaje() << endl;

   //Madre
  
   // Hijos

   Personaje Rhaegar("Rhaegar", "Targaryen", "Dragon",259, "legitimo" );
   Personaje Viserys("Viserys", "Targaryen", "Dragon",276, "legitimo" );
   Personaje Deanerys("Deanerys", "Targaryen", "Dragon",284, "legitimo" );

   //Vector que representa los hijos del rey loco Aerys 
   vector<Personaje*> hijos = {&Viserys, &Rhaegar,&Deanerys};
  

   std::cout << "Informacion de los hijos antes de ordenar:" << std::endl;
   
   Reyloco.printInfo(hijos);
   // se usa el emetodo de ordenamiento 
   Reyloco.bubbleSort(hijos);
   
   std::cout << "Informacion de los hijos despues de ordenar:" << std::endl;
    
   Reyloco.printInfo(hijos);
   

   return 0;

}