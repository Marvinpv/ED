/**
 * @file guia_telefonica.h
 * @author Marvin Peinado Vidaña
 * @brief Definición de la clase Guia_Telefonica
 * @version 0.1
 * @date 2020-12-05
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef GUIA_TELEFONICA_H
#define GUIA_TELEFONICA_H

#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

class Guia_Telefonica{
    private:

        map<string,string> numeros; //Diccionario donde se guardarán las entradas de la guía

    public:

        /**
         * @brief Constructor por defecto
         * Se encuentra vacio ya que numeros llama al constructor por
         * defecto de map, por lo que no hace falta llamarlo de nuevo
         */
        Guia_Telefonica(){

        }

        /**
         * @brief Constructor por copia
         * Crea una guia igual a guia
         * @param guia Guia a copiar
         */
        Guia_Telefonica(const Guia_Telefonica &guia);

        /**
         * @brief Destructor
         * Está vacio, ya que al terminar la ejecución de un programa,
         * numeros llama a su destructor, por lo que no hace falta
         * realizar ninguna otra llamada
         */
        ~Guia_Telefonica(){
        
        }

        /**
         * @brief Definición de la clase iteradora de Guia_Telefonica
         * como un iterador del tipo map<string,string>
         */
        typedef map<string,string>::iterator iterator;
        
        /**
         * @brief Definicion de la clase iteradora (constante) de
         * Guia_Telefonica como un iterador del tipo map<string,string>
         */
        typedef map<string,string>::const_iterator const_iterator;

        /**
         * @brief Método que devuelve un iterador apuntando al primer
         * elemento de un objeto de tipo Guia_Telefonica
         * 
         * @return Guia_Telefonica::iterator 
         */
        Guia_Telefonica::iterator begin();

        /**
         * @brief Método que devuelve un iterador apuntando
         * al ultimo elemento (Elemento no perteneciente al objeto
         * que delimita el final de este) de un objeto de tipo Guia_Telefonica
         * 
         * @return Guia_Telefonica::iterator 
         */
        Guia_Telefonica::iterator end();

        /**
         * @brief Método que devuelve un iterador constante apuntando al 
         * primer elemento de un objeto de tipo Guia_Telefonica
         * 
         * @return const Guia_Telefonica::const_iterator 
         */
        const Guia_Telefonica::const_iterator cbegin()const;

        /**
         * @brief Método que devuelve un iterador constante apuntando
         * al ultimo elemento (Elemento no perteneciente al objeto
         * que delimita el final de este) de un objeto de tipo Guia_Telefonica
         * 
         * @return const Guia_Telefonica::const_iterator 
         */
        const Guia_Telefonica::const_iterator cend()const;

        /**
         * @brief Operador = del TDA Guia_Telefónica
         * Asigna a una Guía los elementos de otra
         * @param guia Guía que se asignará al objeto que llama a la función
         * @return Guia_Telefonica& objeto con la nueva guía asignada
         */
        Guia_Telefonica & operator=(const Guia_Telefonica &guia);

        /**
         * @brief operador[] para acceder a los números introduciendo
         * el nombre asignado.
         * Crea una entrada con la clave nombre si esta no se encuentra, 
         * por lo que se puede usar para asignacion
         * @param nombre clave para buscar el número de teléfono
         * @return string& teléfono asociado a nombre
         */
        string & operator[](const string & nombre);

        /**
         * @brief Método para insertar una nueva entrada a la guía
         * 
         * @param nombre nombre del teléfono a insertar
         * @param tlf teléfono asociado al nombre
         * @return pair<Guia_Telefonica::iterator,bool> objeto tipo pair que contiene un 
         * iterador apuntando al nuevo elemento y una variable booleana que se pone
         * a true si la inserción se ha realizado correctamente 
         */
        pair<Guia_Telefonica::iterator,bool> insert(string nombre, string tlf);

        /**
         * @brief Método para insertar una nueva entrada a la guía
         * 
         * @param p objeto tipo pair que contiene tanto el nombre como el teléfono asociado
         * para insertar en la guia
         * @return pair<Guia_Telefonica::iterator,bool> objeto tipo pair que contiene un 
         * iterador apuntando al nuevo elemento y una variable booleana que se pone
         * a true si la inserción se ha realizado correctamente 
         */
        pair<Guia_Telefonica::iterator,bool> insert(pair<string,string> p);

        /**
         * @brief Método que borra una entrada de la guía
         * 
         * @param nombre Nombre de la entrada que se quiere
         * borrar
         */
        void borrar(const string & nombre);

        /**
         * @brief Método que devuelve el tamaño de una guía
         * 
         * @return int número de entradas de la guía
         */
        int tamanio()const;

        /**
         * @brief Método que comprueba si una guía está vacía
         * 
         * @return true si está vacía
         * @return false si no está vacía
         */
        bool vacia()const;

        /**
         * @brief Sobrecarga del operador +
         * 
         * @param guia segundo operando de la operación
         * @return Guia_Telefonica unión de las dos guías
         * Cuando se encuentran dos nombres iguales con distintos numeros, 
         * se prioriza el número del primer operando
         */
        Guia_Telefonica operator+(const Guia_Telefonica &guia);

        /**
         * @brief Sobrecarga del operador -
         * 
         * @param guia segundo operando de la operación
         * @return Guia_Telefonica intersección de las dos guías
         * Cuando se encuentran dos nombres iguales con distintos numeros, 
         * se prioriza el número del primer operando
         */
        Guia_Telefonica operator-(const Guia_Telefonica &guia);

        /**
         * @brief Sobrecarga del operador << para imprimir el contenido
         * de un objeto de tipo Guia_Telefonica
         * @param os flujo de salida 
         * @param guia objeto a imprimir
         * @return ostream& flujo de salida para concatenar los mensajes
         * El formato de salida corresponde al formato de entrada para poder leer
         * la salida de un objeto
         * Se trata de una función friend exterior a la clase
         */
        friend ostream & operator<<(ostream & os,Guia_Telefonica &guia);

        /**
         * @brief Sobrecarga del operador >> para leer el contenido
         * de un objeto de tipo Guia_Telefonica
         * @param is flujo de entrada
         * @param guia objeto que almacenará la información del flujo de entrada
         * @return istream& flujo de entrada para concatenar lecturas
         * El formato es el siguiente: primero se introduce el nombre, y a continuación
         * el telefono tabulado
         * Se trata de una función friend exterior a la clase
         */
        friend istream & operator>>(istream & is, Guia_Telefonica &guia);

        /**
         * @brief Sobrecarga del operador lógico == para comparar objetos 
         * tipo Guia_Telefonica
         * @param otra objeto a comparar
         * @return true si los dos objetos son iguales
         * @return false si son diferentes
         */
        bool operator==(Guia_Telefonica &otra); //Utilidad adicional

        /**
         * @brief Método que almacena en un string todos los 
         * números que empiezan por letra
         * @param letra para la que se realiza la busqueda
         * @return string con los números correspondientes a
         * los nombres que empiezan por letra
         */
        string Telefonos_que_empiezan_por(char letra)const; //utilidad adicional

        /**
         * @brief Método para borrar todos los números cuyos
         * nombres empiezan por letra
         * @param letra inicial de los nombres que se le borrarán
         * las entradas
         */
        void Borrar_numeros_con(char letra); //Utilidad adicional

        /**
         * @brief Método para vaciar todo el contenido de una
         * Guía Telefónica
         */
        void vaciar_guia(); //Utilidad adicional

};

#endif