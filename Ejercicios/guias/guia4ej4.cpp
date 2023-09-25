#include <iostream>
#include <istream>
#include <ostream>
using namespace std;

class Complejo {
private:
	int pImag, pReal, r;
public:
	Complejo() {}
	Complejo(int real, int img) 
	: pImag(img), pReal(real) {}
	
	void GuardarImg(int im) {
		pImag = im;
	}
	void GuardarReal(int rl) {
		pReal = rl;
	}
	int VerReal() {
		return pReal;
	}
	int VerImag() {
		return pImag;
	}
	int Verrta() {
		return r;
	}
};

istream &operator>> (istream &i, Complejo &c) {
	int img, real;
	i >> real >> img;
	c.GuardarImg(img);
	c.GuardarReal(real);
	return i;
}

ostream &operator<< (ostream &o, Complejo &c) {
	o << c.VerReal() << "+ i " << c.VerImag() << endl;
	return o;
}

Complejo& operator+ (Complejo &c1, Complejo &c2){
	static Complejo r;
	r.GuardarImg(c1.VerImag() + c2.VerImag());
	r.GuardarReal(c1.VerReal() + c2.VerReal());
	
	return r;
}

Complejo& operator- (Complejo &c1, Complejo &c2){
	Complejo* r = new Complejo;
	r->GuardarImg(c1.VerImag() - c2.VerImag());
	r->GuardarReal(c1.VerReal() - c2.VerReal());
	
	return *r;
}

Complejo& operator* (Complejo &c1, Complejo &c2){
	static Complejo r;
	r.GuardarImg(c1.VerImag() * c2.VerImag());
	r.GuardarReal(c1.VerReal() * c2.VerReal());
	
	return r;
}

bool operator== (Complejo &c1, Complejo &c2) {
	return (c1.VerImag() == c2.VerImag()and c1.VerReal() == c2.VerReal());
}


int main() {

    system("cls");
	Complejo c;
	Complejo d(3,4);
	cin >> c;
	cout << c;
	cout << (d+c);
	cout << (d-c);
	cout << (d*c);
	cout << (d==c);
	
	
	return 0;
}

