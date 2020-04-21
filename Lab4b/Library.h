#pragma once
#include "Book.h"
#include <iostream>

class Library
{
	int bookCount;
	Book* books;

public:
	// ETAP 4
	Library();
	~Library();
	bool AddBook(Book);
	friend std::ostream& operator<<(std::ostream&, const Library &);
};

