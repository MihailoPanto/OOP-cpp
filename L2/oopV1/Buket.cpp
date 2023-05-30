#include "Buket.h"

void Buket::kopiraj(const Buket& b) {
	head = nullptr;
	tail = nullptr;
	Node* curr = b.head;

	while (curr) {
		if (!head) head = tail = new Node(curr->cv);
		else tail = tail->next = new Node(curr->cv);
		curr = curr->next;
	}
}

void Buket::premesti(Buket& b) {
	head = b.head;
	tail = b.tail;
	b.head = nullptr;
	b.tail = nullptr;
}

void Buket::brisi() {

	while (head) {
		Node* old = head;
		head = head->next;
		delete old;
	}
	tail = nullptr;

}

Buket::Buket(const Buket& b) {kopiraj(b);}

Buket::Buket(Buket&& b) {premesti(b);}

Buket::~Buket() {brisi();}

Buket& Buket::operator=(const Buket& b) {
	if (this != &b) {
		brisi();
		kopiraj(b);
	}
	return *this;
}

Buket& Buket::operator=(Buket&& b) {
	if (this != &b) {
		brisi();
		premesti(b);
	}
	return *this;
}

int Buket::ukNabavna()const {
	int nab = 0;
	Node* curr = head;
	while (curr != nullptr) {
		nab += curr->cv->getNab();
		curr = curr->next;
	}
	return nab;
}

int Buket::ukProdajna()const {
	int prod = 0;
	Node* curr = head;
	while (curr != nullptr) {
		prod += curr->cv->getPro();
		curr = curr->next;
	}
	return prod;
}

void Buket::dodajCvet(Cvet* c) {

	Node* novi = new Node(c);

	if (head == nullptr) {
		head = novi;
		tail = novi;
	}
	else if (head->cv->getNaz() >= c->getNaz()) {

		novi->next =this->head;
		head = novi;
	}
	else if (this->tail->cv->getNaz() <= c->getNaz()) {
		tail->next = novi;
		tail = novi;
	}
	else {
		Buket::Node* curr = head;

		while (curr->next->cv->getNaz() <= c->getNaz()) {
			curr = curr->next;
		}
		novi->next = curr->next;
		curr->next = novi;
	}
}

int Buket::ukZarada() {
	int zar = this->ukProdajna() - this->ukNabavna();
	return zar;
}

bool operator>(const Buket& b1, const Buket& b2) {
	return (b1.ukProdajna() > b2.ukProdajna());
}

ostream& operator<<(ostream& it, const Buket& b) {

	Buket::Node* curr = b.head;
	Buket::Node* pred = nullptr;

	it << '(';
	while (curr != nullptr) {

		if (pred == nullptr) {
			if (curr->next != nullptr) {
				it << (*curr->cv) << ',';
			}
			else it << (*curr->cv);
		}
		else if (curr->cv->getNaz() != pred->cv->getNaz()) {
			if (curr->next == nullptr) {
				it << (*curr->cv);
			}
			else {
				it << (*curr->cv) << ',';
			}
		}
		pred = curr;
		curr = curr->next;
	}
	int n = b.ukProdajna();
	it <<')' <<n << "RSD";
	return it;
}