#pragma once

#include <iostream>

using namespace std;

class List
    {

    private:

    class Elem
        {
        public:
        int val;
        Elem *next;
        Elem(int v, Elem* n=nullptr);
        };

    Elem *head;
    Elem *tail;

    void clean();
    // You can add private members if you want

    public:

    void PushBack(int v);

    // add members needed for part I

	List();
	List(const List& other);
	~List();
	List& operator=(const List& other);

    void PushFront(int v);
    int Get();
    int Max();
    int At(int i);
    List SubList(int start, int len);
    void Reverse();
    int GetMax();
    int Remove(int v);

    friend ostream& operator<<(ostream& os, const List&);
    };
