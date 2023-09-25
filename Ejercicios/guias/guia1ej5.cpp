#include <iostream>
#include <vector>
#include <ostream>
#include <stdlib.h> //  rand() % 10 + 1; -> random del 1 al 10
#include <time.h> // srand(time(NULL));
using namespace std;
 
void genList( int tam, int lista[] ) {
    for (int i = 0; i < tam; i++) 
        lista[i] = rand() % 100 + 1;
}

void insertar( int value, int pos, int list[], int size) {
    for (int i = size+1; i >= pos-1; i--) 
        if ( i == pos-1 ) list[i] = value;
        else list[i] = list[i-1];
}

void mostrarLista( int lista[], int tamanio ){
    for (int i = 0; i < tamanio; i++) 
        std::cout << lista[i] << endl;
}

int main() {
    
    system("cls");
    srand(time(NULL));

    int n = 10, lista[n+1]; genList(n, lista);
    int m = 12, p = 4; insertar(m, p, lista, n);
    mostrarLista(lista,n);
    
    return 0;
}