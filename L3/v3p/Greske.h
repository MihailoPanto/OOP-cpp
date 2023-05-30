#ifndef Greske_h
#define Greske_h

#include <iostream>
using namespace std;

class ImaError
{
public:
	friend ostream& operator<<(ostream& it, const ImaError& e)
	{
		return it << "Tacka vec postoji na putu";
	}
};


class CurrError
{
public:
	friend ostream& operator<<(ostream& it, const CurrError& e)
	{
		return it << "Tacka vec postoji na putu";
	}
};

#endif