// @author Miguel García Silvente

#include "bintree.h"
#include <iostream>

using namespace std;

 bintree<int> crear_arbol()
{
  bintree<int> A(7);
  bintree<int>::node n;

  A.insert_left(A.root(), 1);
  A.insert_right(A.root(), 9);
  n = A.root().left();
  A.insert_left(n, 6);
  A.insert_right(n, 8);

  n = n.right();
  A.insert_right(n, 4);

  n = A.root().right();
  A.insert_left(n, 5);

  return A;
}

void inorden(const bintree<char>::node &n)
{
    if (!n.null()) {
      inorden(n.left());
      cout << *n << " ";
      inorden(n.right());
    }
}

template <typename T>
void preorden(const typename bintree<T>::node &n){
    if (!n.null()) {
      cout << *n << " ";
      // Esto es necesario hacerlo cuando el parámetro es una subclase de una clase genérica
      preorden<T>(n.left());
      preorden<T>(n.right());
    }
}

int main()
{
  bintree<int> A = crear_arbol();

  // Esto es necesario hacerlo cuando el parámetro es una subclase de una clase genérica
  preorden<int>(A.root());

  cout << endl;

  bintree<string> B("tab");

  B.insert_left(B.root(), "aaa");
  B.insert_right(B.root(), "zzzz");

 for (bintree<int>::preorder_iterator it = A.begin_preorder(); it!=A.end_preorder(); ++it)
    cout << *it << " ";
 cout << endl;

 for (bintree<int>::postorder_iterator it = A.begin_postorder(); it!=A.end_postorder(); ++it)
    cout << *it << " ";
 cout << endl;

 bintree<int> aux;
 A.prune_left(A.root(), aux);
}

