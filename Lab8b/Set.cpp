//#include "Set.h"
//
//Set::Set() : begin(nullptr) {}
//
//Set::~Set() {
//	free();
//}
//
//Set::Set(const Set& s) : begin(nullptr) {
//	copyFrom(s);
//}
//
//void Set::free() {
//	while (begin) {
//		Node * tmp = begin->next;
//		delete begin;
//		begin = tmp;
//	}
//	begin = nullptr;
//}
//
//bool Set::inSet(int v) const {
//	Node* tmp = begin;
//	while (tmp) {
//		if (tmp->data == v) return true;
//		tmp = tmp->next;
//	}
//	return false;
//}
//
//void Set::copyFrom(const Set &s) {
//	Node* tmp = s.begin;
//	while (tmp) {
//		insert(tmp->data);
//		tmp = tmp->next;
//	}
//}
//
//Set& Set::operator=(const Set& s) {
//	if (&s != this) {
//		free();
//		copyFrom(s);
//	}
//	return *this;
//}
//
//void Set::insert(int d) {
//	if (inSet(d)) {
//		cout << "Already in set, no insert" << endl;
//		return;
//	}
//	if (begin == nullptr) {
//		begin = new (nothrow) Node(d);
//	}
//	else {
//		begin = new (nothrow) Node (d, begin);
//	}
//	if(begin==nullptr) cout<<"Memory error, no insert"<<endl;
//}
//
//int Set::pop(){
//	Node* tmp = begin;
//	begin = begin->next;
//	int d = tmp->data;
//	delete tmp;
//	return d;
//}
//
//void Set::print(ostream& os) const {
//	Node *tmp = begin;
//	while (tmp) {
//		os << tmp->data << " ";
//		tmp = tmp->next;
//	}
//}
//
//
//ostream& operator<<(ostream& os, const Set& s) {
//	s.print(os);
//	return os;
//}
//
//Set operator+(const Set &lh, const Set &rh) // suma zbiorow
//{
//	Set S = lh;
//	S.copyFrom(rh);
//	return S;
//}
//
