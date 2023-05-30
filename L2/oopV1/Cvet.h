#ifndef cvet_h
#define cvet_h
#include<iostream>
#include <string>

using namespace std;

class Cvet
{
	string naziv;
	int nabavna;
	int prodajna;

public:

	Cvet(string n, int nab, int prod) :naziv(n), nabavna(nab), prodajna(prod) {};

	string getNaz() const { return naziv; }

	int getNab() const { return nabavna; }

	int getPro() const { return prodajna; }

	int getZarada() { return prodajna - nabavna; }

	friend bool operator==(const Cvet& c1, const Cvet& c2);

	friend ostream& operator<<(ostream& it, const Cvet& c);

};
#endif

