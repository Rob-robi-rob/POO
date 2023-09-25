#include <iostream>
using namespace std;
class Persona{
private:
	string apenom;
 	int dni,fechaNac;
	char ec;
public:
	Persona(string aapenom,int adni, int afn, char aec){
		apenom=aapenom; dni=adni; fechaNac=afn;  ec=aec;
	} 
	string verApenom(){return apenom;}
	int verDni(){return dni;}
	int verFechaNacimiento(){return fechaNac;}
	char verEstCivil(){return ec;}
	int Edad(int fa) {return (fa-fechaNac)/10000;}
};

class Alumno: public Persona{
private:
	float prom;
	int cantMa;
public:
	Alumno(string aapenom,int adni, int afn, char aec, float aprom, int acantma):
	    Persona(aapenom,adni,afn,aec), prom(aprom), cantMa(acantma){}   
	float verProm(){return prom;}
	int verCantMa(){return cantMa;}
	float MeritoAcademico(){return prom*cantMa;}
};

class Docente: public Persona{
private:
	int fechaIng;
public:
	Docente(string aapenom,int adni, int afn, char aec, int afi):
		Persona(aapenom,adni,afn,aec) {fechaIng=afi;}
	int Antiguedad(int fa){	return (fa-fechaIng)/10000;}
};


int main(int argc, char *argv[]) {
	Alumno a1("Juan Perez",30202020, 19870125, 'S',7.65,15);
	Alumno a2("Julio Taborda",40123456, 19990402, 'C',8.6,5);
	Docente d("Ana Lopez", 20056768,19681209,'C',19950301);
	
	cout<<a1.verApenom()<<"   "<<a1.verDni()<<"     "<<a1.verFechaNacimiento()<<endl;
	cout<<"Edad:  "<<a1.Edad(20230901)<<endl;
	cout<<"Mat aprobadas: "<<a1.verCantMa()<<"    promedio: "<<a1.verProm()<<"    Merito: "<<a1.MeritoAcademico()<<endl;
	cout<<endl;
	cout<<a2.verApenom()<<"   "<<a2.verDni()<<"     "<<a2.verFechaNacimiento()<<endl;
	cout<<"Edad:  "<<a2.Edad(20230901)<<endl;
	cout<<"Mat aprobadas: "<<a2.verCantMa()<<"    promedio: "<<a2.verProm()<<"    Merito: "<<a2.MeritoAcademico()<<endl;
	cout<<endl;
	cout<<d.verApenom()<<"   "<<d.verDni()<<"     "<<d.verFechaNacimiento()<<endl;
	cout<<"Antigüedad:  "<<d.Antiguedad(20230901)<<endl;
	
	
	return 0;
}

