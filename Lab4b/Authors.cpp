#include "Authors.h"

using namespace std;

// ETAP 1 from
Authors::Authors(std::string* authors, int count) : authors(nullptr)
{
	authorsCount = count;
	if (count)
	{
		this->authors = new string[count];
		for (int i = 0; i < count; i++)
		{
			this->authors[i] = authors[i];
		}
	}
}
Authors::~Authors()
{
	if (authors)
		delete[] authors;
}
std::ostream& operator<<(std::ostream& out, const Authors& a)
{
	for (int i = 0; i < a.authorsCount; i++)
	{
		out << a.authors[i];
		if (i < a.authorsCount - 1) out << ", ";
	}

	return out;
}

// ETAP 1 to

// ETAP 2 from

Authors::Authors(const Authors& a) // copy c-tor
{
	authorsCount = a.authorsCount;
	
	if (authorsCount)
	{
		authors = new string[authorsCount];
		for (int i = 0; i < authorsCount; i++)
			authors[i] = a.authors[i];
	}
	else authors = nullptr;
}
Authors& Authors::operator=(const Authors& a) // assignment operator
{
	if (authors) delete[] authors;

	authorsCount = a.authorsCount;
	
	if (authorsCount)
	{
		authors = new string[authorsCount];
		for (int i = 0; i < authorsCount; i++)
			authors[i] = a.authors[i];
	}
	else authors = nullptr;

	return *this;
}

// ETAP 2 to

// ETAP 3 from

bool operator==(const Authors& a1, const Authors& a2)
{
	bool flag = true;
	if (a1.authorsCount != a2.authorsCount) flag = false;
	else 
		for (int i = 0; i < a1.authorsCount; i++)
			if (a1.authors[i].compare(a2.authors[i]) != 0) flag = false;
	
	return flag;	
}
bool operator!=(const Authors& a1, const Authors& a2)
{
	bool flag = false;
	if (a1.authorsCount != a2.authorsCount) flag = true;
	else
		for (int i = 0; i < a1.authorsCount; i++)
			if (a1.authors[i].compare(a2.authors[i]) != 0) flag = true;
			
	return flag;	   
}

// ETAP 3 to