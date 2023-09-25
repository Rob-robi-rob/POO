#include <iostream>
#include <vector>
#include <ostream>
using namespace std;
 
int *redimensionar( int *lista, int n, int c ) {
    int *newVint = new int[c];
    for (int i = 0; i < c; i++) 
        if (i >= n) newVint[i] = 0;
        else newVint[i] = lista[i];

    delete []lista;
    return newVint;
}

void mostrarLista( int *lista, int tamanio ){
    for (int i = 0; i < tamanio; i++) 
        std::cout << lista[i] << endl;
}

int main() {
    
    system("cls");
    int n = 9;
    int *vint = new int[n] {1,2,3,4,5,6,7,8,9};

    int c = 15;
    vint = redimensionar(vint, n, c);
    mostrarLista(vint, c);

    delete [] vint;
    
    return 0;
}