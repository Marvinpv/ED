/**
 * @file ejercicio1.cpp
 * @author Marvin Peinado Vidaña
 * @brief 
 * @version 0.1
 * @date 2020-11-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <stack>

using namespace std;

template<class T>
void modificar(stack<T> &P,const T &x,const T &y){
    stack<T> aux;
    T elem;
        while(!P.empty()){
            elem = P.top();
            if(elem == x){
                aux.push(y);
            }else{
                aux.push(elem);
            }
            P.pop();
        }

        while(!aux.empty()){
            P.push(aux.top());
            aux.pop();
        }
}


int main(){
    stack<int> prueba;

    for(int i = 0 ;i < 10 ;i++){
        prueba.push(i%2); //Metemos 5 unos y 5 ceros en la pila
    }

    stack<int> para_imprimir = prueba;

    cout<<"Pila introducida: "<<endl;
    for(int i = 0 ;i < para_imprimir.size() ; i++){
        cout<<para_imprimir.top()<<" ";
        para_imprimir.pop();
    }
    cout<<endl;

    modificar(prueba,0,1);

    cout<<"Cambiados ceros por unos..."<<endl;
    for(int i = 0 ;i < prueba.size() ; i++){
        cout<<prueba.top()<<" ";
        prueba.pop();
    }
    cout<<endl;

    return 0;
}