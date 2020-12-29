/**
 * @file ejercicio05.cpp
 * @author Marvin Peinado Vidaña 
 * @brief 
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <stack>

using namespace std;

map<string,string> params(string cad){

    map<string, string> resultado;
    stack<string> ultima_opcion;
    string opcion = "";
    string parametro = "";

    for(int i = 0 ; i <= cad.length() ; i++){
        if(cad[i] == '-'){
            opcion += cad[i+1];
            ultima_opcion.push(opcion);
            opcion = "";
            parametro = "";
            i++;
        }else if(cad[i] == ' ' || cad[i] == '\0' || cad[i] == '\n' || cad[i] == '\t'){
            if(!ultima_opcion.empty()){
                resultado[ultima_opcion.top()] = parametro;
                parametro = "";
            }
        }else{
            parametro += cad[i];
        }
    }

    return resultado;
}

/*
map <string, string> params(string cad){

    bool esOpcion = false;
    map<string, string> resultado;
    stack<string> ult_param;
    string palabra;

    for(int i = 0 ; i < cad.length() ; i++){
        if(cad[i] == '-'){
            esOpcion = true;

        }else if(cad[i] == ' '){

            if(esOpcion){
                resultado["-"+cad[i]] = "";
                ult_param.push("-"+cad[i]);
                esOpcion = false;
            }else{
                palabra += cad[i];
            }

        }else{
            if(!ult_param.empty() && palabra != ""){
                resultado[ult_param.top()] = palabra;
            }
            palabra = "";
        }
    }

    return resultado;
}
*/

int main(){

    //Ejemplo 1
    string cadena1 = "tar -x -v -f fichero",orden1;
    map<string,string> opciones1 = params(cadena1);

    cout<<"Opciones con sus respectivos parámetros del ejemplo 1: "<<cadena1<<endl;
    for(map<string,string>::iterator iter = opciones1.begin() ; iter != opciones1.end() ; iter++){
        cout<<iter->first<<" "<<iter->second<<endl;
    }

    //Ejemplo 2
    string cadena2 = "ls -l -a",orden2;
    map<string, string> opciones2 = params(cadena2);

    cout<<"Opciones con sus respectivos parámetros del ejemplo 2: "<<cadena2<<endl;

    for(map<string,string>::iterator iter = opciones2.begin() ; iter != opciones2.end() ; iter++){
        cout<<iter->first<<"    "<<iter->second<<endl;
    }

    //Ejemplo 3
    string cadena3,orden3;
    cout<<"Introduzca orden con sus opciones (y parámetros si los necesitan): "<<endl;
    getline(cin,cadena3);
    map<string, string> opciones3 = params(cadena3);

    cout<<"Opciones con sus respectivos parámetros del ejemplo 3: "<<cadena3<<endl;
    for(map<string,string>::iterator iter = opciones3.begin() ; iter != opciones3.end() ; iter++){
        cout<<iter->first<<"    "<<iter->second<<endl;
    }

    return 0;
}