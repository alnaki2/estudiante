#include <iostream>
#include <fstream>
#include "guiatlf.h"

using namespace std;

int main(int argc, char* argv[]){
    if (argc != 4) {
        cerr << "Uso: ./modificar fichero nombre nuevo_telefono" << endl;
        return 1;
    }

    ifstream f(argv[1]);
    if (!f) {
        cerr << "No se puede abrir el fichero: " << argv[1] << endl;
        return 1;
    }

    Guia_Tlf g;
    f >> g;
    g.modi(argv[2], argv[3]);
    cout << g;

    return 0;
}
