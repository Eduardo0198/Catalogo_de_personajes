
/*************************
 Catalogo de personajes
 avl.h
 Autor: Eviveroe
 A01710605
 *************************/

#ifndef AVL_H_
#define AVL_H_

#include "node.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template <class T> class AVL {
private:
  Node<T> *root;


public:
  AVL();
  ~AVL();
  void add(T);
  bool find(T) const;
  bool findCasa(T) const;
  bool findFrase(T) const;
  void remove(T);
  void removeAll();
  void getpersonajesNombre(const string& Nombre, vector<T>& resultados);
  void getpersonajesNombre(Node<T>* node, const string& Nombre, vector<T>& resultados);

  void getpersonajesCasa(const string& casa, vector<T>& resultados);
  void getpersonajesCasa(Node<T>* node, const string& casa, vector<T>& resultados);

  void getpersonajesFrase(const string& frase, vector<T>& resultados);
  void getpersonajesFrase(Node<T>* node, const string& frase, vector<T>& resultados);
};

template <class T> AVL<T>::AVL() : root(0) {}

template <class T> AVL<T>::~AVL() { removeAll(); }

template <class T> void AVL<T>::add(T val) {
  if (root != 0) {
    if (!root->find(val)) {
      Node<T> *temp;
      T check_val = personaje("Nombre", "Casa", "Frase");
      bool aux = false;
      root->add(val);
      root->max_depth();
      temp = root->check_tree(&check_val, 0, &aux);
      if (check_val == root->value) {
        root = temp;
      }
      root->max_depth();
    }
  } else {
    root = new Node<T>(val);
  }
}

template <class T> void AVL<T>::remove(T val) {
  if (root != 0) {
    if (val == root->value) {
      Node<T> *succ = root->predecesor();
      if (succ != 0) {
        succ->left = root->left;
        succ->right = root->right;
      }
      delete root;
      root = succ;
    } else {
      root->remove(val);
    }
    root->max_depth();
    Node<T> *temp;
    T check_val = personaje("Título", "Casa", "Categoría");
    bool aux = false;
    temp = root->check_tree(&check_val, 0, &aux);
    if (check_val == root->value) {
      root = temp;
    }
    root->max_depth();
  }
}

template <class T> void AVL<T>::removeAll() {
  if (root != 0) {
    root->removeChilds();
  }
  delete root;
  root = 0;
}

template <class T> bool AVL<T>::find(T val) const {
  if (root != 0) {
    return root->find(val);
  } else {
    return false;
  }
}

template <class T> bool AVL<T>::findCasa(T val) const {
  if (root != 0) {
    return root->findCasa(val);
  } else {
    return false;
  }
}

template <class T> bool AVL<T>::findFrase(T val) const {
  if (root != 0) {
    return root->findFrase(val);
  } else {
    return false;
  }
}

template <class T>
void AVL<T>::getpersonajesNombre(const string& Nombre, vector<T>& resultados) {
  getpersonajesNombre(root, Nombre, resultados);
}

template <class T>
void AVL<T>::getpersonajesNombre(Node<T>* node, const string& nombre, vector<T>& resultados) {
  if (node == nullptr) {
    return;
  }

  getpersonajesNombre(node->left, nombre, resultados);

  if (node->value.getNombre() == nombre) {
    resultados.push_back(node->value);
  }

  getpersonajesNombre(node->right, nombre, resultados);
}

template <class T>
void AVL<T>::getpersonajesCasa(const string& casa, vector<T>& resultados) {
  getpersonajesCasa(root, casa, resultados);
}

template <class T>
void AVL<T>::getpersonajesCasa(Node<T>* node, const string& casa, vector<T>& resultados) {
  if (node == nullptr) {
    return;
  }

  getpersonajesCasa(node->left, casa, resultados);

  if (node->value.getCasa() == casa) {
    resultados.push_back(node->value);
  }

  getpersonajesCasa(node->right, casa, resultados);
}

template <class T>
void AVL<T>::getpersonajesFrase(const string& frase, vector<T>& resultados) {
  getpersonajesFrase(root, frase, resultados);
}

template <class T>
void AVL<T>::getpersonajesFrase(Node<T>* node, const string& frase, vector<T>& resultados) {
  if (node == nullptr) {
    return;
  }

  getpersonajesFrase(node->left, frase, resultados);

  if (node->value.getFrase() == frase) {
    resultados.push_back(node->value);
  }

  getpersonajesFrase(node->right, frase, resultados);
}

#endif /* AVL_H_ */
