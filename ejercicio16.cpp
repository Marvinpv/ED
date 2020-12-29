/**
 * @file ejercicio16.cpp
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
#include <vector>

using namespace std;

template <typename T>
list<pair<T,int>> comprimir(const list<T> &l){

    typename list<T>::const_iterator iter = l.cbegin();
    list<pair<T,int>> lista_comprimida;
    if(!l.empty()){
        pair<T, int> valor_actual = make_pair(*iter,0);
    

        while(iter != l.end()){
            if(*iter == valor_actual.first){
                valor_actual.second++;
            }else{
                lista_comprimida.push_back(valor_actual);
                valor_actual = make_pair(*iter,1); 
            }
            iter++;
        }
        lista_comprimida.push_back(valor_actual);
    }
        


    return lista_comprimida;
}

template <typename T>
list<T> descomprimir(const list<pair<T,int>> &lc){
    list<T> lista_descomprimida;
    
    for(typename list<pair<T,int>>::const_iterator iter = lc.cbegin() ; iter != lc.cend() ; iter++){
        int veces = iter->second;
        while(veces > 0){
            lista_descomprimida.push_back(iter->first);
            veces--;
        }
    }

    return lista_descomprimida;
}

int main(){
    list<int> lista1;
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(2);
    lista1.push_back(2);
    lista1.push_back(2);
    lista1.push_back(2);
    lista1.push_back(2);
    lista1.push_back(2);
    lista1.push_back(7);
    lista1.push_back(7);
    lista1.push_back(7);
    lista1.push_back(7);
    lista1.push_back(7);
    lista1.push_back(12);
    lista1.push_back(1);
    lista1.push_back(1);
    lista1.push_back(5);
    lista1.push_back(5);

    

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
    lista4.push_back(99);
    lista4.push_back(99);
    lista4.push_back(99);
    lista4.push_back(99);
    lista4.push_back(99);
    lista4.push_back(99);
    lista4.push_back(99);
    lista4.push_back(99);
    lista4.push_back(99);
    lista4.push_back(99);

    //Ejemplo 1
    cout<<"Lista 1: ";
    for(list<int>::iterator iter1 = lista1.begin() ; iter1 != lista1.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;

    list<pair<int,int>> lista1_c = comprimir(lista1);

    cout<<"Resultado compresión: ";
    for(list<pair<int,int>>::iterator iter1 = lista1_c.begin() ; iter1 != lista1_c.end() ; iter1++)
        cout<<"("<<(*iter1).first<<","<<(*iter1).second<<") ";
    cout<<endl;

    list<int> lista1_dc = descomprimir(lista1_c);

    cout<<"Resultado descompresión: ";
    for(list<int>::iterator iter1 = lista1_dc.begin() ; iter1 != lista1_dc.end() ; iter1++)
        cout<<*iter1<<" ";
    cout<<endl;

    //Ejemplo 2

    cout<<"Lista 2: ";
    for(list<char>::iterator iter2 = lista2.begin() ; iter2 != lista2.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    list<pair<char,int>> lista2_c = comprimir(lista2);

    cout<<"Resultado compresión: ";
    for(list<pair<char,int>>::iterator iter2 = lista2_c.begin() ; iter2 != lista2_c.end() ; iter2++)
        cout<<"("<<(*iter2).first<<","<<(*iter2).second<<") ";
    cout<<endl;

    list<char> lista2_dc = descomprimir(lista2_c);

    cout<<"Resultado descompresión: ";
    for(list<char>::iterator iter2 = lista2_dc.begin() ; iter2 != lista2_dc.end() ; iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    //Ejemplo 3

    cout<<"Lista 3: ";
    for(list<string>::iterator iter3 = lista3.begin() ; iter3 != lista3.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;

    list<pair<string,int>> lista3_c = comprimir(lista3);

    cout<<"Resultado compresión: ";
    for(list<pair<string,int>>::iterator iter3 = lista3_c.begin() ; iter3 != lista3_c.end() ; iter3++)
        cout<<"("<<(*iter3).first<<","<<(*iter3).second<<") ";
    cout<<endl;

    list<string> lista3_dc = descomprimir(lista3_c);

    cout<<"Resultado descompresión: ";
    for(list<string>::iterator iter3 = lista3_dc.begin() ; iter3 != lista3_dc.end() ; iter3++)
        cout<<*iter3<<" ";
    cout<<endl;

    //Ejemplo 4

    cout<<"Lista 4: ";
    for(list<long>::iterator iter4 = lista4.begin() ; iter4 != lista4.end() ; iter4++)
        cout<<*iter4<<" ";
    cout<<endl;

    list<pair<long,int>> lista4_c = comprimir(lista4);

    cout<<"Resultado compresión: ";
    for(list<pair<long,int>>::iterator iter4 = lista4_c.begin() ; iter4 != lista4_c.end() ; iter4++)
        cout<<"("<<(*iter4).first<<","<<(*iter4).second<<") ";
    cout<<endl;

    list<long> lista4_dc = descomprimir(lista4_c);

    cout<<"Resultado descompresión: ";
    for(list<long>::iterator iter4 = lista4_dc.begin() ; iter4 != lista4_dc.end() ; iter4++)
        cout<<*iter4<<" ";
    cout<<endl;


}