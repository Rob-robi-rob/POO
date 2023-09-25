#include <iostream>
#include <vector>
#include <ostream>
using namespace std;
 

class Butaca {
    private:
        int numero, precio;
        bool estado;
    public:
        Butaca( int numero, int precio, bool estado ) {
            this -> numero = numero;
            this -> precio = precio;
            this -> estado = estado;
        }
        bool VerEstado() { return estado; }
        int VerPrecio() { return precio; }
        int VerNumero() { return numero; }
        void CambiarEstado() { estado ? estado = false : estado = true; }
};

class Sala {
    private:
        string nombre;
        vector<Butaca> listaButacas;
    public:
        Sala(string nombre): nombre(nombre) { }
        void InicializarButacas();
        int ComprarEntrada(int);
        int VerRecaudado();
        int PorcentajeOcupado();
};

void Sala::InicializarButacas() {
    std::cout << "Cuantas butacas quiere agregar?\n> ";
    int cantidad; std::cin >> cantidad; std::cout << "\n\n\n";

    for (int i = 0; i < cantidad; i++) {
        std::cout << "Nro Butaca: ";
        int number; std::cin >> number; std::cout << "\n";

        std::cout << "Precio: ";
        int price; std::cin >> price; std::cout << "\n";

        std::cout << "Estado:\n0 -Libre\n1 -Ocupado\n> ";
        bool state; std::cin >> state; std::cout << "\n";

        Butaca butak(number, price, state);
        listaButacas.push_back(butak);
    }
}


int Sala::ComprarEntrada(int nroButaca) {
    bool encontroButaca = false; int precioBtk = 0;
    for ( Butaca btk: listaButacas ) {
        if (btk.VerNumero() == nroButaca) {
            encontroButaca = true;
            precioBtk = btk.VerPrecio();
            if (!btk.VerEstado()) return btk.VerNumero();
        }
        if (btk.VerPrecio() == precioBtk && encontroButaca) {
            return btk.VerNumero();
        }
    }
    return -1;
}

int Sala::VerRecaudado() {
    int total = 0;
    for ( Butaca btk: listaButacas ) 
        if (btk.VerEstado()) total += btk.VerPrecio();
    return total;
}

int Sala::PorcentajeOcupado() {
    float contador = 0.0;
    for ( Butaca btk: listaButacas ) 
        if (btk.VerEstado()) contador++;
    return (float)(contador / listaButacas.size()) * 100.00;
}

int main() {
    
    system("cls");

    
    return 0;
}