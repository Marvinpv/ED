#include <iostream>
/**
 * @file ejercicio21.cpp
 * @author Marvin Peinado Vidaña
 * @brief 
 * @version 0.1
 * @date 2020-12-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <string>
#include <cctype>
#include <cassert>
#include <set>
#include <queue>
#include <vector>

using namespace std;

struct paciente{
    string nombre;
    string apellidos;
    string dni;
    int gravedad;

    paciente(){
        nombre = "";
        apellidos = "";
        dni = "";
        gravedad = 0;
    }

    paciente(string n, string a, string d, int g){
        nombre = n;
        apellidos = a;
        dni = d;
        gravedad = g;
    }
};

class comparador_apellidos{
    public:
        bool operator()(const paciente &p1, const paciente &p2)const{
            return p1.apellidos < p2.apellidos || (p1.apellidos == p2.apellidos && p1.nombre < p2.nombre);
        }
};

class comparador_gravedad{
    public:
        bool operator()(const set<paciente>::iterator & i1,const set<paciente>::iterator &i2)const{
            return i1->gravedad < i2->gravedad;
        }
};

/**
 * @brief Para hacer las búsquedas más eficientes, se van a utilizar un set ordenado por apellidos
 * para guardar los pacientes, y una cola con prioridad para poder sacar los pacientes con gravedad
 * máxima y eliminarlos del set con el iterador que devuelve si quisieramos hacer que se pudiera
 * acceder por dni, podríamos implementar un map<string,set<paciente>::iterator> que dirigen a la posicion
 * del set del paciente con dni buscado
 */
class urgencias{
    private:
        priority_queue<set<paciente>::iterator,vector<set<paciente>::iterator>,comparador_gravedad> cola_por_gravedad;
        set<paciente,comparador_apellidos> personas;
    public:
        urgencias(){
            
        }

        void insertar_paciente(const paciente &p){
            pair<set<paciente>::iterator,bool> res_insercion = personas.insert(p);
            if(res_insercion.second){
                cola_por_gravedad.push(res_insercion.first);
            }
            
        }

        paciente mas_grave(){
            set<paciente>::iterator iter = cola_por_gravedad.top();
            paciente p = *iter;
            personas.erase(cola_por_gravedad.top());
            cola_por_gravedad.pop();

            return p;
        }

        paciente buscar_paciente(string nombre,string apellidos)const{
            paciente a_buscar;
            a_buscar.nombre = nombre;
            a_buscar.apellidos = apellidos;
            set<paciente>::iterator it = personas.find(a_buscar);

            if(it != personas.end()){
                return *it;
            }else{
                paciente vacio;
                vacio.nombre = "No encontrado";
                return vacio;
            }
        }

        int size()const{
            return personas.size();
        }

        

        class iterator{
            private:
                set<paciente>::iterator iter;
            public:
                iterator(){

                }

                iterator(const set<paciente>::iterator &otro_iter){
                    iter = otro_iter;
                }

                iterator(const iterator &otro){
                    iter = otro.iter;
                }

                iterator & operator=(const iterator & otro){
                    iter = otro.iter;

                    return *this;
                }

                const paciente & operator *()const{
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

        };

        iterator begin()const{
            urgencias::iterator it(personas.begin());

            return it;
        }

        iterator end()const{
            urgencias::iterator it(personas.end());

            return it;
        }
};

int main(){
    urgencias u;
    paciente p1("Marvin","Peinado Vidania","54199226W",1),
             p2("Francisco","Fernandez Fernandez","11111111A",99),
             p3("Juan","Garcia Garcia","22222222B",56),
             p4("Pepe","Ramirez Suarez","33333333C",12);

    u.insertar_paciente(p1);
    u.insertar_paciente(p2);
    u.insertar_paciente(p3);
    u.insertar_paciente(p4);

    cout<<"Pacientes: "<<endl;
    for(urgencias::iterator it = u.begin() ; it != u.end() ; it++){
        cout<<(*it).nombre<<" "<<(*it).apellidos<<", "<<(*it).dni<<", urgencia: "<<(*it).gravedad<<endl;
    }

    string nom,ap;
    cout<<"Buscar paciente,"<<endl<<"Nombre: ";
    getline(cin,nom);
    cout<<"Apellidos: ";
    getline(cin,ap);

    paciente p = u.buscar_paciente(nom,ap);
    cout<<p.nombre<<" "<<p.apellidos<<", "<<p.dni<<", grado de urgencia: "<<p.gravedad<<endl;

    cout<<"Paciente más grave atendido..."<<endl;

    paciente pg = u.mas_grave();

    cout<<"Paciente atendido: ";
    cout<<pg.nombre<<" "<<pg.apellidos<<", "<<pg.dni<<", grado de urgencia: "<<pg.gravedad<<endl;

    cout<<"Pacientes: "<<endl;
    for(urgencias::iterator it = u.begin() ; it != u.end() ; it++){
        cout<<(*it).nombre<<" "<<(*it).apellidos<<", "<<(*it).dni<<", urgencia: "<<(*it).gravedad<<endl;
    }
}