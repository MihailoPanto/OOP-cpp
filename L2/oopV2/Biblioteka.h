#ifndef BIBLIOTEKA
#define BIBLIOTEKA

#include "Knjiga.h"


class Biblioteka
{
	Knjiga** niz;
	string naziv;
	int broj;
	int max;

	void kopiraj(const Biblioteka& b);

	void premesti(Biblioteka& b);

	void brisi();

public:

	Biblioteka(string n, int m) :naziv(n), max(m) {
		niz = new Knjiga * [max];
		broj = 0;
	}

	Biblioteka(const Biblioteka& b);

	Biblioteka(Biblioteka&& b);

	~Biblioteka();

	Biblioteka& operator=(const Biblioteka& b);

	Biblioteka& operator=(Biblioteka&& b);

	string getNaziv()const { return naziv; }

	int getBroj()const { return broj; }

	int getMax()const { return max; }

	friend Biblioteka& operator +=(Biblioteka& biblioteka, Knjiga& knjiga);

	Knjiga* getKnjiga(int i) const;

	friend ostream& operator <<(ostream& it, const Biblioteka& biblioteka);

};
#endif