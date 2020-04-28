#include <iostream>
#include <ctime>
using namespace std;
#include "client.h"
#include "queue.h"
#include "bank.h"

int main()
{
	//srand(std::time(0));  
	// ==================   PART 1 (1 pts)  ===========================
	cout << endl << "-------------  PART 1 (1 pts) --------------" << endl;
	
	Client k1, k2;
	cout << "Client 1:" << endl;
	cout << k1 << endl;
	k1.set(3);
	k2.set(5);
	cout << "Client 1:" << endl;
	cout << k1 << endl;
	cout << "Client 2:" << endl;
	cout << k2 << endl;
	
	// ==================   PART 2 (5 pts)  ===========================
	cout << endl << "-------------  PART 2 (5 pts) --------------" << endl;
	
	Queue queue(2);
	cout << queue << endl;
	if (queue.enqueue(k1)) cout << "Client 1 added to the queue" << endl;
	if (queue.enqueue(k2)) cout << "Client 2 added to the queue" << endl << endl;
	if (queue.enqueue(k2)) cout << "Client 3 added to the queue. Something is wrong !!!!" << endl << endl;
	cout << queue << endl;
	if (queue.dequeue(k1)) cout << "Client 1 has left the queue" << endl << endl;
	cout << queue << endl;
	cout << "Client 1:" << endl;
	cout << k1 << endl;
	if (queue.dequeue(k2)) cout << "Client 2 has left the queue" << endl << endl;
	cout << queue << endl;
	cout << "Client 2:" << endl;
	cout << k1 << endl;
	if (queue.dequeue(k1)) cout << "Client 3 has left the queue.  Something is wrong !!!!" << endl << endl;
	
	// ==================   PART 3 (1 pts)  ===========================
	cout << endl << "-------------  PART 3 (1 pts) --------------" << endl;
	
	BankWindow window1(5,1);
	cout << "Window no 1 (queue size: 5, working time: 1h" << endl << window1 << endl;
	BankWindow window2(10, 1);
	cout << "Window no 2 (queue size: 10, working time: 1h" << endl << window2 << endl;
	
	// ==================   PART 4 (1 pkt)  ===========================
	cout << endl << "-------------  PART 4 (1 pts) --------------" << endl;
	
	window1.simulation(5);
	window2.simulation(3);
	cout << "Window no 1 (queue size: 5, working time: 1h, client every: 5 minutes" << endl << window1 << endl;
	cout << "Window no 2 (queue size: 10, working time: 1h, client every: 3 minutes" << endl << window2 << endl;
	
	//system("pause");
	return 0;
}
