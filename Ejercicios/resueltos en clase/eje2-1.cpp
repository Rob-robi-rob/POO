#include <iostream>
using namespace std;

class Cilindro{
private:
	float alt,rad;
public:
	Cilindro(float _a, float _r):alt(_a),rad(_r){}   
	Cilindro(){}									    //solucion 1 : sobrecarga de constructor sin parametros (junto con lo de arriba)
	//Cilindro(float _a=0, float _r=0):alt(_a),rad(_r){}  //solucion 2 : pasaje de parametros por defecto (sustituye las 2 lineas anteriores)    //problema si hay 1 parametro
		
	void AsignarDatos(float _a, float _r){
		alt=_a;
		rad=_r;
	}
	float ObtenerVolumen();
};

float Cilindro::ObtenerVolumen(){
	return 3.1415*rad*rad*alt;
}

int main(int argc, char *argv[]) {
	//Cilindro c1,c2;
	Cilindro c1,c2(5.3,10.2);
	2
		2
		float r,h;
	cout<<"Ingrese al radio y la altura del cilindro c1: ";
	cin>>r>>h;
	c1.AsignarDatos(r,h);
	//.AsignarDatos(5.3,10.2);
	cout<<"\nVolumen del cilindro c1: "<<c1.ObtenerVolumen();
	cout<<"\nVolumen del cilindro c2: "<<c2.ObtenerVolumen();
	return 0;
}

