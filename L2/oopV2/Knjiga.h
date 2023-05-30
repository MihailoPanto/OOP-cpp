#ifndef KNJIGA
#define KNJIGA
#include <string>
#include <iostream>

using namespace std;

class Knjiga
{
	static int staticid;
	int id = staticid++;

	string naslov;
	string autor;

public:

	Knjiga(string nas, string a) :naslov(nas), autor(a) {}

	Knjiga(const Knjiga&) = delete;

	Knjiga(Knjiga&&) = delete;

	Knjiga& operator=(const Knjiga&) = delete;

	Knjiga& operator=(Knjiga&&) = delete;

	string getNaslov() const;

	string getAutor()const;

	int getId()const;

	friend ostream& operator <<(ostream& it, const Knjiga& knjiga);
	
	friend Knjiga* operator!(Knjiga& k);

};

#endif
