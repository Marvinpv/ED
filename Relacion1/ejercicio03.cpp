/**
 * @file ejercicio3.cpp
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

template<class T>
class cola{
    private:
        stack<T> pila;
        stack<T> auxiliar;
        int elementos;
    public:

        cola(){
            elementos = 0;
        }

        cola(const cola<T> &otra){
            pila = otra.pila;
            auxiliar = otra.auxiliar;
            elementos = otra.elementos;
        }

        inline bool empty()const{
           return elementos == 0; 
        }

        void push(const T &n){ //Esta operación tiene eficiencia O(n)
            if(this->empty()){
                pila.push(n);
            }else{

                while(!pila.empty()){
                    auxiliar.push(pila.top());
                    pila.pop();
                
                }
                pila.push(n);

                while(!auxiliar.empty()){
                    pila.push(auxiliar.top());
                    auxiliar.pop();
                }

            }
            elementos++;
        }

        inline int size()const{
            return elementos;
        }

        inline int front()const{
            if(elementos > 0)
                return pila.top();
            
            return 0;
        }

        inline void pop(){
            pila.pop();         //Esta operación tiene eficiencia O(1)
            elementos--;
        }

        T back(){
            T max;
            while(pila.size() > 1){
                auxiliar.push(pila.top());
                pila.pop();
            }
            max = pila.top();

            while(!auxiliar.empty()){
                pila.push(auxiliar.top());
                auxiliar.pop();
            }    
            
            return max;
        }

        const cola & operator=(const cola<T> & otra){

            if(this != &otra){
                pila = otra.pila;
                auxiliar = otra.auxiliar;
                elementos = otra.elementos; 
            }
            

            return *this;
        }

        
        friend bool operator==(const cola<T> &a,const cola<T> &b){
            stack<T> aux_a = a.pila;
            stack<T> aux_b = b.pila;
            bool iguales = true;

            if(aux_a.size() != aux_b.size())
                iguales = false;

            while(iguales && !aux_a.empty()){
                if(aux_a.top() != aux_b.top()){
                    iguales = false;
                }
                    
                aux_a.pop();
                aux_b.pop();
            }

            return iguales;
        }

        
        friend bool operator<(const cola<T> &a,const cola<T> &b){

            stack<T> aux_1(a.pila),aux_2(b.pila);
            bool menor = true;

            while(aux_1.top() == aux_2.top() && !aux_1.empty() && !aux_2.empty()){
                aux_1.pop();
                aux_2.pop();  
            }

            if(aux_1.empty())
                menor = true;
            else if(aux_2.empty())
                menor = false;
            else
                menor = aux_1.top() < aux_2.top();

            return menor;

        }
};




int main(){
    cola<int> p,q;
    int i;
    for( i = 0 ; i <= 10 ; i++){
        p.push(i);
        q.push(i);
    }
  
    if(p == q)
        cout<<"p y q son iguales"<<endl;
        
    p.push(11);      
    p.push(9);        

    cout<<"Primer elemento: "<<p.front()<<endl<<"Último elemento: "<<p.back()<<endl;
    while(!p.empty()){
        cout<<"Elemento:"<<p.front()<<endl<<"Número de elementos: "<<p.size()<<endl;
        p.pop();
    }

    cola<int> c;
    bool salir = false;
    int opcion;
    cout<<"Prueba de la clase cola"<<endl;
    do{
        cout<<"¿Qué desea hacer?"<<endl
            <<"1: meter un elemento"<<endl
            <<"2: sacar un elemento"<<endl
            <<"3: conocer el frente"<<endl
            <<"4: salir"<<endl;

        cin>>opcion;

        switch (opcion)
        {
        case 1:
            int elem;
            cout<<"Elemento: ";
            cin >>elem;
            c.push(elem);
            break;
        case 2:
            c.pop();
            cout<<"Elemento eliminado..."<<endl;
            break;
        case 3:
            cout<<"El frente es "<<c.front()<<endl;
            break;
        default:
            salir = true;
            break;
        }
    }while(!salir);

    return 0;
}
