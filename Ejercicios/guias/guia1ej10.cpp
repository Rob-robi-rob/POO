#include <iostream>
#include <vector>
#include <ostream>
#include <stdlib.h> //  rand() % 10 + 1; -> random del 1 al 10
#include <time.h> // srand(time(NULL));
using namespace std;

void genList( int lista[], int tam ) {
    for (int i = 0; i < tam; i++) 
        lista[i] = rand() % 100 + 1;
}

void showList( int lista[], int tamanio ){
    for (int i = 0; i < tamanio; i++) 
        std::cout << lista[i] << endl;
}

struct sameVal {
    int *frst = nullptr,
        *scnd = nullptr;
};

sameVal findDup( int list[], int size ) {
    sameVal newVals; 
    for (int i = 0; i < size; i++) {
        int counter = 0;
        for (int j = 0; j < size; j++) {
            if (list[i] == list[j]) {
                counter++;
                if (counter == 1) newVals.frst = &list[j];
                else if (counter == 2) {
                    newVals.scnd = &list[j];
                    return newVals;
                } 
            } 
        }
    }
    return {nullptr,nullptr};
}

int main() {
    system("cls"); srand(time(NULL));
    int n = rand() % 10 + 10;
    int list[n]; genList(list, n); showList(list, n);
    sameVal valsDup = findDup(list, n);

    if (valsDup.frst == nullptr) std::cout << "No hay duplicados" << endl;
    else std::cout << *valsDup.frst <<" en " << valsDup.frst << " y " << valsDup.scnd << endl;

    return 0;
}













