#include <dictionary.h>

using namespace std;

Guia_Tlf(){
    datos = {};
}


string & operator[](const string &nombre){
    auto it = datos.find[nombre];
    return it->second;
}

string  gettelefono(const string & nombre){
    auto it = datos.find[nombre];
    return it->second;
}

pair<map<string,string>::iterator,bool>  insert(string nombre, string tlf){
    auto par = datos.insert({nombre, tlf});
    return par;
}
// REVISAR

pair<map<string,string>::iterator,bool>  insert(pair<string,string> p){

}

void borrar(const string &nombre){
    datos.erase(nombre);
}

void borrar(const string &nombre,const string &tlf){
    datos.erase(nombre, tlf);<
}

int size()const{
    return datos.size();
}

unsigned int contabiliza(const string &nombre){
    return datos.count(nombre);
}

void clear(){
    datos.clear();
}

Guia_Tlf operator+(const Guia_Tlf & g){

}

Guia_Tlf operator-(const Guia_Tlf & g){

}

Guia_Tlf previos(const string &nombre,const string &tlf){

}

Guia_Tlf inter(const Guia_Tlf & g){

}

void modi(const string &nombre, const string &newtlf){

}

Guia_Tlf filtro(const string & c){

}

friend ostream & operator<<(ostream & os, Guia_Tlf & g){

}

friend istream & operator>>(istream & is, Guia_Tlf & g){

}


iterator  begin(){}

iterator  end(){}