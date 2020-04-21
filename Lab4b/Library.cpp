#include "Library.h"

using namespace std;

// ETAP 4 from

Library::Library()
{
	bookCount = 0;
	books = nullptr;
}
Library::~Library()
{
	if (books) delete[] books;
}

bool Library::AddBook(Book new_book)
{
	if (!bookCount) // if no books in library
	{
		books = new Book[1];
		books[0] = new_book;
		bookCount++;
		return true;
	}		
	
	// if there are books in library

	Book* temp = new Book[bookCount + 1];

	for (int i = 0; i < bookCount; i++)
	{
		if (books[i] == new_book) // duplicate book, so do nothing and return false
		{
			delete[] temp;
			return false;
		}

		temp[i] = books[i];	// make copy of book list	
	}

	//no duplicate book, so new book will be added

	temp[bookCount++] = new_book; // add new book to the end and increase # books in library

	// copy new list to class member
	delete[] books;
	books = new Book[bookCount];
	for (int i = 0; i < bookCount; i++)
		books[i] = temp[i];
	delete[] temp;

	return true;
}

std::ostream& operator<<(std::ostream& out, const Library& l)
{
	out << "Prints Library Resources - Count: " << l.bookCount << endl;
	for (int i = 0; i < l.bookCount; i++)
		out << l.books[i] << endl;
	
	return out;
}


// ETAP 4 to