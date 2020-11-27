#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include <list>
#include <string>

using namespace std;

template<class T,class U>
struct data{
    T clave;
    list<U> info;
};

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

            for(typename list<data<T,U>>::iterator it = D.datos.begin() ; it != D.datos.end() ; it++){
                datos.push_back(*it);
            }

        }

        void Borrar(){
            datos.clear();
        }

    public:

        Diccionario(){
            this->Borrar();
        }

        Diccionario(const Diccionario &D){
            this->datos = D.datos;
        }

        ~Diccionario(){
            datos.~list();
        }


        typename list<data<T,U>>::iterator end(){
            return datos.end();
        }

        typename list<data<T,U>>::iterator begin(){
            return datos.begin();
        }

        Diccionario<T,U> & operator=(const Diccionario<T,U> &D){
            this->Copiar(D);
        }

        bool Esta_Clave(const T &p, typename list<data<T,U>>::iterator &it_out){
            bool esta = false;

            if(!datos.empty()){
                    it_out = this->end();
                it_out--;

                while((*it_out).clave > p)
                    it_out--;

                if((*it_out).clave == p)
                    esta = true;
                else{
                    it_out++;
                }
            }
            
            return esta;
        }

        void Insertar(const T &pclave,const list<U> &pinfo){
            data<T,U> nuevodato;
            nuevodato.clave = pclave;
            nuevodato.info = pinfo;

            if(!this->datos.empty()){
                
                typename list<data<T,U>>::iterator iter;
                cout <<"Bien hasta aqui";

                bool esta = Esta_Clave(pclave,iter);
                cout << "Funciona bien buscar";

                if(!esta)
                    this->datos.insert(iter,nuevodato);   
            }else{
                datos.push_back(nuevodato);
            }                               //Hay que eliminar los elementos repetidos?
            

        }

        void AddSignificado_Palabra(const U &s,const T &p){
            typename list<data<T,U>>::iterator iter;

            bool esta = Esta_Clave(p,iter);

            if(esta){
                (*iter).info.push_back(s);
            }else{
                cout<<"Entra aqui";
                data<T,U> nuevodato;
                cout<<"Hasta aqui bien";
                nuevodato.clave = p;
                nuevodato.info.push_back(s);
                Insertar(nuevodato.clave,nuevodato.info);
            }

        }

        list<U> getInfo_Asoc(const T &p){

            list<U> devolver;
            typename list<data<T,U>>::iterator iter;

            if(Esta_Clave(p,iter))
                devolver = (*iter).info;

            return devolver;

        }

        int size()const{
            return this->datos.size();
        }

        string Entradas_para_clave(const T &clave){
            string s;
            list<U> entradas = this->getInfo_Asoc(clave);
            int i = 1;
            for(typename list<U>::iterator iter = entradas.begin() ; iter != entradas.end() ; iter++){
                s += i+": ";
                s += *iter+"\n";
                i++;
            }

            return s;
        }
};

#endif