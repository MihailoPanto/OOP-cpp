#ifndef Tacka_h
#define Tacka_h

#include<iostream>
#include<cmath>



class Tacka
{

	int x, y;

public:

	Tacka(int xx,int yy):x(xx),y(yy){}

	friend double udaljenost(const Tacka& t1, const Tacka& t2) {
		return sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2));
	}

	friend bool operator ==(const Tacka& t1, const Tacka& t2) {
		return (t1.x == t2.x) && (t1.y == t2.y);
	}

	friend std::ostream& operator <<(std::ostream& it, const Tacka& t) {
		return it << "(" << t.x << ", " << t.y << ")";
	}

};

#endif