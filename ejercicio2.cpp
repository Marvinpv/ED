/**
 * @file ejercicio2.cpp
 * @author Marvin Peinado Vidaña
 * @brief 
 * @version 0.1
 * @date 2020-11-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool esOperador(char a){
    bool operador = false;
        if(a == '*' || a == '/' || a == '^' || a == '+' || a == '-')
            operador = true;
    
    return operador;
}

bool esNumero(char a){
    bool esnum = false;

        if( a >= '1' && a <= '9')
            esnum = true;
    
    return esnum;
}


/*
bool parentizada(string expresion){
    bool bien = true;
    int parentesis_que_abren = 0,parentesis_que_cierran = 0;
    int i;

    if(expresion[0] == '(')
        parentesis_que_abren++;
    
    if(esOperador(expresion[0]))
        bien = false;

    for( i = 1 ; i < expresion.length()-1 && bien; i++){
        if(esOperador(expresion[i])){
            if(!esValidoParaOperadorIzq(expresion[i-1]) || !esValidoParaOperadorDch(expresion[i+1]))
                bien = false;
        }

        if(expresion[i] == '(')
            parentesis_que_abren++;

        if(expresion[i] == ')')
            parentesis_que_cierran++;
    }

        if(expresion[i] == ')')
            parentesis_que_cierran++;

        if(esOperador(expresion[i]))
          bien = false;

    return bien && (parentesis_que_abren == parentesis_que_cierran);
}*/

bool parentizada(string expresion){
    stack<char> pila;
    bool bien = true;
    int parentesis_que_abren = 0;
    int parentesis_que_cierran = 0;

    if(expresion[0] == '(')
        parentesis_que_abren++;

    pila.push(expresion[0]);
        for(int i = 1 ; i < expresion.length() -1 && bien; i++){
            if(expresion[i] == '('){
                if(!esOperador(pila.top()) && pila.top() != '(')
                    bien = false;

                if(!esNumero(expresion[i+1]) && expresion[i+1] != '(')
                    bien = false;

                parentesis_que_abren++;
            }

            if(esOperador(expresion[i])){
                if(!esNumero(pila.top()) && pila.top() != ')')
                    bien = false;
                
                if(!esNumero(expresion[i+1]) && expresion[i+1] != '(')
                    bien = false;
            }

            if(expresion[i] == ')'){
                if(!esNumero(pila.top()) && pila.top() != ')')
                    bien = false;
                
                if(!esOperador(expresion[i+1]) && expresion[i+1] != ')')
                    bien = false;
                
                parentesis_que_cierran++;
            }

            pila.push(expresion[i]);
        }

        if(expresion[expresion.length()-1] == ')')
            parentesis_que_cierran++;

    return bien && (parentesis_que_abren == parentesis_que_cierran);
}

int main(){
    string expr;

    cout << "Introduzca una expresion sin espacios: "<<endl;
    cin  >> expr;

    if(parentizada(expr))
        cout<<"La expresion tiene una configuración de parentesis correcta"<<endl;
    else
        cout<<"La expresion no tiene una configuración de parentesis correcta "<<endl;
    

    return 0;
}