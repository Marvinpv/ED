/**
 * @file ejercicio12.cpp
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

bool mayor(string cadena1, string cadena2){
    bool mayor;

        if(cadena1.length() > cadena2.length())
            mayor = true;
        else
            mayor = cadena1 > cadena2;
    
    return mayor;
}

class ColaconPrioridad{
    private:
    list<string> cola_cadenas;

    public:
    ColaconPrioridad();

    ColaconPrioridad(const ColaconPrioridad &otra){
        cola_cadenas = otra.cola_cadenas;
    }

    void push(string cad){
        if(cola_cadenas.empty()){
            cola_cadenas.push_back(nc);
        }else{
            list<nombre_completo>::iterator iter;
            iter = cola_cadenas.end();
            
            while(iter != cola_cadenas.begin() && mayor(cad,*iter))
                iter--;

            if((*iter) < cad)
                iter++;
            
            cola_nombres.insert(iter,cad);
        }
    }

    string front()const{
        return cola_cadenas.front();
    }

    void pop(){
        list<string>::iterator it = cola_cadenas.begin();
        cola_cadenas.erase(it);
    }

    bool empty()const{
        return cola_cadenas.empty();
    }

    int size()const{
        return cola_cadenas.size();
    }


    const ColaconPrioridad & operator=(const ColaconPrioridad &otro){
        if(this != &otro){
            cola_cadenas = otro.cola_cadenas;
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