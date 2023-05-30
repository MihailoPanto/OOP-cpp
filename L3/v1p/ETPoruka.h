#ifndef ETPoruka_h
#define ETPoruka_h

#include "EPoruka.h"
#include "Greska.h"

class ETPoruka :public EPoruka
{
private:
	string tekst;
public:
	ETPoruka(Korisnik* posiljalac, Korisnik* primalac, string n) : EPoruka(posiljalac, primalac, n) {}
	
	void postavi_tekst(string t) {
		if (stanje == POSLATA) throw GrPoslata();
		tekst = t;
	}

	void posalji() {
		EPoruka::stanje = POSLATA;
	}

	void pisi(ostream& it) const override {
		EPoruka::pisi(it);
		it << endl << tekst;
	}

};

#endif