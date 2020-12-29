/**
 * @file ejercicio06.cpp
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
#include <vector>
#include <list>
#include <set>

using namespace std;

template <typename T>
void elimina(list<T> &l , const vector<T> &v){
    set<T> contenido_v;
    //O(n*log(n))
    for(typename vector<T>::const_iterator iter_vec = v.cbegin() ; iter_vec != v.cend() ; iter_vec++){
        contenido_v.insert(*iter_vec);
        //l.remove(*iter_vec);          ----> otra solucion(un poco menos eficiente)
    }

    //O(n*log(n))
    for(typename list<T>::iterator iter_list = l.begin() ; iter_list != l.end() ; iter_list++){
        if(contenido_v.count(*iter_list) > 0){
            iter_list = l.erase(iter_list);
            iter_list--;
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

    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(6);

    list<char> lista2;
    lista2.push_back('b');
    lista2.push_back('c');
    lista2.push_back('d');
    lista2.push_back('e');
    lista2.push_back('f');
    lista2.push_back('g');

    vector<char> vec2;
    vec2.push_back('h');
    vec2.push_back('i');
    vec2.push_back('j');
    vec2.push_back('k');


    list<string> lista3;
    lista3.push_back("Hola");
    lista3.push_back("Que tal");
    lista3.push_back("Muy bien");
    lista3.push_back("Que tal");
    lista3.push_back("Muy bien");
    lista3.push_back("Hola");
    lista3.push_back("Hola");

    vector<string> vec3;
    vec3.push_back("Que tal");
    vec3.push_back("Muy bien");



    //Ejemplo 1
    cout<<"Lista 1: ";
    for(list<int>::iterator iter1 = lista1.begin() ; iter1 != lista1.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;
    
    cout<<"Vector 1: ";
    for(vector<int>::iterator iter1 = vec1.begin() ; iter1 != vec1.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;

    elimina(lista1 , vec1);

    cout<<"Resultado: ";
    for(list<int>::iterator iter1 = lista1.begin() ; iter1 != lista1.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;

    //Ejemplo 2

    cout<<"Lista 2: ";
    for(list<char>::iterator iter2 = lista2.begin() ; iter2 != lista2.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;
    
    cout<<"Vector 2: ";
    for(vector<char>::iterator iter2 = vec2.begin() ; iter2 != vec2.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    elimina(lista2 , vec2);

    cout<<"Resultado: ";
    for(list<char>::iterator iter2 = lista2.begin() ; iter2 != lista2.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    //Ejemplo 3

    cout<<"Lista 3: ";
    for(list<string>::iterator iter3 = lista3.begin() ; iter3 != lista3.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;
    
    cout<<"Vector 3: ";
    for(vector<string>::iterator iter3 = vec3.begin() ; iter3 != vec3.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;

    elimina(lista3 , vec3);

    cout<<"Resultado: ";
    for(list<string>::iterator iter3 = lista3.begin() ; iter3 != lista3.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;




}