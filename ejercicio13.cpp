/**
 * @file ejercicio13.cpp
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
list<T> lista_posiciones(const list<T> &l, const list<typename list<T>::iterator> &li){
    list<T> a_devolver;
    typename list<typename list<T>::iterator>::const_iterator iter_i = li.cbegin();

    while(iter_i != li.cend()){
        if(*iter_i != l.end())
            a_devolver.push_back(**iter_i);
        iter_i++;
    }

    return a_devolver;
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

    cout<<"Cogiendo posiciones desde el elemento nº3..."<<endl;
    list<list<int>::iterator> l_iters1;
    int i = 0;
    for(list<int>::iterator iter1 = lista1.begin() ; iter1 != lista1.end() ; iter1++){
        if(i > 3){
            l_iters1.push_back(iter1);
        }
        i++;
    }

    list<int> res1 = lista_posiciones(lista1, l_iters1);

    cout<<"Resultado: ";
    for(list<int>::iterator iter1 = res1.begin() ; iter1 != res1.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;


    //Ejemplo 2
    list<char> lista2;
    lista2.push_back('a');
    lista2.push_back('c');
    lista2.push_back('e');
    lista2.push_back('g');
    lista2.push_back('i');
    lista2.push_back('k');


    cout<<"Lista 2: ";
    for(list<char>::iterator iter2 = lista2.begin() ; iter2 != lista2.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;
    
    list<list<char>::iterator> l_iters2;
    i = 0;
    cout<<"Cogiendo elementos con índice impar..."<<endl;
    for(list<char>::iterator iter2 = lista2.begin(); iter2 != lista2.end() ; iter2++){
        if(i % 2 == 0)
            l_iters2.push_back(iter2);
        
        i++;
    }

    list<char> res2 = lista_posiciones(lista2, l_iters2);

    cout<<"Resultado: ";
    for(list<char>::iterator iter2 = res2.begin() ; iter2 != res2.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    //Ejemplo 3
    list<long> lista3;
    lista3.push_back(1);
    lista3.push_back(2);
    lista3.push_back(3);
    lista3.push_back(4);
    lista3.push_back(5);
    lista3.push_back(6);
    lista3.push_back(7);
    lista3.push_back(8);
    lista3.push_back(9);
    lista3.push_back(10);

    cout<<"Lista 3: ";
    for(list<long>::iterator iter3 = lista3.begin() ; iter3 != lista3.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;

    cout<<"Cogiendo primer y último elemento..."<<endl;
    list<list<long>::iterator> l_iters3;
    list<long>::iterator iter3 = lista3.begin();
    l_iters3.push_back(iter3);
    while(*iter3 != 10)
        iter3++;
    
    l_iters3.push_back(iter3);

    list<long> res3 = lista_posiciones(lista3, l_iters3);

    cout<<"Resultado: ";
    for(list<long>::iterator iter3 = res3.begin() ; iter3 != res3.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;
}