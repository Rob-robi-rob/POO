#include <iostream>
#include <ostream>
#include <stdlib.h> //  rand() % 10 + 1; -> random del 1 al 10
#include <time.h> // srand(time(NULL));

using namespace std;
 
int main() {
    
    system("cls");
    
    std::cout << "Ingrese tamanio del arreglo: ";
    int n; std::cin >> n; std::cout << endl;

    int *v = new int[n];
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        v[i] = rand() % 500 + 1000;
        std::cout << "v[" << i << "] = " << v[i] << endl;
    }

    std::cout << endl << "Primer elemento: " << v[2] << " ---> ubicado en ---> " << &v[2] << "\n\n\n\n";

    delete [] v;
        
    return 0;
}