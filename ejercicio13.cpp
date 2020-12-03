/**
 * @file ejercicio13.cpp
 * @author Marvin Peinado Vidaña
 * @brief 
 * @version 0.1
 * @date 2020-12-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

int vocales(string cad){
    int v = 0;
    for(int i = 0 ; i < cad.length() ; i++){
        char letra = tolower(cad[i]);
        if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
            v++;
    }

    return v;
}

bool mayor(string cad1, string cad2){
    bool mayor;
    int vocales1 = vocales(cad1),
        vocales2 = vocales(cad2);

        if(vocales1 > vocales2)
            mayor = true;
        else if(vocales2 > vocales1)
            mayor = false;
        else
            mayor = cad1 < cad2;
    
    return mayor;
}

class colaconprioridad{
    private:
    list<string> cola_cadenas;

    public:
    colaconprioridad(){

    }

    colaconprioridad(const colaconprioridad &otra){
        cola_cadenas = otra.cola_cadenas;
    }

    void push(string cad){                                        
        if(cola_cadenas.empty()){
            cola_cadenas.push_back(cad);
        }else{
            list<string>::iterator iter;
            iter = cola_cadenas.end();
            iter--;

            while((iter != cola_cadenas.begin()) && mayor(cad,*iter))
                iter--;
                

            if(mayor(*iter,cad))
                iter++;
            
            
            cola_cadenas.insert(iter,cad);
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


    const colaconprioridad & operator=(const colaconprioridad &otro){
        if(this != &otro){
            cola_cadenas = otro.cola_cadenas;
        }

        return *this;
    }
};

int main(){
    string cadena;
    colaconprioridad cola; 
    int nombres;
    cout<<"¿Cuántos nombres quiere introducir? ";
    cin >> nombres;

    for(int i = 0; i < nombres; i++){
        cout<<"Nombre: ";
        cin >>cadena;
        cola.push(cadena);
    }

    cout<<endl;
    while(!cola.empty()){
        cout<<cola.front()<<endl;
        cola.pop();
    }

}