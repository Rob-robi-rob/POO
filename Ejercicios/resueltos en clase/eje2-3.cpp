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
using namespace std;
class Polinomio{
private:
	int grado;
	int coef[20];   //supongo hasta grado 19 como maximo
public:
	Polinomio(){grado=0;}
	Polinomio(int _g){
		grado=_g;
		for(int i=0;i<=grado;i++)
			*(coef+i)=0;
	}
	void CambiaCoef(int _g,int _v) {*(coef+_g)=_v;}
	int Evalua(int _x);
	string VerTermino(int _x){
	    stringstream s;
		s<<*(coef+_x)<<"x^"<<_x;
		return s.str();
	}
	int VerGrado(){return grado;}
	int VerCoef(int _x){return *(coef+_x);}
	
};

int Polinomio::Evalua(int _x){
	int s=0;
	for(int i=0;i<=grado;i++) { 
		s=s + *(coef+i) * pow(_x,i);
	}
	return s;
}

Polinomio suma(Polinomio &a, Polinomio &b){
	int gramax=max(a.VerGrado(),b.VerGrado());
	Polinomio aux(gramax);
	for(int i=0;i<=gramax;i++) { 
		int ca,cb;
		if(i <= a.VerGrado()) ca=a.VerCoef(i); else ca=0;
		if(i <= b.VerGrado()) cb=b.VerCoef(i); else cb=0;
		aux.CambiaCoef(i,ca+cb);
	}
	return aux;		
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
	Polinomio su;
	su=suma(p,p2);
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

