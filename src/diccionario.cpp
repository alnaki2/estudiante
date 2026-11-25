#include "diccionario.h"

template <class T, class U>
void Diccionario<T, U>::Copiar(const Diccionario<T, U> &D){
    datos = D.datos;
}

template <class T, class U>
void Diccionario<T, U>::Borrar(){
    datos.clear();
}

template <class T, class U>
Diccionario<T, U>::Diccionario(){
}

template <class T, class U>
Diccionario<T, U>::Diccionario(const Diccionario<T, U> &D){
    Copiar(D);
}

template <class T, class U>
Diccionario<T, U>::~Diccionario(){
    Borrar();
}

template <class T, class U> 
Diccionario<T, U> &Diccionario<T, U>::operator=(const Diccionario<T, U> &D){
    if(this != &D){
        Copiar(D);
    }
    return *this;
}

template <class T, class U>
bool Diccionario<T, U>::Esta_Clave(const T &p, typename Diccionario<T, U>::iterator &it_out){
    typename list<data<T.U>::iterator it = datos.begin();
    while (it != datos.end() && it->clave < p){
        ++it;
    }

    it_out = iterator(it);

    return it != datos.end() && !(p < it->clave) && !(it->clave < p);
}

template <class T, class U>
void Diccionario<T, U>::Insertar(const T &clave, const list<U> &info){
    iterator it;
    if(!Esta_Clave(clave, it)){
        data<T,U> nuevo;
        nuevo.clave = clave;
        nuevo.info_asoci = info;

        datos.insert(it.it, nuevo)
    }
}

template <class T, class U>
void Diccionario<T, U>::AddSignificado_Palabra(const U &s,const T &p){
    iterator it;

    if(Esta_Clave(p, it)){
        (*it).info_asoci.push_back(s);
    } else{
        list<U> nueva_info;
        nueva_info.push_back(s);
        Insertar(p, nueva_info);
    }
}

template <class T, class U>
list<U> Diccionario<T, U>::getInfo_Asoc(const T &p){
    iterator it;

    if(Esta_Clave(p, it)){
        return (*it).info_asoci;
    }

    return list<U>();
}

template <class T, class U>
int Diccionario<T, U>::size() const{
    return datos.size();
}

template <class T, class U>
bool Diccionario<T, U>::Borrar(const T &c){
    iterator it;

    if (!Esta_Clave(c, it)){
        return false;
    }

    datos.erase(it.it);
    return true;
}

template <class T, class U>
Diccionario<T, U> Diccionario<T, U>::union_d(const Diccionario<T, U> &D){
    Diccionario<T,U> resultado(*this); //creamos un diccionario a partir del actual

    for ( typename list<data<T,U>>::const_iterator it = D.datos.begin() ; it != D.datos.end() ; ++it){ // recorremos el dado para la union
        iterator encontrado;

        if (!resultado.Esta_Clave(it->clave, encontrado)){  // si en el resultado no esta el apuntado en D
            resultado.Insertar(it->clave, it->info_asoci);  // se añade
        } else {                                            // si en el resultado esta el apuntado en D
            for (typename list<U>::const_iterator significado = it.info_asoci.begin() ; significado != it->info_asoci.end() ; ++significado){ //recorremos la info asociada del elemento actual 
                bool repetido = false;

                for (typename list<U>::const_iterator actual = (*encontrado).info_asoci.begin() ; actual != (*encontrado).info_asoci.end(); ++actual){
                    if(*actual == *significado){
                        repetido = true;
                    }
                }
                if(!repetido){
                    (*encontrado).info_asoci.push_back(*significado);
                }
            }
        }
    }
    return resultado;
}

template <class T, class U>
Diccionario<T, U> Diccionario<T, U>::diferencia(const Diccionario<T, U> &D){
    Diccionario <T,U> resultado;

    for(typename list<data<T,U>::const_iterator it = datos.begin() ; it != datos.end(); ++it;){
        iterator encontrado;

        if(!D.Esta_Clave(it->clave, encontrado)){
            resultado.Insertar(it->clave, it->info_asoci);
        }
    }
}

template <class T, class U>
Diccionario<T, U> Diccionario<T, U>::interseccion(const Diccionario<T, U> &D){
    Diccionario<T,U> resultado;

    for(typename list<Data<T,U>>::const_iterator it = datos.begin() ; it != datos.end ; ++it){
        iterator encontrado;
        if(D.Esta_Clave(it->clave, encontrado)){
            resultado.Insertar(it->clave, it->info_asoci);
        }
    }
    return resultado;
}

template <class T, class U>
Diccionario<T, U> Diccionario<T, U>::Devolver_rango(const T &i, const T &f){
    Diccionario<T,U> resultado;
    for(typename list<data<T,U>>::const_iterator it = datos.begin() ; it != datos.end() ; ++it){
        if(!(it->clave < i) && it->clave < f){
            resultado.Insertar(it->clave, it->info_asoci);
        }
    }
    return resultado;
}

template <class T, class U>
Diccionario<T, U>::iterator::iterator(){
}

template <class T, class U>
::data<T, U> &
Diccionario<T, U>::iterator::operator*(){
    return *it;
}