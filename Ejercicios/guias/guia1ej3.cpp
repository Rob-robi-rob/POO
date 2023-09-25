#include <iostream>
#include <vector>
#include <ostream>
using namespace std;

int *buscarEntero( vector<int> & lista, int numero ) {
    for (int i = 0; i < lista.size(); i++) 
        if (lista[i] == numero) 
            return &lista[i];

    return nullptr;
}
 
int main() {
    
    system("cls");
    vector<int> numList = {3,6,9,12,1,5,7};

    int *direc = buscarEntero(numList, 1);
    int *direc2 = buscarEntero(numList, 13);
    
    std::cout << direc << endl;
    std::cout << direc2 << endl;

    return 0;
}





