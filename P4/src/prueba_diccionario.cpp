#include "diccionario.h"


int main(){
    Diccionario<string,string> dic_prueba;
    Diccionario<string,string> dic_a_aniadir;
    list<string> significados_a_aniadir;
    significados_a_aniadir.push_back("animal felino doméstico");
    significados_a_aniadir.push_back("aparato que se usa en los talleres");
    dic_a_aniadir.Insertar("gato",significados_a_aniadir);
    


    int opcion;
    bool salir = false;
    


    do{

        cout << " Bienvenido al diccionario , elija opcion: "          << endl
             << "1: Insertar nueva Palabra "                           << endl
             << "2: Añadir un significado a una palabra ya existente " << endl
             << "3: Buscar una palabra en el diccionario "             << endl
             << "4: Combinar diccionario con otro de prueba"           << endl
             << "5: Imprimir el diccionario completo "                 << endl
             << "6: Salir "                                            << endl;
        cin  >> opcion;

        switch (opcion){

            case 1:
            {
                string palabra,significado;
                int num_significados = 0;
                list<string> significados;

                    cout << "Palabra: " ;
                    cin  >> palabra;
                    cout << "¿Cuántos significados tiene? ";
                    cin  >> num_significados;
                    cin.ignore();
                    for(int i = 1 ; i <= num_significados ; i++){
                        cout << "Entrada "<<i<<": ";
                        getline(cin,significado);
                        
                        significados.push_back(significado);
                    }

                dic_prueba.Insertar(palabra,significados);
            }
                break;

            case 2:
            {
                string palabra,significado;
                cout << "Palabra a la que se añade el significado : ";
                cin  >> palabra;
                cin.ignore();
                cout << "Introduzca significado: ";
                getline(cin,significado);

                cout<<"Va a llamar";
                dic_prueba.AddSignificado_Palabra(significado,palabra);
            }
                break;
            case 3:
            {
                string palabra;
                    cout << "Palabra a buscar: ";
                    cin  >> palabra;

                    string entradas = dic_prueba.Entradas_para_clave(palabra);
                    cout << entradas;
            }
                break;
            case 4:
            {
                    cout << "Combinando..." << endl;
                    dic_prueba += dic_a_aniadir;
                    string contenido = dic_prueba.Contenido_del_Diccionario();
                    cout << "Contenido de los diccionarios combinados..." << endl;
                    cout << contenido;
            }
                break;
            case 5:
                cout << "El contenido del diccionario es: "    <<endl
                     << dic_prueba.Contenido_del_Diccionario() <<endl;
                break;
            default:

                salir = true; 
                break;
        }

    }while(!salir);

    return 0;
}