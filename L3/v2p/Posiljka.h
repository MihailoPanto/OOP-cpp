#ifndef Posiljka_h
#define Posiljka_h

#include <iostream>
#include "Greska.h"
#include "Lista.h"
#include "Artikal.h"
#include "Rukovalac.h";

class Posiljka
{

public:

	//TODO: copy constructor
	Posiljka(Artikal& a) :art(a) {}

	friend Posiljka& operator +=(Posiljka& p, Rukovalac& r) {
		if (p.izracunato) throw IzracunatoError();
		p.list += &r;
	}

	void detalji();

	Artikal& getArtikal() {
		return art;
	}

	int getDani()const {
		if (!izracunato) throw NijeIzracunatoError();
		return detalj.dani;
	}

	double getCena()const {
		if (!izracunato) throw NijeIzracunatoError();
		return detalj.cena;
	}
	int getId()const {
		return id;
	}

	friend std::ostream& operator <<(std::ostream& it, Posiljka& p) {
		it << "Posiljka [" << p.id << ", " << (p.art).getNaziv() << "]";
	}




private:
	

		// TODO: agregirani detalji posiljke??
	class Detalj {
	public:
		int dani = 0;
		double cena = 0;
	};	
	Detalj detalj;

	//int dani = 0;
	//double cena = 0;
	
	bool izracunato = false;

	friend class Prodavac;
	Lista<Rukovalac*> list;
	static int staticId;
	int id = staticId++;
	Artikal art;
};



#endif
