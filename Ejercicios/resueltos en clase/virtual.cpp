#include <iostream>
using namespace std;

class base{
public:
	virtual void ver(){cout<<"base\n";}    //SI SACO EL VIRTUAL ME MOSTRARIA MAL LA ULTIMA LINEA DEL MAIN
};

class hija:public base{
public:
	void ver(){cout<<"hija\n";}
};


int main(int argc, char *argv[]) {
	base b;
	b.ver();
	cout<<endl;
	
	hija h;
	h.ver();
	cout<<endl;
	
	base *pb=new base;
	pb->ver();
	cout<<endl;
	
	hija *ph=new hija;
	ph->ver();
	cout<<endl;
	
	base *pp=new hija;
	pp->ver();
	
	return 0;
}

