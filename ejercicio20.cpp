/**
 * @file ejercicio20.cpp
 * @author Marvin Peinado Vidaña
 * @brief 
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include <set>
#include <list>
#include <vector>

using namespace std;

vector<pair<pair<float,float>,int>> contar(const vector< pair<float,float>> &v){
    multiset<pair<float, float>> coordenadas;

        //O(n*log(n))
        for(vector<pair<float,float>>::const_iterator it = v.cbegin() ; it != v.cend() ; it++){
            coordenadas.insert(*it);
        }

        vector<pair<pair<float,float>,int>> devolver;

        multiset<pair<float,float>>::iterator it = coordenadas.begin();
        devolver.push_back(make_pair(*it,coordenadas.count(*it)));
        it++;

        //0(n*log(n))
        while(it != coordenadas.end()){
            if(*it != devolver.back().first){
                devolver.push_back(make_pair(*it,coordenadas.count(*it)));
            }

            it++;
        }

        return devolver;
}

int main(){
    vector<pair<float,float>> c;
    c.push_back(make_pair(0,0));
    c.push_back(make_pair(54,0));
    c.push_back(make_pair(0,1));
    c.push_back(make_pair(0,67));
    c.push_back(make_pair(0,67));
    c.push_back(make_pair(54,0));
    c.push_back(make_pair(1,1));
    c.push_back(make_pair(78,78));
    c.push_back(make_pair(78,77));
    c.push_back(make_pair(78,77));

    cout<<"Vector de coordenadas: ";
    for(vector<pair<float,float>>::iterator it = c.begin() ; it != c.end() ; it++)
        cout<<"("<<it->first<<","<<it->second<<") ";
    cout<<endl;

    vector<pair<pair<float,float>,int>> resultado = contar(c);

    cout<<"Resultado: "<<endl;
    for(vector<pair<pair<float,float>,int>>::iterator it = resultado.begin() ; it != resultado.end() ; it++)
        cout<<"("<<(it->first).first<<","<<(it->first).second<<"): "<<it->second<<endl;


}