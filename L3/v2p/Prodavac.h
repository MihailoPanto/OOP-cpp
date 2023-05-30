#ifndef Prodavac_h
#define Prodavac_h

#include <string>
#include <iostream>
#include "Rukovalac.h"
#include "Posiljka.h"

using namespace std;

class Prodavac : public Rukovalac {

public:

	Prodavac(string n) { this->naziv = n; }

	string getNaziv()const { return naziv; }

	void prosiri_katalog(Artikal a, double m, int d) {
		Trojka t{ a, m, d };
		katalog += t;
	}
	void obradi(Posiljka& p) override;

private:
	string naziv;

	class Trojka {
	public:
		Artikal artikal;
		double marza;
		int dani;
	};

	Lista<Trojka> katalog;
};

#endif