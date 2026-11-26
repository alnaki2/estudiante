/**
 * @file diccionario.h
 * @brief Especificación del TDA Diccionario.
 */
#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

/**
 * @brief Tipo elemento que define el diccionario.
 *
 * Cada elemento asocia una clave única con una lista de información.
 *
 * @tparam T Tipo de la clave (no se repite; p.ej. un DNI).
 * @tparam U Tipo de cada dato asociado a la clave (p.ej. string).
 */
template <class T, class U>
struct data {
    T clave;              ///< Clave del elemento (única dentro del diccionario).
    list<U> info_asoci;   ///< Lista de informaciones asociadas a la clave.
};

/**
 * @brief Operador de comparación de datos.
 *
 * Ordena dos registros de acuerdo a su clave de tipo T. Puede usarse
 * como functor.
 *
 * @tparam T Tipo de la clave.
 * @tparam U Tipo de la información asociada.
 * @param d1 Primer registro.
 * @param d2 Segundo registro.
 * @return true si la clave de @p d1 es menor que la de @p d2, false en caso contrario.
 */
template <class T, class U>
bool operator<(const ::data<T, U> &d1, const ::data <T, U>&d2) {
    if (d1.clave < d2.clave)
        return true;
    return false;
}

/**
 * @brief TDA Diccionario.
 *
 * Almacena elementos ::data ordenados de menor a mayor clave. Cada clave
 * aparece una sola vez y lleva asociada una lista de informaciones.
 *
 * @tparam T Tipo de la clave. Debe tener definido operator<.
 * @tparam U Tipo de la información asociada.
 */
template <class T, class U>
class Diccionario {
private:

    list<::data<T, U> > datos;   ///< Elementos del diccionario, ordenados por clave.

    /**
     * @brief Copia un diccionario en el objeto implícito.
     * @param D Diccionario que se copia.
     * @post El objeto implícito contiene los mismos datos que @p D.
     */
    void Copiar(const Diccionario<T, U>& D);

    /**
     * @brief Borra todos los datos que contiene el diccionario.
     * @post El diccionario queda vacío.
     */
    void Borrar();

public:

    /**
     * @brief Constructor por defecto.
     * @post Crea un diccionario vacío.
     */
    Diccionario();

    /**
     * @brief Constructor de copia.
     * @param D Diccionario a copiar.
     * @post El nuevo diccionario es una copia de @p D.
     */
    Diccionario(const Diccionario &D);

    /**
     * @brief Destructor.
     * @post Libera los recursos del diccionario.
     */
    ~Diccionario();

    /**
     * @brief Operador de asignación.
     * @param D Diccionario a asignar.
     * @return Referencia al objeto implícito, ya con el contenido de @p D.
     */
    Diccionario<T, U> & operator=(const Diccionario<T, U> &D);

    /**
     * @brief Iterador sobre los elementos del diccionario.
     *
     * Permite recorrer y modificar los elementos, en orden creciente de clave.
     */
    class iterator {
    private:
        typename list<::data<T, U>>::iterator it;   ///< Iterador de la lista interna.
        friend class Diccionario<T, U>;
    public:
        /** @brief Constructor por defecto. */
        iterator() {
        }

        /**
         * @brief Constructor a partir de un iterador de la lista interna.
         * @param otro Iterador de la lista interna.
         */
        iterator(typename list<::data<T, U>>::iterator otro) : it(otro) {
        }

        /**
         * @brief Operador de preincremento.
         * @return Referencia al iterador, ya avanzado una posición.
         */
        iterator &operator++() {
            ++it;
            return *this;
        }

        /**
         * @brief Operador de postincremento.
         * @return Copia del iterador antes de avanzar.
         */
        iterator operator++(int) {
            iterator aux(*this);
            ++it;
            return aux;
        }

        /**
         * @brief Operador de predecremento.
         * @return Referencia al iterador, ya retrocedido una posición.
         */
        iterator &operator--() {
            --it;
            return *this;
        }

        /**
         * @brief Operador de postdecremento.
         * @return Copia del iterador antes de retroceder.
         */
        iterator operator--(int) {
            iterator aux(*this);
            --it;
            return aux;
        }

        /**
         * @brief Operador de desreferencia.
         * @pre El iterador no debe estar en end().
         * @return Referencia al elemento ::data apuntado.
         */
        ::data<T, U> &operator*() {
            return *it;
        }

        /**
         * @brief Operador de igualdad.
         * @param otro Iterador con el que se compara.
         * @return true si ambos apuntan al mismo elemento.
         */
        bool operator==(const iterator &otro) const {
            return it == otro.it;
        }

        /**
         * @brief Operador de desigualdad.
         * @param otro Iterador con el que se compara.
         * @return true si apuntan a elementos distintos.
         */
        bool operator!=(const iterator &otro) const {
            return it != otro.it;
        }
    };

    /**
     * @brief Iterador constante sobre los elementos del diccionario.
     *
     * Permite recorrer los elementos, en orden creciente de clave, sin modificarlos.
     */
    class const_iterator {
    private:
        typename list<::data<T, U>>::const_iterator it;   ///< Iterador constante de la lista interna.
    public:
        /** @brief Constructor por defecto. */
        const_iterator() {
        }

        /**
         * @brief Constructor a partir de un iterador constante de la lista interna.
         * @param otro Iterador constante de la lista interna.
         */
        const_iterator(typename list<::data<T, U>>::const_iterator otro) : it(otro) {
        }

        /**
         * @brief Operador de preincremento.
         * @return Referencia al iterador, ya avanzado una posición.
         */
        const_iterator &operator++() {
            ++it;
            return *this;
        }

        /**
         * @brief Operador de postincremento.
         * @return Copia del iterador antes de avanzar.
         */
        const_iterator operator++(int) {
            const_iterator aux(*this);
            ++it;
            return aux;
        }

        /**
         * @brief Operador de desreferencia.
         * @pre El iterador no debe estar en end().
         * @return Referencia constante al elemento ::data apuntado.
         */
        const ::data<T, U> &operator*() const {
            return *it;
        }

        /**
         * @brief Operador de igualdad.
         * @param otro Iterador con el que se compara.
         * @return true si ambos apuntan al mismo elemento.
         */
        bool operator==(const const_iterator &otro) const {
            return it == otro.it;
        }

        /**
         * @brief Operador de desigualdad.
         * @param otro Iterador con el que se compara.
         * @return true si apuntan a elementos distintos.
         */
        bool operator!=(const const_iterator &otro) const {
            return it != otro.it;
        }
    };

    /**
     * @brief Busca una clave en el diccionario.
     * @param p Clave a buscar.
     * @param[out] it_out Si la clave está, apunta al elemento con esa clave;
     *             si no, apunta a la posición donde debería estar.
     * @return true si la clave está en el diccionario, false en caso contrario.
     */
    bool Esta_Clave(const T &p, typename Diccionario<T,U>::iterator &it_out);

    /**
     * @brief Inserta un nuevo registro en el diccionario.
     *
     * La inserción se hace en la posición que mantiene el orden por clave.
     *
     * @param clave Clave del nuevo registro.
     * @param info Lista de información asociada a la clave.
     * @pre El diccionario está ordenado por clave.
     * @post El diccionario contiene el registro (@p clave, @p info) y sigue ordenado.
     */
    void Insertar(const T& clave, const list<U> &info);

    /**
     * @brief Añade una nueva información asociada a una clave.
     *
     * La información se inserta al final de la lista asociada a la clave.
     * Si la clave no está en el diccionario, se inserta y se le asocia @p s.
     *
     * @param s Información a añadir.
     * @param p Clave a la que se asocia la información.
     * @post La clave @p p está en el diccionario y su lista termina en @p s.
     */
    void AddSignificado_Palabra(const U & s, const T &p);

    /**
     * @brief Devuelve la información asociada a una clave.
     * @param p Clave cuya información se consulta.
     * @return Lista con la información asociada a @p p.
     */
    list<U> getInfo_Asoc(const T & p);

    /**
     * @brief Devuelve el tamaño del diccionario.
     * @return Número de claves (elementos) del diccionario.
     */
    int size() const;

    /**
     * @brief Borra un elemento del diccionario a partir de su clave.
     * @param c Clave del elemento que se quiere borrar.
     * @return true si se ha borrado el elemento, false si la clave no estaba.
     * @post Si se borró, el diccionario ya no contiene la clave @p c.
     */
    bool Borrar(const T & c);

    /**
     * @brief Unión de dos diccionarios.
     *
     * Si una clave aparece en ambos diccionarios, en el resultante aparece
     * una sola vez con la unión de las informaciones asociadas.
     *
     * @param D Diccionario con el que se realiza la unión.
     * @return Nuevo diccionario con la unión de ambos.
     */
    Diccionario union_d(const Diccionario & D);

    /**
     * @brief Diferencia de dos diccionarios.
     *
     * Elimina del diccionario las claves que aparecen en @p D.
     *
     * @param D Diccionario cuyas claves se quieren eliminar.
     * @return Diccionario con las claves del objeto implícito que no están en @p D.
     */
    Diccionario diferencia(const Diccionario &D);

    /**
     * @brief Intersección de dos diccionarios.
     * @param D Diccionario con el que se interseca.
     * @return Diccionario con las claves presentes en ambos diccionarios.
     */
    Diccionario interseccion(const Diccionario & D);

    /**
     * @brief Devuelve un diccionario con las claves del intervalo [i,f).
     * @param i Clave inicial del rango (incluida).
     * @param f Clave final del rango (excluida).
     * @return Diccionario con los elementos cuya clave está en [@p i, @p f).
     */
    Diccionario Devolver_rango(const T &i, const T & f);

    /**
     * @brief Iterador al primer elemento.
     * @return Iterador que apunta al primer elemento del diccionario.
     */
    iterator begin() {
        return iterator(datos.begin());
    }

    /**
     * @brief Iterador a la posición posterior al último elemento.
     * @return Iterador que apunta a end().
     */
    iterator end() {
        return iterator(datos.end());
    }

    /**
     * @brief Iterador constante al primer elemento.
     * @return Iterador constante al primer elemento del diccionario.
     */
    const_iterator begin() const {
        return const_iterator(datos.begin());
    }

    /**
     * @brief Iterador constante a la posición posterior al último elemento.
     * @return Iterador constante a end().
     */
    const_iterator end() const {
        return const_iterator(datos.end());
    }

    /**
     * @brief Iterador constante al primer elemento.
     * @return Iterador constante al primer elemento del diccionario.
     */
    const_iterator cbegin() const {
        return const_iterator(datos.begin());
    }

    /**
     * @brief Iterador constante a la posición posterior al último elemento.
     * @return Iterador constante a end().
     */
    const_iterator cend() const {
        return const_iterator(datos.end());
    }
};
#include "../src/diccionario.cpp"

#endif
