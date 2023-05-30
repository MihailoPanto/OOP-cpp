#include <iostream>
#include "Put.h"
#include "Tacka.h"
#include "Obicno_vozilo.h"

using namespace std;

int main() {
	Put p;
	Put p1;
	Tacka t1(0, 0), t2(0, 1), t3(2, 5);
	try{
		p += &t1;
		p += &t2;
		p += &t3;

		cout << p.duzina() << endl;
		cout << p << endl;
		
	}
	catch (ImaError e1) {
		cout << e1;
	}
	catch (CurrError e2) {
		cout << e2;
	}

	
	//Vozilo *v = new ObicnoVozilo("Reno");
	//cout << v->cena_prevoza(p);
	//Vozilo v1 = *v;
	//cout << v1;
}