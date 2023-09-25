#include <iostream>
#include <ostream>
#include <stdlib.h> //  rand() % 10 + 1; -> random del 1 al 10
#include <time.h> // srand(time(NULL));
using namespace std;

void genArrays ( int *start, int *medium, int *end, int * &frstArray, int * &scndArray ) {
    int frstSize = medium - start;
    int scndSize = end - medium;
    frstArray = scndArray = nullptr;

    frstArray = new int [frstSize];
    scndArray = new int [scndSize];

    if (frstSize > 0)
        for (int i = 0; i < frstSize; i++) 
            *(frstArray + i) = rand() % 50;

    if (scndSize > 0)
        for (int i = 0; i < scndSize; i++) 
            *(scndArray + i) = rand() % 50;
}

int main() {
    
    system("cls"); srand(time(NULL));
    std::cout << "Choose the array's length: ";
    int arrLength; std::cin >> arrLength; std::cout << "\n";

    int *array = new int [arrLength];

    std::cout << "Choose the position where you wanna cut the array: ";
    int cutPos; std::cin >> cutPos; std::cout << "\n";

    for (int i = 0; i < arrLength; i++) 
        *(array + i) = rand() % 50;

    int *frstPart, *scndPart;
    genArrays(array, array + cutPos, array + arrLength, frstPart, scndPart);

    for (int i = 0; i < cutPos; i++) 
        std::cout << "Array-1 [" << i << "] = " << *(frstPart+i) << endl;

    std::cout << "\n\n";

    for (int i = 0; i < arrLength - cutPos; i++) 
        std::cout << "Array-2 [" << i << "] = " << *(scndPart+i) << endl;
    
    std::cout << "\n\n";
    delete [] array;
    delete [] frstPart;
    delete [] scndPart;
    
    return 0;
}