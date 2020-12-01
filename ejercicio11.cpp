/**
 * @file ejercicio11.cpp
 * @author Marvin Peinado Vidaña
 * @brief 
 * @version 0.1
 * @date 2020-11-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>
#include <list>
#include <string>
#include <cmath>

using namespace std;

struct nombre_completo{
    string apellidos;
    string nombre;
    int prioridad;
};

class ColaconPrioridad{
    private:
    list<nombre_completo> cola_nombres;
    public:
    ColaconPrioridad(){

    }

    ColaconPrioridad(const ColaconPrioridad &otra){
        cola_nombres = otra.cola_nombres;
    }

    void push(nombre_completo nc){
        if(cola_nombres.empty()){
            cola_nombres.push_back(nc);
        }else{
            list<nombre_completo>::iterator iter;
            iter = cola_nombres.end();
            iter--;

            while(iter != cola_nombres.begin() && (*iter).prioridad > nc.prioridad)
                iter--;

            if((*iter).prioridad < nc.prioridad)
                iter++;
            
            cola_nombres.insert(iter,nc);
        }
    }

    nombre_completo front()const{
        return cola_nombres.front();
    }

    void pop(){
        list<nombre_completo>::iterator it = cola_nombres.begin();
        cola_nombres.erase(it);
    }

    bool empty()const{
        return cola_nombres.empty();
    }

    int size()const{
        return cola_nombres.size();
    }


    const ColaconPrioridad & operator=(const ColaconPrioridad &otro){
        if(this != &otro){
            cola_nombres = otro.cola_nombres;
        }

        return *this;
    }

};



int main(){
    nombre_completo nc;
    ColaconPrioridad cola; 
    int nombres;
    cout<<"¿Cuántos nombres quiere introducir? ";
    cin >> nombres;

    for(int i = 0; i < nombres; i++){
        cout<<"Nombre: ";
        cin >>nc.nombre;
        cin.ignore();
        cout<<"Apellidos: ";
        getline(cin,nc.apellidos);
        cout<<"Prioridad: ";
        cin >> nc.prioridad;
        cola.push(nc);
    }

    cout<<endl;
    while(!cola.empty()){
        cout<<cola.front().nombre<<" "<<cola.front().apellidos<<endl;
        cola.pop();
    }

}