#include <iostream>
#include <vector>
#include <ostream>
using namespace std;
 
class Polinomio {
    private:
        int grado;
        vector<int> coeficientes;
        void InicializarCoefs();
    public:
        Polinomio(int grado) {
            this -> grado = grado;
            InicializarCoefs();
        }
        
};

void Polinomio::InicializarCoefs() {
    vector<int> initValueCoefs(this -> grado,0);
    this -> coeficientes = initValueCoefs;
}

int main() {
    
    system("cls");

    
    return 0;
}