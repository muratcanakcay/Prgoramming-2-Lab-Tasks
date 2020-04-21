#pragma once
#include <string>
#include "Authors.h"

class Book
{
	std::string title;
	Authors authors;
	int publicationYear;

public:
	// ETAP 2
	Book() = default;
	Book(const std::string& _title, Authors _authors, int _publicationYear);
	friend std::ostream& operator<<(std::ostream &, const Book &);

	// ETAP 3
	friend bool operator==(const Book &, const Book &);
	friend bool operator!=(const Book &, const Book &);
};
