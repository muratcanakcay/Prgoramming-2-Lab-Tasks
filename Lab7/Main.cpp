#include "Book.h"
#include "Student.h"
#include "Library.h"

#include <iostream>

int main(int argc, char** argv)
{
    std::cout << std::endl << " --------------------- STAGE_1 (2Pts) --------------------- " << std::endl << std::endl;

    StudentCard freeStudentCard1, freeStudentCard2; freeStudentCard2.SetState(CARD_STATUS::VALID);

    std::cout << "Oryginal StudentCards" << std::endl << std::endl;

    std::cout << "Free Student Cards (No 1):" << freeStudentCard1;
    std::cout << "Free Student Cards (No 2):" << freeStudentCard2 << std::endl;

    StudentCard copyStudentCard1(freeStudentCard1);
    StudentCard copyStudentCard2(freeStudentCard2);

    std::cout << "StudentCards After Making A Copy" << std::endl << std::endl;

    std::cout << "Free Student Cards (No 1):" << freeStudentCard1;
    std::cout << "Free Student Cards (No 2):" << freeStudentCard2 << std::endl;

    std::cout << "Copy Student Cards (No 1):" << copyStudentCard1;
    std::cout << "Copy Student Cards (No 2):" << copyStudentCard2;

    StudentCard::STUDENT_CARD_COUNT = 0;

    std::cout << std::endl << " --------------------- STAGE_2 (1Pts) --------------------- " << std::endl << std::endl;

    Book books_1[] =
    {
        Book(0, "La Catedral del Mar", "Ildefonso Falcones"),
        Book(1, "Tales of the Alhambra", "Washington Irving"),
        Book(2, "Quantum Physics for Beginners", "Jason Stephenson"),
        Book(3, "Death by Black Hole", "Neil deGrasse Tyson"),
        Book(4, "English 4 IT", "Beata Blaszczyk"),
        Book(5, "The Lord of the Rings", "J.R.R. Tolkien"),
        Book(6, "A Song of Ice and Fire", "George R.R. Martin"),
        Book(7, "Lord Jim", "Joseph Conrad"),
        Book(8, "The Adventures of Sherlock Holmes", "Arthur Conan Doyle"),
        Book(9, "The Witcher", "Andrzej Sapkowski"),
    };

    unsigned short counts_1[] = { 4,2,1,2,1,4,6,2,4,3 };

    Book books_2[] =
    {
        Book(0, "English 4 IT", "Beata Blaszczyk"),
        Book(1, "The Lord of the Rings", "J.R.R. Tolkien"),
        Book(2, "Lord Jim", "Joseph Conrad"),
        Book(3, "The Adventures of Sherlock Holmes", "Arthur Conan Doyle"),
        Book(4, "Eye of the Needle", "Ken Follett"),
        Book(5, "The Pillars of the Earth", "Ken Follett"),
        Book(6, "World Without End", "Ken Follett"),
        Book(7, "A Column of Fire", "Ken Follett"),
        Book(8, "Doctors", "Erich Segal"),
        Book(9, "The Witcher", "Andrzej Sapkowski"),
    };

    unsigned short counts_2[] = { 4,2,1,2,1,1,3,5,4,6, };

    Library library_1(books_1, counts_1); std::cout << "Library No 1:" << std::endl << library_1 << std::endl;
    Library library_2(books_2, counts_1); std::cout << "Library No 2:" << std::endl << library_2 << std::endl;


    std::cout << std::endl << " --------------------- STAGE_3 (3Pts) --------------------- " << std::endl << std::endl;

    Student students[] =
    {
       {"Gordon", "Jack"},
       {"Sartman", "Albert"},
       {"Monck", "John"},
       {"Benckin", "Broklyn"},
       {"Lanovic", "Lynk"},
       {"Anna", "STOSIO"},
       {"Wioletta", "JASINSKA"},
       {"Radoslaw", "KAMECKI"},
       {"Zenon", "ZIOMECKI"},
       {"Adam", "KOWALSKI"},
       {"Jan", "DZBAN"},
       {"Gabriela", "ZEBRACKA"},
       {"Joanna", "NOWAK"},
       {"Jaroslaw", "PLUTA"},
    };

    const unsigned short studentCount = sizeof(students) / sizeof(Student);

    for (int i = 0; i < studentCount; i += 2)
        library_1.AddStudent(students[i]);

    for (int i = 1; i < studentCount; i += 2)
        library_2.AddStudent(students[i]);

    for (int i = 0; i < studentCount; i++)
        std::cout << students[i];


    std::cout << std::endl << " --------------------- STAGE_4 (1.5Pts) --------------------- " << std::endl << std::endl;

    MakeReservation(library_1, students[0], 0, 3);
    MakeReservation(library_1, students[1], 1, 3);
    MakeReservation(library_1, students[2], 2, 3);
    MakeReservation(library_1, students[4], 0, 2);
    MakeReservation(library_2, students[10], 0, 2);
    MakeReservation(library_2, students[11], 9, 1);

	
    for (int i = 0; i < studentCount; i++)
        std::cout << students[i];


    std::cout << std::endl << " --------------------- STAGE_5 (0.5Pts) --------------------- " << std::endl << std::endl;

    students[0].LostStudentCard();
    students[2].LostStudentCard();
    students[5].LostStudentCard();
    students[8].LostStudentCard();
    students[9].LostStudentCard();

    MakeReservation(library_1, students[7], 3, 2);
    MakeReservation(library_1, students[8], 9, 2);
    MakeReservation(library_1, students[4], 0, 2);
    MakeReservation(library_2, students[7], 5, 3);
    MakeReservation(library_2, students[1], 2, 3);
    MakeReservation(library_2, students[6], 7, 3);

    for (int i = 0; i < studentCount; i++)
        std::cout << students[i];


	system("pause");

    return 0;
}
