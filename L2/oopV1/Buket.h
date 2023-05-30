#ifndef buket_h
#define buket_h
#include "Cvet.h"
#include <string>
#include <iostream>
using namespace std;

class Buket
{

	struct Node {
		Cvet* cv;
		Node* next;
		Node(Cvet* c) :cv(c), next(nullptr) {};
	};

	Node* head = nullptr;
	Node* tail = nullptr;

	void brisi();

	void kopiraj(const Buket& b);

	void premesti(Buket& b);

public:
	Buket() {}

	Buket(const Buket& b);

	Buket(Buket&& b);

	~Buket();

	Buket& operator=(const Buket& b);

	Buket& operator=(Buket&& b);

	void dodajCvet(Cvet* c);

	int ukNabavna()const;

	int ukProdajna()const;

	int ukZarada();

	friend bool operator>(const Buket& b1, const Buket& b2);

	friend ostream& operator<<(ostream& it, const Buket& b);
};

#endif

