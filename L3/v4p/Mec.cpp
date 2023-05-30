#include "Mec.h"

int Mec::jedan = 1;
int Mec::nula = 0;
int Mec::tri = 3;

void Mec::odigraj(Ishod ish) {
	ishod = ish;

	if (ishod != NERESENO) {
		Tim* pobednik, * gubitnik;
		if (ishod == POBEDA_DOMACIN) {
			pobednik = timovi.dohvati_prvi();
			gubitnik = timovi.dohvati_drugi();
		}
		else {
			pobednik = timovi.dohvati_drugi();
			gubitnik = timovi.dohvati_prvi();
		}

		for (int i = 0; i < pobednik->getMax(); ++i) {
			if ((*pobednik)[i] == nullptr) continue;
			(*pobednik)[i]->povecaj(10);
		}
		for (int i = 0; i < gubitnik->getMax(); ++i) {
			if ((*gubitnik)[i] == nullptr) continue;
			(*gubitnik)[i]->smanji(10);
		}
	}
	odigran = true;
}


Par<int> Mec::dohvati_poene() {
	if (odigran == false) throw GrNijeOdigran();

    int* prvi = nullptr, * drugi = nullptr;

	if (ishod == NERESENO) {
		prvi = &jedan;
		drugi = &jedan;
	}
	if (ishod == POBEDA_DOMACIN) {
		prvi = &tri;
		drugi = &nula;
	}
	if (ishod == POBEDA_GOST) {
		prvi = &nula;
		drugi = &tri;
	}
	Par<int> p(prvi, drugi);
	return p;
}

ostream& operator <<(ostream& it, Mec& t) {

	it << t.timovi;
	if (t.odigran) {
		if (t.ishod == Mec::NERESENO) it << "NERESENO";
		if (t.ishod == Mec::POBEDA_DOMACIN) it << "POBEDA_DOMACIN";
		if (t.ishod == Mec::POBEDA_GOST) it << "POBEDA_GOST";
	}
	return it;
}