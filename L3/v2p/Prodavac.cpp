#include "Prodavac.h"
#include "Posiljka.h"

void Prodavac::obradi(Posiljka& p) {
	int num = katalog.getNum();

	for (int i = 0; i < num; ++i) {
		Trojka t = katalog[i];
		if (t.artikal == p.getArtikal()) {
			p.detalj.dani += t.dani;
			double prodajna_cena = t.marza * t.artikal.getCena();
			p.detalj.cena += prodajna_cena;
			break;
		}
	}
}