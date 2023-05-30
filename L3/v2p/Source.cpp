#include <iostream>
#include <string>
#include "Lista.h"
#include "Artikal.h"
#include "Posiljka.h"
#include "Prodavac.h"

using namespace std;

int main() {
	Artikal a("Cokolada", 1234, 98.12);
	Prodavac p("Pera");
	try {
		p.prosiri_katalog(a, 2, 5);

		Posiljka posiljka(a);
		posiljka += p;
		posiljka.detalji();
		cout <<"Broj dana cekanja: " << posiljka.getDani() << "  Cena: " << posiljka.getCena() << endl;
	}

	catch (NijeIzracunatoError e1) {
		cout << e1;
	}
	catch (IzracunatoError e2) {
		cout << e2;
	}
	catch (CurrError e3) {
		cout << e3;
	}
	return 0;

}