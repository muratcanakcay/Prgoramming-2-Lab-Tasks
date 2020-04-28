#ifndef QUEUE_H_
#define QUEUE_H_
#include "client.h"

const int Q_SIZE = 10;

class Queue
{
private:
	struct Node { Client item; struct Node * next; };
	Node * front;       
	Node * rear;        
	int clients;          // current number of clients in queue
	int qsize;    // maximum number of clients in queue
	
	Queue(const Queue & q) = delete;
	Queue & operator=(const Queue & q) = delete;
public:
	Queue(int qs = Q_SIZE);         // creates a queue with a capacity of qs (default Q_SIZE)
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int size() const;
	bool enqueue(const Client &client); // adds a client to the end (rear) of the queue
	bool dequeue(Client &client);       // pulls a client out of the queue front
	ostream& print(ostream&) const;
	friend ostream& operator<< (ostream& out, const Queue& q);

	friend class BankWindow;
};

#endif