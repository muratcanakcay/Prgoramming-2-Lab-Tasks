#include "Sequence.h"

using namespace std;

int main(void){

	//#############   PART1 - constructors    #################
	cout << "=== PART 1 ===" << endl;
	const Sequence c1;
	Sequence c2(5);
	int coef[] = {1,2,3,4,5,6,7,8,9,10};
	Sequence c3(10,coef);
	Sequence c4(c3);
	Sequence c5;
	c5=c4;

	cout << "Lengths of sequences : " << endl;
	cout << "c1 = " << c1.length() << endl;
	cout << "c2 = " << c2.length() << endl;
	cout << "c3 = " << c3.length() << endl;
	cout << "c4 = " << c4.length() << endl;
	cout << "c5 = " << c5.length() << endl;
	
	//#############   PART2 - test operators >> & <<  #################
	cout << endl << "=== PART 2 ===" << endl;
	
	cout << "- c1 (default) " << c1 << endl;
	cout << "- c2 (1 argument) " << c2 << endl;
	cout << "- c3 (2 arguments) " << c3 << endl;
	cout << "- c4 " << c4 << endl;
	cout << "- c5 " << c5 << endl;

	cout<<endl<<"Input sequence "<<endl;
	cin>>c4;
	cout<<"Your sequence : "<< c4<<endl;

	//#############   PART3 - test methods   #################
	cout << endl << "=== PART 3 ===" << endl;
	Sequence & c = c3;
	int idx,val;

	cout << "Input term index (0-"<<c.length()<<") : ";
	cin >> idx;
	cout << "Value c3[" << idx << "] = " << c.get_idx(idx) << endl;

	cout << "Input new value c3[" << idx << "] = ";
	cin >> val;
	//fill missing
	c.set_idx(idx) = val;
	cout << "Value c3[" << idx << "] = " << c.get_idx(idx) << endl;

	//#############   PART4 - test arithmetic   #################
	cout << endl << "=== PART 4 ===" << endl;
	cout<< "Is a sequence c = "<< c << " is arithmetic?"<<endl; 
	checkArithmetic(c);

	//#############   PART5 - test divide   #################
	cout << endl << "=== PART 5 ===" << endl;
	cout << "Select every n-ty term from sequence " << c << "\nInput n : ";
	int n;
	cin >> n;
	c = nth(c,n);

	cout<<"Result : "<< c <<endl;

	system("pause");
}
