#include <guiatlf.h>

using namespace std;

Guia_Tlf::Guia_Tlf(){} 

Guia_Tlf::Guia_Tlf(const Guia_Tlf &g){
    datos = g.datos;
}

Guia_Tlf::~Guia_Tlf(){}

Guia_Tlf Guia_Tlf::operator=(const Guia_Tlf &g){
    datos = g.datos;
    return *this;
}

string &Guia_Tlf::operator[](const string &nombre){
    return datos[nombre];
}

Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf &g){
    Guia_Tlf resultado(*this);
    for (auto it = g.datos.begin() ; it != g.datos.end() ; ++it){
        resultado.datos.insert(*it);
    }
    return resultado;
}

Guia_Tlf Guia_Tlf::operator-(const Guia_Tlf &g){
    Guia_Tlf resultado;
    for(auto it = g.datos.begin() ; it != g.datos.end() ;++it){
        auto encontrado = g.datos.find(it->first);
        
        if(encontrado == g.datos.end()){
            resultado.datos.insert(*it);
        }
    }
    resultado;
}

ostream &operator<<(ostream & os, Guia_Tlf & g){
    for (auto it = g.datos.begin() ; it != g.datos.end() ; ++it){
        os << it->first << '\t' << it->second << '\n';
    }
    return os;
}

istream &operator>>(istream & is, Guia_Tlf & g){ //uso de LLM para revisar la gestion de archivos
    g.clear();

    string linea;

    while (getline(is, linea)){ //lee hasta el salto de linea en is, y lo guarda en linea
        if(!linea.empty() && linea.back() == '\r'){ //comprueba q la linea no sea vacia y q acabe en \r 
            linea.pop_back();   //eliminaria el \r
        }

        size_t posicion = linea.find('\t'); //si no encuentra tabulador devuelve string::npos

        if(posicion != string::npos){
            string nombre = linea.substr(0, posicion);
            string telefono = linea.substr(posicion +1);

            g.insert(nombre, telefono);
        }
    }

    return is;
}

string Guia_Tlf::gettelefono(const string & nombre){
    auto it = datos.find(nombre);
    
    if(it==datos.end()){
        return "";
    }
    
    return it->second;
}

pair<map<string,string>::iterator,bool> Guia_Tlf::insert(string nombre, string tlf){
    return datos.insert({nombre, tlf});
}


pair<map<string,string>::iterator,bool> Guia_Tlf::insert(pair<string,string> p){
    return datos.insert(p);
}

void Guia_Tlf::borrar(const string &nombre){
    datos.erase(nombre);
}

void Guia_Tlf::borrar(const string &nombre,const string &tlf){
    auto it = datos.find(nombre);
    if(it != datos.end() && it->second == tlf){
        datos.erase(it);
    }
}

int Guia_Tlf::size()const{
    return datos.size();
}

unsigned int Guia_Tlf::contabiliza(const string &nombre){
    return datos.count(nombre);
}

void Guia_Tlf::clear(){
    datos.clear();
}

Guia_Tlf Guia_Tlf::previos(const string &nombre,const string &tlf){
    Guia_Tlf resultado;

    for(auto it = datos.begin() ; it != datos.lower_bound(nombre) ; ++it){
        resultado.datos.insert(*it);
    }

    auto it = datos.find(nombre);

    if(it != datos.end() && it->second == tlf){
        resultado.datos.insert(*it);
    }

    return resultado;
}

Guia_Tlf Guia_Tlf::inter(const Guia_Tlf & g){
    Guia_Tlf res;
    for (auto it = datos.begin() ; it != datos.end() ; ++it){
        auto jt = g.datos.find(it->first);
        if (jt != g.datos.end()) // para coincidencia de nombre y telefono
        res.datos.insert(*it);
    }
    return res;
}

void Guia_Tlf::modi(const string &nombre, const string &newtlf){
    auto it = datos.find(nombre);
    if (it != datos.end())
    it->second = newtlf;
}

Guia_Tlf Guia_Tlf::filtro(const string & prefijo){
    Guia_Tlf res;
    for (auto it = datos.lower_bound(prefijo) ; it != datos.end(); ++it) { // recorre desde q empieza el prejijo hasta q el if acaba los bucles
        if (it->first.compare(0, prefijo.size(), prefijo) != 0) // uso de LLM para aprender una funcion de comparacion 
        break;
        res.datos.insert(*it);
    }
    return res;
}



Guia_Tlf::iterator  Guia_Tlf::begin(){}

iterator  end(){}