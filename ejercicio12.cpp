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

class ColaconPrioridad{
    private:
    list<string> cola_cadenas;

    public:
    ColaconPrioridad();

    ColaconPrioridad(const ColaconPrioridad &otra){
        cola_cadenas = otra.cola_cadenas;
    }

    void push(string nc){
        if(cola_cadenas.empty()){
            cola_cadenas.push_back(nc);
        }else{
            list<nombre_completo>::iterator iter;
            iter = cola_cadenas.end();
            
            while(iter != cola_cadenas.begin() && (*iter).prioridad > nc.prioridad)
                iter--;

            if((*iter).prioridad < nc.prioridad)
                iter++;
            
            cola_nombres.insert(iter,nc);
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