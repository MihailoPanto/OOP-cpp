#include "Rec.h"

Rec& Rec::operator=(const Rec& r) {
	if (this != &r) kopiraj(r);
	return *this;
}

Rec& Rec::operator=(Rec&& r) {
	if (this != &r) premesti(r);
	return *this;
}

int Rec::operator+() const { return rec.length(); }

bool Rec::nosilac(int pos) const {
	return samoglasnik(rec[pos])
		|| (sonant(rec[pos]) && (pos > 0 && !samoglasnik(rec[pos - 1])) && (pos < rec.length() - 1 && !samoglasnik(rec[pos + 1])));
}

int Rec::operator~() const {
	int cnt = 0;
	for (int pos = 0; pos < rec.length(); ++pos) {
		if (nosilac(pos)) cnt++;
	}
	return cnt;
}

int Rec::operator() (int n) const {

	if (n >= 0) {
		int cnt = -1;
		for (int i = 0; i < rec.length(); ++i) {
			if (nosilac(i)) {
				cnt++;
				if (cnt == n) return i;
			}
		}
	}
	else {
		int cnt = 0;
		for (int i = rec.length() - 1; i >= 0; --i) {
			if (nosilac(i)) {
				cnt++;
				if (cnt == -n) return i;
			}
		}
	}
	return -1;
}

bool operator^(const Rec& r1, const Rec& r2) {
	int n1 = ~r1;
	int n2 = ~r2;
	int pos1 = 0, pos2 = 0;
	if (n1 == 1 || n2 == 1) {
		pos1 = r1(-1);
		pos2 = r2(-1);
	}
	else {
		pos1 = r1(-2);
		pos2 = r2(-2);
	}
	if (+r2 - pos2 != +r1 - pos1) return false;

	for (; pos1 < +r1 && pos2 < +r2; pos1++, pos2++) {
		if (tolower(r1.rec[pos1]) != tolower(r2.rec[pos2])) return false;
	}
	return true;
}

ostream& operator <<(ostream& it, const Rec& r) {
	it << r.rec;
	return it;
}

istream& operator>> (istream& is, Rec& r) {
	string str;
	string novi_string;
	getline(is, str);

	for (int i = 0; i < str.length(); ++i) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			novi_string += str[i];
		}
	}
	r.rec = novi_string;
	return is;
}