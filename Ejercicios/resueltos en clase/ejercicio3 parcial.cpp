/*Ejercicio 3 (35 pts)
	Se desea gestionar la venta de entradas de un teatro. Una sala de teatro está compuesta por butacas
	y cada sala puede tener diferente número de butacas.
	a) Cada butaca tiene un número, un precio y un estado (si está libre u ocupada). Codifique una clase
	Butaca que tenga un constructor para cargarle el precio, y métodos para modificar o consultar su
	estado, entre otras funcionalidades que considere necesarias.
	b) Defina una clase Sala que guarde el nombre de la sala y las lista de butacas. La misma deberá
	tener:
	- Un constructor que reciba el nombre de la sala
	- Un método que permita inicializar la lista de butacas
	- Un método para registrar la compra de una entrada recibiendo el número de butaca. Si esa butaca
	está ocupada, a partir de la misma se buscará la siguiente libre del mismo precio. El método debe
	retornar el número de butaca asignado, o -1 si no encuentra ninguna libre.
	- Un método para obtener la recaudación total de una función
	- Un método para obtener el porcentaje de ocupación de la sala
	c) Escriba un programa cliente para crear una sala y utilizar sus funcionalidades. La sala del ejemplo
	debe tener 100 plateas centrales (butacas nros 1 a 100, con un costo de $600), 200 laterales (nros
																								  101 a 300, con un costo de $450), y 200 más en un 1er piso (nros 301 a 501, con un costo de $300).
	El programa debe permitir al usuario registrar N ventas, y luego mostrar la recaudación y el
	porcentaje de ocupación.
*/	
#include <iostream>
#include <vector>
using namespace std;

class Butaca{
	int numero, precio;
	bool ocupada;
public:
	Butaca(int nu,int pr):numero(nu),precio(pr), ocupada(false){} 
	void Ocupar(){ocupada=true;}
	bool EstaOcupada(){return ocupada;}
	int ObtenerPrecio(){return precio;}
	int ObtenerNumero(){return numero;}
};
class Sala{
	string nombre;
	vector<Butaca> but;
public:
	Sala(string n):nombre(n){}
	void IniciarButacas(int cant, int precio){
		int a=but.size()+1;
		for(int i=0;i<cant;i++) { 
			but.push_back(Butaca(a,precio));
			a++;
		}
	}
	int RegistrarEntrada(int numeroButaca) {
		for (int i=0; i<but.size();i++) {
			if (but[i].ObtenerNumero() == numeroButaca && !but[i].EstaOcupada()) {
					but[i].Ocupar();
					return numeroButaca;
			}
		}
		// Si no se encontró una butaca libre del mismo precio, buscar cualquier butaca libre
		for (int i=0; i<but.size();i++) {
			if (!but[i].EstaOcupada() && but[i].ObtenerPrecio()==but[numeroButaca].ObtenerPrecio()) {
				but[i].Ocupar();
				return but[i].ObtenerNumero();
			}
		}
		return -1; // No se encontró ninguna butaca libre
	}
	Butaca ObtenerButaca(int i){return but[i];}
	int CantidadButacas(){return but.size();}
	
	int Recaudacion(){
		int s=0;
		for(Butaca b: but){
			if(!b.EstaOcupada())
			    s+=b.ObtenerPrecio();
		}
		return s;
	}
	
	float PorcentajeOcupacion(){
		int t=0;
		for(int i=0;i<but.size();i++) { 
			if(!but[i].EstaOcupada())
				t++;
		}
		return t*100.0/but.size();
	}
};


int main(int argc, char *argv[]) {
	Sala S("Teatro FICH");
	S.IniciarButacas(10, 600);
	S.IniciarButacas(20, 450);
	S.IniciarButacas(20, 300);
	for(int i=0;i<S.CantidadButacas();i++) { 
		Butaca b=S.ObtenerButaca(i);
		cout<<"numero: "<<b.ObtenerNumero()<<"   estado: "<<b.EstaOcupada()<<"   precio: "<<b.ObtenerPrecio()<<endl;
	}
	
	cout<< S.RegistrarEntrada(20)<<endl;
	cout<< S.RegistrarEntrada(10)<<endl;
	cout<< S.RegistrarEntrada(20)<<endl;
	cout<< S.RegistrarEntrada(30)<<endl;
	cout<< S.RegistrarEntrada(40)<<endl;
	cout<< S.RegistrarEntrada(30)<<endl;
	cout<< S.RegistrarEntrada(40)<<endl;
	cout<< S.RegistrarEntrada(20)<<endl;
	
	cout<<endl<<endl;
	for(int i=0;i<S.CantidadButacas();i++) { 
		Butaca b=S.ObtenerButaca(i);
		cout<<"numero: "<<b.ObtenerNumero()<<"   estado: "<<b.EstaOcupada()<<"   precio: "<<b.ObtenerPrecio()<<endl;
	}
	
	cout<<"Recaudacion: "<<S.Recaudacion()<<endl;
	cout<<"Porcentaje de ocupacion: "<<S.PorcentajeOcupacion()<<endl;
		
	return 0;
}

