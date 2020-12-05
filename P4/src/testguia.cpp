#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include "guia_telefonica.h"

using namespace std;

int main()
{
    Guia_Telefonica uno;

    assert(uno.begin() == uno.end());

    fstream input_data("telefonos.txt", fstream::in);
	input_data >> uno;

    Guia_Telefonica dos(uno);

    if(uno == dos)
        cout<<"uno y dos son iguales"<<endl;
    
    char letra;
    cout<<"Inserta letra para buscar los teléfonos que empiezan por dicha letra: ";
    cin >> letra;
    cout<<uno.Telefonos_que_empiezan_por(letra);


	assert(dos.begin() != dos.end());


	Guia_Telefonica::iterator it;
	uno.insert("Manolo", "666666666");

    assert(uno["Pedro"] == dos["Pedro"]);
    uno["Pedro"][3] = '7';
    assert(uno["Pedro"] != dos["Pedro"]);


	uno = uno;
	assert(*uno.begin() == *dos.begin());

	Guia_Telefonica tres;


    Guia_Telefonica cuatro(tres);
	assert(tres.cbegin() == tres.cend());
	assert(cuatro.cbegin() == cuatro.cend());
	tres = uno;
    
    tres["Manolo"][0] = 0;
    assert(uno["Manolo"] != tres["Manolo"]);

    Guia_Telefonica cinco = uno - dos;
    assert(cinco["Manolo"] == uno["Manolo"]);
    

    size_t c = 0;
    for (Guia_Telefonica::iterator it = cinco.begin(); it != cinco.end(); ++it)
        //esto debe ejecutarse dos veces. Añadimos contador para que falle
        //si el diccionario contiene más elementos
        //Elementos esperados: Manolo y Pedro (porque a Pedro le hemos cambiado
        //un dígito)
        //usando (*it) en vez de it-> para evitar tener que sobrecargar -> en
        //caso de que el Guia_Telefonica::iterator sea implementación propia
        assert(c++ < 2 && ((*it).first == "Manolo" || (*it).first == "Pedro"));
    
    //En la unión de diccionarios, cuando la clave existe en ambos, se puede
    //tomar el valor del primer diccionario o del segundo. Se aceptan ambos.
    Guia_Telefonica seis = uno + dos;
    assert((seis["Pedro"] != uno["Pedro"] && seis["Pedro"] == dos["Pedro"])
        || (seis["Pedro"] == uno["Pedro"] && seis["Pedro"] != dos["Pedro"]));

    pair<std::map<string, string>::iterator, bool> p = seis.insert("Pedro", "123456789");
    assert(!p.second);

    cout << "OK" << endl;

    return 0;
}   