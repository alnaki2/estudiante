/**
 * @ file : guiatlf.h
 * @brief: TDA guia de telefonos
 * */

#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <map>
#include <iostream>
#include <string>
using namespace std;




/**
 *  @brief T.D.A. Guia_Tlf
 *
 * Una instancia @e c del tipo de datos abstracto @c Guia_Tlf es un objeto
 * formado por una colección de pares {(e11,e21),(e12,e22),(e13,e23),...,(e1n-1,e2n-1)}
 * ordenados por la el primer elemento del par denominado clave o key. No existen
 * elementos repetidos.
 *
 *
 * Un ejemplo de su uso:
 *
 *
 * @author Rosa Rodríguez
 * @date Marzo 2012
 */

class Guia_Tlf{
/**
 * @page repGuia_Tlf Rep del TDA Guia_Tlf
 *
 * @section invGuia_Tlf Invariante de la representación
 *
 * El invariante es \e para todo \e i y \e j tal que i<j entonces \e e1i y e1j son distintos
 *
 * @section faGuia_Tlf Función de abstracción
 *
 * Un objeto válido @e rep del TDA Guia_Tlf representa al valor
 *
 * {(rep.begin().first,rep.begin().second),(rep.begin()+1.first,rep.begin()+1.second),....,(rep.begin()+n-1.first,rep.begin()+n-1.second)}
 *
 */
private:
	map<string,string> datos; //si admites que haya nombres repetidos tendrías que usar un multimap

public:

/**
 * @brief Constructor por defecto 
 */
Guia_Tlf();

/**
 * @brief Constructor de copia de Guia_Tlf
 * 
 * @param gt guia telefonica a copiar
 */
Guia_Tlf(const Guia_Tlf & g);

/**
 * @brief Destructor de Guia_Tlf 
 */
~Guia_Tlf();

/**
 * @brief operador de asignacion
 * 
 * @param gt guia telefonica a asignar
 * @return Guia_Tlf 
 */
Guia_Tlf operator=(const Guia_Tlf & g);

/**
 * @brief Acceso a un elemento
 * @param nombre: nombre del elemento  elemento acceder
 * @return devuelve el valor asociado a un nombre, es decir el teléfono
 */
  //si fuese un multimap no podriamos usar []. Ademas que deberiamos devolver p.e un vector con todos
  // los telefonos asociados a dicho nombre
string & operator[](const string &nombre);

/**
 * @brief Union de guias de telefonos
 * @param g: guia que se une
 * @return: una nueva guia resultado de unir el objeto al que apunta this y g
 * @note: si hay 2 nombres con distinto numero, nos quedamos con el primero, de la izquierda
 */
Guia_Tlf operator+(const Guia_Tlf & g);

/**
 * @brief Diferencia de guias de telefonos
 * @param g: guia a restar
 * @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
 * @note: si hay 2 nombres distinto numero, eliminamos ambos
 */
Guia_Tlf operator-(const Guia_Tlf & g);

/**
 * @brief Escritura de la guia de telefonos
 * @param os: flujo de salida. Es MODIFICADO
 * @param g: guia de telefonos que se escribe
 * @return el flujo de salida
 */
friend ostream & operator<<(ostream & os, Guia_Tlf & g);

/**
 * @brief Lectura de  la guia de telefonos
 * @param is: flujo de entrada. ES MODIFICADO
 * @param g: guia de telefonos. ES MODIFICADO
 * @return el flujo de entrada
 * @note: si g tenia contactos los eliminaremos
 */
friend istream & operator>>(istream & is, Guia_Tlf & g);

/**
 * @brief getter de telefono de nombre
 * @param nombre nombre del que queremos obtener el telefono
 * @return string telefono del nombre
 * @note Si no se encuentra el nombre devuelve un string vacio
 */
string  gettelefono(const string & nombre);

/**
 * @brief Insert un nuevo telefono
 * @param nombre: nombre clave del nuevo telefono
 * @param tlf: numero de telefono
 * @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
 */
pair<map<string,string>::iterator,bool>  insert(string nombre, string tlf);

/**
 * @brief Insert un nuevo telefono
 * @param p: pair con el nombre y el telefono asociado
 * @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
 */
pair<map<string,string>::iterator,bool>  insert(pair<string,string> p);

/**
 * @brief Borrar un telefono
 * @param nombre: nombre que se quiere borrar
 * @note: en caso de que fuese un multimap borraria todos con ese nombre
 */
void borrar(const string &nombre);

/**
 * @brief Borrar un telefono
 * @param nombre: nombre que se quiere borrar y telefono asociado
 * @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
 */
//con map siempre hay uno con multimap puede existir mas de uno
void borrar(const string &nombre,const string &tlf);

/**
 * @brief  Numero de telefonos
 * @return el numero de telefonos asociados
 */
int size()const{return datos.size();}

/**
 * @brief cuenta apariciones de un nombre
 * @param nombre: nombre sobre el que queremos consultar
 * @return numero de telefonos asociados a un nombre
 */
//al ser un map debe de ser 0 o 1. Si fuese un multimap podríamos tener mas de uno
unsigned int contabiliza(const string &nombre){return datos.count(nombre);}

/**
 * @brief Limpia la guia
 */
void clear(){datos.clear();}


/**
 * @brief  Obtiene una guia con los nombre previos a uno dado
 * @param nombre: nombre delimitador
 * @param tlf: telefono asociado a nombre
 * @return nueva guia sin nombres mayores que @p nombre
 * @note incluye @p nombre
 */
Guia_Tlf previos(const string &nombre,const string &tlf);

/**
 * @brief Interseccion de guias de telefonos
 * @param g  guia a hacer la interseccion con la guia apuntada por this
 * @return: una nueva guia resultado de la interseccion del objeto al que apunta this y g
 */
Guia_Tlf inter(const Guia_Tlf & g);

/**
 * @brief Modificamos el telefono asociado a un nombre
 * @param nombre es el nombre al que le vamos a cambiar el telefono
 * @param newtlf es el nuevo telefono para ese nombre
 * @return Nada
 */
void modi(const string &nombre, const string &newtlf);

/**
 * @brief obtiene una guia con los nombres que comiencen por un string
 * @param c string con el comienzo de los nombres
 * @return: una nueva guia con los nombres que comienzan por c
 */
Guia_Tlf filtro(const string & c);


/**
 * @brief clase para iterar sobre la guia
 */
class iterator{
  private:
    map<string, string>::iterator it;

  public:
    /**
     * @brief Constructor por defecto
     * 
     */
    iterator(){
    }

    /**
     * @brief Constructor a partir de un
     * 
     * @param i 
     */
    iterator(map<string, string>::iterator i){
      it = i;
    }

    pair<const string, string> &operator*(){
      return *it;
    }

    iterator &operator++(){
      ++it;
      return *this;
    }

    iterator operator++(int){
      iterator aux(*this);
      ++it;
      return aux;
    }

    bool operator==(const iterator &otro) const{
      return it == otro.it;
    }

    bool operator!=(const iterator &otro) const{
      return it != otro.it;
    }

  }; //termina class iterator
  
  
  iterator begin();

  iterator end();



}; //del class Guia_Tlf
#endif

