//-*-Mode: C++;-*-

/**
  @file tree.h
  @brief TDA tree
  @author Miguel García Silvente

 */

#ifndef __TREE_H__
#define __TREE_H__

/**
   TDA tree.

   tree::tree, assign_subtree, setroot, root, ~tree, =,
   prune_left, prune_next_sibling,insert_left, insert_next_sibling, clear, size,
   empty, ==, !=, null, is_root, internal, external


   Representa un árbol general con nodos etiquetados con datos del tipo T.

   T debe tener definidas las operaciones:

   - T & operator=(const T & e);
   - bool operator!=(const T & e);
   - bool operator==(const T & e);

   Son mutables.
   Residen en memoria dinámica.
*/

#include <queue>
#include <iostream>
#include <stack>
#include <list>

template <typename T>
class tree {
public:
  class node;
  typedef unsigned int size_type;

  /**
     @brief Constructor primitivo por defecto.

     Crea un árbol nulo.
  */
  tree();

  /**
     @brief Constructor primitivo.

     @param e: Etiqueta para la raíz.

     Crea un árbol con un único nodo etiquetado con e.
  */
  tree(const T & e);

  /**
     @brief Constructor de copia.

     @param: a árbol que se copia.

     Crea un árbol duplicado exacto de a.
  */
  tree(const tree<T> & a);

  /**
     @brief Reemplaza el receptor por una copia de subárbol.

     @param a: árbol desde el que se copia.
     @param n: nodo raíz del subárbol que se copia.

     El receptor se hace nulo y después se le asigna una copia
     del subárbol de a cuya raíz es n.
  */
  void assign_subtree(const tree<T> & a, node n);

  /**
     @brief Destructor.

     Destruye el receptor liberando los recursos que ocupaba.
  */
  ~tree();

  /**
     @brief Asigna la raiz al arbol vacío

     @param v: el valor a almacenar en la raiz.
     @pre el receptor es el árbol nulo.

  */
  node setroot(const T & v);

  /**
     @brief Operador de asignación.

     @param a: árbol que se asigna.

     Destruye el contenido previo del receptor y le asigna un
     duplicado de a.
  */
  tree<T> & operator=(const tree<T> & a);

  /**
     @brief Obtener el nodo raíz.

     @return nodo raíz del receptor.
  */
  node root() const;

  /**
     @brief Podar el subárbol hijo a la izquierda de un nodo.

     @param n: nodo del receptor. n != nodo_nulo.
     @param dest: subárbol hijo a la izquierda de n. Es MODIFICADO.

     Desconecta el subárbol hijo a la izquierda de n, que pasa a
     ser el árbol que era su hermano a la derecha, si lo tuviera.
     El subárbol anterior se devuelve sobre dest.
  */
  void prune_left(node n, tree<T> & dest);

  /**
     @brief Podar el subárbol hermano a la derecha de un nodo.

     @param n: nodo del receptor. n != nodo_nulo.
     @param dest: subárbol hermano a la derecha de n. Es MODIFICADO.

     Desconecta el subárbol hermano a la derecha de n, que pasa a
     ser el árbol que era su hermano a la derecha, si lo tuviera.
     El subárbol anterior se devuelve sobre dest.

  */
  void prune_next_sibling(node n, tree<T> & dest);

  /**
     @brief Insertar un nodo como hijo a la izquierda de un nodo.

     @param n: nodo del receptor. n != nodo_nulo.
     @param e: etiqueta del nuevo nodo.

     Inserta un nuevo nodo con etiqueta e como hijo a la izquierda, el anterior hijo más a la izquierda queda como hermano a la derecha del recién insertado
  */
  node insert_left(node n, const T & e);

  /**
     @brief Insertar un árbol como subárbol hijo a la izquierda de un nodo.

     @param n: nodo del receptor. n != nodo_nulo.
     @param rama: subárbol que se inserta. Es MODIFICADO.

     Si rama no es un árbol vacío:
        Inserta rama como hijo a la izquierda de n, el anterior hijo más
        a la izquierda queda como hermana a la derecha del recién insertado.
        y rama se hace árbol nulo.
     En caso contrario no se hace nada
  */
  node insert_left(node n, tree<T> & rama);

  /**
     @brief Insertar un nodo como hermano a la derecha de un nodo.

     @param n: nodo del receptor. !n.Nulo().
     @param e: etiqueta del nuevo nodo.

     Inserta un nuevo nodo con etiqueta e como hermano a la derecha, el anterior hermano a la derecha de n queda como hermano a la derecha del nodo insertado
  */
  node insert_next_sibling(node n, const T & e);

  /**
     @brief Insertar un árbol como subárbol hermano a la derecha de un nodo.

     @param n: nodo del receptor. !n.Nulo().
     @param rama: subárbol que se inserta. Es MODIFICADO.

     Si rama no es un árbol vacío:
        Asigna el valor de rama como nuevo subárbol hermano a la derecha, el anteriot hermano a la derecha de n queda como hermano a la derecha del nodo insertado y rama se hace árbol nulo.
     En caso contrario no se hace nada
  */
  node insert_next_sibling(node n, tree<T> & rama);

  /**
     @brief Hace nulo un árbol.

     Destruye todos los nodos del árbol receptor y lo hace
     un árbol nulo.
  */
  void clear();

  /**
     @brief Obtiene el nmero de nodos.

     @return nmero de nodos del receptor.
  */
  size_type size() const;

  /**
     @brief Comprueba si un árbol esta vacío.

     @return true, si el receptor es un árbol vacío.
             false, en otro caso.
  */
  bool empty() const;

  /**
     @brief Comprueba si un árbol es nulo.

     @return true, si el receptor es un árbol nulo.
             false, en otro caso.
  */
  bool null() const;

  /**
     @brief Comprueba si un nodo es la raíz.

     @param n: nodo que se evala.

     @return true, si n es la raíz del receptor.
             false, en otro caso.
  */
  bool is_root(node v) const {return v==root();};

  /**
     @brief Comprueba si un nodo es interior.

     @param n: nodo que se evala.

     @return true, si n es interior.
             false, en otro caso.
  */
  bool is_internal(node v) const {return !v.left().null();};

  /**
     @brief Comprueba si un nodo es exterior.

     @param n: nodo que se evala.

     @return true, si n es exterior.
             false, en otro caso.
  */
  bool is_external(node v) const {return v.left().null();};

  /**
     @brief Operador de comparación de igualdad.

     @param a: árbol con que se compara el receptor.

     @return  true, si el receptor es igual, en estructura y
                    etiquetas a a.
              false, en otro caso.
  */
  bool operator==(const tree<T> & a) const;

  /**
     @brief Operador de comparación de desigualdad.

     @param a: árbol con que se compara el receptor.

     @return  true, si el receptor no es igual, en estructura o
                    etiquetas a a.
              false, en otro caso.
  */
  bool operator!=(const tree<T> & a) const;

  /**
     Clase iterator para recorrer el árbol en PreOrden
  */
  class preorder_iterator {
  public:
    preorder_iterator();
    preorder_iterator(node n);
    bool operator!=(const preorder_iterator & i) const;
    bool operator==(const preorder_iterator & i) const;
    T & operator*();
    preorder_iterator & operator++();
  private:
    node elnodo;
  };

  preorder_iterator begin_preorder();
  preorder_iterator end_preorder();

  class const_preorder_iterator {
  public:
    const_preorder_iterator();
    const_preorder_iterator(node n);
    bool operator!=(const const_preorder_iterator & i) const;
    bool operator==(const const_preorder_iterator & i) const;
    const T & operator*() const;
    const_preorder_iterator & operator++();
  private:
    node elnodo;
  };

  const_preorder_iterator begin_preorder() const;
  const_preorder_iterator end_preorder() const;

  /**
     Clase iterator para recorrer el árbol en _inorder
  */
  class inorder_iterator {
  public:
    inorder_iterator();
    inorder_iterator(node n);
    bool operator!=(const inorder_iterator & i) const;
    bool operator==(const inorder_iterator & i) const;
    T& operator*();
    inorder_iterator & operator++();
  private:
    node elnodo;
    std::stack<std::pair<node,bool> > pila_nodos;
  };
  inorder_iterator begin_inorder();
  inorder_iterator end_inorder();

  class const_inorder_iterator {
  public:
    const_inorder_iterator();
    const_inorder_iterator(node n);
    bool operator!=(const const_inorder_iterator & i) const;
    bool operator==(const const_inorder_iterator & i) const;
    const T & operator*() const;
    const_inorder_iterator & operator++();
  private:
    node elnodo;
    std::stack<std::pair<node,bool> > pila_nodos;
  };

  const_inorder_iterator begin_inorder() const;
  const_inorder_iterator end_inorder() const;


  /**
     Clase iterator para recorrer el árbol en PostOrden
  */
  class postorder_iterator {
  public:
    postorder_iterator();
    postorder_iterator(node n);
    bool operator!=(const postorder_iterator & i) const;
    bool operator==(const postorder_iterator & i) const;
    T& operator*();
    postorder_iterator & operator++();
  private:
    node elnodo;
  };

  postorder_iterator begin_postorder();
  postorder_iterator end_postorder();

  class const_postorder_iterator {
  public:
    const_postorder_iterator();
    const_postorder_iterator(node n);
    bool operator!=(const const_postorder_iterator & i) const;
    bool operator==(const const_postorder_iterator & i) const;
    const T & operator*() const;
    const_postorder_iterator & operator++();
  private:
    node elnodo;
  };
  const_postorder_iterator begin_postorder() const;
  const_postorder_iterator end_postorder() const;


  /**
     Clase iterator para recorrer el árbol por niveles
  */

  class level_iterator {
  public:
    level_iterator();
    level_iterator(node n);
    bool operator!=(const level_iterator & i) const;
    bool operator==(const level_iterator & i) const;
    T & operator*();
    level_iterator & operator++();
  private:
    node elnodo;
    std::queue<node> cola_Nodos;
  };

  level_iterator begin_level();
  level_iterator end_level();

  class const_level_iterator {
  public:
    const_level_iterator();
    const_level_iterator(node n);
    bool operator!=(const const_level_iterator & i) const;
    bool operator==(const const_level_iterator & i) const;
    const T & operator*() const;
    const_level_iterator & operator++();
  private:
    node elnodo;
    std::queue<node> cola_Nodos;
  };

  const_level_iterator begin_level() const;
  const_level_iterator end_level() const ;


private:
  // Funciones auxiliares
  /**
     @brief Destruir subárbol.

     @param n: nodo raíz del subárbol que se destruye.
     Destruye el subárbol cuya raíz es n.
  */
  void destroy(node  n);


  /**
     @brief Copia subárbol.

     @param dest: nodo sobre el que se copia. Es MODIFICADO.
     @param orig: raíz del subárbol que se copia.
     @param pad: nodo padre de dest.

     Destruye el subárbol con raíz en dest. Sobre éste realiza
     un duplicado del subárbol con raíz en orig.
  */
  void copy(node & dest, const node & orig, const node &pad);


  /**
     @brief Cuenta el nmero de nodos.

     @param n: raíz del subárbol a contar.

     @return devuelve el número de nodos del subárbol que
             tiene n como raíz.

     Cuenta el número de nodos en el subárbol cuuya raíz es n.
  */
  size_type count(node n) const;

  /**
     @brief Comparación de igualdad.

     @param n1: raiz del primer subárbol.
     @param n2: raiz del segundo subárbol.

     @return true, si los dos subárboles son iguales, en
                   estructura y etiquetas.
             false, en otro caso.
  */
  bool equals(node n1, node n2) const;

  // Representación
  node laraiz;

  /**
      TDA nodo.
      Modela los nodos del árbol.
  */

  class nodewrapper {
    public:
      nodewrapper();
      nodewrapper(const T&);
      T etiqueta;
      node pad;
      node izda;
      node hermanodcha;
  };

public:
  class node {
  public:
    /**
       @brief Constructor primitivo
    */
    inline node();

    /**
       @brief Constructor copia
    */
    inline node(const node & n);

    /**
       @brief Determina si el nodo es nulo
       @return Devuelve true si el nodo es nulo y false en caso contrario
    */
    inline bool null() const;

    /**
       @brief Devuelve el padre del nodo receptor
       @pre El nodo receptor no puede ser nulo
    */
    inline node parent() const;

    /**
       @brief Devuelve el hizo izquierdo del nodo receptor
       @pre El nodo receptor no puede ser nulo
    */
    inline node left() const;

    /**
       @brief Devuelve el hermano derecho del nodo receptor
       @pre El nodo receptor no puede ser nulo
    */
    inline node next_sibling() const;

    /**
       @brief Devuelve la etiqueta del nodo
       @pre el nodo no puede ser nulo
    */
    inline T & operator*();

    /**
       @brief Devuelve la etiqueta del nodo
       @pre el nodo no puede ser nulo
    */
    inline const T & operator*() const;

    /**
       @brief Operador de asignación
       @param n el nodo a asignar
    */
    inline node & operator=(const node & n);

    /**
       @brief Operador de comparación de igualdad
       @param n el nodo con el que se compara
    */
    inline bool operator==(const node & n) const;

    /**
       @brief Operador de comparación de desigualdad
       @param n el nodo con el que se compara
    */
    inline bool operator!=(const node &n) const;

  private:
    inline node(node * n);
    // Las siguientes funciones son privadas para uso exclusivo en tree

    /**
       @brief Constructor primitivo
       @param e Etiqueta del nodo
    */
    inline node(const T &e);

    /**
       @brief Elimina el nodo actual
       @pre El nodo receptor no puede ser nulo y debe ser una hoja
    */
    inline void remove();

    /**
       @brief Coloca el nodo padre de un nodo
       @param n El nodo que sería padre del receptor. No nulo.
    */
    inline void parent(node n);

    /**
       @brief Coloca el nodo hijo izquierda de un nodo
       @param n El nodo que sería hijo izquierdo del receptor. No nulo
    */
    inline void left(node n);

    /**
       @brief Coloca el nodo hermano derecha de un nodo
       @param n El nodo que sería hermano derecha del receptor No nulo
    */
    inline void next_sibling(node n);

    nodewrapper * elnodo;
    friend class tree<T>;
  };

  int grado_nodo(const typename tree<T>::node n)const;

  int grado()const;
};

#include "tree.hxx"
#include "node.hxx"


#endif
