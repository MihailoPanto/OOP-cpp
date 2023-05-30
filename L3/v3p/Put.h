#ifndef Put_h
#define Put_h

#include "Tacka.h"
#include "Lista.h"
#include "Greske.h"

class Put
{
private:

	Lista<Tacka*> list;

public:

	Put(){}

	friend Put& operator +=(Put& l, Tacka* t) {
		if (l.list.nadji(t)) throw ImaError();
		l.list += t;
	}

	double duzina() const {
		double s = 0.0;
		for (int i = 0; i < list.getNum() - 1; ++i) {
			s+=udaljenost(*list[i], *list[i + 1]);
		}
		return s;
	}

	friend ostream& operator <<(ostream& it, Put& p) {
		int i = 0;
		while (i < p.list.getNum()) {
			if (i == p.list.getNum() - 1) it << *p.list[i];
			else it << *p.list[i] << endl;
			++i;
		}
		return it;
	}

};

#endif