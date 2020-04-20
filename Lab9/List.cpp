
#include <iostream>
#include "list.h"

using namespace std;

List::List() : head(nullptr), tail(nullptr) {}
List::List(const List& other) 
{
	head = tail = nullptr;
	for (List::Elem* ptr = other.head; ptr; ptr = ptr->next)
		PushBack(ptr->val);
}
List::~List() 
{
	clean();
}
List::Elem::Elem(int v, List::Elem* n) : val(v), next(n) {}

void List::clean()
{
	while (head && head->next)
	{
		Elem* tmp = head->next;
		head->next = head->next->next;
		delete tmp;
	}
	delete head;
	head = tail = nullptr;
}
int List::Get()
{
	if (!head) return 0;
	int ret = head->val;
	Elem* tmp = head->next;
	if (head == tail) tail = nullptr;
	delete head;
	head = tmp;
	return ret;
}
void List::PushFront(int v)
{
	if (head)
	{
		Elem* new_Elem = new Elem(v);
		new_Elem->next = head;
		head = new_Elem;
	}
	else
		tail = head = new Elem(v);
}
void List::PushBack(int v)
{
    if ( tail )
        tail = tail->next = new Elem(v);
    else
        tail = head = new Elem(v);
}
int List::At(int i)
{
	if (i < 0) return 0;
	Elem* current = head;
	while (i-- && current)
		current = current->next;
	return (current ? current->val : 0);
}
int List::Max()
{
	if (!head) return 0;
	int max = INT_MIN;
	for (Elem* ptr = head; ptr; ptr = ptr->next)
		if (ptr->val > max) max = ptr->val;
	return max;
}
List List::SubList(int start, int len)
{
	List temp;
	if (start < 0 || len < 0) return temp;
	
	Elem* current = head; 
	
	while (start-- && current)  // move to starting element
		current = current->next; 

	while (len-- && current) // start sublisting 
	{
		temp.PushBack(current->val); 
		current = current->next;
	}
	
	return temp;
}
void List::Reverse()
{
	List temp(*this);
	clean();

	Elem* current = temp.head;
	while (current)
	{
		PushFront(current->val);
		current = current->next;
	}
}
int List::GetMax()
{
	if (!head) return 0; // empty list
	
	int max = Max();
	Elem* current = head;

	if (head->val == max) // if max is at head
	{
		head = (head == tail ? head = tail = nullptr : head->next);
		delete current;
		return max;
	}

	while (current->next) // look if max is inside the list
	{
		if (current->next->val < max)
		{
			current = current->next;
			continue;
		}
		else // found max
		{
			Elem* temp = current->next; 
			if (tail == current->next) // if it was tail reassign tail
				tail = (current->next->next ? current->next->next : current);
			current->next = current->next->next;
			delete temp;
			return max;
		}
	}
}
int List::Remove(int v)
{
	if (!head) return 0;

	int count = 0;
	
	while (head->val == v) // delete values at front
	{
		Elem* current = head; 
		if (head == tail) head = tail = nullptr; // if deleting last element in list
		else head = head->next;
		delete current;
		count++;
		if (!head) return count; // if list becomes empty return
	}

	Elem* current = head;

	while (current->next) // delete values inside the list
	{
		if (current->next->val != v)
		{
			current = current->next;
			continue;
		}
		else
		{
			Elem* temp = current->next;
			if (tail == current->next)
				if (current->next->next) tail = current->next->next;
				else tail = current;
			current->next = current->next->next;

			delete temp;
			count++;
		}
	}

	return count;
}

List& List::operator=(const List& other)
{
	clean();
	for (List::Elem* ptr = other.head; ptr; ptr = ptr->next)
		PushBack(ptr->val);
	return *this;
}
ostream& operator<<(ostream& os, const List& list)
{
	os << "[ ";
	for (List::Elem* ptr = list.head; ptr; ptr = ptr->next)
		os << ptr->val << " ";
	os << "]";
	return os;
}