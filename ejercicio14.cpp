/**
 * @file ejercicio14.cpp
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
#include <list>
#include <vector>

using namespace std;

template <class T>
class vdisperso{
    private:
        list<pair<int,T>> coefs;
        int n; //número de elementos del vdisperso (no el de coefs)
    
    public:

        vdisperso(){
            n = 0;
        }

        vdisperso(const vector<T> &v){
            n = v.size();
            for(int i = 0 ; i < n ; i++){
                if(v[i] != T())
                    coefs.push_back(make_pair(i,v[i]));
            }
        }

        
        void asignar_coeficiente(int i,const T &x){
            bool pertenece = false;
            for(typename list<pair<int, T>>::iterator iter = coefs.begin() ; iter != coefs.end() && !pertenece; iter++){
                if((*iter).first == i){
                    pertenece = true;
                    if(x != T())
                        (*iter).second = x;
                    else{
                        iter = coefs.erase(iter);
                    }
                }
            }

            if(!pertenece && x != T()){
                coefs.push_back(make_pair(i, x));
                if(i > n){
                    n = i+1;
                }
            }
        }


        T operator[](int i) const{
            T elemento = T();
            bool pertenece = false;
            for(typename list<pair<int,T>>::const_iterator iter = coefs.cbegin() ; iter != coefs.cend() && !pertenece; iter++){
                if((*iter).first == i){
                    pertenece = true;
                    elemento = (*iter).second;
                }
            }

            return elemento;
        }

        vector<T> convertir() const{
            vector<T> vec_convertido(n,T());

            for(typename list<pair<int,T>>::const_iterator iter = coefs.cbegin() ; iter != coefs.cend(); iter++){
                vec_convertido[(*iter).first] = (*iter).second;
            }

            return vec_convertido;
        }

        int size() const{
            return n;
        }

        int size_not_nulls() const{
            return coefs.size();
        }
};

int main(){
    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(int());
    vec1.push_back(int());
    vec1.push_back(int());
    vec1.push_back(int());
    vec1.push_back(int());
    vec1.push_back(int());
    vec1.push_back(int());
    vec1.push_back(int());
    vec1.push_back(int());
    vec1.push_back(5);
    vec1.push_back(int());
    vec1.push_back(int());
    vec1.push_back(7);
    vec1.push_back(8);

    cout<<"Vector inicial: ";
    for(vector<int>::iterator it = vec1.begin() ; it != vec1.end() ; it++)
        cout<<*it<<" ";
    cout<<endl;

    vdisperso<int> vd(vec1);
    cout<<"Vector disperso creado a partir de este: ";
    for(int i = 0 ; i < vd.size() ; i++)
        cout<<vd[i]<<" ";
    cout<<endl;

    cout<<"Añadiendo algunos elementos..."<<endl;
    vd.asignar_coeficiente(4,89);
    vd.asignar_coeficiente(0,2);
    vd.asignar_coeficiente(vd.size() + 5,10);

    vector<int> conversion = vd.convertir();
    cout<<"Vector a partir del vector disperso anterior: ";
    for(vector<int>::iterator it = conversion.begin() ; it != conversion.end() ; it++)
        cout<<*it<<" ";
    cout<<endl;


}