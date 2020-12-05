#ifndef GUIA_TELEFONICA_H
#define GUIA_TELEFONICA_H

#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

class Guia_Telefonica{
    private:

        map<string,string> numeros;

    public:

        Guia_Telefonica(){

        }

        Guia_Telefonica(const Guia_Telefonica &guia);

        ~Guia_Telefonica(){
            //NO ES NECESARIO RELLENARLO POR QUE EL COMPILADOR
            //YA LO RELLENA SOLO, Y POR TANTO SI SE RELLENA
            //SE LLAMARIA AL DESTRUCTOR 2 VECES Y GENERARIA UN CORE
        }

        typedef map<string,string>::iterator iterator;
        
        typedef map<string,string>::const_iterator const_iterator;

        Guia_Telefonica::iterator begin();

        Guia_Telefonica::iterator end();

        const Guia_Telefonica::const_iterator cbegin()const;

        const Guia_Telefonica::const_iterator cend()const;

        Guia_Telefonica & operator=(const Guia_Telefonica &guia);

        //Crea una entrada con la clave nombre si esta no se encuentra, por lo que se puede usar para asignacion
        string & operator[](const string & nombre);


        pair<Guia_Telefonica::iterator,bool> insert(string nombre, string tlf);

        pair<Guia_Telefonica::iterator,bool> insert(pair<string,string> p);

        void borrar(const string & nombre);

        int tamanio()const;

        bool vacia()const;

        //Cuando se encuentran dos nombres iguales con distintos numeros, se prioriza el número del primer
        //operando
        Guia_Telefonica operator+(const Guia_Telefonica &guia);

        Guia_Telefonica operator-(const Guia_Telefonica &guia);

        friend ostream & operator<<(ostream & os,Guia_Telefonica &guia);

        //La sintaxis es la siguiente: primero se introduce el nombre, y a continuacion
        //el telefono tabulado
        friend istream & operator>>(istream & is, Guia_Telefonica &guia);

        bool operator==(const Guia_Telefonica &otra)const;

        string Telefonos_que_empiezan_por(char a)const;

        void Borrar_numeros_con(char letra);

        void vaciar_guia();

};

#endif