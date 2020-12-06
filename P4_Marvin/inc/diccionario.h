/**
 * @file diccionario.h
 * @author Marvin Peinado Vidaña
 * @brief Definicion e implementacion de la clase diccionario
 * @version 0.1
 * @date 2020-12-05
 * 
 * @copyright Copyright (c) 2020
 * 
 * Para evitar ciertos errores se han implementado los métodos
 * de la clase en el fichero de cabecera
 */

#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include <list>
#include <string>

using namespace std;

/**
 * @brief Struct data
 * 
 * @tparam T clave de la entrada
 * @tparam U definiciones para la clave
 * Struct de que se van a componer cada entrada de la lista
 * que compone el TDA Diccionario
 */
template<class T,class U>
struct data{
    T clave;
    list<U> info;
};

/**
 * @brief Operador < para dos elementos tipo data
 * 
 * @tparam T clave de la entrada
 * @tparam U definiciones para la clave
 * @param d1 elemento a comparar
 * @param d2 elemento a comparar
 * @return true si la clave de d1 es menor que la de d2
 * @return false si la clave de d2 es mayor o igual que la de d1
 */
template<class T,class U>
bool operator<(const data<T,U> &d1, const data<T,U> &d2){

    if(d1.clave < d2.clave)
        return true;
    
    return false;
}



/**
 * @brief Clase Diccionario
 * 
 * @tparam T Tipo de la clave de cada entrada
 * @tparam U Tipo de las definiciones para la clave T
 */
template<class T,class U>
class Diccionario{
    private:

        list<data<T,U>> datos;  //Lista donde se almacenarán las entradas

        /**
         * @brief Función auxiliar que copia el contenido de Dicc en el
         *        diccionario que llama a la función
         * 
         * @param Dicc Diccionario del que se copiarán los datos
         */
        void Copiar(const Diccionario<T,U>& Dicc){
            datos.assign(Dicc.datos.begin(),Dicc.datos.end());
        }

        /**
         * @brief Función auxiliar que borra el contenido del diccionario
         * 
         */
        void Borrar(){
            this->datos.erase(datos.begin(),datos.end());
        }

    public:

        /**
         * @brief Constructor por defecto
         * Se encuentra vacío por que datos ya llama
         * a su constructor por defecto al crear la clase
         */
        Diccionario(){

        }

        /**
         * @brief Constructor por copia
         * 
         * @param D Diccionario a copiar
         * Crea un diccionario exactamente igual a D
         */
        Diccionario(const Diccionario<T,U> &D){
            this->datos = D.datos;
        }

        /**
         * @brief Destructor
         * 
         * Se encuentra vacío ya que al acabar la ejecución,
         * datos llamará al destructor de list y no se necesitará
         * de ninguna otra llamada
         */
        ~Diccionario(){

        }
        
        /**
         * @brief Definicion de la clase iteradora de Diccionario
         * como un iterador del tipo de dato list<data<T,U>>
         */
        typedef typename list<data<T,U>>::iterator iterator;

        /**
         * @brief Definicion de la clase iteradora(constante) de Diccionario
         * como un iterador del tipo de dato list<data<T,U>>
         */
        typedef typename list<data<T,U>>::const_iterator const_iterator;

        /**
         * @brief Método que devuelve un iterador
         * apuntando al fin de la lista(elemento no perteneciente
         * a la lista que marca el fin de esta)
         * @return Diccionario<T,U>::iterator 
         */
        typename Diccionario<T,U>::iterator end(){
            return datos.end();
        }

        /**
         * @brief Método que devuelve un iterador
         * apuntando al inicio de la lista
         * @return Diccionario<T,U>::iterator 
         */
        typename Diccionario<T,U>::iterator begin(){
            return datos.begin();
        }

         /**
         * @brief Método que devuelve un iterador constante
         * apuntando al fin de la lista(elemento no perteneciente
         * a la lista que marca el fin de esta)
         * @return Diccionario<T,U>::iterator 
         */
        const typename Diccionario<T,U>::const_iterator cend()const{
            return datos.cend();
        }

        /**
         * @brief Método que devuelve un iterador
         * apuntando al inicio de la lista
         * @return Diccionario<T,U>::iterator 
         */
        const typename Diccionario<T,U>::const_iterator cbegin()const{
            return datos.cbegin();
        }

        
        /**
         * @brief Método que comprueba si existen entradas para una clave
         * p en un diccionario. Si la clave se encuentra en el diccionario,
         * el iterador it_out apuntará a esta, y si no se encuentra, it_out
         * apuntará al lugar donde debe insertarse
         * @param p clave a buscar
         * @param it_out iterador que se colocará en el lugar de la clave
         * @return true si se encuentra la clave en el diccionario
         * @return false si no se encuentra la clave en el diccionario
         */
        bool Esta_Clave(const T &p, typename Diccionario<T,U>::iterator &it_out){
            bool esta = false;

            if(!datos.empty()){
                    it_out = this->end();
                it_out--;

                while((*it_out).clave > p && it_out != this->begin()) //Mientras la clave sea mayor, se va decrementando, ya que 
                    it_out--;                                         //La lista se irá insertando ordenadamente

                if((*it_out).clave == p)                              
                    esta = true;                                       
                else if((*it_out).clave < p)                           //si no está la clave se coloca el iterador
                    it_out++;                                          //donde habría que insertarla
                
            }
            
            return esta;
        }

        /**
         * @brief Método que inserta una nueva entrada en el diccionario
         * 
         * @param pclave clave de la nueva entrada del diccionario
         * @param pinfo info asociada a esa clave
         * Si la clave ya se encuentra en el Diccionario, no se colocará
         * Si lo que se desea es añadir más info a una clave existente,
         * se tiene que utilizar el método AddSignificado_Palabra
         */
        void Insertar(const T &pclave,const list<U> &pinfo){
            data<T,U> nuevodato;
            nuevodato.clave = pclave;
            nuevodato.info = pinfo;

            if(!this->datos.empty()){                   //Si la lista no está vacía se busca el sitio donde colocar
                                                        //La nueva entrada
                Diccionario<T,U>::iterator iter;
                

                bool esta = Esta_Clave(pclave,iter);
                

                if(!esta)
                    this->datos.insert(iter,nuevodato); //Si no hay ninguna entrada con esa clave, se coloca
  
            }else{
                datos.push_back(nuevodato);
            }                              
            

        }

        /**
         * @brief Método para añadir un nuevo significado a una
         * clave del diccionario
         * @param s clave
         * @param p nuevo significado
         * Si la clave no se encuentra, se crea una nueva entrada con la clave
         * y su significado asociado
         */
        void AddSignificado_Palabra(const U &s,const T &p){
            Diccionario<T,U>::iterator iter;

            bool esta = Esta_Clave(p,iter);

            if(esta){
                (*iter).info.push_back(s);  //Si la clave está, se inserta el nuevo significado
            }else{
                data<T,U> nuevodato;
                nuevodato.clave = p;        //Si no está, se crea una nueva entrada
                nuevodato.info.push_back(s);
                Insertar(nuevodato.clave,nuevodato.info);
            }

        }

        /**
         * @brief Devuelve la información asociada a una
         * clave p
         * @param p clave  
         * @return list<U> lista donde se devolverá la información 
         */
        list<U> getInfo_Asoc(const T &p){

            list<U> devolver;
            Diccionario<T,U>::iterator iter;

            if(Esta_Clave(p,iter))
                devolver = (*iter).info;

            return devolver;

        }

        /**
         * @brief Método que devuelve el número de entradas
         * de un diccionario
         * @return int tamaño del diccionario
         */
        int size()const{
            return this->datos.size();
        }

        /**
         * @brief Método de utilidad adicional que devuelve en un string todas
         * los significados de una clave
         * 
         * @param clave clave de la que se buscará la información
         * @return string string con los significados de clave
         */
        string Entradas_para_clave(const T &clave){
            string s;
            list<U> entradas = this->getInfo_Asoc(clave);
            int i = 1;
            for(typename list<U>::iterator iter = entradas.begin() ; iter != entradas.end() ; iter++){
                char ic = (char)i + '0';
                    s +="\t";
                    s += ic  ;          //Las definiciones se tabulan para una mejor presentación
                    s += ": " + *iter;
                    s += "\n";
                    i++;
            }

            return s;
        }

        /**
         * @brief Método de utilidad adicional que realiza 
         * la unión de dos diccionarios y la guarda
         * en el diccionario que realiza la llamada
         * @param otro diccionario con el que se realizará la unión
         * @return Diccionario& union de los dos diccionarios
         */
        Diccionario & operator+=(Diccionario<T,U> & otro){
            typename Diccionario<T,U>::iterator iter ;                   
            for(iter = otro.begin() ; iter != otro.end() ; iter++){
                this->Insertar((*iter).clave,(*iter).info);
            }

            return *this;
        }

        /**
         * @brief Método de utilidad adicional que guarda en un string
         * el contenido de un diccionario completo
         * 
         * @return string Contenido del diccionario
         */
        string Contenido_del_Diccionario(){                            

            string s;
            for(typename Diccionario<T,U>::iterator iter = this->begin() ; iter != this->end() ; iter++){
                s+= (*iter).clave + ":\n";          //Se guarda la clave
                list<U> entradas = (*iter).info;
                int i = 1;
                for(typename list<U>::iterator iter = entradas.begin() ; iter != entradas.end() ; iter++){
                    char ic = (char)i + '0';
                    s +="\t";                       //Se guardan a continuación las definiciones tabuladas
                    s += ic  ;
                    s += ": " + *iter;
                    s += "\n";
                    i++;
                }

            }

            return s;
        }

        /**
         * @brief Operador de igualdad de la clase
         * Diccionario, comprueba si dos diccionarios
         * son iguales
         * 
         * @param otro diccionario a comparar 
         * @return true si son iguales
         * @return false si no son iguales
         */
        bool operator==(const Diccionario &otro){
            return datos == otro.datos;
        }
};

#endif