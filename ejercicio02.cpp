#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

bool esLetra(char a){
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') ;
}

string desencripta(string cad, map<char,char> &codigo){
    bool decodificado;
    string cad_desencriptada;

    map<char,char>codigo_inverso;
    for(map<char,char>::iterator it = codigo.begin() ; it != codigo.end() ; it++){
        codigo_inverso[it->second] = it->first;
    }

    for(int i = 0 ; i < cad.length() ; i++){  //EL tolower puede que sobre, ya que el código puede que tenga para minúsculas y mayúsculas
        if( esLetra(cad[i]) )
            cad_desencriptada += codigo_inverso.at( tolower(cad[i]) );
        else
            cad_desencriptada += cad[i];
    }

    /*for(int i = 0 ; i < cad.length() ; i++){
        decodificado = false;
        if(esLetra(cad[i])){                    //Este es menos eficiente
            for(map<char,char>::iterator iter = codigo.begin() ; iter != codigo.end() && !decodificado; iter++ ){
                if(iter->second == cad[i]){
                    cad_desencriptada += iter->first;
                    decodificado = true;
                }
            }
        }else{
            cad_desencriptada += cad[i];
        }
        
    }*/

    return cad_desencriptada;
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

    string prueba1 = "sloz";
    string prueba2 = "jfv kzhz";
    string prueba3 = "qzqzqqzqzqqz";

    cout<<"Palabras a desencriptar: "<<endl
        <<prueba1<<endl
        <<prueba2<<endl
        <<prueba3<<endl;  

    string res_prueba1 = desencripta(prueba1, codig);
    string res_prueba2 = desencripta(prueba2, codig);
    string res_prueba3 = desencripta(prueba3, codig);

    cout<<endl<<"Resultado: "<<endl
        <<res_prueba1<<endl
        <<res_prueba2<<endl
        <<res_prueba3<<endl;

    string prueba_teclado;

    cout<<"Introduce palabra para prueba: ";
    getline(cin , prueba_teclado);

    string res_prueba_teclado = desencripta(prueba_teclado, codig);

    cout<<"Resultado: "<<res_prueba_teclado<<endl;  
}