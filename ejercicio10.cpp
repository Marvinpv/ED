/**
 * @file ejercicio10.cpp
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
list<T> mezclar(const list<T> &l1, const list<T> &l2){
    list<T> resultado;
    typename list<T>::const_iterator iter1 = l1.cbegin();
    typename list<T>::const_iterator iter2 = l2.cbegin();

        while( iter1 != l1.cend() && iter2 != l2.cend() ){
            if(*iter1 < *iter2){
                resultado.push_back(*iter1);
                iter1++;
            }else{
                resultado.push_back(*iter2);
                iter2++;
            }
        }

        while(iter1 != l1.cend()){
            resultado.push_back(*iter1);
            iter1++;
        }

        while(iter2 != l2.cend()){
            resultado.push_back(*iter2);
            iter2++;
        }
    
    return resultado;
}

int main(){
    
    //Ejemplo 1
    list<int> lista1_a;
    lista1_a.push_back(1);
    lista1_a.push_back(1);
    lista1_a.push_back(1);
    lista1_a.push_back(1);
    lista1_a.push_back(1);
    lista1_a.push_back(2);
    lista1_a.push_back(3);
    lista1_a.push_back(5);
    lista1_a.push_back(6);

    list<int> lista1_b;
    lista1_b.push_back(1);
    lista1_b.push_back(1);
    lista1_b.push_back(1);
    lista1_b.push_back(1);
    lista1_b.push_back(1);
    lista1_b.push_back(2);
    lista1_b.push_back(3);
    lista1_b.push_back(5);
    lista1_b.push_back(6);
    

    //Ejemplo 2
    list<char> lista2_a;
    lista2_a.push_back('a');
    lista2_a.push_back('c');
    lista2_a.push_back('e');
    lista2_a.push_back('g');
    lista2_a.push_back('i');
    lista2_a.push_back('k');

    list<char> lista2_b;
    lista2_b.push_back('b');
    lista2_b.push_back('d');
    lista2_b.push_back('f');
    lista2_b.push_back('h');
    lista2_b.push_back('j');
    lista2_b.push_back('m');

    //Ejemplo 3
    list<long> lista3_a;
    lista3_a.push_back(1);
    lista3_a.push_back(2);
    lista3_a.push_back(3);
    lista3_a.push_back(4);
    lista3_a.push_back(5);
    lista3_a.push_back(6);
    lista3_a.push_back(7);
    lista3_a.push_back(8);
    lista3_a.push_back(9);
    lista3_a.push_back(10);

    list<long> lista3_b;
    lista3_b.push_back(11);
    lista3_b.push_back(12);
    lista3_b.push_back(13);
    lista3_b.push_back(14);
    lista3_b.push_back(15);
    lista3_b.push_back(16);
    lista3_b.push_back(17);
    lista3_b.push_back(18);
    lista3_b.push_back(19);
    lista3_b.push_back(20);

    //Ejemplo 1
    cout<<"Lista 1(a): ";
    for(list<int>::iterator iter1 = lista1_a.begin() ; iter1 != lista1_a.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;

    cout<<"Lista 1(b): ";
    for(list<int>::iterator iter1 = lista1_b.begin() ; iter1 != lista1_b.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;

    list<int> lista1 = mezclar(lista1_a, lista1_b);

    cout<<"Resultado: ";
    for(list<int>::iterator iter1 = lista1.begin() ; iter1 != lista1.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;

    //Ejemplo 2
    cout<<"Lista 2(a): ";
    for(list<char>::iterator iter2 = lista2_a.begin() ; iter2 != lista2_a.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    cout<<"Lista 2(b): ";
    for(list<char>::iterator iter2 = lista2_b.begin() ; iter2 != lista2_b.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    list<char> lista2 = mezclar(lista2_a, lista2_b);

    cout<<"Resultado: ";
    for(list<char>::iterator iter2 = lista2.begin() ; iter2 != lista2.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    //Ejemplo 3
    cout<<"Lista 3(a): ";
    for(list<long>::iterator iter3 = lista3_a.begin() ; iter3 != lista3_a.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;

    cout<<"Lista 3(b): ";
    for(list<long>::iterator iter3 = lista3_b.begin() ; iter3 != lista3_b.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;

    list<long> lista3 = mezclar(lista3_a, lista3_b);

    cout<<"Resultado: ";
    for(list<long>::iterator iter3 = lista3.begin() ; iter3 != lista3.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;

}