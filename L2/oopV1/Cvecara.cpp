#include "Cvecara.h"

void Cvecara::brisi() {
	Node* curr = head;

	while (curr) {
		Node* old = curr;
		curr = curr->next;
		delete old;
	}
	tail = nullptr;
}

void Cvecara::kopiraj(const Cvecara& b) {
	head = nullptr;
	tail = nullptr;
	zarada = b.zarada;
	Node* curr = b.head;

	while (curr) {
		if (!head) head = tail = new Node(curr->b);
		else tail = tail->next = new Node(curr->b);
		curr = curr->next;
	}
}

void Cvecara::premesti(Cvecara& b) {
	head = b.head;
	tail = b.tail;
	zarada = b.zarada;
	b.head = nullptr;
	b.tail = nullptr;
}

Cvecara::Cvecara(const Cvecara& b) { kopiraj(b); }

Cvecara::Cvecara(Cvecara&& b) { premesti(b); }

Cvecara::~Cvecara() { brisi(); }

Cvecara& Cvecara::operator=(const Cvecara& c) {
	if (this != &c) {
		brisi();
		kopiraj(c);
	}
	return *this;
}

Cvecara& Cvecara::operator=(Cvecara&& c) {
	if (this != &c) {
		brisi();
		premesti(c);
	}
	return *this;
}

void Cvecara::addBuket(Buket* buk) {

	float p = buk->ukNabavna() * (float)(20 / 100.0);

	if (buk->ukZarada() >= p) {
		zarada -= buk->ukNabavna();
		Node* novi = new Node(buk);
		if (head == nullptr) {
			head = novi;
			tail = novi;
		}
		else if (head->b->ukProdajna() >= buk->ukProdajna()) {
			novi->next = head;
			head = novi;
		}
		else if (tail->b->ukProdajna() <= buk->ukProdajna()) {
			tail->next = novi;
			tail = novi;
		}
		else {
			Node* curr = head;
			while (curr->next && curr->next->b->ukProdajna() <= buk->ukProdajna()) {
				curr = curr->next;
			}
			novi->next = curr->next;
			curr->next = novi;
		}
	}
}

void Cvecara::delBuket(int poz) {
	Node* curr = head;
	
	if (poz == 0) {
		Node* old = head;
		zarada += old->b->ukProdajna();
		head = head->next;
		if (!head) tail = nullptr;
		delete(old);
		return;
	}
	for (; curr && poz > 1; --poz) {
		curr = curr->next;
	}
	if (!curr) return;
	Node* old = curr->next;
	if (!old) return;
	zarada += old->b->ukProdajna();
	curr->next = old->next;

	if (old->next == nullptr) {
		tail = curr;
	}
	delete(old);
}

ostream& operator <<(ostream& it, const Cvecara& c) {

	it << "ZARADA = " << c.getZarada() << " RSD" << endl;
	Cvecara::Node* curr = c.head;
	while (curr) {
		it << (*curr->b) << endl;
		curr = curr->next;
	}
	return it;
}