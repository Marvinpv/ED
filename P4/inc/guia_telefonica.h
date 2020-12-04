#ifndef GUIA_TELEFONICA_H
#define GUIA_TELEFONICA_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Guia_Telefonica{
    private:
        map<string,string> numeros;
    public:

        Guia_Telefonica(){

        }

        Guia_Telefonica(const Guia_Telefonica &guia){
            numeros = guia.numeros;
        }

        ~Guia_Telefonica(){
            //NO ES NECESARIO RELLENARLO POR QUE EL COMPILADOR
            //YA LO RELLENA SOLO, Y POR TANTO SI SE RELLENA
            //SE LLAMARIA AL DESTRUCTOR 2 VECES Y GENERARIA UN CORE
        }

        typedef map<string,string>::iterator iterator;
        
        typedef map<string,string>::const_iterator const_iterator;

        Guia_Telefonica::iterator begin(){
            return numeros.begin();
        }

        Guia_Telefonica::iterator end(){
            return numeros.end();
        }

        const Guia_Telefonica::const_iterator cbegin()const{
            return numeros.cbegin();
        }

        const Guia_Telefonica::const_iterator cend()const{
            return numeros.cend();
        }

        Guia_Telefonica & operator=(const Guia_Telefonica &guia){
            if(this != &guia)
                numeros = guia.numeros;

            return *this;        
        }

        //Crea una entrada con la clave nombre si esta no se encuentra, por lo que se puede usar para asignacion
        string & operator[](const string & nombre){
            return numeros[nombre];
        }


        pair<Guia_Telefonica::iterator,bool> insert(string nombre, string tlf){
            pair<Guia_Telefonica::iterator,bool> valores_insercion;

            valores_insercion = numeros.insert(make_pair(nombre,tlf));

            return valores_insercion;
        }

        pair<Guia_Telefonica::iterator,bool> insert(pair<string,string> p){
            pair<Guia_Telefonica::iterator,bool> valores_insercion;

            valores_insercion = numeros.insert(p);

            return valores_insercion;
        }

        void borrar(const string & nombre){
            numeros.erase(nombre);
        }

        int tamanio()const{
            return numeros.size();
        }

        bool vacia()const{
            return numeros.empty();
        }

        //Cuando se encuentran dos nombres iguales con distintos numeros, se prioriza el número del primer
        //operando
        Guia_Telefonica operator+(const Guia_Telefonica &guia){
            Guia_Telefonica nueva = *this;

            for(Guia_Telefonica::iterator iter = guia.begin ; iter != guia.end() ; iter++){
                nueva.insert(*iter);
            }

            return nueva;
        }

        Guia_Telefonica operator-(const Guia_Telefonica &guia){
            Guia_Telefonica nueva = *this;

            for(Guia_Telefonica::iterator iter = guia.begin() ; iter != guia.end() ; iter++){
                nueva.borrar((*iter).first);
            }

            return nueva;
        }

        friend ostream & operator<<(ostream & os,Guia_Telefonica &guia){
            
            os <<"Contenido de la guía: " << endl;

            for(Guia_Telefonica::const_iterator iter = guia.cbegin() ; iter != guia.cend() ; iter++){
                os << (*iter).first  << ": "
                   << (*iter).second << endl;
            }

            os << endl;

            return os;
        }

        //La sintaxis es la siguiente: primero se introduce el número de teléfonos,
        //y a continuacion cada persona seguida de su teléfono en lineas separadas
        friend istream & operator>>(istream & is, Guia_Telefonica &guia){
            int num_telefonos;
            is >> num_telefonos;
            is.ignore();

            pair<string,string> entrada;
            for(int i = 0 ; i < num_telefonos ; i++){
                getline(is,entrada.first);
                getline(is,entrada.second);
                
                guia.insert(entrada);
            }

            return is;
        }

};

#endif