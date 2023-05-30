#ifndef Greska_h
#define Greska_h
#include <iostream>
using namespace std;

class CurrError
{
public:
	friend ostream& operator<<(ostream& it, const CurrError& e)
	{
		return it << "Ne postoji tekuci element";
	}
};

class GrPoslata
{
public:
	friend ostream& operator<<(ostream& it, const GrPoslata& e)
	{
		return it << "Poruka je poslata, ne moze se izmeniti tekst";
	}
};

#endif
