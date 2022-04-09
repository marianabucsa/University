#pragma once
#include "Domain.h"
#include <algorithm>


template <class TElem> class Iterator;
template <class TElem> class Node;
template <class TElem> class Lista;

// class for node objects from a list
template <class TElem> class Node {
	friend class Lista<TElem>;
private:
	TElem elem; // information
	Node* urm; // pointer to the next node
public:
	/*
	Create a new object of type Node
	input: - TElem , Node* 
	output: a node
	*/
	Node(TElem, Node*);

	/*
		Getter metode for element 
	*/
	TElem element();

	/*
		Getter metode for the adress of the next node
	*/
	Node* next();
};

// class for the iterator of a list
template <class TElem> class Iterator {
	friend class Lista<TElem>;
private:
	const Lista<TElem>& list; // referance to the list
	Node<TElem> *current; // pointer to the current element of the list
public:
	/*
	Create a new object of type Iterator
	input: - 
	output: an iterator
	*/
	Iterator(const Lista<TElem>& list) noexcept;

	// resets the iterator at the begining
	void first() noexcept;

	// moves the iterator to the next node
	void next() noexcept;

	// verifies if the iterator is valid
	bool valid() noexcept;

	// returns the element from the current node
	TElem element() const noexcept;
};


// class for the list
template <class TElem> class Lista {
	friend class Iterator<TElem>;
private:
	Node<TElem>* first;
public:
	/*
	Create a new object of type List
	input: -
	output: an iterator
	*/
	Lista() noexcept;

	/*
	Copy constructor
	input - a list
	output - a copy of the list
	*/
	Lista(const Lista&);

	/*
	Adds an element to the list
	input: an element
	output: -
	*/
	void add(const TElem&);

	/*
	Modifies an element in the list
	input: an element
	output: -
	*/
	void modify(const TElem&);

	/*
	Removes an element from the list
	input: an element
	output: -
	*/
	void remove(const TElem&) noexcept;

	/*
	Verifies if the list is empty
	input: -
	output: 1- if the list is empty
			0- if the list is not empty
	*/
	bool vid() const noexcept;

	/*
	Returns the size of the list
	input:-
	ouput: - returns the size of the list
	*/
	size_t size() const noexcept;

	/*

	*/
	TElem element(size_t) const noexcept;

	/*
	Sorts a list
	*/
	void sort(bool(*cmp)(const TElem&, const TElem&)) noexcept;

	/*
	Returns an iterator for the list
	input: -
	output: an iterator
	*/
	Iterator<TElem> iterator() const noexcept;

	~Lista();
};

template <class TElem> Node<TElem>::Node(TElem e, Node* urm) {
	this->elem = e;
	this->urm = urm;
}


template <class TElem> TElem Node<TElem>::element() {
	return this->elem;
}


template <class TElem> Node<TElem>* Node<TElem>::next() {
	return this->urm;
}


template <class TElem> Iterator<TElem>::Iterator(const Lista<TElem>& list) noexcept : list{ list } {
	this->current = list.first;
}


template <class TElem> void Iterator<TElem>::first() noexcept {
	this->current = list.first;
}


template <class TElem> void Iterator<TElem>::next() noexcept {
	this->current = this->current->next();
}


template <class TElem> bool Iterator<TElem>::valid() noexcept {
	return current != nullptr;
}


template <class TElem> TElem Iterator<TElem>::element() const noexcept {
	return current->element();
}

template <class TElem> Lista<TElem>::Lista() noexcept {
	this->first = nullptr;
}

template <class TElem> void Lista<TElem>::add(const TElem& e) {
	Node<TElem>* q = new Node<TElem>(e, nullptr);
	if (this->first == nullptr)
		this->first = q;
	else {
		Node<TElem>* p = this->first;
		while (p->urm != nullptr) {
			p = p->urm;
		}
		p->urm = q;
	}
}

template <class TElem> void Lista<TElem>::modify(const TElem& e) {
	Node<TElem>* p = this->first;
	while (p->elem != e)
		p = p->urm;
	p->elem = e;
}

template <class TElem> void Lista<TElem>::remove(const TElem& e) noexcept {
	Node<TElem>* p = nullptr, * v = nullptr, * ant = nullptr;
	if (this->first->elem == e) {
		v = this->first;
		this->first = this->first->urm;
		delete v;
	}
	else {
		bool gasit = false;
		p = this->first;
		while (!gasit) {
			if (p->elem == e)
				gasit = true;
			else {
				ant = p;
				p = p->urm;
			}
		}
		if (ant != nullptr)
			ant->urm = p->urm;
		delete p;
	}
}

template <class TElem> bool Lista<TElem>::vid() const noexcept {
	return this->first == nullptr;
}

template <class TElem> size_t Lista<TElem>::size() const noexcept {
	size_t k = 0;
	if (!vid()) {

		Node<TElem>* p = this->first;
		k++;
		while (p->urm != nullptr) {
			k++;
			p = p->urm;
		}
	}
	return k;
}

template <class TElem> TElem Lista<TElem>::element(size_t dim) const noexcept {
	size_t i = 0;
	Node<TElem>* p = this->first;
	while (p->urm != nullptr && i < dim) {
		i++;
		p = p->urm;
	}
	return p->elem;
}

template <class TElem> void Lista<TElem>::sort(bool(*cmp)(const TElem&, const TElem&)) noexcept {
	Node<TElem>* p = this->first;
	while (p->urm != nullptr) {
		Node<TElem>* u = p->urm;
		while (u != nullptr) {
			if (cmp != nullptr && !cmp(p->elem, u->elem))
				std::swap(p->elem, u->elem);
			u = u->urm;
		}
		p = p->urm;
	}
}

template<class TElem> Lista<TElem>::Lista(const Lista& list) {
	this->first = nullptr;
	Node<TElem>* n = list.first;
	if (n != nullptr) {
		this->add(n->elem);
		while (n->urm != nullptr) {
			n = n->urm;
			this->add(n->elem);
		}
	}
}

template <class TElem> Iterator<TElem> Lista<TElem>::iterator() const noexcept {
	return Iterator<TElem>(*this);
}

template <class TElem> Lista<TElem>::~Lista() {
	while (first != nullptr) {
		Node<TElem>* p = first;
		first = first->urm;
		delete p;
	}
}