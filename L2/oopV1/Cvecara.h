#ifndef cvecara_h
#define cvecara_h
#include "Buket.h"

class Cvecara
{
	int zarada;
	struct Node {
		Buket* b;
		Node* next = nullptr;
		Node(Buket* buk) :b(buk) {};
	};
	Node* head = nullptr;
	Node* tail = nullptr;

	void brisi();

	void kopiraj(const Cvecara& b);

	void premesti(Cvecara& b);

public:

	Cvecara(int z = 1000) :zarada(z) {};

	Cvecara(const Cvecara& b);

	Cvecara(Cvecara&& b);

	~Cvecara();

	Cvecara& operator=(const Cvecara& c);

	Cvecara& operator=(Cvecara&& c);
	
	void addBuket(Buket* buk);

	void delBuket(int poz);

	int getZarada()const { return zarada; }

	friend ostream& operator <<(ostream& it, const Cvecara& c);
};

#endif



