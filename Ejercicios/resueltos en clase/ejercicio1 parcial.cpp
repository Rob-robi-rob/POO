


/*Ejercicio 1 (30 pts)
	a) Escriba una función que reciba tres punteros indicando el comienzo, una posición intermedia y el
	final de un arreglo. La función debe generar y retornar dos nuevos arreglos dinámicos: uno con los
	elementos que en el arreglo de entrada estaban antes de la posición intermedia, y otro con los que
	estaban después (notar que el elemento apuntado por ese puntero intermedio no formará parte de
					 ninguno de los dos). Como casos especiales, si se recibe como posición intermedia a la del primer o
	del último elemento la función deberá generar y retornar un solo arreglo (el otro estaría vacío, así que
																			  mejor no generarlo en ese caso).
	b) Escriba un programa cliente para probar la función que permita al usuario ingresar un arreglo y un
	número de posición para generar el 2do puntero; y luego muestre los resultados.
		Nota: no puede usar std::vector para este ejercicio.
*/


#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

void genera(int *ini, int *inter, int *fin, int* &primero, int* &segundo){
	int cantp=inter-ini;
	int cants=fin-inter-1;
	//cout<<cantp<<"   "<<cants;
	cout<<"\ndecarta el "<<*inter<<endl;
	primero=segundo=nullptr;
	if (cantp>0){
		primero=new int[cantp];
		for(int i=0;i<cantp;i++) { 
			*(primero+i)=*(ini+i);
		}
	}
	if (cants>0){
		segundo=new int[cants];
		int a=0;
		for(int i=inter-ini+1;i<fin-ini;i++) { 
			*(segundo+a)=*(ini+i);
			a++;
		}
	}
	
}


int main(int argc, char *argv[]) {
	int cantidad=30;
	int *v=new int[cantidad];
	srand(time(0));
	for(int i=0;i<cantidad;i++) { 
		*(v+i)=rand()%100;
	}
	for(int i=0;i<cantidad;i++) { 
		cout<<*(v+i)<<"  ";
	}
	cout<<endl<<"ingrese donde divide: ";
	int p;
	cin>>p;
	int *pp, *ps;
	genera(v, v+p, v+cantidad, pp, ps);
	cout<<"\nPrimer vector: \n";
	for(int i=0;i<p;i++) { 
		cout<<*(pp+i)<<"  ";
	}	
	cout<<"\n\nSegundo vector: \n";
	for(int i=0;i<cantidad-p-1;i++) { 
		cout<<*(ps+i)<<"  ";
	}	
	delete v;
	delete pp;
	delete ps;
	
	return 0;
}

