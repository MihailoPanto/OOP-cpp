#include "Tim.h"

void Tim::kopiraj(const Tim& t) {
	max = t.max;
	niz = new Igrac * [max];
	broj = t.broj;

	for (int i = 0; i < max; i++) {
		if (t.niz[i] == nullptr)  niz[i] = nullptr;
		else niz[i] = new Igrac(*t.niz[i]);
	}
}

void Tim::premesti(Tim& t) {
	niz = t.niz;
	t.niz = nullptr;
	naziv = t.naziv;
	broj = t.broj;
	max = t.max;
}

void Tim::brisi() {
	delete[] niz;
}

Tim::Tim(const Tim& t) { kopiraj(t); }

Tim::Tim(Tim&& t) { premesti(t); }

Tim::~Tim() { brisi(); }

Tim& Tim::operator=(const Tim& t) {
	if (this != &t) {
		brisi();
		kopiraj(t);
	}
	return *this;
}

Tim& Tim::operator=(Tim&& t) {
	if (this != &t) {
		brisi();
		premesti(t);
	}
	return *this;
}

Tim& Tim::dodajIgraca(int i, Igrac& igrac) {
	if (niz[i] == nullptr) broj++;
	niz[i] = &igrac;
	return *this;
}

ostream& operator <<(ostream& it, const Tim& t) {
	t.pisi(it);
	return it;
}

bool Tim::operator ==(const Tim& t) {

	if (naziv != t.naziv) return false;
	if (max != t.max) return false;
	for (int i = 0; i < max; ++i) {
		if (niz[i] != t.niz[i]) return false;
	}

	return true;
}

Igrac* Tim::operator[](int i) {
	if (i > max) throw IndexGreska();
	return niz[i];
}

double Tim::vrednost() const{
	int sum = 0;
	for (int i = 0; i < max; ++i) {
		if (niz[i] == nullptr) continue;
		sum += niz[i]->getVrednost();
	}
	return (double)sum / broj;
}