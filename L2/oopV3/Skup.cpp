#include "Skup.h"

bool Skup::operator()(char c) {
	return niz[c];
}

void operator +=(Skup& s, char c) {
	s.niz[c] = true;
}

