#include <iostream>
#include <vector>
using namespace std;
class Persona{
protected:
	string apenom;
 	int dni,dn,mn,an;
	char ec;
public:
	Persona(){apenom=""; dni=dn=mn=an=0; ec=' ';}
	Persona(string aapenom,int adni, int adn, int amn, int aan, char aec){
		apenom=aapenom; dni=adni; dn=adn; mn=amn; an=aan; ec=aec;} 
	string VerApenom(){return apenom;}
	int Edad(int ada, int ama, int aaa);
	int VerDni(){return dni;}
	int verDn(){return dn;}
	int verMn(){return mn;}
	int verAn(){return an;}
	char verEc(){return ec;}
};

class Alumno: public Persona{
private:
	float prom;
	int cantma;
public:
	Alumno(){prom=cantma=0;};
	Alumno(string aapenom,int adni, int adn, int amn, int aan, char aec,float aprom, int acantma):
		Persona(aapenom,adni,adn,amn,aan,aec), prom(aprom), cantma(acantma){}
	void AsignarDatos(string aapenom,int adni, int adn, int amn, int aan, char aec,float aprom, int acantma){
		apenom=aapenom; dni=adni; dn=adn; mn=amn; an=aan; ec=aec;prom=aprom;cantma=acantma;
	} 
		float VerProm(){return prom;}
	int VerCantMA(){return cantma;}
	float MeritoAcademico(){return prom*cantma;}
};

class Docente: public Persona{
private:
	int di, mi, ai;
public:
	Docente(){di=mi=ai=0;}
	Docente(string aapenom,int adni, int adn, int amn, int aan, char aec,int adi,int ami, int aai):
		Persona(aapenom,adni,adn,amn,aan,aec), di(adi), mi(ami), ai(aai){}
	int Antiguedad(int ada, int ama, int aaa);
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

int Persona::Edad(int ada, int ama, int aaa){
	return ((aaa*10000+ama*100+ada)-(an*10000+mn*100+dn))/10000;
}

int Docente::Antiguedad(int ada, int ama, int aaa){
	return ((aaa*10000+ama*100+ada)-(ai*10000+mi*100+di))/10000;
}

Alumno Curso::MejorPromedio(){
	int mp=0, posm=0;
	for(unsigned int i=0;i<v.size();i++) 
		if(v[i].VerProm()>mp){
		    mp=v[i].VerProm();
			posm=i;
		}
	return v[posm];
}



int main(int argc, char *argv[]) {
	Docente d("Ana Lopez", 20056768,13,1,1968,'C',1,7,1995);
	Curso cur("Programación Orientada a Objetos",d);
	
	// o esta manera
	//Curso cur("Programación Orientada a Objetos",Docente("Ana Lopez", 20056768,13,1,1968,'C',1,7,1995));
	// o esta otra manera
	//Curso cur("Programación Orientada a Objetos",{"Ana Lopez", 20056768,13,1,1968,'C',1,7,1995});
	
	
	Alumno a;
	a.AsignarDatos("juan",30202020, 14,01,1987, 'S',7.65,15);
	cur.AgregarAlumno(a);
	a.AsignarDatos("ines",23323020, 27,02,1981, 'S',5.45,17);
	cur.AgregarAlumno(a);
	a.AsignarDatos("felipe",33323020, 19,04,1990, 'S',9.75,25);
	cur.AgregarAlumno(a);
	a.AsignarDatos("luis",37999999, 5,02,2000, 'S',7.25,12);
	cur.AgregarAlumno(a);
	a.AsignarDatos("andres",41289786, 3,05,1999, 'S',8.85,6);
	cur.AgregarAlumno(a);
	
	cout<<"Materia: "<<cur.VerMateria()<<"   Docente: "<<cur.VerDocente().VerApenom()<<endl;
	cout<<"listado:\n";
	for(int i=0;i<cur.CantidadAlumnos();i++) { 
		cout<<cur.VerAlumno(i).VerApenom()<<"   "<<cur.VerAlumno(i).VerDni();
		cout<<"     "<<cur.VerAlumno(i).verDn()<<"/"<<cur.VerAlumno(i).verMn()<<"/"<<cur.VerAlumno(i).verAn();
		cout<<"  Edad: "<<cur.VerAlumno(i).Edad(18,9,2020)<<"  Mat aprobadas: "<<cur.VerAlumno(i).VerCantMA();
		cout<<"  promedio: "<<cur.VerAlumno(i).VerProm()<<"    Merito: "<<cur.VerAlumno(i).MeritoAcademico()<<endl;
	}
	cout<<endl;
	
	a=cur.MejorPromedio();
	cout<<"Mejor alumno: "<< a.VerApenom()<<"    promedio: "<<a.VerProm()<<endl;
	
	return 0;
}

