/**
 * @file ejercicio6.cpp
 * @author Marvin Peinado Vidaña
 * @brief 
 * @version 0.1
 * @date 2020-11-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

template<class T>
void insertar(stack<T> &P, int pos, const T &x){
    stack<T> aux;

    for(int i = P.size() ; i > pos && !P.empty() ; i--){
        aux.push(P.top());
        P.pop();
    }

    P.push(x);

    while(!aux.empty()){
        P.push(aux.top());
        aux.pop();
    }
}


int main(){
    stack<int> pila;
    int elemento,posicion;

    for(int i = 10 ; i>0 ; i--)
        pila.push(i);
    
    cout<<"Pila con elementos del 1 al 10"<<endl;
    cout<<"Entero a insertar: ";
    cin >>elemento;
    cout<<"Posicion: ";
    cin >>posicion;

    insertar(pila,posicion,elemento);

    cout<<"La pila ha quedado así: "<<endl;
    while(!pila.empty()){
        cout<<pila.top()<<" ";
        pila.pop();
    }
    cout<<endl;

    return 0;
}