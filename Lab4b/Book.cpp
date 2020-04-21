#include "Book.h"

using namespace std;

// ETAP 2 from

Book::Book(const std::string & _title, Authors _authors, int _publicationYear)
{
	title = _title;
	publicationYear = _publicationYear;
	authors = Authors(_authors);
}

std::ostream& operator<<(std::ostream& out, const Book& b)
{
	out << b.title << ", " << b.authors << ", " << b.publicationYear;
	return out;
}

// ETAP 2 to

// ETAP 3 from

bool operator==(const Book& b1, const Book& b2)
{
	bool flag = true;

	if ((b1.title != b2.title) || \
		(b1.publicationYear != b2.publicationYear) || \
		(b1.authors != b2.authors)) 
		flag = false;

	return flag;
}
bool operator!=(const Book& b1, const Book& b2)
{
	return !(b1 == b2);
}

// ETAP 3 to
