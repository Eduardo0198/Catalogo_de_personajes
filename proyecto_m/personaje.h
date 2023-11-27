

#ifndef PERSONAJE_H_
#define PERSONAJE_H_

#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class personaje{

  private:
    string Nombre; //nombre
    string Casa; //Casa
    string Frase; //frase
    int Seleccion;

  public:

    personaje();
    personaje(const string& Nombre, const string& Casa, const string& Frase); //Constructor
    string getNombre() const; // obtenemos nombre
    string getCasa() const; // obtenemos casa
    string getFrase() const; // obtenemos frase
    void Fichapersonaje() const; // Método para mostrar datos del personaje
    bool operator <= (const personaje& otro)const; // Operador de comparación personalizado
    bool operator < (const personaje& otro) const;
    bool operator > (const personaje& otro) const;
    bool operator == (const personaje& otro) const;
    friend ostream& operator<<(ostream& os, const personaje& personaje);
    int getSeleccion() const;
};


personaje::personaje(){

}

personaje::personaje(const string& Nombre, const string& Casa, const string& Frase){
  this->Nombre = Nombre;
  this-> Casa = Casa;
  this -> Frase = Frase;
}

string personaje::getNombre() const{
  return Nombre;
}

string personaje::getCasa() const{
  return Casa;
}

string personaje::getFrase() const{
  return Frase;
}

// Metodo para poder imprimir personaje
void personaje::Fichapersonaje() const{
  cout << "Nombre: " << Nombre << " | Casa: " << Casa << " | Frase: " << Frase << endl;
}
//Falta modificarlo para que también se pueda hacer comparación con el título del personaje
bool personaje::operator<=(const personaje& otro) const{
  return (*this < otro) || (*this == otro);
}

bool personaje::operator<(const personaje& otro) const {
  if(Nombre != otro.Nombre)
    return Nombre < otro.Nombre;
  if (Casa != otro.Casa)
    return Casa < otro.Casa;
  return Frase < otro.Frase;
}

bool personaje::operator>(const personaje& otro) const {
  return !(*this <= otro);
}

bool personaje::operator==(const personaje& otro) const {
  return Nombre == otro.Nombre && Casa == otro.Casa && Frase == otro.Frase;
}

ostream& operator<<(ostream& os, const personaje& personaje) {
    os << "Nombre: " << personaje.getNombre() << " | Casa: " << personaje.getCasa() << " | Frase: " << personaje.getFrase();
    return os;
}

int personaje::getSeleccion() const{
  return Seleccion;
}

//Este método merge tiene una complejidad de O(n), siendo n el tamaño total de los dos subvectores ordenados, recorriendo ambos y colocandolos en orden en el vector final.
void merge(std::vector<personaje> &v, int izquierda, int mitad, int derecha, std::function<bool(const personaje&, const personaje&)> comparador){

  int n1 = mitad - izquierda + 1;
  int n2 = derecha - mitad;

  std::vector<personaje> Izq(n1);
  std::vector<personaje> Der(n2);

  //Complejidad de los ciclos for O(n), ya que va a realizar n iteraciones
  for(int i = 0; i < n1; i++){ 
    Izq[i] = v[izquierda + i];
  }
  for(int j = 0; j < n2; j++){ 
    Der[j] = v[mitad + 1 + j];
  }

  int i = 0, j = 0, k = izquierda;

  //También la complejidad de los while sería de O(n) realizando como maximo las n compraciones de los n elementos.
  while(i < n1 && j < n2){
    if(comparador(Izq[i], Der[j])){
      v[k] = Izq[i];
      i++;
    }
    else{
      v[k] = Der[j];
      j++;
    }
    k++;
  }

  while(i < n1){
    v[k] = Izq[i];
    i++;
    k++;
  }

  while(j < n2){
    v[k] = Der[j];
    j++;
    k++;
  }
}

//Este método sólo, sin tomar en consideración el conjunto con merge es de una compeljidad de O(log n), realizándose dos llamadas recursivas. 
//Es por ello que al juntar mergeSort con merge, su combinación nos da una complejidad final de O(n log n).
void mergeSort(std::vector<personaje> &v, int izquierda, int derecha, std::function<bool(const personaje&, const personaje&) > comparador) {
    if (izquierda < derecha) {
        int middle = izquierda + (derecha - izquierda) / 2;
        mergeSort(v, izquierda, middle, comparador);
        mergeSort(v, middle + 1, derecha, comparador);
        merge(v, izquierda, middle, derecha, comparador);
    }
  
}


#endif /* personaje_H_ */