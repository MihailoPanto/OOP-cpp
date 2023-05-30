#include "Tim.h"
#include "Mec.h"
#include "PTim.h"
#include <iostream>
using namespace std;


int main() {

	Igrac* i1 = new Igrac("mihailo", 20000);
	Igrac* i2 = new Igrac("aleksa", 44444);
	Igrac* i3 = new Igrac("bobi", 2000);

	Igrac* j1 = new Igrac("x", 20000);
	Igrac* j2 = new Igrac("y", 44444);

	try {
		Tim t1("tim1", 4), t2("tim2", 4), t3("tim3", 4);
		PTim pt1("mali slon", 200, 5), pt2("vuk", 100, 5);

		t1.dodajIgraca(0, *i1);
		t1.dodajIgraca(2, *i2);

		t2.dodajIgraca(1, *i3);
		t2.dodajIgraca(0, *j1);

		t3.dodajIgraca(1, *j2);

		cout << t1 << endl;
		Par<Tim> p1(&t1, &t2), p2(&t1, &t3), p3(&t2, &t1), p4(&t3, &t2), p5(&t3,&t2);

		Mec m1(p1), m2(p2), m3(p3), m4(p4), m5(p5);

		m1.odigraj(Mec::NERESENO);
		m2.odigraj(Mec::POBEDA_DOMACIN);
		m3.odigraj(Mec::POBEDA_DOMACIN);
		m4.odigraj(Mec::POBEDA_GOST);
		cout << m1 << endl;
		cout << m2 << endl;
		cout << m3 << endl;
		cout << m4 << endl;
	}
	catch (CenaError c) {
		cout << c;
	}
	catch (GrNijeOdigran g) {
		cout << g;
	}
	//Mec m();
	return 0;
}