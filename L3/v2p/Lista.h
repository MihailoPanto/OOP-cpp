#ifndef Lista_h
#define Lista_h

#include "Greska.h"


template<typename M>
class Lista
{
private:
	int num;

	struct Node {

		M info;
		Node* next;

		Node(M i, Node* n = nullptr) :info(i), next(n) {}
		~Node() {}

	};

	Node* head = nullptr;
	Node* tail = nullptr;

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
		Node* x = l.head;

		while (x) {
			if (!head) head = tail = new Node(x->info);
			else tail = tail->next = new Node(x->info);
			x = x->next;
		}

	}
	void premesti(Lista& l) {
		num = l.num;
		head = l.head;
		tail = l.tail;
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

	friend Lista& operator+=(Lista& l, M elem) {
		Node* cvor = new Node(elem);

		l.num++;
		if (!l.head) { l.tail = l.head = cvor; }
		else {
			l.tail->next = cvor;
			l.tail = cvor;
		}
		return l;
	}

	int getNum()const { return num; }

	M& operator[](int i) {
		if (i < 0 || i >= num) throw CurrError();
		Node* e = head;
		for (; i > 0; i--, e = e->next);
		return e->info;
	}

};

#endif

