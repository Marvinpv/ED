#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

bool esLetra(char a){
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >='0' && a<='9') ;
}

map<string,int> contar(string texto){
    map<string, int> salida;
    string palabra;

    for(int i = 0 ; i <= texto.length() ; i++ ){

        if(!esLetra(texto[i])){
            if(esLetra(texto[i+1])){
                salida[palabra]++;
                palabra = "";
            }

        }else{
            palabra += texto[i];
        }
    }

    return  salida;
}


int main(){

    string texto1 = "En analisis matematico el logaritmo de un número real positivo n,";
    texto1 +="en una determinada base b, es el exponente x de b para obtener n: ";
    texto1 +="La base tiene que ser positiva y distinta de 1. Asi, el logaritmo de 1000 en base 10 es 3,"; 
    texto1 +="porque 10 al cubo vale 1000";
           
    string texto2 = "A las cinco de la tarde." ;
    texto2 +="Eran las cinco en punto de la tarde.";
                    
    texto2 +="Un ninio trajo la blanca sabana ";
    texto2 +="a las cinco de la tarde.";
                    
    texto2 +="Una espuerta de cal ya prevenida ";
    texto2 +="a las cinco de la tarde.";
                    
    texto2 +="Lo demas era muerte y solo muerte ";
    texto2 +="a las cinco de la tarde.";
                    
    texto2 +="El viento se llevo los algodones ";
    texto2 +="a las cinco de la tarde.";

    cout<<endl<<" Texto 1: "<<endl
        <<texto1<<endl
        <<endl<<"Texto 2: "<<endl
        <<texto2<<endl;

    map<string,int> contador1 = contar(texto1);
    map<string,int> contador2 = contar(texto2);

    cout<<endl<<"Contador texto 1: "<<endl;
    for(map<string, int >::iterator iter = contador1.begin() ; iter != contador1.end() ; iter++)
        cout<<iter->first<<": "<<iter->second<<endl;
    
    
    cout<<endl<<"Contador texto 2: "<<endl;
    for(map<string, int >::iterator iter = contador2.begin() ; iter != contador2.end() ; iter++)
        cout<<iter->first<<": "<<iter->second<<endl;
    
    
}