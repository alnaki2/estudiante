/**
 * @file apariciones.cpp
 * @brief Cuenta las apariciones de un carácter en un diccionario.
 * Uso: ./apariciones fichero_diccionario caracter
 */
#include <iostream>
#include <fstream>
#include "dictionary.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <fichero_diccionario> <caracter>" << endl;
        return 1;
    }
    ifstream f(argv[1]);
    if (!f) {
        cerr << "Error: no se puede abrir " << argv[1] << endl;
        return 1;
    }
    Dictionary dic;
    f >> dic;

    char c = argv[2][0];
    cout << "El caracter '" << c << "' aparece " << dic.getOccurrences(c)
         << " veces en el diccionario." << endl;
    return 0;
}