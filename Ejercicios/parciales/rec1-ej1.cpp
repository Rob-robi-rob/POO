#include <iostream>
#include <vector>
#include <ostream>
using namespace std;
 
class Cancion {
    private:
        string tema, autor;
        int segundos;
    public:
        Cancion(string tema, string autor, int segundos) 
        : tema(tema), autor(autor), segundos(segundos) {}

        string VerTema() { return this -> tema; }
        string VerAutor() { return this -> autor; }
        int VerDuracion() { return this -> segundos; }
};

class PlayList {
    private:
        string nombre;
        vector<Cancion> canciones;
    public:
        PlayList(string nombre): nombre(nombre) {}
        void AgregarCancion(Cancion);
        Cancion ObtenerCancion(int);
        int CantidadCanciones();
        bool ReemplazarTema(Cancion, string);
        int TiempoTotal(string);
};

void PlayList::AgregarCancion(Cancion temon) {
    canciones.push_back(temon);
}

Cancion PlayList::ObtenerCancion(int ubicacion) {
    return canciones[ubicacion];
}

int PlayList::CantidadCanciones() {
    return canciones.size();
}

bool PlayList::ReemplazarTema(Cancion temon, string nombreTema) {
    for (int i = 0; i < canciones.size(); i++) {
        if (nombreTema == canciones[i].VerTema()) {
            canciones[i] = temon;
            return true;
        }
    }
    return false;
}

int PlayList::TiempoTotal( string nombreAutor ) {
    int contSegs = 0;
    for ( Cancion c: canciones ) 
        if (c.VerAutor() == nombreAutor)
            contSegs += c.VerDuracion();
    
    return contSegs;
}

int main() {
    
    system("cls");
    Cancion xd("chop suey", "system of a down", 226);
    
    return 0;
}