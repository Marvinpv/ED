/**
 * @file ejercicio5.cpp
 * @author Marvin Peinado Vidaña
 * @brief 
 * @version 0.1
 * @date 2020-11-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

float encontrar_variable(char variable, pair<char,float> *variables, int num_variables){
    bool encontrado = false;
    float valor = 0;
        for(int i = 0 ; i < num_variables && !encontrado ; i++){
            if(variables[i].first == variable){
                valor = variables[i].second;
                encontrado = true;
            }
        }
    
    return valor;
}

float evalua(string expresion, pair<char,float> *variables, int num_variables){
    stack<float> auxiliar;
    float primero,segundo,valor;
        for(int i = 0 ; i < expresion.length() ; i++){

            switch (expresion[i])
            {
            case '^':
                segundo = auxiliar.top();
                auxiliar.pop();
                primero = auxiliar.top();
                auxiliar.pop();
                auxiliar.push(pow(primero,segundo));
                break;
            case '*':
                primero = auxiliar.top();
                auxiliar.pop();
                segundo = auxiliar.top();
                auxiliar.pop();
                auxiliar.push(primero*segundo);
                break;
            case '+':
                segundo = auxiliar.top();
                auxiliar.pop();
                primero = auxiliar.top();
                auxiliar.pop();
                auxiliar.push(primero+segundo);
                break;
            case '-':
                segundo = auxiliar.top();
                auxiliar.pop();
                primero = auxiliar.top();
                auxiliar.pop();
                auxiliar.push(primero-segundo);
                break;
            case '/':
                segundo = auxiliar.top();
                auxiliar.pop();
                primero = auxiliar.top();
                auxiliar.pop();
                auxiliar.push(primero/segundo);
                break;
            default:
                valor = encontrar_variable(expresion[i],variables,num_variables);
                auxiliar.push(valor);
                break;
            }

        }
    return auxiliar.top();
}

int main(){
    string expresion1 = "ab^c*d/e+",
           expresion2 = "abcde+*+",
           expresion3 = "ab+cd*+e*";
    pair<char,float> variables1[] = {make_pair('a',5.0),make_pair('b',3.0),make_pair('c',2),make_pair('d',2),make_pair('e',9)};
    pair<char,float> variables2[] = {make_pair('a',12),make_pair('b',4),make_pair('c',7),make_pair('d',5),make_pair('e',2)};
    pair<char,float> variables3[] = {make_pair('a',2),make_pair('b',6),make_pair('c',3),make_pair('d',5),make_pair('e',9)};

    cout<<"Resolviendo la expresion "<<expresion1<<" ..."<<endl;
    float solucion1 = evalua(expresion1,variables1,5);
    cout<<"Solucion: "<<solucion1<<endl;

    cout<<"Resolviendo la expresion "<<expresion2<<" ..."<<endl;
    float solucion2 = evalua(expresion2,variables2,5);
    cout<<"Solucion: "<<solucion2<<endl;

    cout<<"Resolviendo la expresion "<<expresion3<<" ..."<<endl;
    float solucion3 = evalua(expresion3,variables3,5);
    cout<<"Solucion: "<<solucion3<<endl;                        //HACER UNA ENTRADA POR TECLADO

    return 0;
}