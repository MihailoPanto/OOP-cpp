#include "Knjiga.h"

int Knjiga::staticid = 0;

string Knjiga::getNaslov() const { return naslov; }

string Knjiga::getAutor()const { return autor; }

int Knjiga::getId()const { return id; }

ostream& operator <<(ostream& it, const Knjiga& knjiga) {
	it << "KNJIGA " << knjiga.getId() << " : " << knjiga.getNaslov() << '-' << knjiga.getAutor();
	return it;
}

Knjiga* operator!(Knjiga& k) {
	Knjiga* k1 = new Knjiga(k.naslov, k.autor);
	return k1;
}