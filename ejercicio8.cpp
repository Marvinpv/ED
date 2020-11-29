/**
 * @file ejercicio8.cpp
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
#include <stack>
#include <string>
#include <cmath>

using namespace std;

bool palindromo(string cadena){
    stack<char> pila_aux;
    queue<char> cola_aux;

    for(int i = 0 ; i < cadena.length() ; i++){
        pila_aux.push(cadena[i]);
        cola_aux.push(cadena[i]);
    }

    bool es_palindromo = true;

    for(int i = 0; i < cadena.length() && es_palindromo; i++){
        if(pila_aux.top() != cola_aux.front())
            es_palindromo = false;

        pila_aux.pop();
        cola_aux.pop();
    }

    return es_palindromo;

}

int main(){
    string palabra;

    cout<< "Inserta palabra para saber si es un palindromo: ";
    cin >> palabra;

    if(palindromo(palabra))
        cout<<"Es un palindromo"<<endl;
    else
        cout<<"No es un palindromo"<<endl;
    
    return 0;
    
}