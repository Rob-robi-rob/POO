#include <iostream>
using namespace std;

class base{
	int valor;
public:
	base(int x):valor(x){}
	virtual void mensaje()=0;
	int verValor(){return valor;}
	virtual ~base(){}
};

class hija1: public base{
public:
	hija1(int w):base(w){}
	void mensaje(){cout<<"hija1\n";}
	~hija1(){}
};

class hija2: public base{
public:
	hija2(int w):base(w){}
	void mensaje(){cout<<"hija2\n";};
	~hija2(){}
};


void funcion(base &b){
	b.mensaje();
	cout<<b.verValor()<<endl;
}

void funcion2(base *b){
	b->mensaje();
	cout<<b->verValor()<<endl;
}
		


int main(int argc, char *argv[]) {
    int op;
	cout<<"Ingrese 1 o 2: ";
	cin>>op;
	if (op==1){
		hija1 h1(10);
		funcion(h1);
	}else {
		hija2 h2(20);
		funcion(h2);
	}

	base *b;
	if (op==1){
	    b=new hija1(10);
	}else {
		b=new hija2(20);
	}
	funcion(*b);
	funcion2(b);
	
	delete b;
	
	
	
	
	
	return 0;
}

