#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

struct Evaluacion {
    string tipo;
    float nota;
};
 
class Asignatura {
    private:
        string materia;
        int cuatrimestre;
    public:
        Asignatura(string mat, int cuat = 1)
        : materia(mat), cuatrimestre(cuat) {}

        string VerMateria() { return materia; }
        int VerCuatrimestre() { return cuatrimestre; }
};

class FuPro: public Asignatura {
    private:
        
    public:
        FuPro()
        : Asignatura("Fundamentos de Programacion") {}
        FuPro(int cuat)
        : Asignatura("Fundamentos de Programacion", cuat) {}

        string CalcularCondicion( vector<Evaluacion> examen) {
            float suma = 0.0; bool hayMin60 = false, hayMin40 = false;
            for ( Evaluacion e: examen ) {
                if ( e.tipo != "parcial1" && e.tipo != "parcial2")
                    return "error";

                suma += e.nota;
                if (e.nota < 60) hayMin60 = true;
                if (e.nota < 40) hayMin40 = true;
            }
            
            if (suma/examen.size() >= 70 && !hayMin60)
                return "promocionado";
            return hayMin40 ? "libre" : "regular";  
        }
        
};

class CompGraf: public Asignatura {
    private:
        
    public:
        CompGraf()
        : Asignatura("Computacion Grafica") {}
        CompGraf(int cuat)
        : Asignatura("Computacion Grafica", cuat) {}

        string CalcularCondicion( vector<Evaluacion> examen) {
            bool tpsAprobados = true, parcialAprobado = true;
            for ( Evaluacion e: examen ) {
                if (e.tipo != "tp1" && e.tipo != "tp2" && e.tipo != "tpFinal" && e.tipo != "parcial")
                    return "error";

                if ((e.tipo == "tp1" || e.tipo == "tp2" || e.tipo == "tpFinal") && e.nota < 60) 
                    tpsAprobados = false;
                if (e.tipo == "parcial" && e.nota < 65)
                    parcialAprobado = false; 
            }

            if (tpsAprobados && parcialAprobado)
                return "promocionado";
            else if (!parcialAprobado && tpsAprobados)
                return "regular";
            else
                return "libre";
        }
        
};

void testCalcularCondicion( int materia ) {
    vector<Evaluacion> examenes; float nota;
    
    string instancias = (materia == 1) ? "(parcial1 / parcial2)" : "(tp1 / tp2 / tpFinal / parcial)";
    std::cout << "Ingresa los datos de cada instancia "; 
    std::cout << instancias << endl;
    std::cout << "------------------------------------" << ((materia == 1) ? "---------------------" : "-------------------------------") << endl;

    for (int i = 0; i < (materia == 1 ? 2 : 4); i++) {
        std::cout << "Instancia: ";
        string tipo; std::cin >> tipo; std::cout << "\n";

        std::cout << "Calificacion: ";
        std::cin >> nota; std::cout << "\n\n";
        std::cout << "----------------" << endl;

        Evaluacion examAlum = {tipo, nota};
        examenes.push_back(examAlum);
    }

    if (materia == 1) {
        FuPro calc;
        std::cout << "El alumno esta " << calc.CalcularCondicion(examenes) << endl;
        return;
    }

    CompGraf calc;
    std::cout << "El alumno esta " << calc.CalcularCondicion(examenes) << endl;
    return;
} 

int main() {
    
    system("cls");
    std::cout << "Materia" << endl;
    std::cout << "-------------------------------" << endl;
    std::cout << "1- Fundamentos de Programacion" << endl;
    std::cout << "2- Computacion Grafica" << endl << "\n> ";
    int materia; std::cin >> materia; std::cout << "\n";
    
    if (materia == 2 || materia == 1) 
        testCalcularCondicion(materia);

    return 0;
}