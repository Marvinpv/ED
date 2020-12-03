/**
 * @file ejercicio10.cpp
 * @author Marvin Peinado Vidaña
 * @brief 
 * @version 0.1
 * @date 2020-11-29
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

template<class T>
class ventana{
    private:                //La decision es arbitraria, en mi caso el elemento
        stack<T> pila_izq;  //actual se encontrará en el tope de la pila de la izquierda
        stack<T> pila_dch;
    public:
        ventana(){

        }

        ventana(const ventana<T> &otra){
            pila_izq = otra.pila_izq;
            pila_dch = otra.pila_dch;
        }


        void insertar(T elemento){
            pila_izq.push(elemento);
        }

        void mover_derecha(){
            if(!fin()){
                pila_izq.push(pila_dch.top());
                pila_dch.pop();
            }
        }

        void mover_izquierda(){
            if(!inicio()){
                pila_dch.push(pila_izq.top());
                pila_izq.pop();
            }
        }

        void borrar_elemento(){
            pila_izq.pop();
        }

        T devolver_elemento()const{
            return pila_izq.top();
        }

        bool fin()const{
            return pila_dch.empty();
        }

        bool inicio()const{
            return pila_izq.empty();
        }

};


int main(){

    ventana<int> v;
    bool salir = false;
    int opcion;
    cout<<"Prueba de la clase ventana"<<endl;
    do{
        cout<<"¿Qué desea hacer?"<<endl
            <<"1: meter un elemento"<<endl
            <<"2: sacar un elemento"<<endl
            <<"3: conocer el elemento actual"<<endl
            <<"4: mover a la derecha"<<endl
            <<"5: mover a la izquierda"<<endl
            <<"6: salir e imprimir contenido"<<endl;

        cin>>opcion;

        switch (opcion)
        {
        case 1:
            int elem;
            cout<<"Elemento: ";
            cin >>elem;
            v.insertar(elem);
            break;
        case 2:
            v.borrar_elemento();
            cout<<"Elemento eliminado..."<<endl;
            break;
        case 3:
            cout<<"El elemento actual es "<<v.devolver_elemento()<<endl;
            break;
        case 4:
            cout<<"Movida una posicion a la derecha..."<<endl;
            v.mover_derecha();
            break;
        case 5:
            cout<<"Movida una posicion a la izquierda..."<<endl;
            v.mover_izquierda();
            break;
        default:
            salir = true;
            while(!v.inicio())
                v.mover_izquierda();
            
            cout<<"Contenido: "<<endl;
            while(!v.fin()){
                v.mover_derecha();
                cout<<v.devolver_elemento()<<" ";
                v.borrar_elemento();
            }
            cout<<endl;

            break;
        }
    }while(!salir);

    return 0;
}