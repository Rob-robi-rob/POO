#include <iostream>
#include <vector>
#include <ostream>
using namespace std;
 
struct Examen {
    int fecha;
    string materia;
    float nota;
};
 
class Carrera {
    private:
        string nombreCarrera;
        int promedioHistorico;
        vector<string> listaMaterias;
    public:
        Carrera(): nombreCarrera(""), promedioHistorico(0) {}
        Carrera( string nombre, int promedio, vector<string> materias ) 
        : nombreCarrera(nombre), promedioHistorico(promedio), listaMaterias(materias) {}


        int PosicionCarrera(string);
        vector<string> VerListaMaterias() { return listaMaterias; }
        int VerPromedioHistorico() { return promedioHistorico; }

};

int Carrera::PosicionCarrera( string materia ) {
    for (int i = 0; i < listaMaterias.size(); i++) 
        if (listaMaterias[i] == materia) 
            return i;

    return -1;
}

class IngMecanica: public Carrera {
    private:
        
    public:
        IngMecanica()
        : Carrera("Ingenieria Mecanica", 0, {}) {}

        float PromedioAlumno( vector<Examen> );
};

float IngMecanica::PromedioAlumno( vector<Examen> exams ) {
    float suma = 0.00;
    for (int i = 0; i < exams.size(); i++) 
        if (i <= 30) 
            suma += exams[i].nota;
        else 
            suma += 2 * exams[i].nota;
    
    return suma / ((float)exams.size() + 12.00);
}

class Arquitectura: public Carrera {
    private:
        
    public:
        Arquitectura()
        : Carrera("Arquitectura", 0, {}) {}

    float PromedioAlumno( vector<Examen> );
        
        
};

float Arquitectura::PromedioAlumno( vector<Examen> exams ) {
    float suma = 0.00;
    for ( Examen e: exams ) 
        suma += e.nota;

    return suma / (float)exams.size();
}            

bool SolicitudBeca( Carrera grado, vector<Examen> exams ) {
    int cantInsuficientes = 0; float suma = 0;

    for ( Examen e: exams ) {
        if (e.nota < 60) cantInsuficientes++;
        suma += e.nota;
    } 

    return suma > grado.VerPromedioHistorico() && cantInsuficientes < 3; 
}

int main() {
    
    system("cls");
    Carrera cr;
    std::cout << "xd" << endl;
    
    return 0;
}