#include <iostream>
#include "Set.h"

using namespace std;

int main() {
	/*cout << "--------- 0 -----------" << endl;
	Set<int> s1, s2;
	for (int i = 0; i < 10; i++)
		s1.insert(i);
	
	for (int i = 8; i < 12; i++)
		s2.insert(i);

	cout << "Set s1: " << s1 << endl;
	cout << "Set s2: " << s2 << endl;

	Set<int> s3 = s1;
	cout << "s3 Copy of s1: " << s3 << endl;
	s3 = s2;
	cout << "s3 assignment from s2: " << s3 << endl;

	s3 = s1 + s2;
	cout << "s3 sum s1+s2 : " << s3 << endl;

	cout << "0 in Set s1 ? " << (s1.inSet(0) ? "YES" : "NO") << endl;
	cout << "10 in Set s1 ? " << (s1.inSet(10) ? "YES" : "NO") << endl;
	cout << "After 2 x pop() from s2 : ";
	s2.pop(); s2.pop();
	cout << s2 << endl;*/

	cout<<"--------- 1 -----------"<<endl;
	Set<int> s1, s2;
	for (int i = 0; i < 10; i++)
		s1.insert(i);
	
	for (int i = 8; i < 12; i++)
		s2.insert(i);

	cout << "Set s1: " << s1 << endl;
	cout << "Set s2: " << s2 << endl;

	Set<int> s3 = s1;
	cout << "s3 Copy of s1: " << s3 << endl;
	s3 = s2;
	cout << "s3 assignment from s2: " << s3 << endl;

	s3 = s1 + s2;
	cout << "s3 sum s1+s2 : " << s3 << endl;

	cout << "0 in Set s1 ? " << (s1.inSet(0) ? "YES" : "NO") << endl;
	cout << "10 in Set s1 ? " << (s1.inSet(10) ? "YES" : "NO") << endl;
	cout << "After 2 x pop() from s2 : ";
	s2.pop(); s2.pop();
	cout << s2 << endl;

	cout << "--------- 2 -----------" << endl;
	Set<char> sch;
	
	for (char i = 0; i < 10; i++)
		sch.insert('a' + i);

	cout << "Set of characters : " <<  sch << endl;

	cout << "z in Set " << (sch.inSet('z') ? "YES" : "NO") << endl;
	cout << "A in Set " << (sch.inSet('A') ? "YES" : "NO") << endl;
	cout << "a in Set " << (sch.inSet('a') ? "YES" : "NO") << endl;

	cout << "--------- 3 -----------" << endl;
	
	// add your code
	
	//uncomment but do not change following  line
	try
	{
		while (true) cout << s2.pop() << endl;
	}
	catch (out_of_range& e)
	{
		cout << e.what() << endl;
	}
	
		
	
	cout << "--------- 4 -----------" << endl;
	cout << "Set 1 : " << s1 << endl << "Set 3 : " << s3 << endl;
	s3 = s3 - s1;
	cout << "s3 = s3 - s1 : " << s3  << endl;

}
