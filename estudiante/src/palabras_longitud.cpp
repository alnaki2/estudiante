/**
 * @file palabras_longitud.cpp
 * @brief Imprime las palabras de un diccionario con una longitud dada.
 * Uso: ./palabras_longitud fichero_diccionario longitud
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "dictionary.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <fichero_diccionario> <longitud>" << endl;
        return 1;
    }
    ifstream f(argv[1]);
    if (!f) {
        cerr << "Error: no se puede abrir " << argv[1] << endl;
        return 1;
    }
    int longitud = atoi(argv[2]);

    Dictionary dic;
    f >> dic;

    vector<string> v = dic.wordsOfLength(longitud);
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    return 0;
}