/**
 * @file guia_telefonica.cpp
 * @author Marvin Peinado Vidaña
 * @brief Implementación de los métodos de la clase Guia_Telefónica
 * @version 0.1
 * @date 2020-12-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include "../inc/guia_telefonica.h"



/**
 * @brief Constructor por copia
 * Crea una guia igual a guia
 * @param guia Guia a copiar
 */
Guia_Telefonica::Guia_Telefonica(const Guia_Telefonica &guia){
    numeros = guia.numeros;
}

/**
 * @brief Método que devuelve un iterador apuntando al primer
 * elemento de un objeto de tipo Guia_Telefonica
 * 
 * @return Guia_Telefonica::iterator 
 */
Guia_Telefonica::iterator Guia_Telefonica::begin(){
    return numeros.begin();
}

/**
 * @brief Método que devuelve un iterador apuntando
 * al ultimo elemento (Elemento no perteneciente al objeto
 * que delimita el final de este) de un objeto de tipo Guia_Telefonica
 * 
 * @return Guia_Telefonica::iterator 
 */
Guia_Telefonica::iterator Guia_Telefonica::end(){
    return numeros.end();
}

/**
 * @brief Método que devuelve un iterador constante apuntando al 
 * primer elemento de un objeto de tipo Guia_Telefonica
 * 
 * @return const Guia_Telefonica::const_iterator 
 */
const Guia_Telefonica::const_iterator Guia_Telefonica::cbegin()const{
    return numeros.cbegin();
}

/**
 * @brief Método que devuelve un iterador constante apuntando
 * al ultimo elemento (Elemento no perteneciente al objeto
 * que delimita el final de este) de un objeto de tipo Guia_Telefonica
 * 
 * @return const Guia_Telefonica::const_iterator 
 */   
const Guia_Telefonica::const_iterator Guia_Telefonica::cend()const{
    return numeros.cend();
}

/**
 * @brief Operador = del TDA Guia_Telefónica
 * Asigna a una Guía los elementos de otra
 * @param guia Guía que se asignará al objeto que llama a la función
 * @return Guia_Telefonica& objeto con la nueva guía asignada
 */
Guia_Telefonica & Guia_Telefonica::operator=(const Guia_Telefonica &guia){
    if(this != &guia)
        numeros = guia.numeros;

    return *this;  
}      


/**
 * @brief operador[] para acceder a los números introduciendo
 * el nombre asignado.
 * Crea una entrada con la clave nombre si esta no se encuentra, 
 * por lo que se puede usar para asignacion
 * @param nombre clave para buscar el número de teléfono
 * @return string& teléfono asociado a nombre
 */
string & Guia_Telefonica::operator[](const string & nombre){
    return numeros[nombre];
}

/**
 * @brief Método para insertar una nueva entrada a la guía
 * 
 * @param nombre nombre del teléfono a insertar
 * @param tlf teléfono asociado al nombre
 * @return pair<Guia_Telefonica::iterator,bool> objeto tipo pair que contiene un 
 * iterador apuntando al nuevo elemento y una variable booleana que se pone
 * a true si la inserción se ha realizado correctamente 
 */
pair<Guia_Telefonica::iterator,bool> Guia_Telefonica::insert(string nombre, string tlf){
    pair<Guia_Telefonica::iterator,bool> valores_insercion;

    valores_insercion = numeros.insert(make_pair(nombre,tlf));

    return valores_insercion;
}

/**
 * @brief Método para insertar una nueva entrada a la guía
 * 
 * @param p objeto tipo pair que contiene tanto el nombre como el teléfono asociado
 * para insertar en la guia
 * @return pair<Guia_Telefonica::iterator,bool> objeto tipo pair que contiene un 
 * iterador apuntando al nuevo elemento y una variable booleana que se pone
 * a true si la inserción se ha realizado correctamente 
 */
pair<Guia_Telefonica::iterator,bool> Guia_Telefonica::insert(pair<string,string> p){
    pair<Guia_Telefonica::iterator,bool> valores_insercion;

    valores_insercion = numeros.insert(p);

    return valores_insercion;
}

/**
 * @brief Método que borra una entrada de la guía
 * 
 * @param nombre Nombre de la entrada que se quiere
 * borrar
 */
void Guia_Telefonica::borrar(const string & nombre){
    numeros.erase(nombre);
}

/**
 * @brief Método que devuelve el tamaño de una guía
 * 
 * @return int número de entradas de la guía
 */
inline int Guia_Telefonica::tamanio()const{
    return numeros.size();
}

/**
 * @brief Método que comprueba si una guía está vacía
 * 
 * @return true si está vacía
 * @return false si no está vacía
 */
bool Guia_Telefonica::vacia()const{
    return numeros.empty();
}


/**
 * @brief Sobrecarga del operador +
 * 
 * @param guia segundo operando de la operación
 * @return Guia_Telefonica unión de las dos guías
 * Cuando se encuentran dos nombres iguales con distintos numeros, 
 * se prioriza el número del primer operando
 */
Guia_Telefonica Guia_Telefonica::operator+(const Guia_Telefonica &guia){
    Guia_Telefonica nueva = *this;

    for(Guia_Telefonica::const_iterator iter = guia.cbegin() ; iter != guia.cend() ; iter++)
        nueva.insert(*iter);
    
    return nueva;
}
    
/**
 * @brief Sobrecarga del operador -
 * 
 * @param guia segundo operando de la operación
 * @return Guia_Telefonica intersección de las dos guías
 * Cuando se encuentran dos nombres iguales con distintos numeros, 
 * se prioriza el número del primer operando
 */
Guia_Telefonica Guia_Telefonica::operator-(const Guia_Telefonica &guia){
    Guia_Telefonica nueva = *this;

    for(Guia_Telefonica::const_iterator iter = guia.cbegin() ; iter != guia.cend() ; iter++)
        nueva.borrar((*iter).first);
    
    return nueva;
}

/**
 * @brief Sobrecarga del operador << para imprimir el contenido
 * de un objeto de tipo Guia_Telefonica
 * @param os flujo de salida 
 * @param guia objeto a imprimir
 * @return ostream& flujo de salida para concatenar los mensajes
 * Se trata de una función friend exterior a la clase
 */
ostream & operator<<(ostream & os,Guia_Telefonica &guia){
            
    os <<"Contenido de la guía: " << endl;

        for(Guia_Telefonica::const_iterator iter = guia.cbegin() ; iter != guia.cend() ; iter++){
            os << (*iter).first  << ": "
               << (*iter).second << endl;
        }

        os << endl;

    return os;
}

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
istream & operator>>(istream & is, Guia_Telefonica &guia){


    pair<string,string> entrada;

    while(getline(is,entrada.first,'\t')){
        
        getline(is,entrada.second);
        
        guia.insert(entrada);
    }

    return is;
}

/**
 * @brief Sobrecarga del operador lógico == para comparar objetos 
 * tipo Guia_Telefonica
 * @param otra objeto a comparar
 * @return true si los dos objetos son iguales
 * @return false si son diferentes
 */
bool Guia_Telefonica::operator==(Guia_Telefonica &otra){
    bool iguales = true;

    if(this->tamanio() != otra.tamanio())
        iguales = false;                    //Si tienen tamaño distinto son distintas
    else{
        Guia_Telefonica::const_iterator iter = this->cbegin();
        
        while(iter != this->cend() && iguales){
            if((*this)[iter->first] != otra[iter->first]){
                iguales = false;

                if(otra[iter->first] == "")      //Si no existía la entrada de this en otra
                    otra.borrar(iter->first);   //Se crea una con valor vacío, por lo que hay que borrarla
            }
                   
            iter++;
        }
    }

    return iguales;
    
}

/**
 * @brief Método que almacena en un string todos los 
 * números que empiezan por letra
 * @param letra para la que se realiza la busqueda
 * @return string con los números correspondientes a
 * los nombres que empiezan por letra
 */
string Guia_Telefonica::Telefonos_que_empiezan_por(char letra)const{
    Guia_Telefonica::const_iterator iter = this->cbegin();
    string s;

    while(iter != this->cend()){

        if(tolower(iter->first[0]) == tolower(letra)){ //La función no es sensible a Mayúsculas ni Minúsculas
            s += iter->first;
            s += "\t";
            s += iter->second;
            s += "\n"; 
        }

        iter++;
    }

    return s;
}

/**
 * @brief Método para borrar todos los números cuyos
 * nombres empiezan por letra
 * @param letra inicial de los nombres que se le borrarán
 * las entradas
 */
void Guia_Telefonica::Borrar_numeros_con(char letra){

    for(Guia_Telefonica::iterator iter = this->begin() ; iter != this->end() ; iter++){
        if(tolower(iter->first[0]) == tolower(letra))
            this->borrar(iter->first);

    }
}

/**
 * @brief Método para vaciar todo el contenido de una
 * Guía Telefónica
 */
void Guia_Telefonica::vaciar_guia(){
    numeros.clear();
}

