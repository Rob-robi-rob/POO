/*Ejercicio 2 (35 pts)
	a) Defina una clase Asignatura que reciba en su constructor el nombre de una materia y el n�mero de
	cuatrimestre al que pertenece. La clase debe tener m�todos para consultar estos datos y para
	gestionar una lista de "unidades" (strings).
	b) Implemente, reutilizando la clase Asignatura, las clases FuPro y CompGraf para representar las
	materias �Fundamentos de Programaci�n� y �Computaci�n Gr�fica� respectivamente. Estas clases
	deben tener un m�todo CalcularCondicion que reciba un vector de elementos de tipo struct
	Evaluacion { string tipo; int nota; } con los resultados de un alumno. El m�todo debe verificar que los
	tipos de evaluaciones sean los correctos (si no lo son, deber� retornar "error"), y calcular su
	condici�n final en base a sus notas la condici�n final del alumno.
	- Para FuPro, las evaluaciones deben ser de tipos "parcial1" y "parcial2"; y la condici�n final ser�
	"promocionado" si el promedio llega a 70 y la nota m�nima no es menor de 60, "regular" si la nota
	m�nima no baja de 40, o "libre" en caso contrario.
	- Para CompGraf, las evaluaciones deben ser de tipos "tp1" y "tp2", "tpFinal", y "parcial". La
	condici�n final ser� "promocionado" si todos los tps est�n aprobados (nota 60 o superior) y el parcial
	tiene 65 o m�s; "regular" si los tps est�n aprobados pero el parcial no, o "libre" si alg�n tp est�
	desaprobado.
	c) Escriba una funci�n �testCalcularCondicion� para probar el m�todo CalcularCondicion. La funci�n
	debe poder recibir cualquier Materia, permitir al usuario ingresar un vector de Evaluaciones y mostrar
	la condici�n resultante.
			
*/			
#include <iostream>
#include <vector>
#include <typeinfo> 


using namespace std;

struct Evaluacion{
	string tipo;
	int nota;
};

class Asignatura{
	string nombre;
	int cuatrimestre;
	vector<string>unidades;
public:
	Asignatura (string n, int c):nombre(n),cuatrimestre(c){}
	string VerNombre(){return nombre;}
	int VerCuatrimestre(){return cuatrimestre;}
	string VerUnidad(int x){return unidades[x];}
	virtual string CalcularCondicion(vector<Evaluacion>&x) = 0;
	void AgregarUnidad(string x){unidades.push_back(x);}
	int CantidadUnidades(){return unidades.size();}
	virtual ~Asignatura(){} 
};

class FuPro:public Asignatura{
public:
	FuPro(string n, int c):Asignatura(n,c){}
	string CalcularCondicion(vector<Evaluacion>&x);
	~FuPro(){}
};
class CompGraf:public Asignatura{
public:
	CompGraf(string n, int c):Asignatura(n,c){}
	string CalcularCondicion(vector<Evaluacion>&x);
	~CompGraf(){}
};

string FuPro::CalcularCondicion(vector<Evaluacion>&x){
	if(x.size()==2 && x[0].tipo=="parcial1" && x[1].tipo=="parcial2"){
		if((x[0].nota+x[1].nota)/2>=70 && x[0].nota>=60 && x[1].nota>=60) return "promocionado";
		if( x[0].nota>=40 && x[1].nota>=40) return "regular";
		return "libre";
	}else return "error";
}

string CompGraf::CalcularCondicion(vector<Evaluacion>&x){
	if(x.size()==4 && x[0].tipo=="tp1" && x[1].tipo=="tp2"&& x[2].tipo=="tpFinal"&& x[3].tipo=="parcial"){
		if(x[0].nota>=60 && x[1].nota>=60 && x[2].nota>=60 && x[3].nota>=65) return "promocionado";
		if( x[0].nota>=60 && x[1].nota>=60 && x[2].nota>=60 ) return "regular";
		return "libre";
	}else return "error";
}


void testCalcularCondicion(Asignatura *x){
	vector<Evaluacion>v;
	string ti;
	int no;
	cout<<x->VerNombre()<< " - Cuatrimestre: "<<x->VerCuatrimestre()<<endl;
	cout<<"Ingrese evaluaciones:\n";
	/*FuPro *fp = dynamic_cast<FuPro*>(x);    // una forma.....
	if(fp)*/
	if (typeid(*x)==typeid(FuPro))          //  otra forma... Utilizando typeid para obtener informaci�n adicional
	    for(int i=0;i<2;i++){ 
			cout<<"Tipo: "; cin>>ti;
			cout<<"Nota: "; cin>>no;
			cin.ignore();
			v.push_back({ti,no});
	    }
	else
		for(int i=0;i<4;i++) { 
			cout<<"Tipo: "; cin>>ti;
			cout<<"Nota: "; cin>>no;
			cin.ignore();
			v.push_back({ti,no});
		} 	
	cout<<x->CalcularCondicion(v);
}
	

int main(int argc, char *argv[]) {
	Asignatura *pA;
	int op;
	cout<<"Ingrese 1:FuPro o 2:CompGraf: ";
	cin>>op;
	if (op==1){
		pA=new FuPro("Fundamentos de Programaci�n",1);
	}else {
		pA=new CompGraf("Computaci�n Gr�fica",2);
	}
	cout<<"\n\n";
	testCalcularCondicion(pA);
	delete pA;
	return 0;
}

