#include <iostream>
#include <ostream>
#include <istream>
using namespace std;

class Racional {
    private:
        int numerador, denominador;
    public:
        Racional() {}
        Racional(int num,int den)
        : numerador(num), denominador(den) {}

        void guardarNum(int n) { numerador = n; }
        void guardarDen(int d) { denominador = d; }
        int verDen() { return denominador; }
        int verNum() { return numerador; }
};

	ostream &operator<< (ostream &o, Racional &r) {
		o << r.verNum() << "/" << r.verDen()<< endl;
		return o;
	} 

istream &operator>> (istream &i, Racional& r) {
	int num, den;
	i >> num >> den;
	r.guardarNum(num);
	r.guardarDen(den);
	return i;
} 

int main() {
    system("cls");
	Racional r;
	cout << "Ingresa r: ";
	cin >> r;
	cout << r;

	return 0;
}

