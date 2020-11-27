#include "../inc/diccionario.h"


int main(){
    Diccionario<string,string> dic_prueba;
    int opcion;
    bool salir = false;

    do{

        cout << " Bienvenido al diccionario , elija opcion: "          << endl
             << "1: Insertar nueva Palabra "                           << endl
             << "2: Añadir un significado a una palabra ya existente " << endl
             << "3: Buscar una palabra en el diccionario "             << endl
             << "4: Salir"                                             << endl;
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
            default:

                salir = true; 
                break;
        }

    }while(!salir);

    dic_prueba.~Diccionario();

    return 0;
}