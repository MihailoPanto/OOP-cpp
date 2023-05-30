#include "Cvet.h"
#include "Buket.h"
#include "Cvecara.h"

int main() {

	//dodavanje cvetova

	Cvet c1("karanfil", 50, 100);
	Cvet c2("karanfil", 30, 60);
	Cvet c3("ruza", 10, 90);
	Cvet c4("beli", 15, 40);
	Cvet c5("crni", 50, 70);
	Cvet c6("roze", 10, 80);


	//primet ispisa cveta
	cout << "ispis zarade cveta c1: " << endl;
	cout << c1.getZarada() << endl;
	cout << "ispis c1: " << endl;
	cout << c1<<endl;
	cout << "_________________" << endl;

	//provera cvetova na jednakost

	cout << "c1 i c2 su " << (c1 == c2 ? "isti" : "razliciti") << endl;
	cout << "c1 i c3 su " << (c1 == c3 ? "isti" : "razliciti") << endl;
	cout<<"_________________" << endl;

	Buket b1;

	b1.dodajCvet(&c1);
	b1.dodajCvet(&c2);
	b1.dodajCvet(&c3);

	Buket b2(b1);

	b2.dodajCvet(&c4);
	b2.dodajCvet(&c5);
	b1.dodajCvet(&c6);

	Cvet c7("mmm", 83, 100);

	

	cout << "b2: "<<endl;
	cout << b2 << endl;
	cout << "b1: " <<endl;
	cout << b1 << endl;

	cout << "_________________" << endl;

	Cvecara cv;

	//dodavanje u cvecaru
	cv.addBuket(&b1);
	cv.addBuket(&b2);

	Buket b3;
	b3.dodajCvet(&c7);

	cv.addBuket(&b3);
	cout << "pre brisanja buketa 1: " << endl;
	cout << cv;

	cv.delBuket(1);
	cout << "posle brisanja buketa 1" << endl;
	cout << cv;

	return 0;
}
