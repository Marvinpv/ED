// @author Miguel García Silvente

#include <iostream>
#include "tree.h"

using namespace std;

tree<char> crear_arbol()
{
  tree<char> A('k');
  tree<char>::node n = A.root();
  A.insert_left(n, 'r');
  n = n.left();
  A.insert_left(n, 'm');
  n = n.left();
  A.insert_next_sibling(n, 'k');
  n = n.parent();
  A.insert_next_sibling(n, 'a');
  n = n.next_sibling();
  A.insert_next_sibling(n, 't');
  n = n.next_sibling();
  A.insert_left(n, 'g');
  n = n.left();
  A.insert_left(n, 'f');
  A.insert_next_sibling(n, 'e');
  n = n.next_sibling();
  A.insert_next_sibling(n, 'w');

  /*tree<char> aux;
  A.prune_left(A.root(), aux);

  A.prune_next_sibling(A.root().left(), aux);
  */

  return A;
}

tree<char> crear_arbol_expresion()
{
  tree<char> A('+');
  tree<char>::node n = A.root();
  A.insert_left(n, '+');
  n = n.left();
  A.insert_left(n, '+');
  n = n.left();
  A.insert_next_sibling(n, 'a');
  A.insert_left(n, 'e');
  n = n.left();
  A.insert_next_sibling(n, 'f');

  n = A.root().left();
  A.insert_next_sibling(n, '/');
  n = n.next_sibling();
  A.insert_left(n, 'b');
  n = n.left();
  A.insert_next_sibling(n, 'c');

  /*tree<char> aux;
  A.prune_left(A.root(), aux);

  A.prune_next_sibling(A.root().left(), aux);
  */

  return A;
}

template <typename T>
void preorden(const tree<T> & A, const typename tree<T>::node &v)
{
  typename tree<T>::node aux;
  if (!v.null()) {
     cout << *v << " ";   //  acción sobre el nodo v.
     for (aux = v.left(); !aux.null(); aux = aux.next_sibling())
        preorden(A, aux);
  }
}

template <typename T>
void postorden(const tree<T> & A, const typename tree<T>::node &v)
{
  typename tree<T>::node aux;
  if (!v.null()) {
     for (aux = v.left(); !aux.null(); aux = aux.next_sibling())
        postorden(A, aux);
      cout << *v << " ";   //  acción sobre el nodo v.
  }
}

template <typename T>
void inorden(const tree<T> & A, const typename tree<T>::node &v)
{
  typename tree<T>::node aux;
  if (!v.null()) {
     inorden(A, v.left());
     cout << *v << " ";   //  acción sobre el nodo v.
     if (!v.left().null())
       for (aux = v.left().next_sibling(); !aux.null(); aux = aux.next_sibling())
        inorden(A, aux);
  }
}

template <typename T>
void pintar_arbol(const typename tree<T>::node &n, int linea, int desde, int hasta)
{
  if (!n.null()) {
    imprimir_etiqueta(*n, linea, (desde+hasta)/2);
    pintar_arbol(n.left(), linea+1, desde, (desde+hasta)/2);
    pintar_arbol(n.left().next_sibling(), linea+1, (desde+hasta)/2, hasta);
  }
}

int main()
{
  // tree<char> A = crear_arbol_expresion();
  tree<char> A = crear_arbol_expresion();

  // O(n)
  cout << "Preorden: ";
  preorden(A, A.root());
  cout << endl;

  // O(n)
  cout << "Postorden: ";
  postorden(A, A.root());
  cout << endl;

  cout << "Inorden: ";
  // O(n)
  inorden(A, A.root());
  cout << endl;

  // O(n log n)
  cout << "Preorden: ";
  for (tree<char>::preorder_iterator it = A.begin_preorder(); it!=A.end_preorder(); ++it)
    cout << *it << " ";
  cout << endl;

  cout << "Postorden: ";
  // O(n log n)
  for (tree<char>::postorder_iterator it = A.begin_postorder(); it!=A.end_postorder(); ++it)
    cout << *it << " ";
  cout << endl;

  // O(n log n)
  cout << "Inorden: ";
  for (tree<char>::inorder_iterator it = A.begin_inorder(); it!=A.end_inorder(); ++it)
    cout << *it << " ";
  cout << endl;
}
