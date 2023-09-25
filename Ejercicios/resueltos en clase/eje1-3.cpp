/*
Escriba una función que utilice punteros para buscar e informar la dirección de un
entero dentro de un arreglo. Se pasan como parámetros el arreglo, su tamaño y el
entero a buscar. Si el dato no se encuentra, devolver la dirección de memoria nula
(nullptr o NULL). ¿Desde un programa cliente, cómo se obtiene el índice del
elemento encontrado cuando la función no devuelve nullptr?
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int *buscar(int *x,int y,int vb){
	for(int i=0;i<y;i++)
		if (*(x+i)==vb){
			return x+i;
		}
	return nullptr;
}

int main() {
	int N;
	cout<<"Ingrese la cantidad de elementos: ";
	cin>>N;
	int *p=new int[N];
	srand(time(0));
	for(int i=0;i<N;i++) {
		*(p+i)=rand()%501+1000;
		cout<<i<<":  "<<(p+i)<<":  "<<*(p+i)<<endl;
	}
	cout<<"\nIngrese el valor a buscar: ";
	int valor;
	cin>>valor;
	int *pb=buscar(p,10,valor);
	if(pb!=nullptr){
		cout<<"\nEncontrado en dirección: "<<pb<<endl;
		cout<<"Indice: "<<pb-p<<endl;
	} else
		cout<<"\nValor no encontrado";
	delete[]p;
	return 0;
}
