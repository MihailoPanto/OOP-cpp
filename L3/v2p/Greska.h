#ifndef Greska
#define Greska
#include <iostream>

class CurrError
{
public:
	friend std::ostream& operator<<(std::ostream& it, const CurrError& e)
	{
		return it << "Ne postoji tekuci element";
	}
};

class IzracunatoError
{
public:
	friend std::ostream& operator<<(std::ostream& it, const IzracunatoError& e)
	{
		return it << "Detalji posiljke su izracunati, ne moze se dodati rukovalac";
	}
};

class NijeIzracunatoError
{
public:
	friend std::ostream& operator<<(std::ostream& it, const NijeIzracunatoError& e)
	{
		return it << "Detalji posiljke nisu izracunati";
	}
};

#endif