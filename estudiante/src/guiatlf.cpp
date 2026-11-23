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
    Guia_Tlf res;
    for (auto it = datos.begin() ; it != datos.end() ; ++it){
        auto jt = g.datos.find(it->first);
        if (jt != g.datos.end()) // para coincidencia de nombre y telefono
            res.datos.insert(*it);
    }
    return res;
}

void modi(const string &nombre, const string &newtlf){
    auto it = datos.find(nombre);
    if (it != datos.end())
        it->second = newtlf;
}

Guia_Tlf filtro(const string & c){
    Guia_Tlf res;
    for (auto it = datos.lower_bound(prefijo) ; it != datos.end(); ++it) { // recorre desde q empieza el prejijo hasta q el if acaba los bucles
        if (it->first.compare(0, prefijo.size(), prefijo) != 0) // uso de LLM para aprender una funcion de comparacion 
            break;
        res.datos.insert(*it);
    }
    return res;
}

friend ostream & operator<<(ostream & os, Guia_Tlf & g){

}

friend istream & operator>>(istream & is, Guia_Tlf & g){
    pair<string,string> p;
    while (is >> p)
        g.instert(p);
    return is;
}


iterator  begin(){}

iterator  end(){}