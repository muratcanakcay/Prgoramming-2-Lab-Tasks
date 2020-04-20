#ifndef BOOK_H
#define BOOK_H

#define MAX_CHAR 10

#include <string>
#include <iomanip>
#include <iostream>

class Book
{
    std::string title;
    std::string author;

    int bookID;
    bool isAvailable = true;

public:
    Book(int _bookID = -1, std::string _title = "No Title", std::string _author = "No Author")
        : bookID(_bookID), title(_title), author(_author) { }

    int GetBookID() { return this->bookID; }
    bool IsAvailable() { return this->isAvailable; }

    void SetAvailability(bool _isAvailable) { this->isAvailable = _isAvailable; }

    friend std::ostream& operator<<(std::ostream& out, const Book& book)
    {
        out << book.title << " - " << book.author;

        return out;
    }
};

#endif /* BOOK_H */
