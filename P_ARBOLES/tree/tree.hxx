//-*-Mode: C++;-*-

/**
  @file tree.template
  @brief TDA tree
  @author Miguel García Silvente

 */

/*
************************************************************
* Implementación
************************************************************
*/

/*
  Función de Abstracción:
  ----------------------------

  Invariante de Representación:
  ----------------------------

*/


#include <cassert>
#include <iostream>

using namespace std;


/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PRIVADAS
/*____________________________________________________________ */
/*____________________________________________________________ */

template <typename T>
void tree<T>::destroy(typename tree<T>::node n)
{
  if (!n.null()) {
    destroy(n.left());
    destroy(n.next_sibling());
    n.remove();
  }
}


template <typename T>
void tree<T>::copy(typename tree<T>::node &dest, const typename tree<T>::node &orig, const typename tree<T>::node &pad)
{

  if (orig.null()) {
    dest = typename tree<T>::node();
  }
  else {
      dest = node(*orig);
      typename tree<T>::node aux(dest.left());
      copy (aux, orig.left(), dest);
      if (!aux.null()) {
        aux.parent(dest);
      }
      dest.left(aux);

      aux = dest.next_sibling();
      copy (aux, orig.next_sibling(), pad);
      if (!aux.null()) {
        aux.parent(pad);
      }
      dest.next_sibling(aux);
    }
}


template <typename T>
typename tree<T>::size_type
tree<T>::count(typename tree<T>::node n) const
{
  if (n.null())
    return 0;
  else
    return 1 + count(n.left()) + count(n.next_sibling());
}


template <typename T>
bool tree<T>::equals(typename tree<T>::node n1, typename tree<T>::node n2) const
{
  if (n1.null() && n2.null())
    return true;
  if (n1.null() || n2.null())
    return false;
  if (*n1 != *n2)
    return false;
  if (!equals(n1.left(),n2.left()))
    return false;
  if (!equals(n1.next_sibling(),n2.next_sibling()))
    return false;
  return true;
}


/*____________________________________________________________ */
//               FUNCIONES PUBLICAS
/*____________________________________________________________ */
/*____________________________________________________________ */


template <typename T>
inline tree<T>::tree()
{
}


template <typename T>
tree<T>::tree(const T & e) : laraiz(e)
{
}


template <typename T>
typename tree<T>::node tree<T>::setroot(const T & e){
  if (!laraiz.null())
    laraiz.elnodo->etiqueta = e;
  else
      laraiz = typename tree<T>::node(e);
  return laraiz;
}


template <typename T>
tree<T>::tree (const tree<T> & a)
{
  copy(laraiz, a.laraiz, typename tree<T>::node());
  if (!laraiz.null())
    laraiz.parent(typename tree<T>::node());
}

template <typename T>
void tree<T>::assign_subtree(const tree<T> & a, typename tree<T>::node n)
{
 if (&a != this) {
   destroy(laraiz);
   typename tree<T>::node aux;
   copy(laraiz, n, typename tree<T>::node());
   if (!laraiz.next_sibling().null()) {
       destroy(laraiz.next_sibling());
       laraiz.next_sibling(aux);
   }
   if (!laraiz.null())
     laraiz.parent(typename tree<T>::node());
 }
 else {  // Reemplazar el receptor por un subarbol suyo.
   typename tree<T>::node nod;
   typename tree<T>::node aux;
   copy(nod, n, typename tree<T>::node());
   destroy(laraiz);
   laraiz = nod;
   if (!nod.next_sibling().null()) {
       destroy(nod.next_sibling());
       laraiz.next_sibling(aux);
   }
   if (!laraiz.null())
     laraiz.parent(typename tree<T>::node());
 }
}

template <typename T>
inline tree<T>::~tree()
{
  destroy(laraiz);
}


template <typename T>
tree<T>&
tree<T>::operator=(const tree<T> & a)
{
  if (&a != this) {
    destroy(laraiz);
    copy(laraiz, a.laraiz, typename tree<T>::node());
    if (!laraiz.null())
      laraiz.parent(typename tree<T>::node());
  }
  return *this;
}


template <typename T>
inline typename tree<T>::node tree<T>::root() const
{
  return laraiz;
}


template <typename T>
void tree<T>::prune_left(typename tree<T>::node n, tree<T> & dest)
{
  if (!n.left().null()){
  	destroy(dest.laraiz);
  	dest.laraiz=n.left();
  	n.left(n.left().next_sibling());
  	dest.laraiz.parent(typename tree<T>::node());
  	dest.laraiz.next_sibling(typename tree<T>::node());
  }
}


template <typename T>
void tree<T>::prune_next_sibling(typename tree<T>::node n, tree<T> & dest)
{
  if (!n.next_sibling().null()){
  	destroy(dest.laraiz);
  	dest.laraiz=n.next_sibling();
  	n.next_sibling(n.next_sibling().next_sibling());
  	dest.laraiz.parent(typename tree<T>::node());
  	dest.laraiz.next_sibling(typename tree<T>::node());
  }
}


template <typename T>
typename tree<T>::node tree<T>::insert_left(typename tree<T>::node n, const T & e)
{
  typename tree<T>::node nuevo(e);

  nuevo.next_sibling(n.left());
  nuevo.parent(n);
  n.left(nuevo);

  return nuevo;
}


template <typename T>
typename tree<T>::node tree<T>::insert_left(typename tree<T>::node n, tree<T> & rama)
{
  if (!rama.empty()){
  	typename tree<T>::node nuevo(*(rama.laraiz));
  	nuevo.left(rama.laraiz.left());

  	typename tree<T>::node aux=rama.laraiz.left();
  	while(!aux.null()){
  		aux.parent(nuevo);
  		aux=aux.next_sibling();
  	}
  	rama.laraiz.remove();

  	nuevo.next_sibling(n.left());
  	nuevo.parent(n);
  	n.left(nuevo);

  	return nuevo;
  }

  return typename tree<T>::node();
}


template <typename T>
typename tree<T>::node tree<T>::insert_next_sibling(typename tree<T>::node n, const T & e)
{
  typename tree<T>::node nuevo(e);

  nuevo.next_sibling(n.next_sibling());
  n.next_sibling(nuevo);
  nuevo.parent(n.parent());

  return nuevo;
}


template <typename T>
typename tree<T>::node tree<T>::insert_next_sibling(typename tree<T>::node n, tree<T> & rama)
{
	typename tree<T>::node nuevo;
	if (!rama.empty()){
		nuevo = *(rama.laraiz);
		nuevo.left(rama.laraiz.left());

		typename tree<T>::node aux=rama.laraiz.left();
		while(!aux.null()){
			aux.parent(nuevo);
			aux=aux.next_sibling();
		}
		rama.laraiz.remove();

		nuevo.next_sibling(n.next_sibling());
		nuevo.parent(n.parent());
		n.next_sibling(nuevo);
  	}
  	return nuevo;
}


template <typename T>
void tree<T>::clear()
{
  destroy(laraiz);
  laraiz = typename tree<T>::node();
}


template <typename T>
inline
typename tree<T>::size_type
tree<T>::size() const
{
  return count(laraiz);
}


template <typename T>
inline bool tree<T>::empty() const
{
  return laraiz == typename tree<T>::node();
}


template <typename T>
inline bool tree<T>::operator==(const tree<T>& a) const
{
  return equals(laraiz, a.laraiz);
}


template <typename T>
inline bool tree<T>::operator!=(const tree<T>& a) const
{
  return !(*this == a);
}

/*
  ************************************************************
  Iteradores
  ************************************************************
  */


/*
  Iterador para recorrido en preorder
*/

template <typename T>
inline tree<T>::preorder_iterator::preorder_iterator()
{
  elnodo = typename tree<T>::node();
}


template <typename T>
inline tree<T>::preorder_iterator::preorder_iterator(
  typename tree<T>::node n): elnodo(n)
{
}

template <typename T>
inline bool tree<T>::preorder_iterator::operator!=(
const tree<T>::preorder_iterator & i) const
{
  return elnodo != i.elnodo;
}


template <typename T>
inline bool tree<T>::preorder_iterator::operator==(
const tree<T>::preorder_iterator & i) const
{
  return elnodo == i.elnodo;
}


template <typename T>
inline T& tree<T>::preorder_iterator::operator*()
{
  return *elnodo;
}


template <typename T>
typename tree<T>::preorder_iterator &
tree<T>::preorder_iterator::operator++()
{
  if (elnodo.null())
    return *this;

  if (!elnodo.left().null()) {
  	 elnodo = elnodo.left();
  }
  else if (!elnodo.next_sibling().null()) {
      elnodo = elnodo.next_sibling();
  }
  else {
    while ((!elnodo.parent().null()) &&
	       (elnodo.parent().next_sibling() == elnodo ||
	        elnodo.parent().next_sibling().null()))
      elnodo = elnodo.parent();
    if (elnodo.parent().null())
      elnodo = typename tree<T>::node();
    else
      elnodo = elnodo.parent().next_sibling();
  }

  return *this;
}


template <typename T>
inline typename tree<T>::preorder_iterator
tree<T>::begin_preorder()
{
  return preorder_iterator(laraiz);
}

template <typename T>
inline typename tree<T>::preorder_iterator
tree<T>::end_preorder()
{
  return preorder_iterator(typename tree<T>::node());
}

/*____________________________________________________________ */

/*
  Iterador para recorrido en inorder
*/

template <typename T>
inline tree<T>::inorder_iterator::inorder_iterator()
{
  elnodo = typename tree<T>::node();
}


template <typename T>
inline tree<T>::inorder_iterator::inorder_iterator(typename tree<T>::node n)
{
    if (n.null()) {
        elnodo = n;
    }
    else {
        bool que = (n.left().null());
        pila_nodos.push(pair<node,bool>(n,que));
        pair<node,bool> aux = pila_nodos.top();

        if (!aux.second) {
            while (!aux.first.left().null()) {
                pila_nodos.pop();
                typename tree<T>::node tt = aux.first.left().next_sibling();
                list<typename tree<T>::node> ll;
                while (!tt.null()) {
                    ll.push_front(tt);
                    tt = tt.next_sibling();
                }
                for (typename list<typename tree<T>::node>::iterator p = ll.begin(); p != ll.end(); p++) {
                    que = ((*p).left().null());
                    pila_nodos.push(pair<node,bool>(*p,que));
                }
                ll.clear();
                pila_nodos.push(pair<node,bool>(aux.first,true));
                que = (aux.first.left().null());
                pila_nodos.push(pair<node,bool>(aux.first.left(),que));
                aux = pila_nodos.top();
            }
        }
        pila_nodos.pop();
        elnodo = aux.first;
    }
}

template <typename T>
inline bool tree<T>::inorder_iterator::operator!=(
const typename tree<T>::inorder_iterator & i) const
{
  return !(*this==i);
}


template <typename T>
inline bool tree<T>::inorder_iterator::operator==(
const typename tree<T>::inorder_iterator & i) const
{
  return ((elnodo == i.elnodo) && (pila_nodos == i.pila_nodos));
}

template <typename T>
inline T& tree<T>::inorder_iterator::operator*()
{
  return *elnodo;
}

template <typename T>
typename tree<T>::inorder_iterator &
tree<T>::inorder_iterator::operator++()
{
    if (pila_nodos.size() > 0) {
        bool que;
        pair<node,bool> aux = pila_nodos.top();

        if (!aux.second) {
            while (!aux.first.left().null()) {
                pila_nodos.pop();
                typename tree<T>::node tt = aux.first.left().next_sibling();
                list<typename tree<T>::node> ll;
                while (!tt.null()) {
                    ll.push_front(tt);
                    tt = tt.next_sibling();
                }
                for (typename list<typename tree<T>::node>::iterator p = ll.begin(); p != ll.end(); p++) {
                    que = ((*p).left().null());
                    pila_nodos.push(pair<node,bool>(*p,que));
                }
                ll.clear();
                pila_nodos.push(pair<node,bool>(aux.first,true));
                que = (aux.first.left().null());
                pila_nodos.push(pair<node,bool>(aux.first.left(),que));
                aux = pila_nodos.top();
            }
        }
        pila_nodos.pop();
        elnodo = aux.first;
    }
    else {
        elnodo = typename tree<T>::node();
    }

  return *this;
}

template <typename T>
inline typename tree<T>::inorder_iterator
tree<T>::begin_inorder()
{
  return inorder_iterator(root());
}


template <typename T>
inline typename tree<T>::inorder_iterator
tree<T>::end_inorder()
{
  return inorder_iterator(typename tree<T>::node());
}

/*____________________________________________________________ */

/*
  Iterador para recorrido en postorder
*/


template <typename T>
inline tree<T>::postorder_iterator::postorder_iterator()
{
  elnodo = typename tree<T>::node();
}

template <typename T>
inline tree<T>::postorder_iterator::postorder_iterator(
  typename tree<T>::node n)
  : elnodo(n)
{
}

template <typename T>
inline bool tree<T>::postorder_iterator::operator!=(
const tree<T>::postorder_iterator & i) const
{
  return elnodo != i.elnodo;
}

template <typename T>
inline bool tree<T>::postorder_iterator::operator==(
const tree<T>::postorder_iterator & i) const
{
  return elnodo == i.elnodo;
}


template <typename T>
inline T& tree<T>::postorder_iterator::operator*()
{
  return *elnodo;
}


template <typename T>
typename tree<T>::postorder_iterator &
tree<T>::postorder_iterator::operator++()
{
  if (elnodo.parent().null()) {
    elnodo = typename tree<T>::node();
  }
  else
    if (elnodo.parent().left() == elnodo) {
      if (!elnodo.next_sibling().null()) {
        elnodo = elnodo.next_sibling();
        while (!elnodo.left().null()) {
          elnodo = elnodo.left();
        }
      }
      else {
        elnodo = elnodo.parent();
      }
    }
    else {// elnodo es hijo a la derecha de su padre
      if (elnodo.next_sibling().null()) {
          elnodo = elnodo.parent();
      }
      else {
        elnodo = elnodo.next_sibling();
        while (!elnodo.left().null()) {
          elnodo = elnodo.left();
        }
      }
    }

  return *this;
}

template <typename T>
inline typename tree<T>::postorder_iterator
tree<T>::begin_postorder()
{
  if (!root().null()) {
    node n = root();

    while (!n.left().null())
        n = n.left();

    return postorder_iterator(n);
  }
  else {
      return end_postorder();
  }
}

template <typename T>
inline typename tree<T>::postorder_iterator
tree<T>::end_postorder()
{
  return postorder_iterator(typename tree<T>::node());
}


/*
  Iterador para recorrido por Niveles
*/

template <typename T>
inline tree<T>::level_iterator::level_iterator()
{
}

template <typename T>
inline tree<T>::level_iterator::level_iterator(
  typename tree<T>::node n) : elnodo(n)
{
    if (!n.null())
        cola_Nodos.push(n);
}
template <typename T>
inline bool tree<T>::level_iterator::operator!=(
const tree<T>::level_iterator & i) const
{
  return !(*this==i);
}

template <typename T>
inline bool tree<T>::level_iterator::operator==(
const tree<T>::level_iterator & i) const
{
  return (elnodo == i.elnodo) && (cola_Nodos == i.cola_Nodos);
}

template <typename T>
inline T& tree<T>::level_iterator::operator*()
{
  return *elnodo;
}


template <typename T>
typename tree<T>::level_iterator &
tree<T>::level_iterator::operator++()
{
  if (elnodo.null())
    return *this;

  if (!elnodo.next_sibling().null()) {
      elnodo = elnodo.next_sibling();
      if (!elnodo.null() && !elnodo.left().null()) {
        cola_Nodos.push(elnodo);
      }
  }
  else {
      if (cola_Nodos.size() > 0) {
        typename tree<T>::node tope = cola_Nodos.front();
        cola_Nodos.pop();
        elnodo = tope.left();
        if (!elnodo.null() && !elnodo.left().null()) {
            cola_Nodos.push(elnodo);
        }
      }
      else {
        elnodo = typename tree<T>::node();
      }
  }

  return *this;
}


template <typename T>
inline typename tree<T>::level_iterator
tree<T>::begin_level()
{
  if (!root().null())
    return level_iterator(laraiz);
  else
    return level_iterator();
}

template <typename T>
inline typename tree<T>::level_iterator
tree<T>::end_level()
{
  return level_iterator(typename tree<T>::node());
}

/*
  ************************************************************
  Iteradores constantes
  ************************************************************
  */


/*
  Iterador cosntante para recorrido en preorder
*/

template <typename T>
inline tree<T>::const_preorder_iterator::const_preorder_iterator()
{
  elnodo = typename tree<T>::node();
}


template <typename T>
inline tree<T>::const_preorder_iterator::const_preorder_iterator(
  typename tree<T>::node n): elnodo(n)
{
}

template <typename T>
inline bool tree<T>::const_preorder_iterator::operator!=(
const tree<T>::const_preorder_iterator & i) const
{
  return elnodo != i.elnodo;
}


template <typename T>
inline bool tree<T>::const_preorder_iterator::operator==(
const tree<T>::const_preorder_iterator & i) const
{
  return elnodo == i.elnodo;
}


template <typename T>
inline const T& tree<T>::const_preorder_iterator::operator*() const
{
  return *elnodo;
}


template <typename T>
typename tree<T>::const_preorder_iterator &
tree<T>::const_preorder_iterator::operator++()
{
  if (elnodo.null())
    return *this;

 if (!elnodo.left().null()) {
  	 elnodo = elnodo.left();
  }
  else if (!elnodo.next_sibling().null()) {
      elnodo = elnodo.next_sibling();
  }
  else {
    while ((!elnodo.parent().null()) &&
	       (elnodo.parent().next_sibling() == elnodo ||
	        elnodo.parent().next_sibling().null()))
      elnodo = elnodo.parent();
    if (elnodo.parent().null())
      elnodo = typename tree<T>::node();
    else
      elnodo = elnodo.parent().next_sibling();
  }

  return *this;
}


template <typename T>
inline typename tree<T>::const_preorder_iterator
tree<T>::begin_preorder() const
{
  return const_preorder_iterator(laraiz);
}

template <typename T>
inline typename tree<T>::const_preorder_iterator
tree<T>::end_preorder() const
{
  return const_preorder_iterator(typename tree<T>::node());
}

/*____________________________________________________________ */

/*
  Iterador constante para recorrido en inorder
*/

template <typename T>
inline tree<T>::const_inorder_iterator::const_inorder_iterator()
{
  elnodo = typename tree<T>::node();
}


template <typename T>
inline tree<T>::const_inorder_iterator::const_inorder_iterator(typename tree<T>::node n)
{
    if (n.null()) {
        elnodo = n;
    }
    else {
        bool que = (n.left().null());
        pila_nodos.push(pair<node,bool>(n,que));
        pair<node,bool> aux = pila_nodos.top();

        if (!aux.second) {
            while (!aux.first.left().null()) {
                pila_nodos.pop();
                typename tree<T>::node tt = aux.first.left().next_sibling();
                list<typename tree<T>::node> ll;
                while (!tt.null()) {
                    ll.push_front(tt);
                    tt = tt.next_sibling();
                }
                for (typename list<typename tree<T>::node>::iterator p = ll.begin(); p != ll.end(); p++) {
                    que = ((*p).left().null());
                    pila_nodos.push(pair<node,bool>(*p,que));
                }
                ll.clear();
                pila_nodos.push(pair<node,bool>(aux.first,true));
                que = (aux.first.left().null());
                pila_nodos.push(pair<node,bool>(aux.first.left(),que));
                aux = pila_nodos.top();
            }
        }
        pila_nodos.pop();
        elnodo = aux.first;
    }
}

template <typename T>
inline bool tree<T>::const_inorder_iterator::operator!=(
const typename tree<T>::const_inorder_iterator & i) const
{
  return !(*this==i);
}


template <typename T>
inline bool tree<T>::const_inorder_iterator::operator==(
const typename tree<T>::const_inorder_iterator & i) const
{
  return ((elnodo == i.elnodo) && (pila_nodos == i.pila_nodos));
}

template <typename T>
inline const T& tree<T>::const_inorder_iterator::operator*() const
{
  return *elnodo;
}

template <typename T>
typename tree<T>::const_inorder_iterator &
tree<T>::const_inorder_iterator::operator++()
{
    if (pila_nodos.size() > 0) {
        bool que;
        pair<node,bool> aux = pila_nodos.top();

        if (!aux.second) {
            while (!aux.first.left().null()) {
                pila_nodos.pop();
                typename tree<T>::node tt = aux.first.left().next_sibling();
                list<typename tree<T>::node> ll;
                while (!tt.null()) {
                    ll.push_front(tt);
                    tt = tt.next_sibling();
                }
                for (typename list<typename tree<T>::node>::iterator p = ll.begin(); p != ll.end(); p++) {
                    que = ((*p).left().null());
                    pila_nodos.push(pair<node,bool>(*p,que));
                }
                ll.clear();
                pila_nodos.push(pair<node,bool>(aux.first,true));
                que = (aux.first.left().null());
                pila_nodos.push(pair<node,bool>(aux.first.left(),que));
                aux = pila_nodos.top();
            }
        }
        pila_nodos.pop();
        elnodo = aux.first;
    }
    else {
        elnodo = typename tree<T>::node();
    }

  return *this;
}

template <typename T>
inline typename tree<T>::const_inorder_iterator
tree<T>::begin_inorder() const
{
  return const_inorder_iterator(root());
}


template <typename T>
inline typename tree<T>::const_inorder_iterator
tree<T>::end_inorder() const
{
  return const_inorder_iterator(typename tree<T>::node());
}

/*____________________________________________________________ */

/*
  Iterador constante para recorrido en postorder
*/


template <typename T>
inline tree<T>::const_postorder_iterator::const_postorder_iterator()
{
  elnodo = typename tree<T>::node();
}

template <typename T>
inline tree<T>::const_postorder_iterator::const_postorder_iterator(
  typename tree<T>::node n)
  : elnodo(n)
{
}

template <typename T>
inline bool tree<T>::const_postorder_iterator::operator!=(
const tree<T>::const_postorder_iterator & i) const
{
  return elnodo != i.elnodo;
}

template <typename T>
inline bool tree<T>::const_postorder_iterator::operator==(
const tree<T>::const_postorder_iterator & i) const
{
  return elnodo == i.elnodo;
}


template <typename T>
inline const T& tree<T>::const_postorder_iterator::operator*() const
{
  return *elnodo;
}


template <typename T>
typename tree<T>::const_postorder_iterator &
tree<T>::const_postorder_iterator::operator++()
{
  if (elnodo.parent().null()) {
    elnodo = typename tree<T>::node();
  }
  else
    if (elnodo.parent().left() == elnodo) {
      if (!elnodo.next_sibling().null()) {
        elnodo = elnodo.next_sibling();
        while (!elnodo.left().null()) {
          elnodo = elnodo.left();
        }
      }
      else {
        elnodo = elnodo.parent();
      }
    }
    else {// elnodo es hijo a la derecha de su padre
      if (elnodo.next_sibling().null()) {
          elnodo = elnodo.parent();
      }
      else {
        elnodo = elnodo.next_sibling();
        while (!elnodo.left().null()) {
          elnodo = elnodo.left();
        }
      }
    }

  return *this;
}

template <typename T>
inline typename tree<T>::const_postorder_iterator
tree<T>::begin_postorder() const
{
  if (!root().null()) {
    node n = root();

    while (!n.left().null())
        n = n.left();

    return postorder_iterator(n);
  }
  else {
      return end_postorder();
  }
}

template <typename T>
inline typename tree<T>::const_postorder_iterator
tree<T>::end_postorder() const
{
  return const_postorder_iterator(typename tree<T>::node());
}


/*____________________________________________________________ */

/*
  Iterador cosntante para recorrido por Niveles
*/


template <typename T>
inline tree<T>::const_level_iterator::const_level_iterator()
{
}

template <typename T>
inline tree<T>::const_level_iterator::const_level_iterator(
  typename tree<T>::node n) : elnodo(n)
{
    if (!n.null())
        cola_Nodos.push(n);
}
template <typename T>
inline bool tree<T>::const_level_iterator::operator!=(
const tree<T>::const_level_iterator & i) const
{
  return !(*this==i);
}

template <typename T>
inline bool tree<T>::const_level_iterator::operator==(
const tree<T>::const_level_iterator & i) const
{
  return (elnodo == i.elnodo) && (cola_Nodos == i.cola_Nodos);
}

template <typename T>
inline const T& tree<T>::const_level_iterator::operator*() const
{
  return *elnodo;
}


template <typename T>
typename tree<T>::const_level_iterator &
tree<T>::const_level_iterator::operator++()
{
  if (elnodo.null())
    return *this;

  if (!elnodo.next_sibling().null()) {
      elnodo = elnodo.next_sibling();
      if (!elnodo.null() && !elnodo.left().null()) {
        cola_Nodos.push(elnodo);
      }
  }
  else {
      if (cola_Nodos.size() > 0) {
        typename tree<T>::node tope = cola_Nodos.front();
        cola_Nodos.pop();
        elnodo = tope.left();
        if (!elnodo.null() && !elnodo.left().null()) {
            cola_Nodos.push(elnodo);
        }
      }
      else {
        elnodo = typename tree<T>::node();
      }
  }

  return *this;
}


template <typename T>
inline typename tree<T>::const_level_iterator
tree<T>::begin_level() const
{
  if (!root().null())
    return const_level_iterator(laraiz);
  else
    return const_level_iterator();
}

template <typename T>
inline typename tree<T>::const_level_iterator
tree<T>::end_level() const
{
  return const_level_iterator(typename tree<T>::node());
}

template <typename T>
int tree<T>::grado_nodo(const typename tree<T>::node n)const{
  typename tree<T>::node nodoaux = n;
  int grado = 0;
  if(!nodoaux.left().null()){
    nodoaux = nodoaux.left();
    grado++;
      while(!nodoaux.next_sibling().null()){
        grado++;
        nodoaux = nodoaux.next_sibling();
      }
  }

  return grado;
}

template <typename T>
int tree<T>::grado()const{
  int grado = 0;
    for(tree<T>::const_preorder_iterator it = this->begin_preorder() ; it != this->end_preorder() ; it++){
      grado = max( grado , this->grado_nodo(*it));
    }

  return grado;
}

template <typename T>
list<T> camino(const tree<T> &arb,typename tree<T>::node a, int &longitud){
  typename tree<T>::node aux = arb.root();
  bool encontrado_camino = false;
  longitud = 0;
  list<T> a_devolver;

  a_devolver.push_back(*aux);
 
    while(!encontrado_camino){
      if(aux == a){
        encontrado_camino = true;
      }else{

        if(!aux.left().null()){
          aux = aux.left();
          a_devolver.push_back(*aux);
          longitud++;
        }else if(!aux.next_sibling().null()){
          a_devolver.pop_back();
          aux = aux.next_sibling();
          a_devolver.push_back(*aux);
        }else{
          a_devolver.pop_back();
          aux = aux.parent();
          a_devolver.pop_back();
          aux = aux.next_sibling();
          a_devolver.push_back(*aux);
          longitud--;
        }

      }
    }

  return a_devolver;
}

template <typename T>
int altura(const tree<T> a, typename tree<T>::node n){
  int altura = 0;
  
  if(!n.left().null()){
    n = n.left();
    altura = altura(n);

    while(!n.next_sibling().null()){
      altura = max(altura , altura(n.next_sibling()));
      n = n.next_sibling();
    }
    altura++; 
  }

  return altura;
}

