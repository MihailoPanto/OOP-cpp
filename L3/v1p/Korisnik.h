#ifndef Korisnik_h
#define Korisnik_h
#include<ostream>
#include <string>

using namespace std;

class Korisnik
{

	string ime;
	string eposta;

public:

	Korisnik(string i, string e) :ime(i), eposta(e) {}
	Korisnik(const Korisnik&) = delete;
	Korisnik(Korisnik&&) = delete;
	Korisnik& operator=(const Korisnik&) = delete;
	Korisnik& operator=(Korisnik&&) = delete;

	string getIme() const{ return ime; }
	string getEposta() const{ return eposta; }
	friend ostream& operator <<(ostream& it, const Korisnik& k) {
		return it << '(' << k.ime << ')' << k.eposta;
	}
};

#endif