#include <iostream>
#include <ostream>
#include <cmath>
using namespace std;
 
#define Pi 3.141592

class Tanque {
    private:
        int peso, volumen;
    public:
        Tanque(int peso): volumen(0) {
            this -> peso = peso;
        }
        void VerPeso() {
            std::cout << peso << endl;
        }
};

class Cilindro: public Tanque {
    private:
        int radio, altura, volumen;
    public:
        Cilindro(int radio, int altura, int peso) 
        : Tanque(peso) {
            this -> radio = radio;
            this -> altura = altura;
            this -> volumen = Pi * pow(radio,2);   
        }
        int VerVolumen() { return volumen; }
};

class Esfera: public Tanque {
    private:
        int radio, altura, volumen;
    public:
        Esfera(int radio, int peso) 
        : Tanque(peso) {
            this -> radio = radio;
            this -> altura = altura;
            this -> volumen = 4 / 3 * Pi * pow(radio,3);   
        }
        int VerVolumen() { return volumen; }
};

int main() {
    Tanque *tanqCil = new Cilindro(5,4,250);
    Tanque *tanqEsf = new Esfera(5,250);

    delete tanqCil;
    delete tanqEsf;
    
    return 0;
}