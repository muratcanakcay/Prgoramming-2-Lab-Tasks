#pragma once
#include <string>
#include <iostream>

class Authors
{
	int authorsCount; 
	std::string* authors;

public:
	// ETAP 1
	Authors(std::string *authors = nullptr, int count = 0);
	~Authors();
	friend std::ostream& operator<<(std::ostream &, const Authors &);

	// ETAP 2
	Authors(const Authors &);
	Authors& operator=(const Authors &);

	// ETAP 3
	friend bool operator==(const Authors &, const Authors &);
	friend bool operator!=(const Authors &, const Authors &);
};

