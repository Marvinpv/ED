/**
 * @file ejercicio4.cpp
 * @author Marvin Peinado Vidaña
 * @brief 
 * @version 0.1
 * @date 2020-11-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <queue>
#include <string>
#include <cassert>

using namespace std;

template<class T>
class PilaConColas{
    private:
        queue<T> duo[2];
        int usando;
        
        int elementos;
    public:
        PilaConColas(){
            usando = 0;
            elementos = 0;
        }

        inline bool empty()const{
            return elementos == 0;
        }

        void push(const T &n){
            if(this->empty()){
                duo[usando].push(n);     //Si la pila está vacía se pone el elemento sin problema
            }else{
                
                int auxiliar = (usando+1)%2;

                duo[auxiliar].push(n);         //Se le mete el elemento

                while(!duo[usando].empty()){  
                    duo[auxiliar].push(duo[usando].front());        //Se van sacando los elementos de la cola
                    duo[usando].pop();                             //y se van metiendo en la auxiliar
                }

                usando = auxiliar;

            }

            elementos++;        //Se incrementa num_elementos
        }

        inline T top()const{
            
            
            return duo[usando].front();

        }

        void pop(){
            duo[usando].pop();
            elementos--;
        }

        inline int size()const{
            return elementos; 
        }

        friend bool operator<(const PilaConColas<T> & a,const PilaConColas<T> &b){
            queue<T> aux_1 = a.duo[a.usando];
            queue<T> aux_2 = b.duo[b.usando];
            bool menor = true;

            while(aux_1.front() == aux_2.front() && !aux_1.empty() && !aux_2.empty()){
                aux_1.pop();             //Se busca el primer elemento diferente
                aux_2.pop();  
            }

            if(aux_1.empty())               //Si todos los elementos son iguales y a es mas corta que b, entonces menor es true
                menor = true;
            else if(aux_2.empty())
                menor = false;              //Si ocurre lo mismo pero con b en vez de a, entonces menor es false
            else
                menor = aux_1.front() < aux_2.front(); //Si se ha llegado a un elemento distinto entonces se calcula cual es menor

            return menor;
        }

        friend bool operator==(const PilaConColas & a, const PilaConColas & b){
            queue<T> aux_1(a.duo[a.usando]),aux_2(b.duo[b.usando]);
            bool igual = true;
                
                if(aux_1.size() != aux_2.size())
                    igual = false;          //Si no tienen el mismo número de elementos ya sabemos que no son iguales

                while(igual && !aux_1.empty()){
                    if(aux_1.front() != aux_2.front())    //Si tienen el mismo número de elementos
                        igual = false;                      //Se comprueban 1 a 1 los elementos de cada pila
                    aux_1.pop();
                    aux_2.pop();
                }

            return igual;
        }
};



int main(){
    PilaConColas<int> p,q;
    int i;
    for( i = 10 ; i >= 0 ; i--){
        p.push(i);
        q.push(i);
    }

    if(p == q)
        cout<<"p y q son iguales"<<endl;
        
    p.push(11);        //Para ver si funciona 
    p.push(9);         //bien el elemento máximo
    while(!p.empty()){
        cout<<"Elemento:"<<p.top()<<endl<<"Número de elementos: "<<p.size()<<endl;
        p.pop();
    }

    PilaConColas<int> c;
    bool salir = false;
    int opcion;
    cout<<"Prueba de la clase PilaConColas"<<endl;
    do{
        cout<<"¿Qué desea hacer?"<<endl
            <<"1: meter un elemento"<<endl
            <<"2: sacar un elemento"<<endl
            <<"3: conocer el tope"<<endl
            <<"4: salir"<<endl;

        cin>>opcion;

        switch (opcion)
        {
        case 1:
            int elem;
            cout<<"Elemento: ";
            cin >>elem;
            c.push(elem);
            break;
        case 2:
            c.pop();
            cout<<"Elemento eliminado..."<<endl;
            break;
        case 3:
            cout<<"El tope es "<<c.top()<<endl;
            break;
        default:
            salir = true;
            break;
        }
    }while(!salir);


    return 0;
}