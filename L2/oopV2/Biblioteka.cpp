#include "Biblioteka.h"

void Biblioteka::kopiraj(const Biblioteka& b) {
	max = b.max;
	niz = new Knjiga * [max];
	broj = b.broj;

	for (int i = 0; i < broj; i++) {
		niz[i] = !(*b.niz[i]);
	}
}

void Biblioteka::premesti(Biblioteka& b) {
	niz = b.niz;
	b.niz = nullptr;
	naziv = b.naziv;
	broj = b.broj;
	max = b.max;
}

void Biblioteka::brisi() {

	for (int i = 0; i < broj; ++i) {
		delete(niz[i]);
	}
}

Biblioteka::Biblioteka(const Biblioteka& b) { kopiraj(b); }

Biblioteka::Biblioteka(Biblioteka&& b) { premesti(b); }

Biblioteka::~Biblioteka() { brisi(); }

Biblioteka& Biblioteka::operator=(const Biblioteka& b) {
	if (this != &b) {
		brisi();
		kopiraj(b);
	}
	return *this;
}

Biblioteka& Biblioteka::operator=(Biblioteka&& b) {
	if (this != &b) {
		brisi();
		premesti(b);
	}
	return *this;
}

Biblioteka& operator +=(Biblioteka& biblioteka, Knjiga& knjiga) {
	if (biblioteka.broj == biblioteka.max) {
		cout << "Biblioteka je popunjena" << endl;
		return biblioteka;
	}
	biblioteka.niz[biblioteka.broj++] = !knjiga;
	return biblioteka;
}

Knjiga* Biblioteka::getKnjiga(int i) const {

	for (int j = 0; j < broj; ++j) {
		if (niz[j]->getId() == i) return niz[j];
	}
	return nullptr;
}

ostream& operator <<(ostream& it, const Biblioteka& biblioteka) {
	it << "BIBLIOTEKA " << biblioteka.getNaziv() << ' ' << biblioteka.getBroj() << '/' << biblioteka.getMax() << endl;
	for (int i = 0; i < biblioteka.getBroj(); ++i) {
		it << *biblioteka.niz[i] << endl;
	}
	return it;
}