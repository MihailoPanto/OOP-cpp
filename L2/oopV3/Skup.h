#ifndef SKUP
#define SKUP

#include <iostream>
#include <string>
using namespace std;

class Skup
{

	bool niz[256];

public:

	Skup(string s) {
		int n = s.length();

		for (int i = 0; i < 256; ++i) {niz[i] = false;}

		for (int i = 0; i < n; i++) {niz[s[i]] = true;}
	}

	Skup(const Skup&) = delete;

	Skup(Skup&&) = delete;

	Skup& operator=(const Skup& s) = delete;

	Skup& operator=(Skup&& s) = delete;

	bool operator()(char c);

	friend void operator +=(Skup& s, char c);

};

#endif