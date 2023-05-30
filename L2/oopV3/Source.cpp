#include "Rec.h"
#include "Skup.h"

int main() {


	//pravim skup
	Skup s1("abcabc");
	s1 += 'd';

	Rec r1("");
	Rec r2("");

	//unos stringa, ispis stringa, broj slogova
	cin >> r1;
	cout << r1 << endl;
	cout << ~r1 << endl;

	//upis stringa
	cin >> r2;

	//ispis pozicije n-tog nosioca sloga, ili -1 ako je neuspesna pretraga
	cout <<"pozicija: " <<r1(-4) << endl;;

	cout << (r1 ^ r2 ? "Rimuju se" : "Ne rimuju se");
}