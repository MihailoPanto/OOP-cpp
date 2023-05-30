#include "Biblioteka.h"
#include "Knjiga.h"
#include <iostream>
#include <string>

using namespace std;


int main() {

	Knjiga k1("AA", "Mihailo Pantovic");
	Knjiga k2("BB", "Mihailo222");
	Knjiga k3("cc", "Mihailo333");
	Knjiga k4("WWW", "Mihailo444");

	cout << "ispis knjiga" << endl;

	cout << k1 << endl;
	cout << k2 << endl;
	cout << k3 << endl;
	cout << k4 << endl;

	cout<< "ispis kopije knjige k1" << endl;
	cout << *(!k1) << endl;

	//stvaranje biblioteka i ubacivanje knjiga
	Biblioteka b1("prva", 4);
	b1 += k1;
	b1 += k2;
	b1 += k3;
	b1 += k4;

	cout << "____________________________" << endl;
	cout << b1;

	//dohvatanje knjige po indeksu
	cout << "knjiga iz zadate biblioteke sa zadatim identifikatorom: " << endl;
	cout << *b1.getKnjiga(5);



}