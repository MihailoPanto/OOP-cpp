#ifndef Artikal_h
#define Artikal_h

#include <string>
using namespace std;

class Artikal
{

private:
	string naziv;
	int barkod;
	double cena;

public:

	Artikal(string n, int b, double c) :naziv(n), barkod(b), cena(c) {}

	string getNaziv()const { return naziv; }
	int getBarkod() const{ return barkod; }
	double getCena()const { return cena; }

	friend bool operator ==(const Artikal& a1, const Artikal& a2) {
		return a1.barkod == a2.barkod;
	}
};

#endif