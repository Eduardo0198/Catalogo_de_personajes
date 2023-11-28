
/*************************
 Catalogo de personajes
 node.h
 Autor: Eviveroe
 A01710605
 *************************/

#ifndef NODE_H
#define NODE_H
#include <sstream>

template <class T>class Node {
private:
  T value;
  Node *left, *right;
  int level, balance;
  Node<T> *predecesor();

public:
  Node(T);
  Node(T, Node<T> *, Node<T> *, int, int);
  void add(T); // agregar nodo
  bool find(T); // encontrar por nombre
  bool findCasa(T); // encontrar por casa
  bool findFrase(T); // encontar por frase
  void remove(T); 
  void removeChilds();
  void inorder(std::stringstream &) const;
  void preorder(std::stringstream &) const;
  int max_depth();

  Node<T> *check_tree(T *, Node<T> *, bool *);
  Node<T> *balance_tree();

  Node<T> *rot_left(Node<T> *);
  Node<T> *rot_right(Node<T> *);
  Node<T> *rot_left_right(Node<T> *);
  Node<T> *rot_right_left(Node<T> *);

  template <class U> friend class AVL;


};


template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0), level(0), balance(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri, int lev, int bal)
    : value(val), left(le), right(ri), level(lev), balance(bal) {}

template <class T> void Node<T>::add(T val) {
  if (val < value) {
    if (left != 0) {
      left->add(val);
    } else {
      left = new Node<T>(val);
    }
  } else {
    if (right != 0) {
      right->add(val);
    } else {
      right = new Node<T>(val);
    }
  }
}

template <class T>
bool Node<T>::find(T val) {
  if (val.getNombre() == value.getNombre()) {
    return true;
  } else if (val.getNombre() < value.getNombre() && left != nullptr) {
    return left->find(val);
  } else if (val.getNombre() > value.getNombre() && right != nullptr) {
    return right->find(val);
  }
  return false;
}

template <class T> 
bool Node<T>::findCasa(T val) {
  if (val.getCasa() == value.getCasa()) {
    return true;
  } else if (val < value) {
    return (left != 0 && left->findCasa(val));
  } else if (val > value) {
    return (right != 0 && right->findCasa(val));
  }
  return false;
}

template <class T> bool Node<T>::findFrase(T val) {
  if (val.getFrase() == value.getFrase()) {
    return true;
  } else if (val < value) {
    return (left != 0 && left->findFrase(val));
  } else if (val > value) {
    return (right != 0 && right->findFrase(val));
  }

  return false;
}

template <class T> Node<T> *Node<T>::predecesor() {
  Node<T> *le, *ri;

  le = left;
  ri = right;

  if (left == 0) {
    if (right != 0) {
      right = 0;
    }
    return ri;
  }

  if (left->right == 0) {
    left = left->left;
    le->left = 0;
    return le;
  }

  Node<T> *parent, *child;
  parent = left;
  child = left->right;
  while (child->right != 0) {
    parent = child;
    child = child->right;
  }
  parent->right = child->left;
  child->left = 0;
  return child;
}

template <class T> void Node<T>::remove(T val) {
  Node<T> *succ, *old;

  if (val < value) {
    if (left != 0) {
      if (left->value == val) {
        old = left;
        succ = left->predecesor();
        if (succ != 0) {
          succ->left = old->left;
          succ->right = old->right;
        }
        left = succ;
        delete old;
      } else {
        left->remove(val);
      }
    }
  } else if (val > value) {
    if (right != 0) {
      if (right->value == val) {
        old = right;
        succ = right->predecesor();
        if (succ != 0) {
          succ->left = old->left;
          succ->right = old->right;
        }
        right = succ;
        delete old;
      } else {
        right->remove(val);
      }
    }
  }
}

template <class T> void Node<T>::removeChilds() {
  if (left != 0) {
    left->removeChilds();
    delete left;
    left = 0;
  }
  if (right != 0) {
    right->removeChilds();
    delete right;
    right = 0;
  }
}

template <class T> void Node<T>::inorder(std::stringstream &aux) const {
  if (left != 0) {
    left->inorder(aux);
  }
  if (aux.tellp() != 1) {
    std::cout << " ";
  }
  cout << "(" << value << " " << level << " " << balance << ")";
  if (right != 0) {
    right->inorder(aux);
  }
}

template <class T> void Node<T>::preorder(std::stringstream &aux) const {
 std:: cout << "(" << value << " " << level << " " << balance << ")";
  if (left != 0) {
    std::cout << " ";
    left->preorder(aux);
  }
  if (right != 0) {
    std::cout << " ";
    right->preorder(aux);
  }
}

template <class T> int Node<T>::max_depth() {
  int le = 0, ri = 0;
  if (left != 0)
    le = left->max_depth() + 1;
  if (right != 0)
    ri = right->max_depth() + 1;
  if (le > ri)
    level = le;
  else
    level = ri;
  balance = le - ri;
  return level;
}

template <class T>
Node<T> *Node<T>::check_tree(T *check_val, Node<T> *parent, bool *checked) {
  Node<T> *le = 0, *ri = 0, *a = 0;
  if (left != 0)
    le = left->check_tree(check_val, this, checked);
  if (right != 0)
    ri = right->check_tree(check_val, this, checked);
  if (*checked == false) {
    if (balance > 1) {
      a = balance_tree();
      *check_val = value;
      *checked = true;
      if (parent != 0) {
        parent->left = a;
      }
    } else if (balance < -1) {
      a = balance_tree();
      *check_val = value;
      *checked = true;
      if (parent != 0) {
        parent->right = a;
      }
    }
  }
  return a;
}

template <class T> Node<T> *Node<T>::balance_tree() {
  Node<T> *a = this, *le = left, *ri = right;
  T old_value = value;
  if (balance > 0) {
    if (le->balance > 0) {
      a = rot_right(a);
    } else {
      a = rot_left_right(a);
    }
  } else {
    if (ri->balance < 0) {
      a = rot_left(a);
    } else {
      a = rot_right_left(a);
    }
  }
  return a;
}

template <class T> Node<T> *Node<T>::rot_left(Node<T> *a) {
  Node<T> *b, *temp = 0;
  if (a->right != 0) {
    b = a->right;
    if (b->left != 0)
      temp = b->left;
    b->left = a;
    if (temp != 0) {
      a->right = temp;
    } else {
      a->right = 0;
    }
  }
  return b;
}

template <class T> Node<T> *Node<T>::rot_right(Node<T> *a) {
  Node<T> *b, *temp = 0;
  if (a->left != 0) {
    b = a->left;
    if (b->right != 0)
      temp = b->right;
    b->right = a;
    if (temp != 0) {
      a->left = temp;
    } else {
      a->left = 0;
    }
  }
  return b;
}

template <class T> Node<T> *Node<T>::rot_left_right(Node<T> *a) {
  a->left = rot_left(a->left);
  a = rot_right(a);
  return a;
}

template <class T> Node<T> *Node<T>::rot_right_left(Node<T> *a) {
  a->right = rot_right(a->right);
  a = rot_left(a);
  return a;
}

#endif