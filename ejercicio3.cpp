/**
 * @file ejercicio3.cpp
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
#include <string>

using namespace std;

template<class T>
class ColaConPilas(){
    private:
        stack<T> cola;
        stack<T> auxiliar;
        int elementos
    public:

        ColaConPilas(){
            elementos = 0;
        }

        inline bool vacia()const{
           return elementos == 0; 
        }

        template<class T>
        void Cola_max::push(const T &n){
            if(this->vacia()){
                pila.push(n);
            }else{

                while(!pila.empty()){
                    auxiliar.push(pila.top());
                    pila.pop();
                
                }
                pila.push(n);

                while(!auxiliar.empty()){
                    pila.push(auxiliar.top());
                    auxiliar.pop();
                }

            }
            elementos++;
        }

        inline int size()const{
            return elementos;
        }

        inline int front()const{
            return pila.top();
        }

        inline void pop(){
            pila.pop();
            num_elementos--;
        }

        template<class T>
        T back()const{
            T max;
            auxiliar = pila;
            while(auxiliar.size() > 1)
                auxiliar.pop();
            
            max = auxiliar.top();
        }

        friend bool operator==(const ColaConPilas<T> &a,const ColaConPilas<T> &b);

};

template<class T>
bool operator==(const ColaConPilas<T> &a,const ColaConPilas<T> &b){
    stack<T> aux_a(a.pila);
    stack<T> aux_b(b.pila);
    bool iguales = true;

    if(aux_a.size() != aux_b.size())
        iguales = false;

    while(iguales && !aux_a.empty()){
        if(aux_a.top() =! aux_b.top())
            iguales = false;
        aux_a.pop();
        aux_b.pop();
    }

    return iguales;
}

template<class T>
bool operator<(const ColaConPilas<T> &a,const ColaConPilas<T> &b){

    stack<T> aux_1(a.elementos),aux_2(b.elementos);
    bool menor = true;

    while(aux_1.top() == aux_2.top() && !aux_1.empty() && !aux_2.empty()){
        aux_1.pop();
        aux_2.pop();  
    }

    if(aux_1.empty())
        menor = true;
    else if(aux_2.empty())
        menor = false;
    else
        menor = aux_1.top() < aux_2.top();

    return menor;

}


int main(){
    ColaConPilas<int> p,q;
    int i;
    for( i = 0 ; i <= 10 ; i++){
        p.push(i);
        q.push(i);
    }
  
    if(p == q)
        cout<<"p y q son iguales"<<endl;
        
    p.push(11);        //Para ver si funciona 
    p.push(9);         //bien el elemento máximo

    cout<<"Primer elemento: "<<p.front()<<endl<<"Último elemento: "<<p.back()<<endl;
    while(!p.vacia()){
        cout<<endl<<"Elemento:"<<p.front()<<endl<<"Número de elementos: "<<p.size()<<endl;
        p.pop();
    }

    ColaConPilas c;
    bool salir = false;
    int opcion;
    cout<<"Prueba de la clase ColaConPilas"<<endl;
    do{
        cout<<"¿Qué desea hacer?"<<endl
            <<"1: meter un elemento"<<endl
            <<"2: sacar un elemento"<<endl
            <<"3: conocer el frente"<<endl
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
            cout<<"El frente es "<<c.front()<<endl;
            break;
        default:
            salir = true;
            break;
        }
    }while(!salir);

    return 0;
}
