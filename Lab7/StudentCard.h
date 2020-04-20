#ifndef STUDENT_CARD_H
#define STUDENT_CARD_H

#define MAX_STUDENT_BOOKS 5

#include "Book.h"
#include <iostream>

enum class CARD_STATUS { INVALID, VALID };

class StudentCard
{
    friend class Student;

    /* ----------- ALREADY IMPLEMENTED ----------- */
    unsigned short studentID; unsigned short bookCount = 0;
    
    /* ----------- ALREADY IMPLEMENTED ----------- */
    CARD_STATUS validStatus = CARD_STATUS::INVALID;
    Book studentBooks[MAX_STUDENT_BOOKS];

public:
    /* ----------- ALREADY IMPLEMENTED ----------- */
    static unsigned short STUDENT_CARD_COUNT;


    /* ----------- STAGE 1 ----------- */
    StudentCard(); 
	StudentCard(StudentCard& studentCard);
    
    /* ----------- STAGE 1 ----------- */
    friend std::ostream& operator<<(std::ostream& out, const StudentCard& studentCard);


    /* ----------- STAGE 4 ----------- */
    unsigned short GetBookCount() const;
    unsigned short GetID() const;
  

    /* ----------- ALREADY IMPLEMENTED ----------- */
    CARD_STATUS Status() const { return this->validStatus; }
    void SetState(CARD_STATUS validStatus) { this->validStatus = validStatus; }
};

#endif /* STUDENT_CARD_H */
