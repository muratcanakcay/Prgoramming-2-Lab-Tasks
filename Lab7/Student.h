#ifndef STUDENT_H
#define STUDENT_H

#define MAX_CHAR 10

#include "Book.h"
#include "StudentCard.h"

#include <ostream>

class Library;

class Student
{
    /* ----------- ALREADY IMPLEMENTED ----------- */
    char name[MAX_CHAR];
    char surname[MAX_CHAR];

    /* ----------- ALREADY IMPLEMENTED ----------- */
    StudentCard studentCard;
	
public:
    /* ----------- ALREADY IMPLEMENTED ----------- */
    Student() = default;


    /* ----------- STAGE 3 ----------- */
    Student(const char _name[MAX_CHAR], const char _surname[MAX_CHAR]);

    /* ----------- STAGE 3 ----------- */
    void ValidateStudentCard();

    /* ----------- STAGE 3 ----------- */
    unsigned short GetID() const;

    /* ----------- STAGE 3 ----------- */
    friend std::ostream& operator<<(std::ostream& out, const Student& student);


    /* ----------- STAGE 4 ----------- */
    void BorrowBook(Book newBook);

    /* ----------- STAGE 4 ----------- */ /* ----------- MakeReservation Function Here ----------- */

	friend void MakeReservation(Library& library, Student& student, unsigned short bookID, unsigned short amount);

    /* ----------- STAGE 5 ----------- */
    
	void LostStudentCard();
};

#endif /* STUDENT_H */
