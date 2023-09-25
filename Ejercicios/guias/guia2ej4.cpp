#include <iostream>
#include <vector>
#include <ostream>
#include <stdlib.h> //  rand() % 10 + 1; -> random del 1 al 10
#include <time.h> // srand(time(NULL));
using namespace std;

class VectorDinamico {
    private:
        int *list;
        int size;
    public:
        VectorDinamico(int size) {
            this -> size = size;
            this -> list = new int[size];
            for (int i = 0; i < size; i++) 
                list[i] = rand() % 10 + 1;
        }
        ~VectorDinamico() {
            delete [] this -> list;
        }
        void VerLista();
        void Duplicar();
        int VerElemento( int pos );
        
};

void VectorDinamico::Duplicar() {
    int *newList = new int[ this -> size * 2 ];
    for (int i = 0; i < this -> size*2; i++) 
        if (i >= this -> size) 
            newList[i] = rand() % 10 + 1;
        else 
            newList[i] = this -> list[i];

    delete [] this -> list;
    this -> list = newList;
    this -> size *= 2;
}
 
int VectorDinamico::VerElemento( int pos ) {
    return this -> list[pos-1];
}

void VectorDinamico::VerLista() {
    for (int i = 0; i < this -> size; i++) 
        std::cout << this -> list[i] << endl;
}

int main() {
    
    system("cls"); srand(time(NULL));
    VectorDinamico vd(rand() % 5 + 5);
    vd.VerLista(); std::cout << endl;
    vd.Duplicar(); 
    vd.VerLista(); std::cout << endl;
    std::cout << "Ver posicion: ";
    int pos; std::cin >> pos;
    std::cout << vd.VerElemento(pos);
    
    return 0;
}