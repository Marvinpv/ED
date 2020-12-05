#include "../inc/guia_telefonica.h"

Guia_Telefonica::Guia_Telefonica(const Guia_Telefonica &guia){
    numeros = guia.numeros;
}

Guia_Telefonica::iterator Guia_Telefonica::begin(){
    return numeros.begin();
}

Guia_Telefonica::iterator Guia_Telefonica::end(){
    return numeros.end();
}

const Guia_Telefonica::const_iterator Guia_Telefonica::cbegin()const{
    return numeros.cbegin();
}

   
const Guia_Telefonica::const_iterator Guia_Telefonica::cend()const{
    return numeros.cend();
}

Guia_Telefonica & Guia_Telefonica::operator=(const Guia_Telefonica &guia){
    if(this != &guia)
        numeros = guia.numeros;

    return *this;  
}      

//Crea una entrada con la clave nombre si esta no se encuentra, por lo que se puede usar para asignacion
string & Guia_Telefonica::operator[](const string & nombre){
    return numeros[nombre];
}

pair<Guia_Telefonica::iterator,bool> Guia_Telefonica::insert(string nombre, string tlf){
    pair<Guia_Telefonica::iterator,bool> valores_insercion;

    valores_insercion = numeros.insert(make_pair(nombre,tlf));

    return valores_insercion;
}

pair<Guia_Telefonica::iterator,bool> Guia_Telefonica::insert(pair<string,string> p){
    pair<Guia_Telefonica::iterator,bool> valores_insercion;

    valores_insercion = numeros.insert(p);

    return valores_insercion;
}

void Guia_Telefonica::borrar(const string & nombre){
    numeros.erase(nombre);
}

inline int Guia_Telefonica::tamanio()const{
    return numeros.size();
}

bool Guia_Telefonica::vacia()const{
    return numeros.empty();
}

//Cuando se encuentran dos nombres iguales con distintos numeros, se prioriza el número del primer
//operando
Guia_Telefonica Guia_Telefonica::operator+(const Guia_Telefonica &guia){
    Guia_Telefonica nueva = *this;

    for(Guia_Telefonica::const_iterator iter = guia.cbegin() ; iter != guia.cend() ; iter++)
        nueva.insert(*iter);
    
    return nueva;
}
    

Guia_Telefonica Guia_Telefonica::operator-(const Guia_Telefonica &guia){
    Guia_Telefonica nueva = *this;

    for(Guia_Telefonica::const_iterator iter = guia.cbegin() ; iter != guia.cend() ; iter++)
        nueva.borrar((*iter).first);
    
    return nueva;
}

ostream & operator<<(ostream & os,Guia_Telefonica &guia){
            
    os <<"Contenido de la guía: " << endl;

        for(Guia_Telefonica::const_iterator iter = guia.cbegin() ; iter != guia.cend() ; iter++){
            os << (*iter).first  << ": "
               << (*iter).second << endl;
        }

        os << endl;

    return os;
}

istream & operator>>(istream & is, Guia_Telefonica &guia){


    pair<string,string> entrada;

    while(getline(is,entrada.first,'\t')){
        
        getline(is,entrada.second);
        
        guia.insert(entrada);
    }

    return is;
}

bool Guia_Telefonica::operator==(const Guia_Telefonica &otra)const{
    bool iguales = true;

    if(this->tamanio() != otra.tamanio())
        iguales = false;
    else{
        Guia_Telefonica::const_iterator iter = this->cbegin();
        
        while(iter != this->cend() && iguales){
            if((*this).numeros.count(iter->first) != otra.numeros.count(iter->first))
                iguales = false;
                
            iter++;
        }
    }

    return iguales;
    
}

string Guia_Telefonica::Telefonos_que_empiezan_por(char letra)const{
    Guia_Telefonica::const_iterator iter = this->cbegin();
    string s;

    while(iter != this->cend()){

        if(tolower(iter->first[0]) == tolower(letra)){
            s += iter->first;
            s += "\t";
            s += iter->second;
            s += "\n"; 
        }

        iter++;
    }

    return s;
}

void Guia_Telefonica::Borrar_numeros_con(char letra){

    for(Guia_Telefonica::iterator iter = this->begin() ; iter != this->end() ; iter++){
        if(tolower(iter->first[0]) == tolower(letra))
            this->borrar(iter->first);

    }
}

void Guia_Telefonica::vaciar_guia(){
    numeros.clear();
}

