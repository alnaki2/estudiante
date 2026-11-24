#include <iostream>
#include <fstream>
#include "guiatlf.h"

using namespace std;

int main(int argc, char* argv[]){
    if (argc != 3) {
        cerr << "Uso: ./inter fichero_guia_1 fichero_guia_2" << endl;
        return 1;
    }

    ifstream f1(argv[1]);
    ifstream f2(argv[2]);
    if (!f1 || !f2) {
        cerr << "No se puede abrir uno de los ficheros indicados" << endl;
        return 1;
    }

    Guia_Tlf g1;
    Guia_Tlf g2;
    f1 >> g1;
    f2 >> g2;

    Guia_Tlf resultado = g1.inter(g2);
    cout << resultado;

    return 0;
}
