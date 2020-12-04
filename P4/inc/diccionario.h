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

        void Copiar(const Diccionario<T,U>& Dicc){
            datos.assign(Dicc.datos.begin(),Dicc.datos.end());
        }

        void Borrar(){
            this->datos.erase(datos.begin(),datos.end());
        }

    public:

        Diccionario(){

        }

        Diccionario(const Diccionario<T,U> &D){
            this->datos = D.datos;
        }

        ~Diccionario(){

        }
        

        typedef typename list<data<T,U>>::iterator iterator;

        typedef typename list<data<T,U>>::const_iterator const_iterator;

        typename Diccionario<T,U>::iterator end(){
            return datos.end();
        }

        typename Diccionario<T,U>::iterator begin(){
            return datos.begin();
        }

        const typename Diccionario<T,U>::const_iterator cend()const{
            return datos.cend();
        }

        const typename Diccionario<T,U>::const_iterator cbegin()const{
            return datos.cbegin();
        }

        

        bool Esta_Clave(const T &p, typename Diccionario<T,U>::iterator &it_out){
            bool esta = false;

            if(!datos.empty()){
                    it_out = this->end();
                it_out--;

                while((*it_out).clave > p && it_out != this->begin())
                    it_out--;

                if((*it_out).clave == p)
                    esta = true;
                else if((*it_out).clave < p)
                    it_out++;
                
            }
            
            return esta;
        }

        void Insertar(const T &pclave,const list<U> &pinfo){
            data<T,U> nuevodato;
            nuevodato.clave = pclave;
            nuevodato.info = pinfo;

            if(!this->datos.empty()){
                
                Diccionario<T,U>::iterator iter;
                

                bool esta = Esta_Clave(pclave,iter);
                

                if(!esta)
                    this->datos.insert(iter,nuevodato);
  
            }else{
                datos.push_back(nuevodato);
            }                              
            

        }

        void AddSignificado_Palabra(const U &s,const T &p){
            Diccionario<T,U>::iterator iter;

            bool esta = Esta_Clave(p,iter);

            if(esta){
                (*iter).info.push_back(s);
            }else{
                data<T,U> nuevodato;
                nuevodato.clave = p;
                nuevodato.info.push_back(s);
                Insertar(nuevodato.clave,nuevodato.info);
            }

        }

        list<U> getInfo_Asoc(const T &p){

            list<U> devolver;
            Diccionario<T,U>::iterator iter;

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
                char ic = (char)i + '0';
                    s +="\t";
                    s += ic  ;
                    s += ": " + *iter;
                    s += "\n";
                    i++;
            }

            return s;
        }

        Diccionario & operator+=(Diccionario<T,U> & otro){
            typename Diccionario<T,U>::iterator iter ;                   //Utilidad adicional
            for(iter = otro.begin() ; iter != otro.end() ; iter++){
                this->Insertar((*iter).clave,(*iter).info);
            }

            return *this;
        }

        string Contenido_del_Diccionario(){                            //Utilidad adicional

            string s;
            for(typename Diccionario<T,U>::iterator iter = this->begin() ; iter != this->end() ; iter++){
                s+= (*iter).clave + ":\n";
                list<U> entradas = (*iter).info;
                int i = 1;
                for(typename list<U>::iterator iter = entradas.begin() ; iter != entradas.end() ; iter++){
                    char ic = (char)i + '0';
                    s +="\t";
                    s += ic  ;
                    s += ": " + *iter;
                    s += "\n";
                    i++;
                }

            }

            return s;
        }

        bool operator==(const Diccionario &otro){
            return datos == otro.datos;
        }
};

#endif