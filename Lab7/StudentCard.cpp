#include "StudentCard.h"

/* ----------- STAGE 1 ----------- */
unsigned short StudentCard::STUDENT_CARD_COUNT = 0;

StudentCard::StudentCard()
{
	studentID = STUDENT_CARD_COUNT++;
}

StudentCard::StudentCard(StudentCard& studentCard)
{
	studentID = STUDENT_CARD_COUNT++;
	validStatus = studentCard.validStatus;
	bookCount = studentCard.bookCount;
	for (int i = 0; i < bookCount; i++)
		studentBooks[i] = studentCard.studentBooks[i];

	studentCard.validStatus = CARD_STATUS::INVALID; // invalidate old card
}

std::ostream& operator<<(std::ostream& out, const StudentCard& studentCard)
{
	out << studentCard.studentID << ' ' \
		<< (studentCard.validStatus == CARD_STATUS::VALID ? "(Valid)" : "(Not valid)") << std::endl;

	for (int i = 0; i < studentCard.bookCount; i++)
		out << "        " << studentCard.studentBooks[i] << std::endl;
		
	return out;
}

/* ----------- STAGE 4 ----------- */

unsigned short StudentCard::GetBookCount() const
{
	return bookCount;
}

unsigned short StudentCard::GetID() const
{
	return studentID;
}
