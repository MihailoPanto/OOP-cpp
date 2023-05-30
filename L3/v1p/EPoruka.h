#ifndef EPoruka_h
#define EPoruka_h

#include <iostream>
#include "Korisnik.h"

using namespace std;

class EPoruka
{

public:

	EPoruka(Korisnik* po, Korisnik* pr, string n) :posiljalac(po), primalac(pr), naslov(n) { stanje = U_PRIPREMI; }

	enum Stanje { U_PRIPREMI, POSLATA, PRIMLJENA };

	virtual void posalji() = 0;

	friend ostream& operator <<(ostream& it, const EPoruka& ep) {
		ep.pisi(it);
		return it;
	}

	Korisnik& getPos() const{ return *posiljalac; }
	Korisnik& getPrim()const { return *primalac; }
	string getNaslov() const{ return naslov; }
	Stanje getStanje()const { return stanje; }

	EPoruka(const EPoruka& s) {
		kopiraj(s);
	}
	EPoruka(EPoruka&& s) { premesti(s); }
	EPoruka& operator=(const EPoruka& s) {
		if (this != &s) { brisi(); kopiraj(s); }
		return *this;
	}
	EPoruka& operator=(EPoruka&& s) {
		if (this != &s) { brisi(); premesti(s); }
		return *this;
	}
	void brisi(){}

protected:
	Stanje stanje;
	virtual void pisi(ostream& it) const {
		it << naslov << endl;
		it << *posiljalac << endl;
		it << *primalac;
	}

private:

	Korisnik* posiljalac, * primalac;
	string naslov;



	void kopiraj(const EPoruka& e) {
		this->naslov = e.naslov;
		this->posiljalac = e.posiljalac;
		this->primalac = e.primalac;
		this->stanje = e.stanje;
	}

	void premesti(EPoruka& e) {
		this->naslov = e.naslov;
		this->posiljalac = e.posiljalac;
		e.posiljalac = nullptr;
		this->primalac = e.primalac;
		e.primalac = nullptr;
		this->stanje = e.stanje;
	}

};
#endif