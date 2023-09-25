#include <iostream>
#include <cmath>
using namespace std;
struct Punto{
	int x,y;
};

bool esIgual(float a, float b){
	return fabs(a-b)<=0.001;
}

class RectaExplicita{
	float m,b;
public:
	RectaExplicita(Punto p, Punto q){
		m=((q.y-p.y)*1.0) / (q.x-p.x);
		b=p.y-m*p.x;
	}
	float verM(){return m;}
	float verB(){return b;}
	string obtenerEcuacion(){
		return "y= "+to_string(m)+"x + "+to_string(b);
	}
	bool pertenece(Punto p){return esIgual(p.y, m*p.x+b);}
};

int main(int argc, char *argv[]) {
	Punto P1,P2;
	P1.x=2;
	P1.y=2;
	P2.x=5;
	P2.y=5;
	RectaExplicita  r(P1,P2);
	cout<< r.obtenerEcuacion()<<endl;
	P1.x=8;
	P1.y=8;
	if (r.pertenece({5,6}))
		cout<<"Si pertenece"<<endl;
	else
		cout<<"NO pertenece"<<endl;
	
	return 0;
}

