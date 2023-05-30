#ifndef Tim_h
#define Tim_h

#include "Igrac.h"
#include "Greske.h"


class Tim
{
	Igrac** niz;
	string naziv;
	int broj;
	int max;

	void kopiraj(const Tim& b);

	void premesti(Tim& b);

	void brisi();



protected:
	
	virtual void pisi(ostream& it)const {
		it << naziv << '[';
		for (int i = 0; i < max; ++i) {
			if(niz[i] &&i<broj-1 ) it << *niz[i] << " ,";
			else if (niz[i]) it << *niz[i];
		}
		cout << "]";
	}
	
public:
	Tim() = default;
	Tim(string n, int m) :naziv(n), max(m) {
		niz = new Igrac * [max];
		broj = 0;

		for (int i = 0; i < max; ++i) {
			niz[i] = nullptr;
		}
	}

	Tim(const Tim& b);

	Tim(Tim&& b);

	~Tim();

	Tim& operator=(const Tim& b);

	Tim& operator=(Tim&& b);

	string getNaziv()const { return naziv; }

	int getBroj()const { return broj; }

	int getMax()const { return max; }

	Tim& dodajIgraca(int i, Igrac& igrac);

	Igrac* operator[](int i);

	double vrednost()const;

	bool operator ==(const Tim& t);

	friend ostream& operator <<(ostream& it, const Tim& t);

};
#endif

