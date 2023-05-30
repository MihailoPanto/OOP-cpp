#ifndef Igrac_h
#define Igrac_h

#include <ostream>
#include <string>

using namespace std;

class Igrac
{

	string ime;
	int vrednost;

public:

	Igrac(string i, int v = 1000) :ime(i), vrednost(v) {}

	Igrac(const Igrac& i) {
		this->ime = i.ime;
		this->vrednost = i.vrednost;
	}

	void povecaj(int x) {
		vrednost += vrednost * x / 100;
	}

	void smanji(int x) {
		vrednost -= vrednost * x / 100;
	}

	friend bool operator ==(const Igrac& i1, const Igrac& i2) {
		return (i1.ime == i2.ime) && (i1.vrednost == i2.vrednost);
	}

	friend ostream& operator <<(ostream& it, const Igrac& i) {
		return it << i.ime << '#' << i.vrednost;
	}

	int getVrednost() const{ return vrednost; }

};

#endif