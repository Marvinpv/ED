/**
 * @file ejercicio07.cpp
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
void elimina_duplicados(list<T> &l){
    set<T> elementos;

    for(typename list<T>::iterator iter = l.begin() ; iter != l.end() ; iter++){//O(n)

        
        if(elementos.count(*iter) > 0){//O(log(n))
            iter = l.erase(iter);
            iter--;
        }else{
            elementos.insert(*iter);//O(log(n))
        }
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

    list<long> lista4;
    lista4.push_back(3);
    lista4.push_back(3);
    lista4.push_back(3);
    lista4.push_back(3);
    lista4.push_back(3);
    lista4.push_back(3);


    //Ejemplo 1
    cout<<"Lista 1: ";
    for(list<int>::iterator iter1 = lista1.begin() ; iter1 != lista1.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;

    elimina_duplicados(lista1);

    cout<<"Resultado: ";
    for(list<int>::iterator iter1 = lista1.begin() ; iter1 != lista1.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;

    //Ejemplo 2

    cout<<"Lista 2: ";
    for(list<char>::iterator iter2 = lista2.begin() ; iter2 != lista2.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    elimina_duplicados(lista2);    

    cout<<"Resultado: ";
    for(list<char>::iterator iter2 = lista2.begin() ; iter2 != lista2.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    //Ejemplo 3

    cout<<"Lista 3: ";
    for(list<string>::iterator iter3 = lista3.begin() ; iter3 != lista3.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;

    elimina_duplicados(lista3);

    cout<<"Resultado: ";
    for(list<string>::iterator iter3 = lista3.begin() ; iter3 != lista3.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;

    //Ejemplo 4

    cout<<"Lista 4: ";
    for(list<long>::iterator iter4 = lista4.begin() ; iter4 != lista4.end() ; iter4++)
        cout<<*iter4<<" ";
    cout<<endl;

    elimina_duplicados(lista4);

    cout<<"Resultado: ";
    for(list<long>::iterator iter4 = lista4.begin() ; iter4 != lista4.end() ; iter4++)
        cout<<*iter4<<" ";
    cout<<endl;
    
}