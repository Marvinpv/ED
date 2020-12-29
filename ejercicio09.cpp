/**
 * @file ejercicio09.cpp
 * @author Marvin Peinado Vidaña 
 * @brief 
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string>
#include <cctype>
#include <list>

using namespace std;

template <typename T>
void inversa(list<T> &l){
    T aux;
    int superior = l.size() - 1;
    int inferior = 0;
    typename list<T>::iterator iter = l.begin();
    typename list<T>::reverse_iterator riter = l.rbegin();

    while(inferior < superior){
        aux = *riter;
        *riter = *iter;
        *iter = aux;

        superior--;
        inferior++;
        iter++;
        riter++;
    }
}

int main(){
    list<int> lista1;
    lista1.push_back(2);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(5);
    lista1.push_back(3);
    lista1.push_back(6);

    

    list<char> lista2;
    lista2.push_back('b');
    lista2.push_back('c');
    lista2.push_back('d');
    lista2.push_back('e');
    lista2.push_back('f');
    lista2.push_back('g');

    


    list<string> lista3;
    lista3.push_back("Hola");
    lista3.push_back("Que tal");
    lista3.push_back("Muy bien");
    lista3.push_back("Que tal");
    lista3.push_back("Muy bien");
    lista3.push_back("Hola");
    lista3.push_back("Hola");

    //Ejemplo 1
    cout<<"Lista 1: ";
    for(list<int>::iterator iter1 = lista1.begin() ; iter1 != lista1.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;

    inversa(lista1);

    cout<<"Resultado: ";
    for(list<int>::iterator iter1 = lista1.begin() ; iter1 != lista1.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;

    //Ejemplo 2

    cout<<"Lista 2: ";
    for(list<char>::iterator iter2 = lista2.begin() ; iter2 != lista2.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    inversa(lista2);

    cout<<"Resultado: ";
    for(list<char>::iterator iter2 = lista2.begin() ; iter2 != lista2.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    //Ejemplo 3

    cout<<"Lista 3: ";
    for(list<string>::iterator iter3 = lista3.begin() ; iter3 != lista3.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;

    inversa(lista3);

    cout<<"Resultado: ";
    for(list<string>::iterator iter3 = lista3.begin() ; iter3 != lista3.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;

    
}