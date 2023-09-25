#include <iostream>
#include <ostream>
using namespace std;
 
#define HOY 20230902

class Persona {
    private:
        string nombre, apellido, estadoCivil;
        int dni, nacimiento;
    public:
        Persona(string nombre,string apellido,string estadoCivil,int dni,int nacimiento) {
            this -> nombre = nombre;
            this -> apellido = apellido;
            this -> estadoCivil = estadoCivil;
            this -> dni = dni;
            this -> nacimiento = nacimiento;
        }

        int Edad(int hoy);
        string VerNombre();
};
int Persona::Edad(int hoy = int(HOY)) {
    return (hoy - nacimiento) / 10000;
}
string Persona::VerNombre() {
    return nombre + " " + apellido;
}

class Alumno: public Persona {
    private:
        int promedio, materiasAprobadas;
    public:
        Alumno(string nombre, string apellido, string estadoCivil, int dni, int nacimiento, int promedio, int materiasAprobadas) 
        : Persona(nombre, apellido, estadoCivil, dni, nacimiento) {
            this -> promedio = promedio;
            this -> materiasAprobadas = materiasAprobadas;
        }
        
        int MeritoAcademico();
};
int  Alumno::MeritoAcademico() {
    return promedio * materiasAprobadas; 
}

class Docente: public Persona {
    private:
        int fechaIngreso;
    public:
        Docente(string nombre, string apellido, string estadoCivil, int dni, int nacimiento, int fechaIngreso)
        : Persona(nombre, apellido, estadoCivil, dni, nacimiento) {
            this -> fechaIngreso = fechaIngreso;
        }
        
        int Antiguedad( int hoy );
};
int Docente::Antiguedad( int hoy = int(HOY) ) {
    return (hoy - fechaIngreso) / 10000;
}


int main() {
    
    system("cls");
    Persona ian("Ian", "Gonzalez", "soltero", 40000000, 20030226);
    std::cout << ian.VerNombre() << " tiene " << ian.Edad() << " anios" << endl;

    Alumno alumnoIan("Ian", "Gonzalez", "soltero", 40000000, 20030226, 8, 4);
    std::cout << alumnoIan.VerNombre() << " tiene un promedio de: " << alumnoIan.MeritoAcademico() << " puntos" << endl;
    
    Docente profeVallejos("Alfredo", "Vallejos", "casado", 20000000, 19780523, 20020101);
    std::cout << profeVallejos.VerNombre() << " tiene " << profeVallejos.Antiguedad() <<" anios de antiguedad" << endl << endl;

    return 0;
}