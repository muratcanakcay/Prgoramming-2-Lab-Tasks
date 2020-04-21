#include "Library.h"
#include <iostream>

using namespace std;

int main() {
	// ==================   STAGE  1  ===========================
	cout << endl << "-------------  STAGE  1  --------------" << endl;

	std::string	*a01 = new std::string[1]{ "Adam Mickiewicz" };
	Authors l01(a01, 1);

	std::string *a02 = new std::string[1]{ "Henryk Sienkiewicz" };
	Authors l02(a02, 1);

	std::string *a03 = new std::string[2]{ "Rene Goscinny","Jean-Jacques Sempe" };
	Authors l03(a03, 2);

	cout << l01 << endl;
	cout << l02 << endl;
	cout << l03 << endl;

	// ==================   STAGE  2  ===========================
	cout << endl << "-------------  STAGE  2  --------------" << endl;

	Book k01("Pan Tadeusz", l01, 1834);

	char * t02 = new char[6];
	strcpy_s(t02, 6, "Potop");
	Book k02(t02, l02, 1886);
	delete[] t02;

	Book k03("Mikolajek", l03, 1959);

	cout << k01 << endl;
	cout << k02 << endl;
	cout << k03 << endl;

	Authors l04 = l02;
	Book k04("Krzyzacy", l04, 1900);

	cout << k04 << endl;

	Authors l05(a02, 1);
	l05 = l01;
	Book k05("Konrad Wallenrod", l05, 1828);

	cout << k05 << endl;

	// ==================   STAGE  3  ===========================
	cout << endl << "-------------  STAGE  3  --------------" << endl;

	cout << k01 << " vs " << k02 << endl << (k01 == k02 ? "EQUAL" : "NOT EQUAL") << "(EXPECTED: NOT EQUAL)" << endl;
	cout << k01 << " vs " << k02 << endl << (k01 != k02 ? "NOT EQUAL" : "EQUAL") << "(EXPECTED: NOT EQUAL)" << endl;
	cout << k03 << " vs " << k03 << endl << (k03 == k03 ? "EQUAL" : "NOT EQUAL") << "(EXPECTED:     EQUAL)" << endl;
	cout << k03 << " vs " << k03 << endl << (k03 != k03 ? "NOT EQUAL" : "EQUAL") << "(EXPECTED:     EQUAL)" << endl;
	Book k06(k03);                                                                                          
	cout << k03 << " vs " << k06 << endl << (k03 == k06 ? "EQUAL" : "NOT EQUAL") << "(EXPECTED:     EQUAL)" << endl;
	cout << k03 << " vs " << k06 << endl << (k03 != k06 ? "NOT EQUAL" : "EQUAL") << "(EXPECTED:     EQUAL)" << endl;
	k06 = Book("Mikolajek", l03, 1961);                                                                     
	cout << k03 << " vs " << k06 << endl << (k03 == k06 ? "EQUAL" : "NOT EQUAL") << "(EXPECTED: NOT EQUAL)" << endl;
	cout << k03 << " vs " << k06 << endl << (k03 != k06 ? "NOT EQUAL" : "EQUAL") << "(EXPECTED: NOT EQUAL)" << endl;

	// ==================   STAGE  4  ===========================
	cout << endl << "-------------  STAGE  4  --------------" << endl;

	Library b01;
	cout << k01 << (b01.AddBook(k01) ? "" : " NOT") << " ADDED" << " (EXPECTED:     ADDED)" << endl;
	cout << k02 << (b01.AddBook(k02) ? "" : " NOT") << " ADDED" << " (EXPECTED:     ADDED)" << endl;
	cout << k04 << (b01.AddBook(k04) ? "" : " NOT") << " ADDED" << " (EXPECTED:     ADDED)" << endl;
	cout << k03 << (b01.AddBook(k03) ? "" : " NOT") << " ADDED" << " (EXPECTED:     ADDED)" << endl;
	cout << k05 << (b01.AddBook(k05) ? "" : " NOT") << " ADDED" << " (EXPECTED:     ADDED)" << endl;
	cout << k06 << (b01.AddBook(k06) ? "" : " NOT") << " ADDED" << " (EXPECTED:     ADDED)" << endl;
	Book *k07 = new Book(k06);
	cout << *k07 << (b01.AddBook(*k07) ? "" : " NOT") << " ADDED" << " (EXPECTED: NOT ADDED)" << endl;
	delete k07;
	
	std::string *a08 = new std::string[1]{ "Maria Konopnicka" };
	Authors l08(a08, 1);
	Book k08("Nasza szkapa", l08, 1890);
	cout << k08 << (b01.AddBook(k08) ? "" : " NOT") << " ADDED" << " (EXPECTED:     ADDED)" << endl;
	
	cout << endl << b01 << endl;

	cout << "Program Should Not Display Any Error!" << endl << endl;
	
	return 0;
}