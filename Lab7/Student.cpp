#include "Student.h"

/* ----------- STAGE 3 ----------- */

Student::Student(const char _name[MAX_CHAR], const char _surname[MAX_CHAR])
{
	strcpy_s(name, MAX_CHAR, _name);
	strcpy_s(surname, MAX_CHAR, _surname);
}

void Student::ValidateStudentCard()
{
	studentCard.validStatus = CARD_STATUS::VALID;
}

unsigned short Student::GetID() const
{
	return studentCard.studentID;
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
	out << student.name << ' ' << student.surname << ' ' << student.studentCard;
	return out;
}

/* ----------- STAGE 4 ----------- */

void Student::BorrowBook(Book newBook)
{
	if (newBook.IsAvailable() && studentCard.GetBookCount() <= MAX_STUDENT_BOOKS)
		studentCard.studentBooks[studentCard.bookCount++] = newBook;
}

/* ----------- STAGE 5 ----------- */
 
void Student::LostStudentCard()
{
	if (studentCard.validStatus == CARD_STATUS::INVALID) return;
	
	StudentCard new_card(studentCard);
	studentCard = new_card;
}