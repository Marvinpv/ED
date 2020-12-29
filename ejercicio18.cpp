/**
 * @file ejercicio18.cpp
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
#include <vector>
#include <set>

using namespace std;

template <typename T>
void intercalar(vector<T> &v, vector<pair<int,T>> pos){
    for(typename vector<pair<int,T>>::iterator it = pos.begin() ; it != pos.end() ; it++){
        assert((*it).first >= 0 && (*it).first <= v.size());

        typename vector<T>::iterator it_v = v.begin();
        int indice = 0;

            while(indice < (*it).first){
                it_v++;
                indice++;
            }
                

        v.insert(it_v , (*it).second);
    }
}

int main(){

    //EJEMPLO 1
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(7);
    v1.push_back(3);

    vector<pair<int,int>> pos1;
    pos1.push_back(make_pair(1,5));
    pos1.push_back(make_pair(0,7));
    pos1.push_back(make_pair(4,12));

    cout<<"Vector inicial: ";
    for(vector<int>::iterator it = v1.begin() ; it != v1.end() ; it++)
        cout<<*it<<" ";
    cout<<endl;

    cout<<"Valores a insertar: ";
    for(vector<pair<int,int>>::iterator it = pos1.begin() ; it != pos1.end() ; it++)
        cout<<"("<<it->first<<","<<it->second<<") ";
    cout<<endl;

    intercalar(v1, pos1);

    //Resultado esperado: 7, 1, 5, 3, 12, 7, 3
    cout<<"Resultado: ";
    for(vector<int>::iterator it = v1.begin() ; it != v1.end() ; it++)
        cout<<*it<<" ";
    cout<<endl;


    //EJEMPLO 2
    vector<char> v2;
    v2.push_back('k');
    v2.push_back('l');
    v2.push_back('m');
    v2.push_back('n');
    v2.push_back('o');

    vector<pair<int,char>> pos2;
    pos2.push_back(make_pair(0,'e'));
    pos2.push_back(make_pair(0,'d'));
    pos2.push_back(make_pair(0,'c'));
    pos2.push_back(make_pair(0,'b'));
    pos2.push_back(make_pair(0,'a'));
    pos2.push_back(make_pair(v2.size(),'j'));
    pos2.push_back(make_pair(v2.size(),'i'));
    pos2.push_back(make_pair(v2.size(),'h'));
    pos2.push_back(make_pair(v2.size(),'g'));
    pos2.push_back(make_pair(v2.size(),'f'));

    cout<<"Vector inicial: ";
    for(vector<char>::iterator it = v2.begin() ; it != v2.end() ; it++)
        cout<<*it<<" ";
    cout<<endl;

    cout<<"Valores a insertar: ";
    for(vector<pair<int,char>>::iterator it = pos2.begin() ; it != pos2.end() ; it++)
        cout<<"("<<it->first<<","<<it->second<<") ";
    cout<<endl;

    intercalar(v2, pos2);

    //Resultado esperado: a, b, c, d, e, f, g, h, i, j, k, l, m, n, o
    cout<<"Resultado: ";
    for(vector<char>::iterator it = v2.begin() ; it != v2.end() ; it++)
        cout<<*it<<" ";
    cout<<endl;

    //EJEMPLO 3
    vector<long> v3;
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(3);
    v3.push_back(4);
    v3.push_back(5);

    vector<pair<int,long>> pos3;
    pos3.push_back(make_pair(v3.size(),10));
    pos3.push_back(make_pair(v3.size(),9));
    pos3.push_back(make_pair(v3.size(),8));
    pos3.push_back(make_pair(v3.size(),7));
    pos3.push_back(make_pair(v3.size(),6));

    cout<<"Vector inicial: ";
    for(vector<long>::iterator it = v3.begin() ; it != v3.end() ; it++)
        cout<<*it<<" ";
    cout<<endl;

    cout<<"Valores a insertar: ";
    for(vector<pair<int,long>>::iterator it = pos3.begin() ; it != pos3.end() ; it++)
        cout<<"("<<it->first<<","<<it->second<<") ";
    cout<<endl;

    intercalar(v3, pos3);

    //Resultado esperado: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    cout<<"Resultado: ";
    for(vector<long>::iterator it = v3.begin() ; it != v3.end() ; it++)
        cout<<*it<<" ";
    cout<<endl;
}