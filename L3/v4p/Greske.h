#ifndef Greske_h
#define Greske_h

#include <iostream>
#include <string>
using namespace std;


class CenaError
{
public:
	friend ostream& operator<<(ostream& it, const CenaError& e)
	{
		return it << "Igrac je jeftin za ovaj tim";
	}
};


class IndexGreska
{
public:
	friend ostream& operator<<(ostream& it, const IndexGreska& e)
	{
		return it << "Indeks izvan granica niza";
	}
};

class GrNijeOdigran
{
public:
	friend ostream& operator<<(ostream& it, const GrNijeOdigran& e)
	{
		return it << "Mec nije odigran";
	}
};


#endif