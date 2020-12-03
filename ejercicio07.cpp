/**
 * @file ejercicio7.cpp
 * @author Marvin Peinado Vidaña
 * @brief 
 * @version 0.1
 * @date 2020-11-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

template<class T>
void insertar(queue<T> &P, int pos, const T &x){
    queue<T> auxiliar;

    for(int i = 0 ; i < pos ; i++){
        auxiliar.push(P.front());
        P.pop();
    }

    auxiliar.push(x);

    while(!P.empty()){
        auxiliar.push(P.front());
        P.pop();
    }

    P = auxiliar;
}

int main(){
     queue<int> cola;
    int elemento,posicion;

    for(int i = 1 ; i<=10 ; i++)
        cola.push(i);
    
    cout<<"Cola con elementos del 1 al 10"<<endl;
    cout<<"Entero a insertar: ";
    cin >>elemento;
    cout<<"Posicion: ";
    cin >>posicion;

    insertar(cola,posicion,elemento);

    cout<<"La cola ha quedado así: "<<endl;
    while(!cola.empty()){
        cout<<cola.front()<<" ";
        cola.pop();
    }
    cout<<endl;

    return 0;
}