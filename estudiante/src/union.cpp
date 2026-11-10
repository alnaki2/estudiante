/**
 * @file union.cpp
 * @brief Genera la unión de dos diccionarios e imprime el resultado.
 * Uso: ./union diccionario1 diccionario2
 */
#include <iostream>
#include <fstream>
#include "dictionary.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <diccionario1> <diccionario2>" << endl;
        return 1;
    }
    ifstream f1(argv[1]), f2(argv[2]);
    if (!f1 || !f2) {
        cerr << "Error: no se puede abrir alguno de los ficheros" << endl;
        return 1;
    }
    Dictionary d1, d2;
    f1 >> d1;
    f2 >> d2;

    Dictionary u(d1);
    u.anade(d2);

    cout << u;
    return 0;
}