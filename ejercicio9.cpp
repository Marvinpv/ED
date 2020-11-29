/**
 * @file ejercicio9.cpp
 * @author Marvin Peinado Vidaña
 * @brief 
 * @version 0.1
 * @date 2020-11-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

pair<int,int> buscar_entrada(char **laberinto, int num_filas, int num_cols){
    for(int i = 0 ; i < num_filas ; i++){
        for(int j = 0 ; j < num_cols ; j++){
            if(laberinto[i][j] == 'E'){
                pair<int,int> devolver(i,j);
                return devolver;
            }
                
        }
    }
    pair<int,int> no_encontrado(0,0);
    return no_encontrado;
}

pair<int,int> siguiente_paso(pair<int,int> paso_anterior,char **laberinto, int num_filas, int num_cols,bool &salida_encontrada){
    pair<int,int> siguiente = paso_anterior;

    if(paso_anterior.first > 0 && (laberinto[paso_anterior.first-1][paso_anterior.second] == '0' || laberinto[paso_anterior.first-1][paso_anterior.second] == 'S'))
        siguiente = make_pair(paso_anterior.first-1,paso_anterior.second);
    else if(paso_anterior.first < num_filas-1 && (laberinto[paso_anterior.first+1][paso_anterior.second] == '0' || laberinto[paso_anterior.first+1][paso_anterior.second] == 'S'))
        siguiente = make_pair(paso_anterior.first+1,paso_anterior.second);
    else if(paso_anterior.second > 0 && (laberinto[paso_anterior.first][paso_anterior.second - 1] == '0' || laberinto[paso_anterior.first][paso_anterior.second-1] == 'S'))
        siguiente = make_pair(paso_anterior.first,paso_anterior.second-1);
    else if(paso_anterior.second < num_cols-1 && (laberinto[paso_anterior.first][paso_anterior.second + 1] == '0' || laberinto[paso_anterior.first][paso_anterior.second+1] == 'S'))
        siguiente = make_pair(paso_anterior.first,paso_anterior.second+1);
    

    if(laberinto[siguiente.first][siguiente.second] == 'S')
        salida_encontrada = true; 

    return siguiente;
}

stack<pair<int,int>> salida_laberinto(char **laberinto, int num_filas, int num_cols){
    stack<pair<int,int>> camino;
    camino.push(buscar_entrada(laberinto,num_filas,num_cols));
    bool salida_encontrada = false;
        while(!salida_encontrada){

            pair<int,int> sig_paso = siguiente_paso(camino.top(),laberinto,num_filas,num_cols,salida_encontrada);

            if(sig_paso == camino.top()){
                laberinto[sig_paso.first][sig_paso.second] = '1';
                camino.pop();
            }else{
                laberinto[camino.top().first][camino.top().second] = '*';
                camino.push(sig_paso);
            }

        }
    
    return camino;
    
}


int main(){
    char **laberinto = new char*[4];
        
            laberinto[0] = new char[8]{'1','E','0','0','1','1','1','1'};
            laberinto[1] = new char[8]{'0','0','1','1','1','0','1','1'};
            laberinto[2] = new char[8]{'1','0','0','0','0','0','1','1'};
            laberinto[3] = new char[8]{'1','0','1','1','S','1','1','1'};

    int filas = 4, columnas = 8;
    
    stack<pair<int,int>> salida = salida_laberinto(laberinto,filas,columnas);

    stack<pair<int,int>> salida_inverso;

    while(!salida.empty()){                     //Para que salga el camino en orden correcto
        salida_inverso.push(salida.top());
        salida.pop();
    }

    cout<<"Camino para salir del laberinto: "<<endl;
    while(!salida_inverso.empty()){
        cout<<"("<<salida_inverso.top().first<<","<<salida_inverso.top().second<<"),";
        salida_inverso.pop();
    }
    cout<<endl;

    return 0;
}