#ifndef Lista_h
#define Lista_h

#include "Greska.h"


template<typename M>
class Lista
{

	int num;

	struct Node {

		M* info;
		Node* next;

		Node(M* i, Node* n = nullptr) :info(i), next(n) {}
		~Node() {}

	};

	Node* head = nullptr;
	Node* tail = nullptr;
	Node* curr = nullptr;

	void brisi() {
		while (head) {
			Node* old = head;
			head = head->next;
			delete old;
		}
	}
	void kopiraj(const Lista& l) {
		head = nullptr;
		tail = nullptr;
		curr = nullptr;

		num = l.num;
		Node* x = l.head;

		while (x) {
			if (!head) head = tail = new Node(x->info);
			else tail = tail->next = new Node(x->info);
			if (l.curr == x) curr = tail;
			x = x->next;
		}
	}
	void premesti(Lista& l) {
		num = l.num;
		head = l.head;
		tail = l.tail;
		curr = l.curr;
		l.head = nullptr;
		l.tail = nullptr;
		l.curr = nullptr;
	}

public:

	Lista() { num = 0; }

	~Lista() { brisi(); }

	Lista(const Lista& l) { kopiraj(l); }

	Lista(Lista&& l) { premesti(l); }

	Lista& operator=(const Lista& l) {
		if (this != &l) {
			brisi();
			kopiraj(l);
		}
		return *this;
	}

	Lista& operator=(Lista&& l) {
		if (this != &l) {
			brisi();
			premesti(l);
		}
		return *this;
	}

	void dodaj(M* in) {
		Node* cvor = new Node(in);

		if (!head) { curr = tail = head = cvor; }
		else {
			tail->next = cvor;
			tail = cvor;
		}
	}

	void vratiNaPrvi()const { curr = head; }

	void predjiNaSledeci()const {
		if (curr) curr = curr->next;
	}

	M* trenutni()const {
		if (curr == nullptr) throw CurrError();
		return curr->info;
	}

	int getNum() const{ return num; }

};

#endif
