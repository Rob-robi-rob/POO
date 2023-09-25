#include <iostream>
#include <vector>
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

class Curso{
private:
	string materia;
	Docente doc;
	vector<Alumno> v;
public:
	Curso(string amat, const Docente &adoc): materia(amat),doc(adoc) {}
	void AgregarAlumno(const Alumno &aalu){v.push_back(aalu);}
	Alumno MejorPromedio();
	Alumno VerAlumno(int x){return v[x];}
	Docente VerDocente(){return doc;}
	string VerMateria(){return materia;}
	int CantidadAlumnos(){return v.size();}
};

Alumno Curso::MejorPromedio(){
	int mp=0, posm=0;
	for(unsigned int i=0;i<v.size();i++) 
		if(v[i].verProm()>mp){
		mp=v[i].verProm();
		posm=i;
	}
		return v[posm];
}


int main(int argc, char *argv[]) {
	
	//para inicializar el curso puede ser.... 
	
	Docente doc("Ana Lopez", 20056768,19681209,'C',19950301);
	Curso cur("Programación Orientada a Objetos",doc);
	
	// o esta manera
	//Curso cur("Programación Orientada a Objetos",Docente("Ana Lopez", 20056768,19681209,'C',19950301));
	
	// o esta otra manera
	//Curso cur("Programación Orientada a Objetos",{"Ana Lopez", 20056768,19681209,'C',19950301});
	
	
	Alumno a("juan",30202020, 19871214, 'S',7.65,15);
	cur.AgregarAlumno(a);
	Alumno b("ines",23323020, 19810217, 'S',5.45,17);
	cur.AgregarAlumno(b);
	Alumno c("felipe",33323020, 19901108, 'S',9.75,25);
	cur.AgregarAlumno(c);
	Alumno d("luis",37999999, 20000507, 'S',7.25,12);
	cur.AgregarAlumno(d);
	Alumno e("andres",41289786, 19990614, 'S',8.85,6);
	cur.AgregarAlumno(e);
	
	cout<<"Materia: "<<cur.VerMateria()<<"   Docente: "<<cur.VerDocente().verApenom()<<endl;
	cout<<"listado:\n";
	for(int i=0;i<cur.CantidadAlumnos();i++) { 
		cout<<cur.VerAlumno(i).verApenom()<<"   "<<cur.VerAlumno(i).verDni()<<"     "<<cur.VerAlumno(i).verFechaNacimiento();
		cout<<"  Edad: "<<cur.VerAlumno(i).Edad(20230901)<<"  Mat aprobadas: "<<cur.VerAlumno(i).verCantMa();
		cout<<"  promedio: "<<cur.VerAlumno(i).verProm()<<"    Merito: "<<cur.VerAlumno(i).MeritoAcademico()<<endl;
	}
	cout<<endl;
	
	a=cur.MejorPromedio();
	cout<<"Mejor alumno: "<< a.verApenom()<<"    promedio: "<<a.verProm()<<endl;
	
	return 0;
}

