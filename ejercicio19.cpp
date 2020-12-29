#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include <set>
#include <list>
#include <vector>

using namespace std;

struct piloto{
    string nombre;
    string apellidos;
    string escuderia;
    int puntos;

    piloto(){
        nombre = "";
        apellidos = "";
        escuderia = "";
        puntos = int();
    }

    piloto(string n, string a, string e, int p){
        nombre = n;
        apellidos = a;
        escuderia = e;
        puntos = p;
    }
};

bool operator==(const piloto &p1, const piloto &p2){
    return p1.nombre == p2.nombre && p1.apellidos == p2.apellidos && p1.escuderia == p2.escuderia && p1.puntos == p2.puntos;
}


class comparacion_cads{
    public:
        template<typename T>
        bool operator()(const T &p1,const T &p2)const{
            return p1.first < p2.first;
        }
};

/**
 * @brief Para acceder a cada piloto por su campo de manera más eficiente,
 * se tendrán sets para cada campo ordenados para así facilitar el acceso a un piloto
 * por su campo, estos sets contendrán ademas un entero que indica el índice en el vector
 * donde se encuentran los elementos de tipo piloto. La desventaja de esta representación
 * es que cada piloto se almacena "2 veces", sin embargo, los accesos se hacen mucho más 
 * eficientes independientemente del campo
 */
class pilotos{
    private:
        set<pair<string,int>,comparacion_cads> nombres_ordenados;
        set<pair<string,int>,comparacion_cads> apellidos_ordenados;
        multiset<pair<string,int>,comparacion_cads> escuderias_ordenadas;
        set<pair<int,int>,greater<pair<int,int>>> puntos_ordenados;

        vector<piloto> vec_pilotos;
    public:
        pilotos(){

        }

        pilotos(const pilotos &otros){
            vec_pilotos = otros.vec_pilotos;
            nombres_ordenados = otros.nombres_ordenados;
            apellidos_ordenados = otros.apellidos_ordenados;
            escuderias_ordenadas = otros.escuderias_ordenadas;
            puntos_ordenados = otros.puntos_ordenados;
        }

        piloto buscar_apellidos(string apellidos)const{
            pair<string,int> a_buscar;
            a_buscar.first = apellidos;
            set<pair<string,int>>::const_iterator it = apellidos_ordenados.find(a_buscar);

            if(it != apellidos_ordenados.end()){
                return vec_pilotos[it->second];
            }else{
                piloto p;
                p.nombre = "No encontrado";
                return p;
            }
            
        }

        piloto buscar_nombre(string nombre)const{
            pair<string,int> a_buscar;
            a_buscar.first = nombre;
            set<pair<string,int>>::const_iterator it = nombres_ordenados.find(a_buscar);
            
            if(it != nombres_ordenados.end()){
                return vec_pilotos[it->second];
            }else{
                piloto p;
                p.nombre = "No encontrado";
                return p;
            }
            
        }

        list<piloto> buscar_escuderia(string ecuderia) const{
            list<piloto> lista_pilotos;
            pair<string,int> a_buscar;
            a_buscar.first = ecuderia;
            pair<multiset<pair<string,int>>::const_iterator,multiset<pair<string,int>>::const_iterator> ret = escuderias_ordenadas.equal_range(a_buscar);

            for(multiset<pair<string,int>>::const_iterator iter = ret.first ; iter != ret.second ; iter++){
                lista_pilotos.push_back(vec_pilotos[iter->second]);
            }

            return lista_pilotos;
        }

        piloto posicion(int num)const{
            assert(num <= vec_pilotos.size());
            int indice = 1;
            set<pair<int,int>>::iterator it = puntos_ordenados.begin();
            
            while(indice < num){
                indice++;
                it++;
            }
            
            return vec_pilotos[it->second];
        }

        void insertar_piloto(const piloto &p){
            nombres_ordenados.insert(make_pair(p.nombre,vec_pilotos.size()));
            apellidos_ordenados.insert(make_pair(p.apellidos,vec_pilotos.size()));
            escuderias_ordenadas.insert(make_pair(p.escuderia,vec_pilotos.size()));
            puntos_ordenados.insert(make_pair(p.puntos,vec_pilotos.size()));

            vec_pilotos.push_back(p);
        }

        void cambiar_puntuacion(string apellidos, string nombre,int puntos){
            pair<string,int> a_buscar1;
            a_buscar1.first = apellidos;
            pair<string,int> a_buscar2;
            a_buscar2.first = nombre;
            set<pair<string,int>>::iterator iter1 = apellidos_ordenados.find(a_buscar1);
            set<pair<string,int>>::iterator iter2 = nombres_ordenados.find(a_buscar2);
            
            if(iter1->second == iter2->second){
                vec_pilotos[iter1->second].puntos = puntos;
            }
        }

        class iterator{
            private:
                set<pair<int,int>>::reverse_iterator iterador_puntuaciones;
                vector<piloto> pilotos_asociados;
            public:
                iterator(){

                }

                iterator(set<pair<int,int>>::reverse_iterator punts, vector<piloto> pilotos){
                    iterador_puntuaciones = punts;
                    pilotos_asociados = pilotos;
                }

                iterator & operator=(const iterator & otro){
                    iterador_puntuaciones = otro.iterador_puntuaciones;
                    pilotos_asociados = otro.pilotos_asociados;

                    return *this;
                }

                piloto & operator *(){
                    return pilotos_asociados[iterador_puntuaciones->second];
                }

                iterator operator++(int ){
                    iterator iter_aux;
                    iter_aux.iterador_puntuaciones = iterador_puntuaciones;
                    iterador_puntuaciones++;
                    return iter_aux;
                }

                bool operator==(const iterator &otro)const{
                    return iterador_puntuaciones == otro.iterador_puntuaciones;
                }

                bool operator!=(const iterator &otro)const{
                    return iterador_puntuaciones != otro.iterador_puntuaciones;
                }
        };

        iterator begin(){
            iterator a_devolver(puntos_ordenados.rbegin(),vec_pilotos);

            return a_devolver;
        }

        iterator end(){
            iterator a_devolver(puntos_ordenados.rend(),vec_pilotos);

            return a_devolver; 
        }
};

int main(){
    pilotos pi;
    piloto p1("Valtteri", "Bottas", "Mercedes", 100),
           p2("Lewis","Hamilton","Mercedes",100),
           p3("Lando","Norris","Mclaren",76),
           p4("Carlos", "Sainz", "Mclaren",50),
           p5("Max", "Verstappen","Redbull",60),
           p6("Alexander","Albon","Redbull",89),
           p7("Charles","Leclerc","Ferrari",120),
           p8("Sebastian","Vettel","Ferrari",35);
    
    pi.insertar_piloto(p1);
    pi.insertar_piloto(p2);
    pi.insertar_piloto(p3);
    pi.insertar_piloto(p4);
    pi.insertar_piloto(p5);
    pi.insertar_piloto(p6);
    pi.insertar_piloto(p7);
    pi.insertar_piloto(p8);

    cout<<"Pilotos: "<<endl;
    for(pilotos::iterator it = pi.begin() ; it != pi.end() ; it++){
        cout<<(*it).nombre<<" "<<(*it).apellidos<<", "<<(*it).escuderia<<", "<<(*it).puntos<<" puntos"<<endl;
    }

    
    string n;
    cout<<"Búsqueda por nombre: ";
    getline(cin,n);
    piloto busqueda_por_nombre = pi.buscar_nombre(n);
    cout<<busqueda_por_nombre.nombre<<" "<<busqueda_por_nombre.apellidos<<", "<<busqueda_por_nombre.escuderia<<", "<<busqueda_por_nombre.puntos<<" puntos"<<endl;


    cout<<"Búsqueda por apellidos: ";
    getline(cin,n);
    piloto busqueda_por_apellidos = pi.buscar_apellidos(n);
    cout<<busqueda_por_apellidos.nombre<<" "<<busqueda_por_apellidos.apellidos<<", "<<busqueda_por_apellidos.escuderia<<", "<<busqueda_por_apellidos.puntos<<" puntos"<<endl;

    cout<<"Búsqueda por escudería: ";
    getline(cin,n);
    list<piloto> con_escuderia = pi.buscar_escuderia(n);
    for(list<piloto>::iterator it = con_escuderia.begin() ; it != con_escuderia.end() ; it++){
        cout<<(*it).nombre<<" "<<(*it).apellidos<<", "<<(*it).escuderia<<", "<<(*it).puntos<<" puntos"<<endl;
    }

    int p;
    cout<<"Búsqueda por posicion: ";
    cin >>p;
    piloto busqueda_por_pos = pi.posicion(p);
    cout<<busqueda_por_pos.nombre<<" "<<busqueda_por_pos.apellidos<<", "<<busqueda_por_pos.escuderia<<", "<<busqueda_por_pos.puntos<<" puntos"<<endl;

    string nom,ap;
    int punt;
    cout<<"Cambiar puntuación: "<<endl<<"Nombre: ";
    cin.ignore();
    getline(cin,nom);
    cout<<"Apellidos: ";
    getline(cin,ap);
    cout<<"Puntuación: ";
    cin>>punt;
    pi.cambiar_puntuacion(ap,nom,punt);

    cout<<"Pilotos: "<<endl;
    for(pilotos::iterator it = pi.begin() ; it != pi.end() ; it++){
        cout<<(*it).nombre<<" "<<(*it).apellidos<<", "<<(*it).escuderia<<", "<<(*it).puntos<<" puntos"<<endl;
    }
}