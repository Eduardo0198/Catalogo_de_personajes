

#include "personaje.h"
#include "avl.h"
//#include "node.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main() {

    AVL<personaje> arbolAVL; // Creo una instancia de clase AVL para almacenar los personajes en un árbol AVL   
    vector<personaje> catalogo; // Creo un vector para almacenar todos los personajes

    ifstream archivo("GoT.txt");

    if (!archivo) {
        cout << "No se pudo abrir archivo" << endl;
        return 1;
    }
    string linea;
    // Complejidad O(n), siendo n el número de líneas que tiene el archivo
    while (getline(archivo, linea)) {
        istringstream ss(linea);
        string Nombre, Casa, Frase;
        if (ss >> Nombre >> Casa >> Frase) {
            // Agregar personajes dentro del árbol AVL es de una complejidad O(log n)
            arbolAVL.add(personaje(Nombre, Casa, Frase));
            // Agregar personajes dentro del vector es de una complejidad O(n)
            catalogo.push_back(personaje(Nombre, Casa, Frase));
        } else {
            cout << "Error al leer una línea del archivo" << endl;
        }
    }
    archivo.close();

    int opcion;
    bool salir = false;

    while (!salir) {
        cout << "\n----CATALOGO DE PERSONAJES----" << endl;
        cout << endl << "Elige la opcion de busqueda: " << endl;
        cout << "1. Buscar personaje por Nombre" << endl;
        cout << "2. Buscar personaje por Casa" << endl;
        cout << "3. Buscar personaje por Frase" << endl;
        cout << "4. Agregar personaje" << endl;
        cout << "5. Eliminar personaje" << endl;
        cout << "6. Mostrar la catalogo completa" << endl;
        cout << "7. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Muestro Títulos disponibles
                cout << "Personajes disponibles: " << endl << endl;
                // La complejidad de ordenamiento que se está haciendo es de O(n log n)
                mergeSort(catalogo, 0, catalogo.size() - 1, [](const personaje &a, const personaje &b) {
                    return a.getNombre() < b.getNombre();
                });

                for (const personaje &personaje : catalogo) {
                    cout << "* " << personaje.getNombre() << endl << endl;
                }
                // Se hace la búsqueda 
                cout << "Introduce personaje a buscar: " << endl;
                string NombreBuscado;
                cin >> NombreBuscado;

                personaje personajeBuscado(NombreBuscado, "", "");
                vector<personaje> personajesEncontrados; 
                // La operación de búsqueda dentro de un árbol AVL es de complejidad O(log n)
                arbolAVL.getpersonajesNombre(NombreBuscado, personajesEncontrados);
                // Muestra los personajes encontrados
                if (!personajesEncontrados.empty()) {
                    cout << "personaje encontrado por nombre: " << NombreBuscado << endl << endl;
                    for (const personaje &personaje : personajesEncontrados) {
                        cout << personaje << endl << endl;
                    }
                } else {
                    cout << "No se encontro el personaje" << endl;
                }
                break;
            }

            case 2: {
                // Muestro Casaes disponibles
                cout << "Casas disponibles: " << endl << endl;
                mergeSort(catalogo, 0, catalogo.size() - 1, [](const personaje &a, const personaje &b) {
                    return a.getCasa() < b.getCasa();
                });

                string ultimoCasa = "";
                for (const personaje &personaje : catalogo) {
                    if (personaje.getCasa() != ultimoCasa) {
                        cout << "* " << personaje.getCasa() << endl << endl;
                        ultimoCasa = personaje.getCasa();
                    }
                }

                // Se hace la búsqueda 
                cout << "Introduce la casa a buscar: " << endl;
                string casaBuscado;
                cin >> casaBuscado;

                personaje casapersonaje("", casaBuscado, ""); // objeto temporal
                vector<personaje> personajesEncontrados; 

                arbolAVL.getpersonajesCasa(casaBuscado, personajesEncontrados);

                // Muestra los personajes encontrados
                if (!personajesEncontrados.empty()) {
                    cout << "personaje encontrado por Casa: " << casaBuscado << endl;
                    for (const personaje &personaje : personajesEncontrados) {
                        cout << personaje << endl;
                    }
                } else {
                    cout << "No se encontraron personajes de ese Casa" << endl;
                }
                break;
            }

            case 3: {
            // Muestro Frases disponibles
            cout << "Frases disponibles: " << endl << endl;
            mergeSort(catalogo, 0, catalogo.size() - 1, [](const personaje &a, const personaje &b) {
                   return a.getFrase() < b.getFrase();
            });

            string ultimaFrase = "";
            for (const personaje &personaje : catalogo) {
            if (personaje.getFrase() != ultimaFrase) {
                cout << "* " << personaje.getFrase() << endl << endl;
                ultimaFrase = personaje.getFrase();
                }
            }

            // Se hace la búsqueda 
            cout << "Introduce la frase a buscar: " << endl;
            string FraseBuscada;
            cin.ignore();  // Agregado para manejar el salto de línea pendiente
            getline(cin, FraseBuscada);

            vector<personaje> personajesEncontradosPorFrase;

            arbolAVL.getpersonajesFrase(FraseBuscada, personajesEncontradosPorFrase);

            // Muestra los personajes encontrados
            if (!personajesEncontradosPorFrase.empty()) {
               cout << "personaje encontrado por frase: " << FraseBuscada << endl;
        for (const personaje &personaje : personajesEncontradosPorFrase) {
            cout << personaje << endl << endl;
        }
    } else {
        cout << "No se encontraron personajes con esa frase" << endl;
    }
    break;
}


            case 4: {
                string nuevoNombre, nuevoCasa, nuevaFrase;
                cout << "Ingrese el Nombre del personaje nuevo: ";
                cin.ignore();
                getline(cin, nuevoNombre);
                cout << "Ingrese la Casa del personaje nuevo: ";
                getline(cin, nuevoCasa);
                cout << "Ingrese la Frase del personaje nuevo: ";
                getline(cin, nuevaFrase);

                ofstream archivo("personajes.txt", ios::app);
                if (archivo.is_open()) {
                    archivo << nuevoNombre << " " << nuevoCasa << " " << nuevaFrase << endl;

                    cout << "personaje agregado correctamente" << endl;
                    archivo.close();
                } else {
                    cout << "Error al abrir archivo" << endl;
                }

                personaje nuevopersonaje(nuevoNombre, nuevoCasa, nuevaFrase);
                arbolAVL.add(nuevopersonaje);
                catalogo.push_back(nuevopersonaje);
                break;
            }

            case 5: {
                string NombreEliminar;
                cout << "Ingrese el Nombre del personaje a eliminar: ";
                cin.ignore();
                getline(cin, NombreEliminar);

                if (arbolAVL.find(personaje(NombreEliminar, "", ""))) {
                    // Elimino personaje del árbol
                    arbolAVL.remove(personaje(NombreEliminar, "", ""));
                } else {
                    cout << "personaje no encontrado" << endl;
                }

                // Buscar el personaje en el vector catalogo
                auto it = find_if(catalogo.begin(), catalogo.end(), [NombreEliminar](const personaje &personaje) {
                    return personaje.getNombre() == NombreEliminar;
                });

                if (it != catalogo.end()) {
                    // Eliminar el personaje del vector catalogo
                    catalogo.erase(it);
                } else {
                    cout << "personaje no encontrado en el catalogo." << endl;
                }

                // Eliminar del archivo de texto
                ofstream archivo("personajes.txt");
                if (archivo.is_open()) {
                    bool personajeEncontrado = false; // Variable para verificar si se encontró el personaje

                    for (const personaje &personaje : catalogo) {
                        if (personaje.getNombre() == NombreEliminar) {
                            personajeEncontrado = true;
                            continue; // No escribe el personaje que se quiere eliminar en el archivo
                        }

                        archivo << personaje.getNombre() << " " << personaje.getCasa() << " " << personaje.getFrase() << endl;
                    }

                    archivo.close();

                    if (!personajeEncontrado) {
                        cout << "personaje eliminado" << endl;
                    } else {
                        cout << "personaje no encontrado. No se ha eliminado del archivo." << endl;
                    }
                } else {
                    cout << "Error al abrir archivo" << endl;
                }

                break;
            }

            case 6: {
                cout << "Catalogo completado: " << endl;
                mergeSort(catalogo, 0, catalogo.size() - 1, [](const personaje &a, const personaje &b) {
                    return a.getNombre() < b.getNombre();
                });
                for (const personaje &personaje : catalogo) {
                    cout << personaje << endl;
                }
                break;
            }

            case 7: // salida
                salir = true;
                cout << "Saliendo del programa" << endl;
                break;

            default:
                cout << "Opcion inválida" << endl;
        }
    }

    return 0;
}