#include <iostream>
#include <ostream>
using namespace std;

 
int main() {
    
    system("cls");

    int staticVar = 10;
    int *dynamicVar = new int;

    std::cout << "Ingrese el valor de dynamicVar: ";
    std::cin >> *dynamicVar;

    std::cout << "\nLa direccion de staticVar es: " << &staticVar << endl;
    std::cout << "La direccion de dynamicVar es: " << dynamicVar << endl;

    delete dynamicVar;
    std::cout << "\n\n";

    return 0;
}