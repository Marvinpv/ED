#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

bool esLetra(char a){
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') ;
}

string encripta(string cad, const map<char,char> &codigo){

    string nuevacad;

    for(int i = 0 ; i < cad.length() ; i++){  //EL tolower puede que sobre, ya que el código puede que tenga para minúsculas y mayúsculas
        if( esLetra(cad[i]) )
            nuevacad += codigo.at( tolower(cad[i]) );
        else
            nuevacad += cad[i];
        
    }
    
    return nuevacad;
}

int main(){
    map<char,char> codig = {
        {'a','z'},
        {'b','y'},
        {'c','x'},
        {'d','w'},
        {'e','v'},
        {'f','u'},
        {'g','t'},
        {'h','s'},
        {'i','r'},
        {'j','q'},
        {'k','p'},
        {'l','o'},
        {'m','n'},
        {'n','m'},
        {'o','l'},
        {'p','k'},
        {'q','j'},
        {'r','i'},
        {'s','h'},
        {'t','g'},
        {'u','f'},
        {'v','e'},
        {'w','d'},
        {'x','c'},
        {'y','b'},
        {'z','a'},
    };

    string prueba1 = "hola";
    string prueba2 = "Que pasa";
    string prueba3 = "jajajjajajja";

    cout<<"Palabras a encriptar: "<<endl
        <<prueba1<<endl
        <<prueba2<<endl
        <<prueba3<<endl;  

    string res_prueba1 = encripta(prueba1, codig);
    string res_prueba2 = encripta(prueba2, codig);
    string res_prueba3 = encripta(prueba3, codig);

    cout<<endl<<"Resultado: "<<endl
        <<res_prueba1<<endl
        <<res_prueba2<<endl
        <<res_prueba3<<endl;

    string prueba_teclado;

    cout<<"Introduce palabra para prueba: ";
    getline(cin , prueba_teclado);

    string res_prueba_teclado = encripta(prueba_teclado, codig);

    cout<<"Resultado: "<<res_prueba_teclado<<endl;  
}