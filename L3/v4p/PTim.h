#ifndef PTim_h
#define PTim_h
#include "Tim.h"
#include "Greske.h"

class PTim :
	public Tim
{

	int min;

public:

	PTim(string n, int mi, int v) :Tim(n, v), min(mi) {}

	void dodajIgraca(int i, Igrac& igrac) {
		if (igrac.getVrednost() < min) throw CenaError();
		Tim::dodajIgraca(i, igrac);
	}

	void pisi(ostream& it) const override {
		Tim::pisi(it);
		it << '(' << min << ')';
	}

};

#endif