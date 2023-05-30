#include "Korisnik.h"
#include "ETPoruka.h"
#include "VOznaka.h"
#include "Lista.h"
#include "Greska.h"

#include <iostream>
#include <string>
using namespace std;

int main() {

	Korisnik k1("Mihailo Pantovic", "mihailopantovic@gmail.com");
	Korisnik k2("Miki Mecava", "mikimecava@gmail.com");
	
	try {
		ETPoruka por(&k1, &k2, "Obavestenje");
		por.postavi_tekst("MUJ IMPORTANTE");

		por.posalji();
		cout << por << endl;
		por.postavi_tekst("Nono");
	}
	catch (GrPoslata e1) {
		cout << e1;
	}

	return 0;
}