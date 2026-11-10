/**
 * @file dictionary.h
 * @brief Especificación del TDA Dictionary (implementado sobre set<string>)
 */
#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/**
 * @brief TDA Dictionary
 * @details Almacena un conjunto de palabras ordenadas alfabéticamente y sin
 * repeticiones, y permite iterar sobre ellas.
 *
 * @par Representación
 * Se usa un set<string>. El invariante de la representación es que no hay
 * palabras repetidas (garantizado por set) y están ordenadas.
 */
class Dictionary{
private:
  set<string> words; ///< Conjunto de palabras del diccionario
public:

  /**
   * @brief Constructor por defecto. Crea un Dictionary vacío
   */
  Dictionary();

  /**
   * @brief Constructor de copia
   * @param other Dictionary que se quiere copiar
   */
  Dictionary(const Dictionary& other);

  /**
   * @brief Destructor. Limpia todos los elementos del Dictionary
   */
  ~Dictionary();

  /**
   * @brief Limpia el Dictionary. Elimina todas las palabras del conjunto
   */
  void clear();

  /**
   * @brief Tamaño del diccionario
   * @return Número de palabras guardadas en el diccionario
   */
  unsigned int size() const;

  /**
   * @brief Devuelve las palabras del diccionario con una longitud dada
   * @param length Longitud de las palabras buscadas
   * @return Vector de palabras con la longitud deseada
   */
  vector<string> wordsOfLength(int length) const;

  /**
   * @brief Indica si una palabra está en el diccionario
   * @param val Palabra que se quiere buscar
   * @return true si la palabra existe, false en caso contrario
   */
  bool exists(const string& val) const {return words.count(val) > 0;}

  /**
   * @brief Número de apariciones de una letra en todo el diccionario
   * @param c Letra a buscar
   * @return Número de apariciones de c
   */
  int getOccurrences(const char c) const;

  /**
   * @brief Añade al diccionario actual las palabras de otro
   * @param dic Diccionario cuyas palabras se añaden
   */
  void anade(const Dictionary &dic);

  /**
   * @brief Comprueba si el diccionario está vacío
   * @return true si está vacío, false en caso contrario
   */
  bool empty() const {return words.empty();}

  /**
   * @brief Elimina una palabra del diccionario
   * @param val Palabra a borrar
   * @return true si la palabra se ha borrado, false si no estaba
   */
  bool erase(const string &val){return words.erase(val) > 0;}

  /**
   * @brief Inserta una palabra en el diccionario
   * @param val Palabra a insertar
   * @return true si la inserción ha tenido éxito (la palabra no existía)
   */
  bool insert(const string &val);

  /**
   * @brief Sobrecarga del operador de asignación
   * @param dic Diccionario a copiar
   * @return Referencia al objeto implícito
   */
  Dictionary& operator=(const Dictionary &dic);

  /**
   * @brief Sobrecarga del operador de entrada
   *
   * Lee palabras de un flujo (una por línea) y las inserta en el diccionario.
   * El contenido previo de dic se pierde.
   *
   * @param is Flujo de entrada
   * @param dic Diccionario a rellenar
   * @return Flujo de entrada para poder encadenar el operador
   */
  friend istream& operator>>(istream &is, Dictionary &dic);

  /**
   * @brief Sobrecarga del operador de salida
   *
   * Imprime todas las palabras del diccionario, una por línea.
   *
   * @param os Flujo de salida
   * @param dic Diccionario a imprimir
   * @return Flujo de salida para poder encadenar el operador
   */
  friend ostream& operator<<(ostream &os, const Dictionary &dic);

  /**
   * @brief Clase iterator para recorrer el diccionario
   */
  class iterator{
  private:
    set<string>::iterator it;
  public:
    iterator(){}
    iterator(const set<string>::iterator& otro):it(otro){}
    iterator(const iterator& otro):it(otro.it){}
    ~iterator(){}
    iterator& operator=(const set<string>::iterator& otro){it=otro;return *this;}
    iterator& operator=(const iterator& otro){it=otro.it;return *this;}
    string operator*() const {return *it;}
    iterator& operator++(){++it;return *this;}
    iterator& operator--(){--it;return *this;}
    iterator operator++(int){iterator aux(*this);++it;return aux;}
    iterator operator--(int){iterator aux(*this);--it;return aux;}
    bool operator!=(const iterator& otro) const {return it != otro.it;}
    bool operator==(const iterator& otro) const {return it == otro.it;}
  };

  /**
   * @brief Clase const_iterator para recorrer diccionarios constantes
   */
  class const_iterator{
  private:
    set<string>::const_iterator const_it;
  public:
    const_iterator(){}
    const_iterator(const set<string>::const_iterator& otro):const_it(otro){}
    const_iterator(const const_iterator& otro):const_it(otro.const_it){}
    ~const_iterator(){}
    const_iterator& operator=(const set<string>::const_iterator& otro){const_it = otro;return *this;}
    const_iterator& operator=(const const_iterator& otro){const_it = otro.const_it;return *this;}
    const string operator*() const {return *const_it;}
    const_iterator& operator++(){++const_it;return *this;}
    const_iterator& operator--(){--const_it;return *this;}
    const_iterator operator++(int){const_iterator aux(*this);++const_it;return aux;}
    const_iterator operator--(int){const_iterator aux(*this);--const_it;return aux;}
    bool operator!=(const const_iterator& otro) const {return const_it != otro.const_it;}
    bool operator==(const const_iterator& otro) const {return const_it == otro.const_it;}
  };

  /** @brief Iterador al primer elemento */
  iterator begin(){iterator i = words.begin();return i;}
  /** @brief Iterador a la posición posterior al último elemento */
  iterator end(){iterator i = words.end();return i;}
  /** @brief const_iterator al primer elemento */
  const_iterator begin() const {const_iterator i = words.begin();return i;}
  /** @brief const_iterator a la posición posterior al último elemento */
  const_iterator end() const {const_iterator i = words.end();return i;}
};

#endif
