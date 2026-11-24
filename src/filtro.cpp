#include <iostream>
#include <fstream>
#include "guiatlf.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Uso: ./filtro fichero prefijo" << endl;
        return 1;
    }

    ifstream f(argv[1]);

    if (!f) {
        cerr << "No se puede abrir el fichero: " << argv[1] << endl;
        return 1;
    }

    Guia_Tlf guia;

    f >> guia;

    Guia_Tlf resultado = guia.filtro(argv[2]);

    cout << resultado;

    return 0;
}