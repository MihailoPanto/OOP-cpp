#ifndef MEC_H
#define MEC_H
#include "Par.h"
#include "Tim.h"
#include "Greske.h"

class Mec {
public:
	enum Ishod { POBEDA_DOMACIN, NERESENO, POBEDA_GOST };
	Par<Tim> getTimovi() {return timovi;}


	Mec() = default;
	Mec(Par<Tim> timovi) : timovi(timovi), odigran(false) {}

	void odigraj(Ishod ish);

	bool is_odigran() const { return odigran; }

	Par<int> dohvati_poene();

	friend ostream& operator <<(ostream& it, Mec& t);

private:
	bool odigran;
	Par<Tim> timovi;
	enum Ishod ishod;
	static int jedan, nula, tri;
};

#endif