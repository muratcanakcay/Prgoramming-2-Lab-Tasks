#include "Library.h"

/* ----------- STAGE 2 ----------- */

Library::Library(Book books[MAX_LIBRARY_BOOKS], unsigned short counts[MAX_LIBRARY_BOOKS])
{
	for (int i = 0; i < MAX_LIBRARY_BOOKS; i++)
	{
		resources[i].book = books[i];
		resources[i].count = counts[i];
	}

	*students = NULL;
}

std::ostream& operator<<(std::ostream& out, Library& library)
{
	for (int i = 0; i < MAX_LIBRARY_BOOKS; i++)
	{
		out << "Book No " << i << ':' \
			<< " (" << library.resources[i].count << ") " \
			<< library.resources[i].book << std::endl;
	}
	return out;
}

/* ----------- STAGE 3 ----------- */

void Library::AddStudent(Student& newStudent)
{
	if (STUDENTS_COUNT >= MAX_STUDENTS) return;

	students[STUDENTS_COUNT++] = newStudent.GetID(); // add student ID to array
	newStudent.ValidateStudentCard(); 
}

/* ----------- STAGE 4 ----------- */

void MakeReservation(Library& library, Student& student, unsigned short bookID, unsigned short amount)
{
	if (student.studentCard.Status() == CARD_STATUS::INVALID) return; // return if card invalid

	bool student_added = false;
	for (int i = 0; i < MAX_STUDENTS; i++)
		if (library.students[i] == student.GetID()) student_added = true; 
	
	if (!student_added) return; // return if student not added to library
	
	int book_idx;
	for (int i = 0; i < MAX_LIBRARY_BOOKS; i++)
		if (library.resources[i].book.GetBookID() == bookID) book_idx = i; // find book index
	
	while (library.resources[book_idx].count > 0 && amount > 0)
	{
		student.BorrowBook(library.resources[book_idx].book);
		
		if (--library.resources[book_idx].count == 0) // decrease # of books left in library
			library.resources[book_idx].book.SetAvailability(false); // if no books left in library
		amount--; // decrease # of requests
	}
}