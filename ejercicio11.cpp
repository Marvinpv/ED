/**
 * @file ejercicio11.cpp
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

void inserta_despues(list<int> &l, int x){
    int valor = x-1;

    for(list<int>::iterator iter = l.begin() ; iter != l.end() ; iter++){
        if(*iter == x){
            iter++;
            iter = l.insert(iter, valor);
        }
    }


}

int main(){

    //Ejemplo 1
    list<int> lista1;
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(2);
    lista1.push_back(3);
    lista1.push_back(5);
    lista1.push_back(6);

    
    cout<<"Lista 1: ";
    for(list<int>::iterator iter1 = lista1.begin() ; iter1 != lista1.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;

    cout<<"Calculando lista para x = 1..."<<endl;
    inserta_despues(lista1, 1);

    cout<<"Resultado: ";
    for(list<int>::iterator iter1 = lista1.begin() ; iter1 != lista1.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;


    //Ejemplo 2
    list<int> lista2;
    lista2.push_back(1);
    lista2.push_back(2);
    lista2.push_back(3);
    lista2.push_back(4);
    lista2.push_back(5);
    lista2.push_back(6);
    lista2.push_back(7);
    lista2.push_back(8);
    lista2.push_back(9);
    lista2.push_back(10);

    cout<<"Lista 2: ";
    for(list<int>::iterator iter2 = lista2.begin() ; iter2 != lista2.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;
    
    cout<<"Calculando lista para x = 10..."<<endl;
    inserta_despues(lista2, 10);

    cout<<"Resultado: ";
    for(list<int>::iterator iter2 = lista2.begin() ; iter2 != lista2.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    //Ejemplo 3
    list<int> lista3;
    lista3.push_back(10);
    lista3.push_back(11);
    lista3.push_back(12);
    lista3.push_back(13);
    lista3.push_back(14);
    lista3.push_back(15);
    lista3.push_back(16);
    lista3.push_back(17);
    lista3.push_back(18);
    lista3.push_back(19);

    cout<<"Lista 3: ";
    for(list<int>::iterator iter3 = lista3.begin() ; iter3 != lista3.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;

    cout<<"Calculando lista para x = 1..."<<endl;
    inserta_despues(lista3, 1);

    cout<<"Resultado: ";
    for(list<int>::iterator iter3 = lista3.begin() ; iter3 != lista3.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;


}