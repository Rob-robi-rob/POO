/*Diseñe una clase Polinomio que contenga:
	a. un constructor que reciba el grado el polinomio e inicialice sus coeficientes
	en 0.
	b. un método que permita cambiar un coeficiente.
	c. un método evaluar que permita evaluar el polinomio para un valor dado de
	la variable x.
	d. el/los métodos que considere necesarios para poder mostrar un polinomio
	desde un programa cliente.
	e. una función que permita sumar dos polinomios retornando un tercer
	polinomio con el resultado (ej. p_res=Sumar(p1,p2);). ¿Cómo variaría si en
	lugar de ser una función libre fuera un método de la clase?
	Verifique el funcionamiento de la función Sumar(...) mediante un programa cliente.*/
#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
using namespace std;
class Polinomio {
	vector<float> coef;
public:
	Polinomio(int g) {
		coef.resize(g+1,0);
	}
	void CambiaCoef(int g, float k) { 
		coef[g] = k;
	}
	int VerGrado() { return coef.size()-1; }
	int Evalua(int _x);
	float VerCoef(int g) {
		if (g >= coef.size()) return 0;    //si es un valor mayor que el grado devuelvo 0 es para la suma
		return coef[g]; 
	}
	string VerTermino(int _x){
		stringstream s;
		s<<coef[_x]<<"x^"<<_x;
		return s.str();
	}
};

int Polinomio::Evalua(int _x){
	int s=0;
	for(int i=0;i<=coef.size();i++) { 
		s=s + coef[i] * pow(_x,i);
	}
	return s;
}

Polinomio suma(Polinomio p1, Polinomio p2) {
	int gmax = max(p1.VerGrado(),p2.VerGrado());
	Polinomio res(gmax);
	for (int i=0; i< gmax; ++i) { 
		res.CambiaCoef(i,p1.VerCoef(i)+p2.VerCoef(i));
	}
	return res;
}


int main(int argc, char *argv[]) {
	int N;
	cout<<"Ingrese el grado del polinomio: ";
	cin>>N;
	Polinomio p(N);
	int c;
	for(int i=p.VerGrado();i>=0;i--) { 
		cout<<"Ingrese el coeficiente para el grado "<<i<<": ";
		cin>>c;
		p.CambiaCoef(i,c);
	}
	cout<<"\nPolinomio: ";
	for(int i = p.VerGrado();i>0;i--) { 
		cout<<p.VerTermino(i)<<" + ";
	}
	cout<<p.VerTermino(0)<<endl;
	
	cout<<endl<<endl;
	cout<<"Ingrese el grado del polinomio 2: ";
	cin>>N;
	Polinomio p2(N);
	for(int i=p2.VerGrado();i>=0;i--) { 
		cout<<"Ingrese el coeficiente para el grado "<<i<<": ";
		cin>>c;
		p2.CambiaCoef(i,c);
	}
	cout<<"\nPolinomio2: ";
	for(int i = p2.VerGrado();i>0;i--) { 
		cout<<p2.VerTermino(i)<<" + ";
	}
	cout<<p2.VerTermino(0)<<endl;
	
	
	cout<<endl<<endl<<"suma: ";
	Polinomio su=suma(p,p2);
	for(int i = su.VerGrado();i>0;i--) { 
		cout<<su.VerTermino(i)<<" + ";
	}
	cout<<su.VerTermino(0)<<endl;
	
	cout<<"\nIngrese el valor de x para evaluar: ";
	int x;
	cin>>x;
	cout<<"Resultado de suma("<<x<<")= "<<su.Evalua(x)<<endl;
	
	
	return 0;
}

