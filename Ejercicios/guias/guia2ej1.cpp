#include <iostream>
#include <ostream>
#include <cmath>
using namespace std;

#define Pi 3.14159265358979323846

class Cilindro {
    private:
        float radio, altura, volumen;
    public:
        void AsignarDatos(float radio, float altura);
        float ObtenerVolumen();
};

void Cilindro::AsignarDatos(float radio, float altura) {
    this -> radio = radio;
    this -> altura = altura;
};

float Cilindro::ObtenerVolumen() {
    this -> volumen = Pi * pow(radio,2) * altura;
    return volumen;
}; // π r² h
 
int main() {
    
    system("cls");
    float radio, altura;
    std::cout << "Radio de C1: "; std::cin >> radio;
    std::cout << "Altura de C1: "; std::cin >> altura;

    Cilindro c1; c1.AsignarDatos(radio, altura);
    Cilindro c2; c2.AsignarDatos(5.3, 10.2);

    std::cout << endl << "Volumen de C1: " << c1.ObtenerVolumen() << endl;
    std::cout << "Volumen de C2: " << c2.ObtenerVolumen() << endl;

    return 0;
}



