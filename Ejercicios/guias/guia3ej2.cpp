#include <iostream>
#include <ostream>
#include <vector>
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
        int VerPromedio();
};
int Alumno::MeritoAcademico() {
    return promedio * materiasAprobadas; 
}
int Alumno::VerPromedio() {
    return promedio;
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

class Curso {
    private:
        string nombreCurso, profesor;
        vector<Alumno> alumnos;
    public:
        Curso(string nombreCurso, string profesor) {
            this -> nombreCurso = nombreCurso;
            this -> profesor = profesor;
        }
        void AgregarAlumno( Alumno );
        Alumno MejorPromedio();
};
void Curso::AgregarAlumno( Alumno estudiante ) {
    alumnos.push_back(estudiante);
    std::cout << "Se agrego un alumno" << endl;
}
Alumno Curso::MejorPromedio() {
    int promedio = -1, index = -1;
    for (int i = 0; i < alumnos.size(); i++) {
        if (alumnos[i].VerPromedio() > promedio) {
            index = i; 
            promedio = alumnos[i].VerPromedio();
        }
    }

    return alumnos[index];
}

int main() {
    system("cls");
    Alumno alumnoIan("Ian", "Gonzalez", "soltero", 40000000, 20030226, 8, 4);
    Alumno alumnoFran("Franco", "Venitez", "soltero", 40000000, 20030226, 7, 2);
    Docente profeVallejos("Alfredo", "Vallejos", "casado", 20000000, 19780523, 20020101);

    Curso poo("Programacion Orientada a Objetos", profeVallejos.VerNombre());
    poo.AgregarAlumno(alumnoIan);
    poo.AgregarAlumno(alumnoFran);

    std::cout << "\nMejor promedio de POO: " << poo.MejorPromedio().VerNombre() << " con " << poo.MejorPromedio().VerPromedio() << endl;
    
    return 0;
}










