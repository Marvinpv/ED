/**
 * @file ejercicio17.cpp
 * @author Marvin Peinado Vidaña
 * @brief 
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

//Da errores


#include <iostream>
#include <string>
#include <cctype>
#include <list>
#include <cassert>
#include <vector>

using namespace std;

template <typename T>
class vector_dinamico{
    private:
        list<T> elementos;
        int n;
    public:

        class iterator{
            private:
                typename list<T>::iterator iter;

            public:
                iterator(){

                }

                iterator(const iterator &otro){
                    iter = otro.iter;
                }

                iterator(const typename list<T>::iterator &otro_iter){
                    iter = otro_iter;
                }

                iterator & operator=(const iterator & otro){
                    iter = otro.iter;

                    return *this;
                }

                T & operator *(){
                    return *iter;
                }

                iterator operator++(int ){
                    iterator iter_aux;
                    iter_aux.iter = iter;
                    iter++;
                    return iter_aux;
                }

                bool operator==(const iterator &otro)const{
                    return iter == otro.iter;
                }

                bool operator!=(const iterator &otro)const{
                    return iter != otro.iter;
                }

                friend iterator vector_dinamico::insert(iterator it, const T &x);

                friend iterator vector_dinamico::erase(iterator it);
        };

        vector_dinamico(){
            n = 0;
        }

        vector_dinamico(const vector<T> & v){
            n = v.size();
            for(int i = 0 ; i< n ; i++)
                elementos.push_back(v[i]);
        }

        iterator insert(iterator it,const T &x){//Eficiencia O(1)
            typename list<T>::iterator nuevo_iter = elementos.insert(it.iter,x);
            iterator iterador_clase(nuevo_iter);
            n++;
            return iterador_clase;
        }

        iterator erase(iterator it){//Eficiencia: O(1)
            typename list<T>::iterator nuevo_iter = elementos.erase(it.iter);
            iterator iterador_clase(nuevo_iter);
            n--;
            return iterador_clase;
        }

        iterator erase(int i){//Eficiencia: O(n)
            vector_dinamico<T>::iterator it = this->begin();

            if(i < n && i >= 0){
                for(int ind = 0 ; ind < i ; ind++)
                    it++;

                it = this->erase(it);
            }else{
                it = this->end();
            }

            return it;
            
        }

        void push_back(const T &x){//Eficiencia: O(1)
            elementos.push_back(x);
            n++;
        }

        T & operator[](int i){//Eficiencia: O(n)
            
            assert(i >= 0 && i < n);
            vector_dinamico<T>::iterator it = this->begin();
            for(int indice = 0 ; indice < i ; indice++){
                it++;
            }
            
            return *it;
        }

        int size()const{ //Eficiencia: O(1)
            return n;
        }

        iterator begin(){ //Eficiencia: O(1)
            iterator it(elementos.begin());

            return it;
        }

        iterator end(){ //Eficiencia: O(1)
            iterator it(elementos.end());

            return it;
        }

        
};

int main(){
    vector_dinamico<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);
    vec1.push_back(6);
    vec1.push_back(7);
    vec1.push_back(8);
    vec1.push_back(9);
    vec1.push_back(10);
    vec1.push_back(11);

    vector_dinamico<int>::iterator it = vec1.begin();

    for (int i = 0; i < 5; i++)
        it++;
    
    cout<<"Insertando en posicion 5 con iterador..."<<endl;
    it = vec1.insert(it,99);
    cout<<"Iterador apuntando a: "<<*it<<endl;

    cout<<"Vector: ";
    for(vector_dinamico<int>::iterator it = vec1.begin() ; it != vec1.end() ; it++)
        cout<<*it<<" ";
    cout<<endl;

    it++;

    cout<<"Borrando elemento en posicion 6 con iterador..."<<endl;
    it = vec1.erase(it);
    cout<<"Iterador apuntando a: "<<*it<<endl;

    cout<<"Vector: ";
    for(vector_dinamico<int>::iterator it = vec1.begin() ; it != vec1.end() ; it++)
        cout<<*it<<" ";
    cout<<endl;

    cout<<"Borrando elemento en posicion 10 con indice..."<<endl;
    vector_dinamico<int>::iterator it_borrado_pos = vec1.erase(10);
    if(it_borrado_pos == vec1.end())
        cout<<"Iterador en posición correcta"<<endl;

    vector_dinamico<int>::iterator it2 = vec1.begin();

    cout<<"Insertando 50 al principio y 1000 al final..."<<endl;

    vec1.insert(it2,50);

    while(it2 != vec1.end())
        it2++;
    
    vec1.insert(it2,1000);

    //Comprobación del operador [] y size
    cout<<"Vector: ";
    for(int i = 0 ; i < vec1.size() ; i++)
        cout<<vec1[i]<<" "; 
    cout<<endl;


}