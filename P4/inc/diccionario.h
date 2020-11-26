#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include <list>


using namespace std;

template<class T,class U>
struct data{
    T clave;
    list<U> info;
}

template<class T,class U>
bool operator<(const data<T,U> &d1, const data<T,U> &d2){

    if(d1.clave < d2.clave)
        return true;
    
    return false;
}




template<class T,class U>
class Diccionario{
    private:

        list<data<T,U>> datos;

        void Copiar(const Diccionario<T,U> &D){
            this->Borrar();

            for(list<data<T,U>>::iterator it = D.datos.begin() ; it != D.datos.end() ; it++){
                datos.push_back(*it);
            }

        }

        void Borrar(){
            for(list<data<T,U>>::iterator it = datos.begin() ; it != datos.end() ; it++){
                datos.erase(it);
            }
        }

    public:

        Diccionario(); //No hay nada que hacer?? PREGUNTAR

        Diccionario(const Diccionario &D); //Función copiar???

        ~Diccionario();

        Diccionario<T,U> & operator=(const Diccionario<T,U> &D);

        bool Esta_Clave(const T &p, typename list<data<T,U>>::iterator &it_out);

        void Insertar(const T &clave,const list<U> &info);

        void AddSignificado_Palabra(const U &s,const T &p);

        list<U> getInfo_Asoc(const T &p);

        int size()const;

}