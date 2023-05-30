#ifndef OBICNO_VOZILO_H
#define OBICNO_VOZILO_H

#include "Vozilo.h"

class ObicnoVozilo : public Vozilo {

protected:
	double startna_cena()const override { return 120.; }
public:
	ObicnoVozilo(string model) : Vozilo(model) {}
};
#endif