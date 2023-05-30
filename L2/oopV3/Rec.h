#ifndef rec_h
#define rec_h
#include <string>
#include <iostream>

using namespace std;

class Rec
{
	string rec;

	static bool samoglasnik(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
	}

	static bool sonant(char c) {
		return c == 'r' || c == 'l' || c == 'n' || c == 'R' || c == 'L' || c == 'N';
	}
	
	bool nosilac(int pos) const;

	void kopiraj(const Rec& b) {rec = b.rec;}

	void premesti(Rec& b) {rec = b.rec;}

public:

	Rec(string s) :rec(s) {};

	int operator+() const;

	int operator~() const;

	int operator() (int n) const;

	Rec(const Rec& b) { kopiraj(b); }

	Rec(Rec&& b) { premesti(b); }

	Rec& operator=(const Rec& r);

	Rec& operator=(Rec&& r);

	friend bool operator^(const Rec& r1, const Rec& r2);

	friend ostream& operator <<(ostream& it, const Rec& r);

	friend istream& operator>> (istream& is, Rec& dt);
};

#endif