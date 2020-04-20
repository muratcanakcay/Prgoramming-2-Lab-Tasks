#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_STUDENTS 5
#define MAX_LIBRARY_BOOKS 10

#include "Book.h"
#include "Student.h"

#include <iostream>
#include <string>

class Library
{
    /* ----------- ALREADY IMPLEMENTED ----------- */
    struct Resources
    {
        Book book; unsigned short count;
    };
    
    /* ----------- ALREADY IMPLEMENTED ----------- */
    unsigned short STUDENTS_COUNT = 0;

    /* ----------- ALREADY IMPLEMENTED ----------- */
    Resources resources[MAX_LIBRARY_BOOKS];
    unsigned short students[MAX_STUDENTS];

public:
    /* ----------- STAGE 2 ----------- */
    Library(Book books[MAX_LIBRARY_BOOKS], unsigned short counts[MAX_LIBRARY_BOOKS]);

    /* ----------- STAGE 2 ----------- */
    friend std::ostream& operator<<(std::ostream& out, Library& library);


    /* ----------- STAGE 3 ----------- */
    void AddStudent(Student& newStudent);

    
    /* ----------- STAGE 4 ----------- */ /* ----------- MakeReservation Function Here ----------- */

	friend void MakeReservation(Library& library, Student& student, unsigned short bookID, unsigned short amount);

};

#endif /* LIBRARY_H */
