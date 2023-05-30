#ifndef Vozilo_h
#define Vozilo_h
#include <iostream>
#include "Put.h"


class Vozilo
{
private:
	string model;

protected:
	virtual double startna_cena() const { return 0.0; };

public:
	Vozilo(string model) : model(model){}

	double cena_prevoza(Put& p) const{
		return startna_cena() + 0.1 * p.duzina();
	}

	friend std::ostream& operator <<(std::ostream& it, Vozilo& v) {
		it << v.model;
		return it;
	}
	 
};

#endif