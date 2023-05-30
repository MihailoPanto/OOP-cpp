#ifndef Par_h
#define Par_h

#include <iostream>
#include <string>

using namespace std;

template<typename M>
class Par
{

	M* pod1;
	M* pod2;

	void kopiraj(const Par& p) {
		pod1 = new M(*p.pod1);
		pod2 = new M(*p.pod2);
	}

	void premesti(Par& p) {
		pod1 = p.pod1;
		pod2 = p.pod2;
		p.pod1 = nullptr;
		p.pod2 = nullptr;
	}

	void brisi() {}
public:

	Par(const Par& p) { kopiraj(p); }

	Par(Par&& p) { premesti(p); }

	Par& operator=(const Par& p) {
		if (this != &p) {
			brisi();
			kopiraj(p);
		}
		return *this;
	}

	Par& operator=(Par&& p) {
		if (this != &p) {
			brisi();
			premesti(p);
		}
		return *this;
	}

	Par(M* p1, M* p2) :pod1(p1), pod2(p2) {}
	void postavi_prvi(M* p) { pod1 = p; }

	void postavi_drugi(M* p) { pod2 = p; }

	M* dohvati_prvi() { return pod1; }

	M* dohvati_drugi() { return pod2; }

	bool operator ==(const Par& p) {
		return (pod1 == p.pod1 && pod2 == p.pod2) || (pod1 == p.pod2 && pod2 == p.pod1);
	}

	friend ostream& operator<<(ostream& it, const Par& p) {
		return it << '[' << (*p.pod1) << '-' << (*p.pod2) << ']';
	}

};

#endif