#include "Posiljka.h"

#include <iostream>
int Posiljka::staticId = 0;


void Posiljka::detalji() {
	int num = list.getNum();
	for (int i = 0; i < num; ++i) {
		list[i]->obradi(*this);
	}
	izracunato = true;
}
