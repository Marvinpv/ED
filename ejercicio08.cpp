/**
 * @file ejercicio08.cpp
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
#include <set>

using namespace std;

template <typename T>
list<T> inversa(const list<T> &l){
    list<T> devolver;

    for(typename list<T>::const_iterator iter = l.cbegin() ; iter != l.cend() ; iter++){
        devolver.push_front(*iter);
    }

    return devolver;
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

    list<int> lista_i1 = inversa(lista1);

    cout<<"Resultado: ";
    for(list<int>::iterator iter1 = lista_i1.begin() ; iter1 != lista_i1.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;

    //Ejemplo 2

    cout<<"Lista 2: ";
    for(list<char>::iterator iter2 = lista2.begin() ; iter2 != lista2.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    list<char> lista_i2 = inversa(lista2);

    cout<<"Resultado: ";
    for(list<char>::iterator iter2 = lista_i2.begin() ; iter2 != lista_i2.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    //Ejemplo 3

    cout<<"Lista 3: ";
    for(list<string>::iterator iter3 = lista3.begin() ; iter3 != lista3.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;

    list<string> lista_i3 = inversa(lista3);

    cout<<"Resultado: ";
    for(list<string>::iterator iter3 = lista_i3.begin() ; iter3 != lista_i3.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;

    
}