#include <iostream>
#include <fstream>
#include "guiatlf.h"
using namespace std;

int main(int argc, char* argv[]){
    if (argc != 3) {
        cerr << "Uso: ./filtro fichero prefijo" << endl;
        return 1;
    }
    ifstream f(argv[1]);
    Guia_Tlf g;
    f >> g;
    cout << g.filtro(argv[2]);
    return 0;
}