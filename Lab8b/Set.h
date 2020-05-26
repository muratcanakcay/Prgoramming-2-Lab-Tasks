#ifndef _SET_H_
#define _SET_H_

#include <iostream>

using namespace std;

template <typename T>
class Set;

template <typename T>
class Node {
	T data;
	Node *next;
public:
	Node(T d, Node* n = nullptr) : data(d), next(n) {}
	friend class Set<T>;
};

template <typename T>
class Set {
	Node<T> *begin;
public:
	Set();
	~Set();
	Set(const Set& );
	Set& operator=(const Set& );

	bool isEmpty() const { return begin == nullptr; }
	bool inSet(T) const;
	
	void insert(T);
	void free();
	void copyFrom(const Set&);
	T pop();
	void print(ostream&) const;

	template <typename T>
	friend ostream& operator<<(ostream&, const Set<T>& );
	
	template <typename T>
	friend Set<T> operator+(const Set<T>&, const Set<T>&);

	template <typename T>
	friend Set<T> operator-(const Set<T>&, const Set<T>&);
};

#endif //_SET_H_





template <typename T>
Set<T>::Set() : begin(nullptr) {}

template <typename T>
Set<T>::~Set() {
	free();
}

template <typename T>
Set<T>::Set(const Set<T>& s) : begin(nullptr) {
	copyFrom(s);
}

template <typename T>
void Set<T>::free() {
	while (begin) {
		Node<T>* tmp = begin->next;
		delete begin;
		begin = tmp;
	}
	begin = nullptr;
}

template <typename T>
bool Set<T>::inSet(T v) const {
	Node<T>* tmp = begin;
	while (tmp) {
		if (tmp->data == v) return true;
		tmp = tmp->next;
	}
	return false;
}

template <> // specialized method for char
bool Set<char>::inSet(char c) const {
	Node<char>* tmp = begin;
	while (tmp) {
		if (tmp->data == toupper(c) || tmp->data == tolower(c) ) return true;
		tmp = tmp->next;
	}
	return false;
}

template <typename T>
void Set<T>::copyFrom(const Set<T>& s) {
	Node<T>* tmp = s.begin;
	while (tmp) {
		insert(tmp->data);
		tmp = tmp->next;
	}
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& s) {
	if (&s != this) {
		free();
		copyFrom(s);
	}
	return *this;
}

template <typename T>
void Set<T>::insert(T d) {
	if (inSet(d)) {
		cout << "Already in set, no insert" << endl;
		return;
	}
	if (begin == nullptr) {
		try
		{
			begin = new Node<T>(d);
		}
		catch (exception& e) // I leave as 'exception' to catch ALL exceptions
		{
			cout << "Exception happened: " << e.what() << endl;
		}
	}
	else 
	{
		try
		{
			begin = new Node<T>(d, begin);
		}
		catch (exception& e) // I leave as 'exception' to catch ALL exceptions
		{
			cout << "Exception happened: " << e.what() << endl;
		}
	}	
}

template <typename T>
T Set<T>::pop() 
{
	Node<T>* tmp = begin;
	if (begin != nullptr)
		{
			begin = begin->next;
			T d = tmp->data;
			delete tmp;
			return d;
		}
	else
		throw out_of_range("No elements in set");	
}

template <typename T>
void Set<T>::print(ostream& os) const {
	Node<T>* tmp = begin;
	while (tmp) {
		os << tmp->data << " ";
		tmp = tmp->next;
	}
}

template <typename T>
ostream& operator<<(ostream& os, const Set<T>& s) {
	s.print(os);
	return os;
}

template <typename T>
Set<T> operator+(const Set<T>& lh, const Set<T>& rh) 
{
	Set<T> S = lh;
	S.copyFrom(rh);
	return S;
}

template <typename T>
Set<T> operator-(const Set<T>& lh, const Set<T>& rh) 
{
	Set<T> C = lh;
	Set<T> S;
	
	while (!(C.isEmpty()))
	{
		T tmp = C.pop();
		if (!(rh.inSet(tmp))) 
			S.insert(tmp);		
	}

	return S;
}