#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    file fic_g = argv[1];
    string no = argv[2];

    Guia_Tlf n_g_f = fic_g.filtro(no);
}