#include <iostream>
#include <cmath>
using namespace std;
struct Punto{
	int x,y;
};

bool esIgual(float a, float b){
	return fabs(a-b)<=0.001;
}

class Recta{
public:
	virtual string obtenerEcuacion()=0;
	virtual bool pertenece(Punto p)=0;
};
	
class RectaExplicita: public Recta{
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

class RectaGeneral: public Recta{
	float a,b,c;
public:
	RectaGeneral(Punto p, Punto q){
		a=q.y-p.y;  b=p.x-q.x;   c=-a*p.x-b*p.y;
	}
	float verA(){return a;}
	float verB(){return b;}
	float verC(){return c;}
	string obtenerEcuacion(){
		return to_string(a)+"x + "+to_string(b)+"y + "+to_string(c)+" = 0";
	}
	bool pertenece(Punto p){return esIgual(a*p.x+b*p.y+c , 0.0);}
};


int main(int argc, char *argv[]) {
	Punto P1,P2;
	P1.x=2;
	P1.y=3;
	P2.x=5;
	P2.y=9;
	int opcion;
	cin>>opcion;
	Recta *r;
	if(opcion==1){
	  r= new RectaGeneral(P1,P2);
	}else{
      r= new RectaExplicita(P1,P2);
	}	
	cout<< r->obtenerEcuacion()<<endl;
	P1.x=8;
	P1.y=8;
	if ( r->pertenece({5,6}))
		cout<<"Si pertenece"<<endl;
	else
		cout<<"NO pertenece"<<endl;
	
	return 0;
}

