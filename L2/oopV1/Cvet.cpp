#include "Cvet.h"

bool operator==(const Cvet& c1, const Cvet& c2) {
	return c1.naziv == c2.naziv;
}

ostream& operator<<(ostream& it, const Cvet& c) {
	return it << c.naziv;
}