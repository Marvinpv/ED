#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

bool esLetra(char a)
{
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
}

map<string, int> contar(string texto)
{
    map<string, int> salida;
    string palabra;

    for (int i = 0; i <= texto.length(); i++)
    {

        if (!esLetra(texto[i]))
        {
            if (esLetra(texto[i + 1]))
            {
                salida[palabra]++;
                palabra = "";
            }
        }
        else
        {
            palabra += texto[i];
        }
    }

    return salida;
}

vector<string> veces(const map<string, int> &palabras, int num)
{
    vector<string> devolver;
    for (map<string, int>::const_iterator iter = palabras.cbegin(); iter != palabras.cend(); iter++)
    {
        if (iter->second == num)
            devolver.push_back(iter->first);
    }

    return devolver;
}

int main()
{

    string texto1 = "A las cinco de la tarde.";
    texto1 += "Eran las cinco en punto de la tarde.";

    texto1 += "Un ninio trajo la blanca sabana ";
    texto1 += "a las cinco de la tarde.";

    texto1 += "Una espuerta de cal ya prevenida ";
    texto1 += "a las cinco de la tarde.";

    texto1 += "Lo demas era muerte y solo muerte ";
    texto1 += "a las cinco de la tarde.";

    texto1 += "El viento se llevo los algodones ";
    texto1 += "a las cinco de la tarde.";

    cout << endl
         << " Texto 1: " << endl
         << texto1 << endl;

    map<string, int> contadores = contar(texto1);

    vector<string> repetidas_n;
    for (int i = 1; i <= 10; i++)
    {
        repetidas_n = veces(contadores, i);
        cout << "Palabras repetidas " << i << " veces: " << endl;
        for (vector<string>::iterator iter = repetidas_n.begin(); iter != repetidas_n.end(); iter++)
            cout << *iter << ", ";
        cout << endl;
    }
}