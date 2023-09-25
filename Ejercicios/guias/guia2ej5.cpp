#include <iostream>
#include <vector>
#include <ostream>
using namespace std;
 
struct Alumno {
    string nombre;
    float nota;
};

class Curso {
    private:
        Alumno *alumnos;
        int cantidad;
        string materia;
    public:
        Curso( int cantidad, string materia )
        : alumnos(nullptr), cantidad(cantidad), materia(materia) {
            alumnos = new Alumno[cantidad];
        }
        ~Curso() {
            delete [] alumnos;
        }
        void AgregarAlumno( Alumno estudiante );
        int Promedio();
        Alumno MejorCalificacion();
};

void Curso::AgregarAlumno( Alumno estudiante ) {
    Alumno *nuevosAlumnos = new Alumno[cantidad+1];
    for (int i = 0; i < cantidad; i++) 
        nuevosAlumnos[i] = alumnos[i];
    nuevosAlumnos[cantidad] = estudiante;

    delete [] alumnos;
    cantidad += 1;
    alumnos = nuevosAlumnos;
}

int Curso::Promedio() {
    float suma = 0;
    for (int i = 0; i < cantidad; i++) 
        suma += alumnos[i].nota; 
    
    return suma / cantidad; 
}

Alumno Curso::MejorCalificacion() {
    float nota = 0; int pos = 0;
    for (int i = 0; i < cantidad; i++) {
        if (alumnos[i].nota > nota) {
            pos = i;
            nota = alumnos[i].nota;
        }
    }
    return alumnos[pos];
}
 
int main() {
    
    system("cls");

    
    return 0;
}